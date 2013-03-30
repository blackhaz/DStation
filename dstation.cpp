#include <QtGui>
#include "dstation.h"
#include "ui_dstation.h"
#include <list>
#include "Magick++.h"
#include "QProcess.h"
#include "aboutdialog.h"
#include <cmath>

using namespace std;
using namespace Magick;

DStation::DStation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DStation)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Application initialization.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->setupUi(this);

    ui->tabWidget->setParent(0);                                                                        // Setting up scroll feature for the settings tab area.
    ui->scrollArea->setWidget(ui->tabWidget);

    this->removeToolBar(ui->mainToolBar);

#ifdef Q_WS_X11
    OSv=QString("Linux");
    ui->stop32bitSpaceExceededCheckBox->setChecked(false);
    ui->stop32bitSpaceExceededCheckBox->setEnabled(false);
#endif
#ifdef Q_WS_WIN
    OSv=QString("Windows");
    ui->stop32bitSpaceExceededCheckBox->setChecked(true);
    ui->stop32bitSpaceExceededCheckBox->setEnabled(true);
#endif
#ifdef Q_WS_MACX
    ui->stop32bitSpaceExceededCheckBox->setChecked(false);                                              // Mac OS X build is 64-bit so we don't need to check for 32-bit address space boundaries.
    ui->stop32bitSpaceExceededCheckBox->setEnabled(false);
    OSv=QString("Mac OS X");
    ui->useHDRI->setChecked(false);                                                                     // Do not use HDRI Wiener deconvolution on Mac OS X. HDRI mode produces sporadic checkerboard pattern,
#endif                                                                                                  // probably due to buggy OpenMP implementation. Subject to investigation.

    HDRIenabled=false;
#ifdef MAGICKCORE_HDRI_SUPPORT
    HDRIenabled=true;
#endif

    const char *tmpDirBuffer = QDir::tempPath().toAscii().data();                                       // Locating temporary directory to work in.
    sprintf(TMPDIR, "%s", tmpDirBuffer);

    workingDirectory="";                                                                                // Initializing working directory to current directory.

    IMfilters[0] = PointFilter;                                                                         // Initialize sampling filters.
    IMfilters[1] = BoxFilter;
    IMfilters[2] = TriangleFilter;
    IMfilters[3] = HermiteFilter;
    IMfilters[4] = HanningFilter;
    IMfilters[5] = HammingFilter;
    IMfilters[6] = BlackmanFilter;
    IMfilters[7] = GaussianFilter;
    IMfilters[8] = QuadraticFilter;
    IMfilters[9] = CubicFilter;
    IMfilters[10] = CatromFilter;
    IMfilters[11] = MitchellFilter;
    IMfilters[12] = LanczosFilter;
    IMfilters[13] = BesselFilter;
    IMfilters[14] = SincFilter;

    ui->menuPreview->setEnabled(false);                                                                 // Disabling menus. Qt Creator workaround as IDE does not allow to edit disabled menus.
    previewX=0;
    previewY=0;
    haveExternalFilter=false;
    haveReferenceImage=false;
    haveDeconvolvedImage=false;

    previewH=256;                                                                                       // Initializing settings according to default menu state.
    previewW=256;
    zoomFactor=1;
    zoomImage(zoomFactor);

    // Start with displaying introduction strings in console.
    ui->consoleEdit->setPlainText(QString(APPNAME).append(QString(" ")).append(VERSION_STRING(VERSION_NUMBER)).append(QString(" for ")).append(OSv));
    ui->consoleEdit->appendPlainText(QString(APPCOPYRIGHTS).append(QString(" All rights reserved.")));
    ui->consoleEdit->appendPlainText(QString("Using ImageMagick libraries version ").append(QString(MagickLibVersionText)).append(QString(" Quantum Depth: ")).append(QString::number(MAGICKCORE_QUANTUM_DEPTH)).append(QString("-bit. ")).append(QString(MagickCopyright)));
    if (HDRIenabled)
        ui->consoleEdit->appendPlainText("HDRI Support Enabled.");
    else
        ui->consoleEdit->appendPlainText("No HDRI Support. *** PLEASE NOTICE: DSTATION REQUIRES HDRI TO WORK. REBUILD IMAGEMAGICK. *** ");
    ui->consoleEdit->appendPlainText("Ready.");

    scene=new DGraphicsScene(this);                                                                     // Creating new DGraphicsScene object that holds images. Connecting it's slot to function
    histogramScene=new DGraphicsScene(this);                                                            // that handles preview windows. That is, when user clicks on the image, the mouse coordinates
    PSFScene=new DGraphicsScene(this);
    ui->imageView->setScene(scene);                                                                     // define where the preview window is placed. We also create a scene for histogram image.
    ui->histogramView->setScene(histogramScene);
    ui->PSFView->setScene(PSFScene);
    scene->connect(scene, SIGNAL(mousePressed()), this, SLOT(changePreviewCoordinates()));
    equalizerScene=new DGraphicsScene(this);
    ui->equalizerView->setScene(equalizerScene);
    on_filteringMethod_currentIndexChanged(ui->filteringMethod->currentIndex());                          // Update UI depending on the initial filtering method chosen.
    updateEqualizerImage();

    if (DEBUG)
        openImage(QString("/-Astro/deconv/moon.png"));
    //openImage(QString("/-Astro/deconv/G06_st3000.fit"));
}

DStation::~DStation()
{
    delete ui;
}

void DStation::on_actionOpen_Image_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Open image menu.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QFileDialog openDialog;
    QString fileName = openDialog.getOpenFileName(this, "Choose an image", workingDirectory, "Images (*.png *.fts *.fits *.fit *.tif *.tiff)");
    if (!fileName.isEmpty()) {
        openImage(fileName);
        QDir dir(fileName);
        workingDirectory=dir.absolutePath();
    }
    updateEqualizerImage();
}

void DStation::openImage(const QString &fileName)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Open new input image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->action1024x1024->setEnabled(true);                                                              // Enabling all preview options. These may be disabled later by default depending on the input
    ui->action128x128->setEnabled(true);                                                                // image dimensions, as there is no sense to place a large preview window over a small image.
    ui->action256x256->setEnabled(true);
    ui->action512x512->setEnabled(true);
    ui->action64x64->setEnabled(true);
    ui->action32x32->setEnabled(true);

    clearHistogram();
    ui->consoleEdit->appendPlainText(QString("Opening ").append(fileName).append(QString("...")));
    qApp->processEvents();
    inputImageFileName=fileName;
    try {
        inputImage.read(fileName.toAscii().data());
        inputImage.page("0x0+0+0");                                                                     // Fix virtual canvas.
    }
    catch (exception& e)
    {
        ui->consoleEdit->appendPlainText(QString("Error opening image. Exception caught: ").append(QString(e.what())));
    }
    FFTRealComponentShown=false;
    zoomFactor=1;
    zoomImage(zoomFactor);
    previewDeployed=false;
    haveDeconvolvedImage=false;
    deconvolvedImageShown=false;
    displayMagickImage(inputImage);
    ui->consoleEdit->appendPlainText("Done.");

    this->setWindowTitle(QString(APPNAME).append(QString(": ")).append(QFileInfo(inputImageFileName).fileName()));       // Setting window title to hold input image file name.

    ui->showInputButton->setEnabled(false);                                                             // Disabling UI items that require deconvolved image or preview window defined.
    ui->showFFTMagnitudeButton->setEnabled(false);
    ui->actionRemove_Preview->setEnabled(false);
    ui->actionMeasure_NSR->setEnabled(false);

    ui->deconvolveButton->setEnabled(true);                                                             // Enabling UI items required to produce deconvolved images.
    ui->actionDeconvolve->setEnabled(true);
    ui->menuPreview->setEnabled(true);
    ui->actionNew_Preview->setEnabled(true);
    ui->showOnlyInputButton->setEnabled(true);
}

void DStation::displayMagickImage(const Image imageToDisplay)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Displaying ImageMagick Image object in main scene.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QPixmap temporaryPixmap = QPixmap::fromImage(imageToQImage(imageToDisplay));
    scene->clear();
    scene->setSceneRect(0,0,imageToDisplay.columns(),imageToDisplay.rows());                            // Making sure scene dimensions equal input image.
    scene->addPixmap(temporaryPixmap);
    showPreview();
}

void DStation::showPreview()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Showing preview window in main scene.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (previewDeployed && !FFTRealComponentShown) {                                                    // Displaying preview area if preview window is deployed.
        QPen previewPen;
        QColor previewColor;
        QFont previewLabelFont;
        QGraphicsTextItem *previewLabel;
        previewColor.setNamedColor("white");
        previewPen.setWidth(1);
        previewPen.setColor(previewColor);
        scene->addRect(previewX,previewY,previewW,previewH,previewPen,Qt::NoBrush);
        previewLabelFont.setPixelSize(10);
        previewLabel=scene->addText(QString("Preview Area"), previewLabelFont);
        previewLabel->setPos(previewX,previewY-16);
        previewLabel->setDefaultTextColor(Qt::white);
    }
}

QImage DStation::imageToQImage(const Image tempImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Converting ImageMagick Image object to Qt QImage object.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Magick::ColorRGB rgb;
    int red;
    int green;
    int blue;
    QImage convertedImage(tempImage.columns(), tempImage.rows(), QImage::Format_RGB32);
    const PixelPacket *pixels;
    for (int y=0; y<(int)tempImage.rows(); y++) {
        pixels = tempImage.getConstPixels(0, y, tempImage.columns(), 1);
        for (int x=0; x<(int)tempImage.columns(); x++) {
            rgb=(*(pixels+x));
            red=(int)(255*rgb.red());
            green=(int)(255*rgb.green());
            blue=(int)(255*rgb.blue());
            if (red>255) red=255;                                                                       // Clamping values exceeding display quantum range. We don't need to clamp negatives as
            if (green>255) green=255;                                                                   // Qt displays negatives as black.
            if (blue>255) blue=255;
            if (red<0) red=0;
            if (green<0) green=0;
            if (blue<0) blue=0;
            convertedImage.setPixel(x, y, QColor(red, green, blue).rgb());
        }
    }
    return(convertedImage);
}

void DStation::displayMagickBlob(const Blob imageToDisplay)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Displaying ImageMagick BLOB object in main scene.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tempImage(imageToDisplay);                                                                    // Constructing Image object from BLOB
    QPixmap temporaryPixmap = QPixmap::fromImage(imageToQImage(tempImage));
    scene->clear();
    scene->setSceneRect(0,0,tempImage.columns(),tempImage.rows());                                      // Making sure scene dimensions equal input image.
    scene->addPixmap(temporaryPixmap);
    showPreview();
}

void DStation::displayMagickImageInHistogram(const Image imageToDisplay)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Displaying ImageMagick object in histogram scene.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    histogramScene->clear();
    histogramScene->addPixmap(QPixmap::fromImage(imageToQImage(imageToDisplay)));

    QPen previewPen;
    QColor previewColor;
    QFont previewLabelFont;
    QGraphicsTextItem *previewLabel;
    previewLabelFont.setPixelSize(10);
    previewLabel=histogramScene->addText(QString("Histogram"), previewLabelFont);
    previewLabel->setPos(1,1);
    previewLabel->setDefaultTextColor(Qt::white);
}

void DStation::displayMagickImageInPSF(const Image imageToDisplay)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Displaying ImageMagick object in PSFscene.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    PSFScene->clear();
    Image scaledImage=imageToDisplay;
    scaledImage.scale(Geometry(91,91));
    scaledImage.normalize();

    PSFScene->addPixmap(QPixmap::fromImage(imageToQImage(scaledImage)));

    QPen previewPen;
    QColor previewColor;
    QFont previewLabelFont;
    QGraphicsTextItem *previewLabel;
    previewLabelFont.setPixelSize(10);
    previewLabel=PSFScene->addText(QString("PSF"), previewLabelFont);
    previewLabel->setPos(1,1);
    previewLabel->setDefaultTextColor(Qt::white);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Image Zoom Functions
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DStation::zoomImage(const double zoom)
{
    /* Zoom Image */
    ui->imageView->resetTransform();
    ui->imageView->scale(zoom, zoom);
    char buffer[256];
    snprintf(buffer, 5, "%f", zoom);
    ui->zoomLabel->setText(QString(buffer).append(QString("X")));
}

void DStation::on_zoomInButton_clicked()
{
    /* Zoom In */
    zoomFactor=zoomFactor*ZOOMSTEP;
    zoomImage(zoomFactor);
}

void DStation::on_zoomFullButton_clicked()
{
    /* 100% Zoom */
    zoomFactor=1;
    zoomImage(zoomFactor);
}

void DStation::on_zoomOutButton_clicked()
{
    /* Zoom Out */
    zoomFactor=zoomFactor/ZOOMSTEP;
    zoomImage(zoomFactor);
}

void DStation::on_deconvolveButton_clicked()
{
    /* Deconvolve Image */
    deconvolve();
}

QString DStation::shellCommand(const QString process, const QStringList arguments, const bool debug)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Executing shell command.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QString output;

    if (debug) {
        ui->consoleEdit->appendPlainText(QString(process).append(QString(" ")).append(QString(arguments.join(" "))));
        qApp->processEvents(); /* Required to update console screen before doing something intensive */
    }

    QProcess *shellcmd = new QProcess(this);
    shellcmd->start(process, arguments);

    if (!shellcmd->waitForFinished())
        output=QString("Failed:").append(QString(shellcmd->errorString()));
    else
        output=QString(shellcmd->readAll());

    if (debug) {
        ui->consoleEdit->appendPlainText(output);
        ui->consoleEdit->appendPlainText("Finished.");
    }
    qApp->processEvents(); /* Required to update console screen before doing something intensive */
    return(output);
}

void DStation::deconvolve()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Primary deconvolution function. It is very spaghetti styled because I am too lame to understand how to avoid conserving excessive amounts of RAM when it is sliced into many smaller pieces.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int width;
    int height;
    Image tmpF;
    Image tmpR;
    Image savedInputImage;
    Image supersampledSavedInputImage;
    Image tmpRed;
    Image tmpGreen;
    Image tmpBlue;
    Magick::Image::ImageStatistics tmpFStatistics;
    Magick::Image::ImageStatistics tmpRStatistics;
    ChannelType currentChannel;
    int currentChannelCycle;
    int channelCycles;
    int memoryConsumption;
    char bufferA[256];
    char bufferB[256];
    char widthString[256];
    char heightString[256];
    char atmosphericMTFDimension[256];
    char atmosphericMTF[256];
    double gainF;
    double gainRef;
    double gainR;
    double gainG;
    double gainB;
    double cutOff;
    double falpha;
    double lambda;
    double superSampling;
    double focalLength;
    double pixel;
    double gamma;
    double benchmarkElapsed;
    QTime timer;
    QPalette consoleEditPalette;
    double benchmark;

    if (ui->deconvolutionAlgorithm->currentIndex()!=6) {                                               // Deconvolve unless none algorithm is selected.

        //ui->consoleEdit->appendPlainText(QString("Preparing to start..."));

        if (ui->deconvolutionAlgorithm->currentIndex()==3 && !haveExternalFilter) {                         // Checking if we have an external filter available if we need it. -0.312-
            ui->consoleEdit->appendPlainText(QString("No external filter available. Please load a filter image to deconvolve using an external filter."));
            return;
        }

        ui->deconvolveButton->setEnabled(false);                                                            // Updating UI and changing console background color to signalize deconvolution process.
        ui->actionDeconvolve->setEnabled(false);
        consoleEditPalette=ui->consoleEdit->palette();
        QPalette consoleEditBusyPalette=consoleEditPalette;
        consoleEditBusyPalette.setColor(QPalette::Base,QColor(60,0,0));
        ui->consoleEdit->setPalette(consoleEditBusyPalette);

        qApp->processEvents();

        try {
            timer.start();                                                                                 // Starting benchmark timer.
            savedInputImage=inputImage;                                                                    // Saving the original input image. We will need it later to restore the original input image.

            if (previewDeployed) {
                inputImage.crop(Geometry(previewW,previewH,previewX,previewY));
            }

            if (ui->bufferSpin->value()>0 && !previewDeployed) {                                           // Anti-FFT Artifact Buffer.
                checkBufferIsValid();
                int width_=inputImage.columns();                                                           // Saving width and height
                int height_=inputImage.rows();
                int buffer=ui->bufferSpin->value()/2;
                inputImage.borderColor(Magick::Color(0,0,0));                                              // Adding border.
                inputImage.border(Geometry(buffer,buffer));
                inputImage=lowLevel_mirrorRight(inputImage,buffer,buffer,width_,height_);
                inputImage=lowLevel_mirrorLeft(inputImage,buffer,buffer,width_,height_);
                inputImage=lowLevel_mirrorUp(inputImage,buffer,height_);
                inputImage=lowLevel_mirrorDown(inputImage,buffer,height_);
            }

            width=inputImage.columns()*ui->supersamplingFactorSpin->value();
            height=inputImage.rows()*ui->supersamplingFactorSpin->value();

            if (ui->supersamplingFactorSpin->value()>1) {                                                   // Pre-Supersampling.
                ui->consoleEdit->appendPlainText(QString("Supersampling..."));
                qApp->processEvents();
                inputImage.filterType(IMfilters[ui->supersamplingFilter->currentIndex()]);
                inputImage.resize(Geometry(width, height));
            }
            supersampledSavedInputImage=inputImage;                                                         // Saving supersampled image so we won't need to supersample per each channel if we are
            // operating in separate wavelength mode.

            sprintf(widthString, "%i", width);
            sprintf(heightString, "%i", height);
            ui->consoleEdit->appendPlainText(QString("Input image dimensions (supersampled and buffered), pixels: ").append(QString(widthString)).append(QString("x")).append(QString(heightString)));
            qApp->processEvents();

            if (width>height) memoryConsumption=width*width;                                                // Finding out how much RAM is needed for deconvolution process.
            else
                memoryConsumption=height*height;
            memoryConsumption=(((memoryConsumption*5*32)/8)/1024)/1024;                                     // Per image in Megabytes.
            memoryConsumption=memoryConsumption*10;                                                         // Total images in operation while deconvolving. (Approximate!)
            sprintf(bufferA,"%i",memoryConsumption);
            ui->consoleEdit->appendPlainText(QString("RAM required for deconvolution: ").append(QString(bufferA)).append(QString("MB, approximate.")));
            qApp->processEvents();

#ifdef Q_WS_WIN                                                                                         // Applicable to 32-bit Windows build only.
            if (memoryConsumption>1700) {
                ui->consoleEdit->appendPlainText(QString("WARNING! You are running 32-bit version of this application. There is not enough RAM to process image of this size."));
                ui->consoleEdit->appendPlainText(QString("WARNING! Unpredictable results, memory corruption or even system hang ups may occur."));
                qApp->processEvents();
                if (ui->stop32bitSpaceExceededCheckBox->isChecked()) {
                    ui->consoleEdit->appendPlainText(QString("Aborting deconvolution as RAM usage exceeds 32-bit address space safe boundaries. You can adjust settings"));
                    ui->consoleEdit->appendPlainText(QString("in the System tab to continue anyways, however this is generally not recommended."));
                    ui->deconvolveButton->setEnabled(true);
                    ui->actionDeconvolve->setEnabled(true);
                    ui->consoleEdit->setPalette(consoleEditPalette);
                    qApp->processEvents();
                    return;
                }
            }
#endif

            /* Defining if we are working with a single channel (central wavelength mode) or three channels separately (separate wavelength mode). With the latter, we will be doing
       three deconvolution cycles. Separate wavelength mode is not active if blind filter is used. */
            if (ui->processingMode->currentIndex()==1) {                                                // Correction v.0.312
                ui->consoleEdit->appendPlainText(QString("Processing under separate RGB wavelengths mode, individual channel messages are suppressed."));
                channelCycles=3;
            }
            else
                channelCycles=1;

            // ----------------------------------------- DECONVOLUTION CYCLE -------------------------------------------------
            for (currentChannelCycle=0; currentChannelCycle<channelCycles; currentChannelCycle++) {         // This is begin of each channel cycle. For central wavelength mode, this cycle will run once.
                inputImage=supersampledSavedInputImage;                                                     // Restoring input image per each cycle.
                /* Extracting channel if separate wavelength mode is selected */
                if (ui->processingMode->currentIndex()==1) {                                            // Correction v.0.312
                    if (currentChannelCycle==0) {
                        ui->consoleEdit->appendPlainText(QString("Processing channel R..."));
                        currentChannel=RedChannel;
                    }
                    if (currentChannelCycle==1) {
                        ui->consoleEdit->appendPlainText(QString("Processing channel G..."));
                        currentChannel=GreenChannel;
                    }
                    if (currentChannelCycle==2) {
                        ui->consoleEdit->appendPlainText(QString("Processing channel B..."));
                        currentChannel=BlueChannel;
                    }
                    inputImage.channel(currentChannel);
                }

                if (ui->subtractBias->isChecked()) {
                    Magick::Image::ImageStatistics IStatistics;
                    inputImage.statistics(&IStatistics);
                    double bias=(double)IStatistics.red.minimum*0.9/QuantumRange;
                    inputImage=lowLevel_subtract(inputImage,bias);
                }

                if (ui->deconvolutionAlgorithm->currentIndex()!=3) {                                        // FILTER CREATION STAGE. Not needed if we are deconvolving with external filter. -v0.312-

                    // ----------------------------------------- ATMOSPHERIC MTF ---------------------------------------------
                    if (width>=height) strcpy(atmosphericMTFDimension,widthString);                         // Here we build the atmospheric MTF filter of the input image dimensions. Because FFT filters
                    else                                                                                    // are always NxN square, we use N=width or N=height (of the input image), whichever is greater.
                        strcpy(atmosphericMTFDimension,heightString);                                       // ImageMagick then does the padding of the input image to square dimensions automatically when
                    strcpy(bufferA,atmosphericMTFDimension);                                                // doing Fourier transforms.
                    strcat(bufferA,"x1");
                    Image tmpA (bufferA,"black");                                                           // Creating Nx1 image - horizontal component for atmospheric MTF.
                    // We are not building Atmospheric MTF if we use blind or external filter deconvolution.
                    if (ui->deconvolutionAlgorithm->currentIndex()!=3 && ui->deconvolutionAlgorithm->currentIndex()!=4 && ui->deconvolutionAlgorithm->currentIndex()!=5) {
                        qApp->processEvents();
                        pixel=(double)ui->pixelSpin->value()/1000;                                          // Converting pixels from microns to mm.
                        superSampling=ui->supersamplingFactorSpin->value();
                        focalLength=(double)ui->fSpin->value()*ui->barlowSpin->value();
                        cutOff=(double)1/(pixel/superSampling/focalLength);                                 // Finding MTF cut-off frequency.
                        if (ui->FriedAlpha->currentIndex()==0)
                            falpha=0;                                                                       // Fried's Long exposure case.
                        else
                            falpha=0.5;                                                                     // Fried's Short exposure case.
                        if (ui->processingMode->currentIndex()==1) {
                            if (currentChannelCycle==0) lambda=(double)ui->wavelengthRSpin->value()/1000000;// Converting R channel lambda from nm to mm.
                            if (currentChannelCycle==1) lambda=(double)ui->wavelengthGSpin->value()/1000000;// Converting G channel lambda from nm to mm.
                            if (currentChannelCycle==2) lambda=(double)ui->wavelengthBSpin->value()/1000000;// Converting B channel lambda from nm to mm.
                        } else
                            lambda=(double)ui->wavelengthGSpin->value()/1000000;                            // Using G channel lambda as central frequency for central wavelength mode.
                        buildAtmosphericFx(atmosphericMTF,lambda,pixel,cutOff,ui->r0Spin->value(),falpha,ui->dSpin->value(),true);
                        tmpA.fx(atmosphericMTF);
                        strcpy(bufferA,"1x");
                        strcat(bufferA,atmosphericMTFDimension);
                        Image tmpB (bufferA,"black");                                                       // Creating 1xN - vertical component for atmospheric MTF.
                        buildAtmosphericFx(atmosphericMTF,lambda,pixel,cutOff,ui->r0Spin->value(),falpha,ui->dSpin->value(),false);
                        tmpB.fx(atmosphericMTF);
                        strcpy(bufferA,atmosphericMTFDimension);                                            // Scaling vertical and horizontal images to produce NxN image.
                        strcat(bufferA,"x");
                        strcat(bufferA,atmosphericMTFDimension);
                        strcat(bufferA,"!");
                        tmpA.scale(bufferA);
                        tmpB.scale(bufferA);
                        tmpA.composite(tmpB,0,0,MultiplyCompositeOp);                                       // Multiply images together to produce atmospheric MTF - Fred's NxN! school.
                        if (DEBUG)
                            tmpA.write("/temp/MTF.png");
                    }

                    // ----------------------------------------- FORWARD FFT -------------------------------------------------
                    if (!(ui->deconvolutionAlgorithm->currentIndex()==1 && !ui->useHDRI->isChecked())) {    // Forward Fourier Transform. Saving real and imaginary components of input
                        // image to a container. We don't need to save components when
                        // deconvolving using atmospheric MTF algorithm in non-HDRI mode. This is because
                        // non-HDRI Wiener deconvolution mode does the magnitude and phase Fourier
                        // transform of the input image itself.
                        if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Forward Fourier Transform..."));
                        qApp->processEvents();
                        forwardFourierTransformImage(&FFTContainer,inputImage,false);
                    }
                    // -------------------------------------------------------------------------------------------------------

                    // ----------------------------------------- BLIND FILTER ------------------------------------------------
                    if (ui->deconvolutionAlgorithm->currentIndex()!=1) {                                    // We don't need to process blind filter if we are using Atmospheric MTF mode.
                        tmpF=FFTContainer.front();
                        tmpF=lowLevel_clamp_negatives(tmpF);                                                // Clamping negatives from the FFT real component

                        Image *FFTRealComponent = new Image(tmpF);                                          // Saving normalized FFT real component to a BLOB. Freeing memory afterwards.
                        FFTRealComponent->normalize();
                        FFTRealComponent->magick("JPEG");
                        FFTRealComponent->write(&FFTRealComponentImageBlob);
                        delete FFTRealComponent;

                        tmpF=smooth(tmpF,ui->gaussianBlurSpin->value());                                    // Filtering (smoothing) FFT real component.

                        tmpF.statistics(&tmpFStatistics);
                        gainR=(double)1/(tmpFStatistics.red.maximum/QuantumRange);
                        gainG=(double)1/(tmpFStatistics.green.maximum/QuantumRange);
                        gainB=(double)1/(tmpFStatistics.blue.maximum/QuantumRange);
                        gainF=min(min(gainR,gainG),gainB);                                                  // Using (1/Maxima) of a filtered real component, across all RGB channels.
                    }

                    if (ui->deconvolutionAlgorithm->currentIndex()!=1) {                                    // Applying gain. We don't need to do this if we are building only Atmospheric MTF filter.
                        //if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Preparing image..."));
                        qApp->processEvents();

                    }
                    // -------------------------------------------------------------------------------------------------------

                    // ----------------------------------------- CREATE FILTER -----------------------------------------------
                    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Creating filter...")); // -v0.312-
                    qApp->processEvents();

                    Image tmpD(Geometry(tmpF.columns(),tmpF.rows()),Color("black"));                        // Construct a new black denominator image. -- DEBUG --
                    double fact;

                    switch(ui->deconvolutionAlgorithm->currentIndex()) {
                    case 0:                                                                                 // Filter is a square root from multipication of power
                        tmpF=lowLevel_multiply(tmpF,gainF);                                                 // Blind filter (compression)
                        tmpF=lowLevel_compress(tmpF,ui->logFactorSpin->value(),1);
                        tmpF.composite(tmpA,0,0,MultiplyCompositeOp);                                       // Mean between blind and atmospheric filters.
                        tmpF=lowLevel_power(tmpF,0.5);
                        break;

                    case 1:
                        tmpF=tmpA;                                                                          // This is Atmospheric MTF mode whereby filter equals Atmospheric MTF.
                        break;

                    case 2:                                                                                 // -v0.312-
                        tmpF=lowLevel_multiply(tmpF,gainF);                                                 // Blind filter (compression)
                        tmpF=lowLevel_compress(tmpF,ui->logFactorSpin->value(),1);
                        gamma=(double)ui->gammaSpinBox->value();                                            // This is weighted filter, whereby additional parameter (gamma) is introduced to
                        tmpA=lowLevel_power(tmpA,gamma);                                                    // change filter weights. Gamma=1 produces 100% atmospheric MTF filter, and Gamma=0 produces
                        tmpF=lowLevel_power(tmpF,(double)1-gamma);                                          // 100% blind filter.
                        tmpF.composite(tmpA,0,0,MultiplyCompositeOp);
                        break;

                    case 4:
                        // Jae Lim Blind Deconvolution filter, equals smoothed magnitude of input divided by smoothed
                        // magnitude of reference image.
                        tmpF=lowLevel_multiply(tmpF,gainF);
                        tmpR=LimReferenceImage;
                        if (tmpR.rows()<tmpF.rows() || tmpR.columns()<tmpF.columns()) {
                            ui->consoleEdit->appendPlainText("WARNING! Reference image is smaller than the filter. Results are unpredictable.");
                        }
                        tmpR.crop(Geometry(tmpF.columns(),tmpF.rows()));                                        // Crop reference image to the size of the filter
                        forwardFourierTransformImage(&FFTContainerReference,tmpR,true);
                        tmpR=FFTContainerReference.front();
                        tmpR=smooth(tmpR,ui->gaussianBlurSpin->value());                                        // Filtering (smoothing) of reference image.
                        tmpR.statistics(&tmpRStatistics);
                        gainR=(double)1/(tmpRStatistics.red.maximum/QuantumRange);
                        gainG=(double)1/(tmpRStatistics.green.maximum/QuantumRange);
                        gainB=(double)1/(tmpRStatistics.blue.maximum/QuantumRange);
                        gainRef=min(min(gainR,gainG),gainB);                                                  // Using (1/Maxima) of a filtered real component, across all RGB channels.
                        tmpR=lowLevel_multiply(tmpR,gainRef);
                        tmpR.composite(tmpF,0,0,DivideCompositeOp);
                        tmpF=tmpR;
                        break;

                    case 5:
                        // Blind with compression
                        tmpF=lowLevel_multiply(tmpF,gainF);                                                 // Blind filter (compression)
                        tmpF=lowLevel_compress(tmpF,ui->logFactorSpin->value(),1);
                        //tmpF=lowLevel_power(tmpF,ui->logFactorSpin->value());
                        //tmpF=lowLevel_normalized_log_gain(tmpF,(double)ui->logFactorSpin->value()*1000,1);

                        break;
                    }


                    if (!ui->doNotSaveFilterCheckBox->isChecked()) filterImage=tmpF;                        // Saving built filter.
                } else
                    tmpF=filterImage;                                                                       // Use external filter if [Wiener deconvolution with external filter] is selected.


                if (ui->filteringMethod->currentIndex()==3 || ui->filteringMethod->currentIndex()==4 || ui->filteringMethod->currentIndex()==5
                        || ui->filteringMethod->currentIndex()==6) {
                    // Spatial deconvolution (Van Cittert, etc), so spatial filter is required

                    Image PSF=tmpF;
                    PSF.backgroundColor(Color(0,0,0));
                    PSF.erase();
                    PSF.pixelColor(PSF.columns()/2,PSF.rows()/2,Color(QuantumRange,QuantumRange,QuantumRange));

                    int PSFwidth=PSF.columns()*ui->supersamplingFactorSpin->value(); // Supersampling PSF - tricky
                    int PSFheight=PSF.rows()*ui->supersamplingFactorSpin->value();
                    PSF.resize(Geometry(PSFwidth,PSFheight));

                    forwardFourierTransformImage(&PSF_FFTContainer,PSF,true);
                    Image PSFmagnitude=PSF_FFTContainer.front();
                    Image PSFphase=PSF_FFTContainer.back();
                    PSFmagnitude.composite(tmpF,0,0,MultiplyCompositeOp);
                    PSFmagnitude.inverseFourierTransform(PSFphase,true);
                    //PSFmagnitude=lowLevel_clamp_negatives(PSFmagnitude);
                    Magick::Image::ImageStatistics PSFstatistics;
                    PSFmagnitude.statistics(&PSFstatistics);
                    double PSFgain=(double)1/(PSFstatistics.red.maximum/QuantumRange);   // normalize PSF
                    PSFmagnitude=lowLevel_multiply(PSFmagnitude,PSFgain);
                    int fw=ui->spatialFilterSize->value();
                    int off=(PSF.rows()/2)-(fw/2);
                    PSFmagnitude.crop(Geometry(fw,fw,off,off));
                    tmpF=PSFmagnitude;
                    displayMagickImageInPSF(tmpF);
                }
                // -----------------------------------------------------------------------------------------------------------


                // ----------------------------------------- DERINGING PREPARE -------------------------------------------------
                // Procedure described in "Partitioned Image Filtering for Reduction of the Gibbs Phenomenon" by Gengsheng L. Zeng and Richard J. Allred
                Image deringingImage=inputImage;
                int pixelsThresholded=0;
                vector<int> pixelsThresholdedX;
                vector<int> pixelsThresholdedY;

                if (ui->deringingEnabledCheckBox->isChecked()) {
                    if (ui->deringingMethod->currentIndex()==0) {                                           // Image Threshold Partitioning Method
                        inputImage=lowLevel_thresholdMax(inputImage,(double)ui->deringingThreshold->value()*QuantumRange, pixelsThresholdedX, pixelsThresholdedY, pixelsThresholded);
                        if (ui->deringingSmoothMax->isChecked()) inputImage=lowLevel_mixTwoImagesWithBlur(deringingImage,inputImage,pixelsThresholdedX,pixelsThresholdedY,pixelsThresholded,ui->deringingSmoothness->value());
                        if (DEBUG) inputImage.write("/temp/maxthresholded-blurred.png");
                    }

                }
                // -----------------------------------------------------------------------------------------------------------



                // ----------------------------------------- DECONVOLUTION ---------------------------------------------------
                processedImage=deconvolveSwitch(&inputImage,&tmpF,(double)(ui->noiseSpin->value()/1000), true);

                if (ui->deringingEnabledCheckBox->isChecked()) {                                              // Deconvolve deringing support image
                    if (ui->deringingApplyMinThreshold->isChecked()) deringingImage=lowLevel_thresholdMin(deringingImage,(double)ui->deringingThreshold->value()*QuantumRange);
                    if (DEBUG) deringingImage.write("/temp/deringingImage.png");
                    deringingImage=deconvolveSwitch(&deringingImage,&tmpF,(double)(ui->noiseSpin->value()/1000*ui->deringingFactor->value()), true);
                }
                // -----------------------------------------------------------------------------------------------------------


                // ----------------------------------------- DERINGING MIXING -------------------------------------------------
                if (ui->deringingEnabledCheckBox->isChecked()) {
                    if (ui->deringingMethod->currentIndex()==0) {                                           // Image Threshold Partitioning Method
                        processedImage=lowLevel_mixTwoImagesWithBlur(processedImage,deringingImage,pixelsThresholdedX,pixelsThresholdedY,pixelsThresholded,ui->deringingSmoothness->value());
                    }
                    if (ui->deringingMethod->currentIndex()==1) {                                           // Exponential Transform Method
                    }

                }
                // -----------------------------------------------------------------------------------------------------------




                // ----------------------------------------- PREPARING OUTPUT IMAGE ------------------------------------------
                if (!previewDeployed) processedImage.crop(Geometry(width,height,0,0));                       // Crop FFT garbage as FFT pads all images to square. Previews are always assumed to be square.
                if (channelCycles>1) {                                                                       // Save result to a temporary channel storage for RGB combination later on.
                    if (currentChannelCycle==0) tmpRed=processedImage;
                    if (currentChannelCycle==1) tmpGreen=processedImage;
                    if (currentChannelCycle==2) tmpBlue=processedImage;
                }
            }                                                                                               // End of deconvolution cycle.
            // ---------------------------------------------------------------------------------------------------------------

            // ----------------------------------------- PREPARING RESULT ----------------------------------------------------
            if (channelCycles>1) {                                                                          // RGB combination.
                processedImage.composite(tmpRed,0,0,CopyRedCompositeOp);
                processedImage.composite(tmpGreen,0,0,CopyGreenCompositeOp);
                processedImage.composite(tmpBlue,0,0,CopyBlueCompositeOp);
            }

            if (ui->supersamplingFactorSpin->value()>1 && !ui->doNotDownsampleCheckBox->isChecked()) {      // De-supersampling.
                //ui->consoleEdit->appendPlainText(QString("De-supersampling..."));
                qApp->processEvents();
                width=processedImage.columns()/ui->supersamplingFactorSpin->value();
                height=processedImage.rows()/ui->supersamplingFactorSpin->value();
                processedImage.filterType(IMfilters[ui->supersamplingFilterDown->currentIndex()]);
                processedImage.resize(Geometry(width,height));
            }

            if (ui->bufferSpin->value()>0 && !previewDeployed) {                                            // De-buffering.
                int buffer;
                if (!ui->doNotDownsampleCheckBox->isChecked()) buffer=ui->bufferSpin->value()/2;
                else
                    buffer=ui->bufferSpin->value()/2*ui->supersamplingFactorSpin->value();
                processedImage.chop(Geometry(buffer,buffer));
                processedImage.crop(Geometry(processedImage.columns()-buffer,processedImage.rows()-buffer));
            }

            if (!ui->doNotDownsampleCheckBox->isChecked()) benchmark=(double)(width*ui->supersamplingFactorSpin->value()*height*ui->supersamplingFactorSpin->value()/1000)/((double)timer.elapsed()/1000);
            else
                benchmark=(double)(width*height/1000)/((double)timer.elapsed()/1000);
            benchmarkElapsed=(double)timer.elapsed()/1000;

            haveDeconvolvedImage=true;                                                                      // Setting a flag that we have a deconvolved image available.
            ui->actionUse_Deconvolved_Image_as_Reference->setEnabled(true);

            if (previewDeployed) {                                                                          // Overlaying deconvolved preview window over original image if we are deconvolving preview.
                processedPreviewImage=processedImage;
                processedImage=savedInputImage;
                processedImage.composite(processedPreviewImage,previewX,previewY);
            }

            postProcessing();                                                                               // Applying post-processing.
            trackStatistics();                                                                              // Grab deconvolved image statistics and update statistics table if necessary.
            // ---------------------------------------------------------------------------------------------------------------

            sprintf(bufferA, "%.2f", benchmark);
            sprintf(bufferB, "%.2f", benchmarkElapsed);
            ui->consoleEdit->appendPlainText(QString("Benchmark: ").append(QString(bufferA)).append(QString(" kpixels per second, total time: ")).append(QString(bufferB)).append(QString(" seconds.")));

            deconvolvedImageShown=true;                                                                     // Setting flags, updating UI and displaying deconvolved image.
            FFTRealComponentShown=false;
            displayMagickBlob(postProcessedImageBlob);
            ui->showInputButton->setEnabled(true);
            ui->showFFTMagnitudeButton->setEnabled(true);
            ui->deconvolveButton->setEnabled(true);
            ui->actionDeconvolve->setEnabled(true);
            ui->actionSave_Filter_As->setEnabled(true);
            ui->consoleEdit->setPalette(consoleEditPalette);

            inputImage=savedInputImage;                                                                     // Restoring original input image.
        }
        catch (Magick::Warning &warning)                                                                    // Handling exceptions here.
        {
            ui->consoleEdit->appendPlainText(QString("Warning: ").append(QString(warning.what())));
            ui->deconvolveButton->setEnabled(true);
            ui->consoleEdit->setPalette(consoleEditPalette);
        }
        catch (Magick::Exception &error)
        {
            ui->consoleEdit->appendPlainText(QString("Error: ").append(QString(error.what())));
            ui->deconvolveButton->setEnabled(true);
            ui->actionDeconvolve->setEnabled(true);
            ui->consoleEdit->setPalette(consoleEditPalette);
        }
        catch (exception& e)
        {
            ui->consoleEdit->appendPlainText(QString("Critical Error. Exception caught: ").append(QString(e.what())));
            ui->deconvolveButton->setEnabled(true);
            ui->actionDeconvolve->setEnabled(true);
            ui->consoleEdit->setPalette(consoleEditPalette);
        }
        catch ( ... )
        {
            ui->consoleEdit->appendPlainText(QString("Unknown Critical Error."));
            ui->deconvolveButton->setEnabled(true);
            ui->actionDeconvolve->setEnabled(true);
            ui->consoleEdit->setPalette(consoleEditPalette);
        }
    }
    else
    {
        processedImage=inputImage;                                                                      // None is selected as deconvolution algorithm. Passing input through.
        haveDeconvolvedImage=true;                                                                      // Setting a flag that we have a deconvolved image available.
        ui->actionUse_Deconvolved_Image_as_Reference->setEnabled(true);
        postProcessing();                                                                               // Applying post-processing.
        displayMagickBlob(postProcessedImageBlob);
    }
}

void DStation::buildAtmosphericFx(char atmosphericMTF[], const double lambda, const double pixel, const double cutOff, const int r0, const double falpha, const int d, const bool orientation)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Building Fried's atmospheric MTF ImageMagick FX string. bool orientation defines how coordinates are referred to: true is horizontal MTF component, false is vertical.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    char bufferA[256];
    strcpy(atmosphericMTF,"lambdamm=");                                                                 // Lambda (wavelength) definition.
    sprintf(bufferA, "%f", lambda);
    strcat(atmosphericMTF,bufferA);
    strcat(atmosphericMTF,"; pixelmm=");                                                                // CCD pixel size definition.
    sprintf(bufferA, "%f", pixel);
    strcat(atmosphericMTF,bufferA);
    strcat(atmosphericMTF,"; lco=");                                                                    // MTF cut-off frequency definition.
    sprintf(bufferA, "%f", cutOff);
    strcat(atmosphericMTF,bufferA);
    if (orientation)
        strcat(atmosphericMTF,"; freq=(abs(i-w/2)/w)*lco; rzero=");                                     // Frequency and r0 definitions.
    else
        strcat(atmosphericMTF,"; freq=(abs(j-h/2)/h)*lco; rzero=");
    sprintf(bufferA, "%d", r0);
    strcat(atmosphericMTF,bufferA);
    strcat(atmosphericMTF,"; falpha=");                                                                 // Fried's alpha parameter.
    sprintf(bufferA, "%f", falpha);
    strcat(atmosphericMTF,bufferA);
    strcat(atmosphericMTF,"; D=");                                                                      // Objective diameter.
    sprintf(bufferA, "%d", d);
    strcat(atmosphericMTF,bufferA);
    strcat(atmosphericMTF,"; exp(-3.44*((lambdamm*freq)/rzero)^(5/3))*(1-(falpha*(((lambdamm*freq)/D)^(1/3))))");
    if (DEBUG)
        ui->consoleEdit->appendPlainText(QString(atmosphericMTF));
}

Image DStation::deconvolutionWienerHDRI(const Image *filter, double noise)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Wiener deconvolution in HDRI mode. This function takes C and D from a FFT container that should be prepared in a function calling this.
    //
    // P/F = [AC/(A^2+N)]+i[AD/(A^2+N)], where A is the filter magnitude, C and D are real and imaginary parts of input, N is noise.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQ;
    Image tmpQa;
    Image tmpW;
    Image tmpE;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Deconvolution...")); // -v0.312-
    qApp->processEvents();
    tmpQ=*filter;
    tmpQ=lowLevel_squared_plus_noise(tmpQ,noise);                                                       // tmpQ=tmpQa=(A^2+N)
    tmpQa=tmpQ;
    tmpW=FFTContainer.front();                                                                          // Grabbing tmpW=C
    tmpW.composite(*filter,0,0,MultiplyCompositeOp);                                                    // tmpW=AC
    tmpQ.composite(tmpW,0,0,DivideCompositeOp);                                                         // tmpQ=AC/(A^2+N)

    tmpE=FFTContainer.back();                                                                           // Grabbing tmpE=D
    tmpE.composite(*filter,0,0,MultiplyCompositeOp);                                                    // tmpQa=AD/(A^2+N)
    tmpQa.composite(tmpE,0,0,DivideCompositeOp);

    tmpQ.inverseFourierTransform(tmpQa,false);                                                          // Inverse Fourier transform.
    return(tmpQ);
}

Image DStation::deconvolutionWiener_nonHDRI(const Image *inputImage, const Image *filter, double noise)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Wiener deconvolution in non-HDRI mode.
    //
    // P/F = [AC/(A^2+N)], where A is the filter magnitude, C is the magnitude part of input, N is noise. Phase part of the input D is used in the inverse Fourier transform.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQ;
    Image tmpQa;
    Image tmpW;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Deconvolution...")); // -v0.312-
    qApp->processEvents();

    forwardFourierTransformImage(&FFTContainer,*inputImage,true);                                       // Forward Fourier Transform
    tmpQ=*filter;
    tmpQ=lowLevel_squared_plus_noise(tmpQ,noise);                                                       // tmpQ=A^2+N
    tmpW=FFTContainer.front();                                                                          // Grabbing tmpW=C
    tmpW.composite(*filter,0,0,MultiplyCompositeOp);                                                    // tmpQ=AC/(A^2+N)
    tmpQ.composite(tmpW,0,0,DivideCompositeOp);
    tmpQa=FFTContainer.back();                                                                          // Grabbing tmpQa=D
    tmpQ.inverseFourierTransform(tmpQa,true);                                                           // Inverse Fourier transform.
    return(tmpQ);
}

Image DStation::deconvolutionIterativeWiener_nonHDRI(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Iterative inverse filter deconvolution in non-HDRI mode.
    // See J. S. Lim, Two-dimensional Signal and Image Processing, eq 9.52
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQa;
    Image g;
    Image fknext;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Iterative Deconvolution..."));
    qApp->processEvents();

    double lambda=ui->convergenceSpin->value();
    int totalIterations=ui->iterationsSpin->value();
    forwardFourierTransformImage(&FFTContainer,*inputImage,true);                                       // Forward Fourier Transform

    Image f0=FFTContainer.front();
    Image b=*filter;

    Image fk=f0;
    fk=lowLevel_multiply(fk,lambda);                                                                    // F0 = lambda*G

    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        g=f0;
        fknext=fk;
        fk.composite(b,0,0,MultiplyCompositeOp);                                                         // Fk * B
        fk.composite(g,0,0,MinusCompositeOp);                                                            // G - Fk * B

        //        chiSquared=lowLevel_chiSquared(fk);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();


        g=fk;
        g=lowLevel_multiply(g,lambda);                                                                   // lambda * (G - Fk * B)
        fknext.composite(g,0,0,PlusCompositeOp);                                                         // Fk + lambda * (G - Fk * B)
        fk=fknext;
    }

    tmpQa=FFTContainer.back();                                                                          // Grabbing tmpQa=phase
    fknext.inverseFourierTransform(tmpQa,true);                                                         // Inverse Fourier transform.
    return(fknext);
}

Image DStation::deconvolutionIterativeWienerFDE_nonHDRI(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Iterative inverse filter deconvolution in non-HDRI mode.
    // See J. S. Lim, Two-dimensional Signal and Image Processing, eq 9.52
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQa;
    Image g;
    Image fknext;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Iterative Deconvolution..."));
    qApp->processEvents();

    double lambda=ui->convergenceSpin->value();
    int totalIterations=ui->iterationsSpin->value();
    forwardFourierTransformImage(&FFTContainer,*inputImage,true);                                       // Forward Fourier Transform

    Image f0=FFTContainer.front();
    Image b=*filter;

    Image fk=f0;
    fk=lowLevel_multiply(fk,lambda);                                                                    // F0 = lambda*G

    double chiSquared;

    Image equalizerFilterH=FDEfilter(fk.columns(),fk.rows());

    for (int iteration=0; iteration<totalIterations; iteration++) {
        g=f0;
        fknext=fk;
        fk.composite(b,0,0,MultiplyCompositeOp);                                                         // Fk * B
        fk.composite(g,0,0,MinusCompositeOp);                                                            // G - Fk * B

        //        chiSquared=lowLevel_chiSquared(fk);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();


        g=fk;
        //g=lowLevel_multiply(g,lambda);                                                                   // lambda * (G - Fk * B)
        g.composite(equalizerFilterH,0,0,MultiplyCompositeOp);
        fknext.composite(g,0,0,PlusCompositeOp);                                                         // Fk + lambda * (G - Fk * B)
        fk=fknext;
    }

    tmpQa=FFTContainer.back();                                                                          // Grabbing tmpQa=phase
    fknext.inverseFourierTransform(tmpQa,true);                                                         // Inverse Fourier transform.
    return(fknext);
}

Image DStation::deconvolutionLandweber(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Landweber Deconvolution
    // On+1 = On + (gamma * P[transpose] * (I - P * On))
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQa;
    Image g;
    Image fknext;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Iterative Deconvolution..."));
    qApp->processEvents();

    double lambda=ui->convergenceSpin->value();
    int totalIterations=ui->iterationsSpin->value();
    forwardFourierTransformImage(&FFTContainer,*inputImage,true);                                       // Forward Fourier Transform

    Image f0=FFTContainer.front();
    Image b=*filter;
    Image btranspose=b;

    btranspose.flip();
    btranspose.flop();

    Image fk=f0;
    fk=lowLevel_multiply(fk,lambda);                                                                    // F0 = lambda*G

    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        g=f0;
        fknext=fk;
        fk.composite(b,0,0,MultiplyCompositeOp);                                                         // Fk * B
        fk.composite(g,0,0,MinusCompositeOp);                                                            // G - Fk * B

        //        chiSquared=lowLevel_chiSquared(fk);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();


        g=fk;
        g=lowLevel_multiply(g,lambda);                                                                   // lambda * (G - Fk * B)
        g.composite(btranspose,0,0,MultiplyCompositeOp);                                                 // B[transpose] * lambda * (G - Fk * B)
        fknext.composite(g,0,0,PlusCompositeOp);                                                         // Fk + lambda * (G - Fk * B)
        fk=fknext;
    }

    tmpQa=FFTContainer.back();                                                                          // Grabbing tmpQa=phase
    fknext.inverseFourierTransform(tmpQa,true);                                                         // Inverse Fourier transform.
    return(fknext);
}


Image DStation::FDEfilter(int width, int height)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Constructs Frequency Domain Equalizer Filter, also updates the equalizer image
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // EQUALIZER CODE
    char bufferA[256];
    char bufferB[256];
    int numEqualizerPoints=6;
    double c[6];
    c[0]=(double)(ui->equalizerSlider_1->value())/100;                                                      // Getting values in [0..1] range.
    c[1]=(double)(ui->equalizerSlider_2->value())/100;
    c[2]=(double)(ui->equalizerSlider_3->value())/100;
    c[3]=(double)(ui->equalizerSlider_4->value())/100;
    c[4]=(double)(ui->equalizerSlider_5->value())/100;
    c[5]=(double)(ui->equalizerSlider_6->value())/100;

    int imageDimensions;
    if (width>=height) imageDimensions=width;
    else
        imageDimensions=height;

    int halfCurveDimensions=imageDimensions/2;

    double halfCurve[halfCurveDimensions];                                                                  // Equalizer curve array size of the greater image dimension/2. (Filter should be rectangular for FFT.)
    int intervals=numEqualizerPoints-1;
    double pointStep=(double)halfCurveDimensions/intervals;

    for (int i=0; i<halfCurveDimensions; i++) {
        int pointStart=floor(i/pointStep);
        int pointEnd=pointStart+1;
        double pointInterpolated=(double)(i/pointStep)-pointStart;
        double mu2;
        mu2 = (1-cos(pointInterpolated*PI))/2;
        halfCurve[i]=(double)(c[pointStart]*(1-mu2)+c[pointEnd]*mu2);                                       // Cosine interpolation.
    }

    Image equalizerFilterH(Geometry(imageDimensions,1),Color("black"));                                     // Construct a new black equalizer filter image, horizontal Nx1.

    equalizerFilterH.modifyImage();
    PixelPacket *pixels = equalizerFilterH.getPixels(0, 0, equalizerFilterH.columns(), 1);
    for (int x=0; x<(int)equalizerFilterH.columns(); x++) {
        PixelPacket *pixel = pixels+x;
        int coord=abs(x-(int)(equalizerFilterH.columns()/2));
        pixel->red=(double)halfCurve[coord]*QuantumRange;
        pixel->green=(double)halfCurve[coord]*QuantumRange;
        pixel->blue=(double)halfCurve[coord]*QuantumRange;
    }

    equalizerFilterH.syncPixels();

    Image equalizerFilterV=equalizerFilterH;
    equalizerFilterV.rotate(90);

    sprintf(bufferB,"%d",imageDimensions);
    strcpy(bufferA,bufferB);                                                                       // Scaling vertical and horizontal images to produce NxN image.
    strcat(bufferA,"x");
    strcat(bufferA,bufferB);
    strcat(bufferA,"!");
    equalizerFilterH.scale(bufferA);
    equalizerFilterV.scale(bufferA);
    equalizerFilterH.composite(equalizerFilterV,0,0,MultiplyCompositeOp);                                  // Multiply images together to produce atmospheric MTF - Fred's NxN! school.
    // EQUALIZER CODE

    std::list<Magick::Drawable> drawList;

    Image curveImage(Geometry(SIDEBAR_IMAGE_WIDTH,SIDEBAR_IMAGE_HEIGHT),Color("black"));        // Construct a new black curve image.
    int bins=curveImage.columns();
    double step=(double)halfCurveDimensions/bins;

    drawList.push_back(DrawableStrokeColor("red"));
    for (int i=1; i<bins; i++) {
        int value=halfCurve[(int)(i*step)]*curveImage.rows();
        int x=i;
        int ya=curveImage.rows()-value;
        int yb=curveImage.rows();
        drawList.push_back(DrawableLine(x,yb,x,ya));
    }
    curveImage.draw(drawList);

    equalizerScene->clear();
    equalizerScene->addPixmap(QPixmap::fromImage(imageToQImage(curveImage)));

    return(equalizerFilterH);
}

Image DStation::deconvolutionVanCittert(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Van-Cittert Deconvolution
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Van Cittert Deconvolution..."));
    qApp->processEvents();
    Image I=*inputImage;
    Image P=*filter;
    Image Onext=I;
    Image On;
    double gamma=ui->convergenceSpin->value();
    std::vector<double> PSF;

    // Prepare Convolution Kernel
    int kernelOrder=ui->spatialFilterSize->value();
    double kernel[kernelOrder*kernelOrder];                                                // 2D kernel
    if (DEBUG) P.write("/temp/spatialFilter.png");
    PSF=lowLevel_imageToVector(P);
    for (int k=0; k<kernelOrder*kernelOrder; k++) {
        kernel[k]=PSF.at(k);
    }

    int totalIterations=ui->iterationsSpin->value();
    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        On=Onext;
        On.convolve(kernelOrder,kernel);  // convolve On with P
        On.composite(I,0,0,MinusCompositeOp); // I minus (On (x) P)

        //        chiSquared=lowLevel_chiSquared(On);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();


        On=lowLevel_multiply(On,gamma);
        On.composite(Onext,0,0,PlusCompositeOp);
        Onext=On;

        if (ui->iterativeShowProgress->isChecked()) {
            displayMagickImage(Onext);
            qApp->processEvents();
        }

    }
    return(Onext);
}

Image DStation::deconvolutionLR(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // LR Deconvolution with Sine Relaxation
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Lucy-Richardson Deconvolution..."));
    qApp->processEvents();
    Image I=*inputImage;
    Image P=*filter;
    Image Onext=I;
    Image On;
    Image Om;
    Image Relax;
    double gamma=ui->convergenceSpin->value();
    std::vector<double> PSF;

    // Prepare Convolution Kernel
    int kernelOrder=ui->spatialFilterSize->value();
    double kernel[kernelOrder*kernelOrder];                                                // 2D kernel

    if (DEBUG) P.write("/temp/spatialFilter.png");
    PSF=lowLevel_imageToVector(P);
    for (int k=0; k<kernelOrder*kernelOrder; k++) {
        kernel[k]=PSF.at(k);
    }


    int totalIterations=ui->iterationsSpin->value();

    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        On=Onext;
        // LR
        On.convolve(kernelOrder,kernel);  // [On] = k(X)o(x,y)
        On.composite(I,0,0,DivideCompositeOp); // [On] = s(x,y) / [ k(X)o(x,y) ]

        //        chiSquared=lowLevel_chiSquared(On);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();

        Om=lowLevel_subtract(On,1); // [Om] = s(x,y) / [ k(X)o(x,y) ] - 1
        Relax=lowLevel_sineRelaxation(Onext,gamma);
        //Relax=lowLevel_compress(Onext,gamma,1);       // Compression can be used instead of sine relaxation
        Om.composite(Relax,0,0,MultiplyCompositeOp); // [Om] = w(o(x,y)) * s(x,y) / [ k(X)o(x,y) ] - 1
        Om=lowLevel_add(Om,1); // [Om] = { w(o(x,y)) * s(x,y) / [ k(X)o(x,y) ] - 1 } + 1
        Om.composite(Onext,0,0,MultiplyCompositeOp); // multiply by O
        Onext=Om;

        if (ui->iterativeShowProgress->isChecked()) {
            displayMagickImage(Onext);
            qApp->processEvents();
        }


    }
    return(Onext);
}

Image DStation::deconvolutionMEM(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // MEM Deconvolution
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Lucy-Richardson Deconvolution..."));
    qApp->processEvents();
    Image I=*inputImage;
    Image P=*filter;
    Image Onext=I;
    Image On;
    Image Om;
    Image Relax;
    double gamma=ui->convergenceSpin->value();
    std::vector<double> PSF;

    // Prepare Convolution Kernel
    int kernelOrder=ui->spatialFilterSize->value();
    double kernel[kernelOrder*kernelOrder];                                                // 2D kernel

    if (DEBUG) P.write("/temp/spatialFilter.png");
    PSF=lowLevel_imageToVector(P);
    for (int k=0; k<kernelOrder*kernelOrder; k++) {
        kernel[k]=PSF.at(k);
    }


    int totalIterations=ui->iterationsSpin->value();

    double chiSquared;

    Magick::Image::ImageStatistics IStatistics;
    I.statistics(&IStatistics);
    double sigmaSquared=pow(IStatistics.red.variance,2);


    // On+1 = -On

    for (int iteration=0; iteration<totalIterations; iteration++) {
        On.convolve(kernelOrder,kernel);  // [On] = k(X)o(x,y)
        On.composite(I,0,0,MinusCompositeOp); // [On] = s(x,y)  [ k(X)o(x,y) ]




        //        chiSquared=lowLevel_chiSquared(On);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();

        Om=lowLevel_subtract(On,1); // [Om] = s(x,y) / [ k(X)o(x,y) ] - 1
        Relax=lowLevel_sineRelaxation(Onext,gamma);
        //Relax=lowLevel_compress(Onext,gamma,1);       // Compression can be used instead of sine relaxation
        Om.composite(Relax,0,0,MultiplyCompositeOp); // [Om] = w(o(x,y)) * s(x,y) / [ k(X)o(x,y) ] - 1
        Om=lowLevel_add(Om,1); // [Om] = { w(o(x,y)) * s(x,y) / [ k(X)o(x,y) ] - 1 } + 1
        Om.composite(Onext,0,0,MultiplyCompositeOp); // multiply by O
        Onext=Om;

        if (ui->iterativeShowProgress->isChecked()) {
            displayMagickImage(Onext);
            qApp->processEvents();
        }


    }
    return(Onext);
}

Image DStation::deconvolutionMAP(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Maximum A Posteriori Deconvolution
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("MAP Deconvolution..."));
    qApp->processEvents();
    Image I=*inputImage;
    Image P=*filter;
    Image Onext=I;
    Image On;
    double gamma=ui->convergenceSpin->value();
    std::vector<double> PSF;

    // Prepare Convolution Kernel
    int kernelOrder=ui->spatialFilterSize->value();
    double kernel[kernelOrder*kernelOrder];                                                // 2D kernel

    if (DEBUG) P.write("/temp/spatialFilter.png");
    PSF=lowLevel_imageToVector(P);
    for (int k=0; k<kernelOrder*kernelOrder; k++) {
        kernel[k]=PSF.at(k);
    }


    int totalIterations=ui->iterationsSpin->value();
    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        On=Onext;

        On.convolve(kernelOrder,kernel);  // [On] = k(X)o(x,y)
        On.composite(I,0,0,DivideCompositeOp); // [On] = s(x,y) / [ k(X)o(x,y) ]

        //        chiSquared=lowLevel_chiSquared(On);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();

        On=lowLevel_subtract(On,1); // [On] = [ s(x,y) / [ k(X)o(x,y) ] ] - 1
        On=lowLevel_exp(On,gamma);
        On.composite(Onext,0,0,MultiplyCompositeOp); // multiply by O
        Onext=On;

        if (ui->iterativeShowProgress->isChecked()) {
            displayMagickImage(Onext);
            qApp->processEvents();
        }


    }
    return(Onext);
}

Image DStation::deconvolutionLRConstant(const Image *inputImage, const Image *filter)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // LR Deconvolution - Constant Regularized
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("Lucy-Richardson Deconvolution..."));
    qApp->processEvents();
    Image I=*inputImage;
    Image P=*filter;
    Image Onext=I;
    Image On;
    Image Om;
    Image Relax;
    double gamma=ui->convergenceSpin->value();
    std::vector<double> PSF;

    // Prepare Convolution Kernel
    int kernelOrder=ui->spatialFilterSize->value();
    double kernel[kernelOrder*kernelOrder];                                                // 2D kernel

    if (DEBUG) P.write("/temp/spatialFilter.png");
    PSF=lowLevel_imageToVector(P);
    for (int k=0; k<kernelOrder*kernelOrder; k++) {
        kernel[k]=PSF.at(k);
    }


    int totalIterations=ui->iterationsSpin->value();
    double chiSquared;

    for (int iteration=0; iteration<totalIterations; iteration++) {
        On=Onext;
        // LR
        On.convolve(kernelOrder,kernel);  // [On] = k(X)o(x,y)
        On.composite(I,0,0,DivideCompositeOp); // [On] = s(x,y) / [ k(X)o(x,y) ]

        //        chiSquared=lowLevel_chiSquared(On);
        //        ui->consoleEdit->appendHtml(QString("Iteration ").append(QString::number(iteration).append(QString(" Chi squared: ").append(QString::number(chiSquared)))));
        //        qApp->processEvents();

        Om=lowLevel_subtract(On,1); // [Om] = s(x,y) / [ k(X)o(x,y) ] - 1

        //Relax=lowLevel_sineRelaxation(Onext,gamma);

        Om=lowLevel_multiply(Om,gamma); // [Om] = (s(x,y) / [ k(X)o(x,y) ] - 1)*gamma

        Om=lowLevel_add(Om,1); // [Om] = { (s(x,y) / [ k(X)o(x,y) ] - 1)*gamma } + 1
        Om.composite(Onext,0,0,MultiplyCompositeOp); // multiply by O
        Onext=Om;

        if (ui->iterativeShowProgress->isChecked()) {
            displayMagickImage(Onext);
            qApp->processEvents();
        }

    }
    return(Onext);
}


Image DStation::deconvolutionCLS_nonHDRI(const Image *inputImage, const Image *filter, double noise)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Constrained Least Squares deconvolution in non-HDRI mode.
    // http://www.cis.rit.edu/class/simg782/lectures/lecture_16/lec782_05_16.pdf
    // Jain "Fundamentals of Digital Image Processing", page 298
    //
    // P/F = [AC/(A^2+N*L^2)], where A is the filter magnitude, C is the magnitude part of input, N is noise (lambda). Phase part of the input D is used in the inverse Fourier transform.
    // L is the Fourier Transform of Laplacian filter.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tmpQ;
    Image tmpQa;
    Image tmpW;
    int filterWidth;
    int filterHeight;

    if (ui->processingMode->currentIndex()==0) ui->consoleEdit->appendPlainText(QString("CLS Deconvolution..."));
    qApp->processEvents();
    filterWidth=filter->columns();
    filterHeight=filter->rows();
    Image LaplacianImage(Geometry(filterWidth,filterHeight),Color("black"));                            // Constructing Laplacian filter
    LaplacianImage.modifyImage();
    for (int y=0; y<(int)LaplacianImage.rows(); y++) {
        PixelPacket *pixels = LaplacianImage.getPixels(0, y, LaplacianImage.columns(), 1);
        for (int x=0; x<(int)LaplacianImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            double freqa=(abs((double)x-LaplacianImage.columns()/2)/LaplacianImage.columns());
            double freqb=(abs((double)y-LaplacianImage.rows()/2)/LaplacianImage.rows());
            double alpha=ui->LaplacianAlpha->value();
            pixel->red=QuantumRange*(-1+2*alpha*cos(freqa)+2*alpha*cos(freqb));
            pixel->green=QuantumRange*(-1+2*alpha*cos(freqa)+2*alpha*cos(freqb));
            pixel->blue=QuantumRange*(-1+2*alpha*cos(freqa)+2*alpha*cos(freqb));
        }
    }
    LaplacianImage.syncPixels();
    if (DEBUG) LaplacianImage.write("/temp/laplacian.tiff");
    tmpQ=*filter;                                                                                        // tmpQ=A^2+N*L^2
    tmpQ=lowLevel_power(tmpQ,2);
    LaplacianImage=lowLevel_power(LaplacianImage,2);
    LaplacianImage=lowLevel_multiply(LaplacianImage,noise);
    tmpQ.composite(LaplacianImage,0,0,PlusCompositeOp);
    forwardFourierTransformImage(&FFTContainer,*inputImage,true);                                       // Forward Fourier Transform
    tmpW=FFTContainer.front();                                                                          // Grabbing tmpW=C
    tmpW.composite(*filter,0,0,MultiplyCompositeOp);                                                    // tmpQ=AC/A^2+N*L^2)
    tmpQ.composite(tmpW,0,0,DivideCompositeOp);
    tmpQa=FFTContainer.back();                                                                          // Grabbing tmpQa=D
    tmpQ.inverseFourierTransform(tmpQa,true);                                                           // Inverse Fourier transform.
    return(tmpQ);
}

void DStation::on_actionSave_Image_As_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Saving post-processed image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QFileDialog saveDialog;
    QString fileName = saveDialog.getSaveFileName(this, "Save image", QFileInfo(workingDirectory).absolutePath().append(QString("/")).append(QFileInfo(workingDirectory).baseName()), tr("TIFF Image (*.tiff);;FITS Image (*.fits);;JPEG Image (*.jpg);;PNG Image (*.png);;Windows Bitmap (*.bmp);;GIF Image (*.gif)"));
    if (!fileName.isEmpty()) {
        Image imageToSave(postProcessedImageBlob);
        if (ui->savedImagePrecision->currentIndex()==0) imageToSave.depth(16);
        if (ui->savedImagePrecision->currentIndex()==1) imageToSave.depth(32);
        try
        {
            imageToSave.write(fileName.toAscii().data());
        }
        catch (exception& e)
        {
            ui->consoleEdit->appendPlainText(QString("Error saving image. Exception caught: ").append(QString(e.what())));
        }
        ui->consoleEdit->appendPlainText(QString("Processed image saved as ").append(fileName).append(QString("...")));
        QDir dir(fileName);
        workingDirectory=dir.absolutePath();
    }
}

void DStation::on_showInputButton_pressed()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Blink feature. Shows input image when the blink button is pressed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    FFTRealComponentShown=false;
    displayMagickImage(inputImage);
}

void DStation::on_showInputButton_released()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Blink feature. Shows post-processed image when the blink button is released.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    FFTRealComponentShown=false;
    displayMagickBlob(postProcessedImageBlob);
}

void DStation::on_actionExit_DStation_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Application exit.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    qApp->exit(0);
}

void DStation::postProcessing()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Applying post-processing functions to deconvolved image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Image postProcessedImage=processedImage;                                                           // Copying deconvolved (processed) image to post-processing stage.

    if (ui->postProcessingEnabledCheckBox->isChecked() && haveDeconvolvedImage) {

        //        if (ui->equalizerEnabled->isChecked()) {
        //            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //            //
        //            // Process frequency domain equalizer. Applies on the post processing stage.
        //            // http://local.wasp.uwa.edu.au/~pbourke/miscellaneous/interpolation/
        //            //
        //            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //            char bufferA[256];
        //            char bufferB[256];
        //            std::list<Magick::Drawable> drawList;

        //            ui->equalizerSlider_1->setEnabled(false);
        //            ui->equalizerSlider_2->setEnabled(false);
        //            ui->equalizerSlider_3->setEnabled(false);
        //            ui->equalizerSlider_4->setEnabled(false);
        //            ui->equalizerSlider_5->setEnabled(false);
        //            ui->equalizerSlider_6->setEnabled(false);

        //            int numEqualizerPoints=6;
        //            double c[6];
        //            c[0]=(double)(100-ui->equalizerSlider_1->value())/100;                                                      // Getting values in [0..1] range.
        //            c[1]=(double)(100-ui->equalizerSlider_2->value())/100;
        //            c[2]=(double)(100-ui->equalizerSlider_3->value())/100;
        //            c[3]=(double)(100-ui->equalizerSlider_4->value())/100;
        //            c[4]=(double)(100-ui->equalizerSlider_5->value())/100;
        //            c[5]=(double)(100-ui->equalizerSlider_6->value())/100;

        //            int width=postProcessedImage.columns();                                                                     // Get input image dimensions. Equalizer filter should match those.
        //            int height=postProcessedImage.rows();
        //            int imageDimensions;
        //            if (width>=height) imageDimensions=width;
        //            else
        //                imageDimensions=height;

        //            int halfCurveDimensions=imageDimensions/2;

        //            double halfCurve[halfCurveDimensions];                                                                  // Equalizer curve array size of the greater image dimension/2. (Filter should be rectangular for FFT.)
        //            int intervals=numEqualizerPoints-1;
        //            double pointStep=(double)halfCurveDimensions/intervals;

        //            for (int i=0; i<halfCurveDimensions; i++) {
        //                int pointStart=floor(i/pointStep);
        //                int pointEnd=pointStart+1;
        //                double pointInterpolated=(double)(i/pointStep)-pointStart;
        //                double mu2;
        //                mu2 = (1-cos(pointInterpolated*PI))/2;
        //                halfCurve[i]=(double)(c[pointStart]*(1-mu2)+c[pointEnd]*mu2);                                       // Cosine interpolation.
        //            }

        //            Image equalizerFilterH(Geometry(imageDimensions,1),Color("black"));                                     // Construct a new black equalizer filter image, horizontal Nx1.

        //            equalizerFilterH.modifyImage();
        //            PixelPacket *pixels = equalizerFilterH.getPixels(0, 0, equalizerFilterH.columns(), 1);
        //            for (int x=0; x<(int)equalizerFilterH.columns(); x++) {
        //                PixelPacket *pixel = pixels+x;
        //                int coord=abs(x-(int)(equalizerFilterH.columns()/2));
        //                pixel->red=(double)halfCurve[coord]*QuantumRange;
        //                pixel->green=(double)halfCurve[coord]*QuantumRange;
        //                pixel->blue=(double)halfCurve[coord]*QuantumRange;
        //            }

        //            equalizerFilterH.syncPixels();

        //            Image equalizerFilterV=equalizerFilterH;
        //            equalizerFilterV.rotate(90);

        //            sprintf(bufferB,"%d",imageDimensions);
        //            strcpy(bufferA,bufferB);                                                                       // Scaling vertical and horizontal images to produce NxN image.
        //            strcat(bufferA,"x");
        //            strcat(bufferA,bufferB);
        //            strcat(bufferA,"!");
        //            equalizerFilterH.scale(bufferA);
        //            equalizerFilterV.scale(bufferA);
        //            equalizerFilterH.composite(equalizerFilterV,0,0,MultiplyCompositeOp);                                  // Multiply images together to produce atmospheric MTF - Fred's NxN! school.

        //            postProcessedImage=deconvolveSwitch(&postProcessedImage,&equalizerFilterH,(double)(ui->equalizerNoiseSpin->value()/1000),false); // HDRI is not allowed here as we don't have FFT container for post-processed image.

        //            Image curveImage(Geometry(SIDEBAR_IMAGE_WIDTH,SIDEBAR_IMAGE_HEIGHT),Color("black"));        // Construct a new black curve image.
        //            int bins=curveImage.columns();
        //            double step=(double)halfCurveDimensions/bins;

        //            drawList.push_back(DrawableStrokeColor("red"));
        //            for (int i=1; i<bins; i++) {
        //                int value=halfCurve[(int)(i*step)]*curveImage.rows();
        //                int x=i;
        //                int ya=curveImage.rows();
        //                int yb=value;
        //                drawList.push_back(DrawableLine(x,ya,x,yb));
        //            }
        //            curveImage.draw(drawList);

        //            equalizerScene->clear();
        //            equalizerScene->addPixmap(QPixmap::fromImage(imageToQImage(curveImage)));
        //            ui->equalizerSlider_1->setEnabled(true);
        //            ui->equalizerSlider_2->setEnabled(true);
        //            ui->equalizerSlider_3->setEnabled(true);
        //            ui->equalizerSlider_4->setEnabled(true);
        //            ui->equalizerSlider_5->setEnabled(true);
        //            ui->equalizerSlider_6->setEnabled(true);

        //            ui->consoleEdit->appendPlainText("Frequency Domain Equalizer Filter Applied.");
        //            // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //        }


        /* Processing dynamic range extension. Because deconvolution tends to brighten bright parts of the image, white clipping may occur at certain parts of deconvolved image.
       This applies a division operator to the final image, and results in deconvolved image to appear darkened, which avoids clipping. Dynamic range extension works only when normalize
       is not turned on. */
        if (ui->dynamicRangeExtensionSpin->value()>0 && !ui->normalizeCheckBox->isChecked()) {
            postProcessedImage=lowLevel_divide(postProcessedImage,(double)ui->dynamicRangeExtensionSpin->value()/100+1);
        }
        if (ui->normalizeCheckBox->isChecked()) postProcessedImage.normalize();                         // Normalization.

        if (ui->enhanceCheckBox->isChecked()) {                                                         // Automatic noise filter using ImageMagick enhance operator.
            Image denoisedImage(postProcessedImage);
            denoisedImage.enhance();
            double gamma=(double)ui->noiseFilterStrengthSpin->value()/100;
            denoisedImage=lowLevel_power(denoisedImage,gamma);
            postProcessedImage=lowLevel_power(postProcessedImage,(double)1-gamma);
            postProcessedImage.composite(denoisedImage,0,0,MultiplyCompositeOp);
        }

        double contrast=(double)ui->conDial->value()-100;
        double brightness=(double)ui->briDial->value()-100;
        if (ui->briConEnabled->isChecked() && (contrast!=0 || brightness!=0)) {                           // Brightness/Contrast Adjustment.
            ui->briDial->setEnabled(false);
            ui->conDial->setEnabled(false);
            qApp->processEvents();
            double slope=tan((contrast/100+1)*PI/4);
            if (slope<0) slope=0;
            double intercept=0.5*(brightness/100-1)*(slope+1)+1;
            postProcessedImage=lowLevel_multiply(postProcessedImage,slope);
            postProcessedImage=lowLevel_add(postProcessedImage,intercept);
            ui->briDial->setEnabled(true);
            ui->conDial->setEnabled(true);
        }

    }

    postProcessedImage.magick(TEMPORARY_CONTAINER_FORMAT);                                              // Converting post-processed image to a BLOB.
    postProcessedImage.write(&postProcessedImageBlob);

    /* Showing histogram */
    if (ui->postProcessingEnabledCheckBox->isChecked() && haveDeconvolvedImage) on_redrawHistogramButton_clicked();
}

void DStation::on_dynamicRangeExtensionSpin_editingFinished()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_dynamicRangeExtensionSpin_valueChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_normalizeCheckBox_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time once post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->normalizeCheckBox->isChecked()) {                                                           // Disable post-processing functionality that is not working (DRE, etc) when normalize is turned on.
        ui->dynamicRangeExtensionSpin->setEnabled(false);
        ui->dynamicRangeExtensionLabel->setEnabled(false);
    }
    else
    {
        ui->dynamicRangeExtensionSpin->setEnabled(true);
        ui->dynamicRangeExtensionLabel->setEnabled(true);
    }
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_postProcessingEnabledCheckBox_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time once post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    on_applyPostProcessing_clicked();
}

void DStation::on_deconvolutionAlgorithm_currentIndexChanged(int index)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates UI depending on what deconvolution algorithm is selected.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    switch(index) {
    case 0:                                                                                             // Usatov-Weinhaus.
        ui->gaussianBlurSpin->setEnabled(true);
        if (ui->processingMode->currentIndex()==1) {                                                    // Enable only if separate wavelength mode is selected.
            ui->wavelengthBSpin->setEnabled(true);
            ui->wavelengthRSpin->setEnabled(true);
            ui->wavelengthBLabel->setEnabled(true);
            ui->wavelengthRLabel->setEnabled(true);
        }
        ui->wavelengthGSpin->setEnabled(true);
        ui->dSpin->setEnabled(true);
        ui->fSpin->setEnabled(true);
        ui->r0Spin->setEnabled(true);
        ui->noiseSpin->setEnabled(true);
        ui->pixelSpin->setEnabled(true);

        ui->gaussianBlurLabel->setEnabled(true);
        ui->wavelengthGLabel->setEnabled(true);
        ui->dLabel->setEnabled(true);
        ui->fLabel->setEnabled(true);
        ui->r0Label->setEnabled(true);
        ui->noiseLabel->setEnabled(true);
        ui->pixelLabel->setEnabled(true);
        ui->barlowLabel->setEnabled(true);
        ui->barlowSpin->setEnabled(true);
        ui->logFactorLabel->setEnabled(true);
        ui->logFactorSpin->setEnabled(true);
        break;

    case 1:                                                                                             // Atmospheric MTF only.
        ui->gaussianBlurSpin->setEnabled(false);
        if (ui->processingMode->currentIndex()==1) {                                                    // Enable only if separate wavelength mode is selected.
            ui->wavelengthBSpin->setEnabled(true);
            ui->wavelengthRSpin->setEnabled(true);
            ui->wavelengthBLabel->setEnabled(true);
            ui->wavelengthRLabel->setEnabled(true);
        }
        ui->wavelengthGSpin->setEnabled(true);
        ui->dSpin->setEnabled(true);
        ui->fSpin->setEnabled(true);
        ui->r0Spin->setEnabled(true);
        ui->noiseSpin->setEnabled(true);
        ui->pixelSpin->setEnabled(true);

        ui->gaussianBlurLabel->setEnabled(false);
        ui->wavelengthGLabel->setEnabled(true);
        ui->dLabel->setEnabled(true);
        ui->fLabel->setEnabled(true);
        ui->r0Label->setEnabled(true);
        ui->noiseLabel->setEnabled(true);
        ui->pixelLabel->setEnabled(true);
        ui->barlowLabel->setEnabled(true);
        ui->barlowSpin->setEnabled(true);
        ui->logFactorLabel->setEnabled(false);
        ui->logFactorSpin->setEnabled(false);
        break;

    case 2:                                                                                             // Weighted Usatov-Weinhaus. -v0.312-
        ui->gaussianBlurSpin->setEnabled(true);
        if (ui->processingMode->currentIndex()==1) {                                                    // Enable only if separate wavelength mode is selected.
            ui->wavelengthBSpin->setEnabled(true);
            ui->wavelengthRSpin->setEnabled(true);
            ui->wavelengthBLabel->setEnabled(true);
            ui->wavelengthRLabel->setEnabled(true);
        }
        ui->wavelengthGSpin->setEnabled(true);
        ui->dSpin->setEnabled(true);
        ui->fSpin->setEnabled(true);
        ui->r0Spin->setEnabled(true);
        ui->noiseSpin->setEnabled(true);
        ui->pixelSpin->setEnabled(true);

        ui->gaussianBlurLabel->setEnabled(true);
        ui->wavelengthGLabel->setEnabled(true);
        ui->dLabel->setEnabled(true);
        ui->fLabel->setEnabled(true);
        ui->r0Label->setEnabled(true);
        ui->noiseLabel->setEnabled(true);
        ui->pixelLabel->setEnabled(true);
        ui->barlowLabel->setEnabled(true);
        ui->barlowSpin->setEnabled(true);
        ui->logFactorLabel->setEnabled(true);
        ui->logFactorSpin->setEnabled(true);
        break;

    case 3:                                                                                             // Wiener with external filter. -v0.312-
        ui->gaussianBlurSpin->setEnabled(false);
        ui->wavelengthBSpin->setEnabled(false);
        ui->wavelengthGSpin->setEnabled(false);
        ui->wavelengthRSpin->setEnabled(false);
        ui->dSpin->setEnabled(false);
        ui->fSpin->setEnabled(false);
        ui->r0Spin->setEnabled(false);
        ui->noiseSpin->setEnabled(false);
        ui->pixelSpin->setEnabled(false);

        ui->gaussianBlurLabel->setEnabled(false);
        ui->wavelengthBLabel->setEnabled(false);
        ui->wavelengthGLabel->setEnabled(false);
        ui->wavelengthRLabel->setEnabled(false);
        ui->dLabel->setEnabled(false);
        ui->fLabel->setEnabled(false);
        ui->r0Label->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        ui->pixelLabel->setEnabled(false);
        ui->barlowLabel->setEnabled(false);
        ui->barlowSpin->setEnabled(false);
        ui->logFactorLabel->setEnabled(false);
        ui->logFactorSpin->setEnabled(false);
        break;

    case 4:                                                                                             // Lim blind filter.
        ui->gaussianBlurSpin->setEnabled(true);
        ui->wavelengthBSpin->setEnabled(false);
        ui->wavelengthGSpin->setEnabled(false);
        ui->wavelengthRSpin->setEnabled(false);
        ui->dSpin->setEnabled(false);
        ui->fSpin->setEnabled(false);
        ui->r0Spin->setEnabled(false);
        ui->noiseSpin->setEnabled(true);
        ui->pixelSpin->setEnabled(false);

        ui->gaussianBlurLabel->setEnabled(true);
        ui->wavelengthBLabel->setEnabled(false);
        ui->wavelengthGLabel->setEnabled(false);
        ui->wavelengthRLabel->setEnabled(false);
        ui->dLabel->setEnabled(false);
        ui->fLabel->setEnabled(false);
        ui->r0Label->setEnabled(false);
        ui->noiseLabel->setEnabled(true);
        ui->pixelLabel->setEnabled(false);
        ui->barlowLabel->setEnabled(false);
        ui->barlowSpin->setEnabled(false);
        ui->logFactorLabel->setEnabled(false);
        ui->logFactorSpin->setEnabled(false);
        break;

    case 5:                                                                                             // Blind filter.
        ui->gaussianBlurSpin->setEnabled(true);
        ui->wavelengthBSpin->setEnabled(false);
        ui->wavelengthGSpin->setEnabled(false);
        ui->wavelengthRSpin->setEnabled(false);
        ui->dSpin->setEnabled(false);
        ui->fSpin->setEnabled(false);
        ui->r0Spin->setEnabled(false);
        ui->noiseSpin->setEnabled(true);
        ui->pixelSpin->setEnabled(false);

        ui->gaussianBlurLabel->setEnabled(true);
        ui->wavelengthBLabel->setEnabled(false);
        ui->wavelengthGLabel->setEnabled(false);
        ui->wavelengthRLabel->setEnabled(false);
        ui->dLabel->setEnabled(false);
        ui->fLabel->setEnabled(false);
        ui->r0Label->setEnabled(false);
        ui->noiseLabel->setEnabled(true);
        ui->pixelLabel->setEnabled(false);
        ui->barlowLabel->setEnabled(false);
        ui->barlowSpin->setEnabled(false);
        ui->logFactorLabel->setEnabled(true);
        ui->logFactorSpin->setEnabled(true);
        break;
    }

    on_filteringMethod_currentIndexChanged(ui->filteringMethod->currentIndex());                          // Update UI depending on the filtering method chosen.
}

void DStation::on_processingMode_currentIndexChanged(int index)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates UI depending on wavelength mode selected.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    switch (index) {
    case 0:                                                                                             // Central wavelength processing mode.
        ui->wavelengthGLabel->setText(QString("Wavelength, nm (Central)"));
        ui->wavelengthBSpin->setEnabled(false);
        ui->wavelengthRSpin->setEnabled(false);
        ui->wavelengthBLabel->setEnabled(false);
        ui->wavelengthRLabel->setEnabled(false);
        break;

    case 1:                                                                                             // Separate RGB wavelength processing mode. Wavelength choices are not enabled if algorithm is
        ui->wavelengthGLabel->setText(QString("(Channel G)"));                                          // external or Lim.
        if (ui->deconvolutionAlgorithm->currentIndex()!=3 || ui->deconvolutionAlgorithm->currentIndex()!=4) {
            ui->wavelengthBSpin->setEnabled(true);
            ui->wavelengthRSpin->setEnabled(true);
            ui->wavelengthBLabel->setEnabled(true);
            ui->wavelengthRLabel->setEnabled(true);
        }
        break;
    }
}

void DStation::on_enhanceCheckBox_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_showFFTMagnitudeButton_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Displaying FFT real component with optional filtering radius circle when FFT Real button is pressed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image labeledMagnitude(FFTRealComponentImageBlob);
    std::list<Magick::Drawable> drawList;

    if (ui->deconvolutionAlgorithm->currentIndex()!=1 && ui->deconvolutionAlgorithm->currentIndex()!=3) {// Displaying filtering radius if filtering (smoothing) is used in the algorithm. -v0.312-
        int blurX=(labeledMagnitude.columns()/2);
        int blurY=(labeledMagnitude.rows()/2);
        int blurXa=(labeledMagnitude.columns()/2)+(ui->gaussianBlurSpin->value()/2);
        int blurYa=(labeledMagnitude.rows()/2)+(ui->gaussianBlurSpin->value()/2);
        drawList.push_back(DrawableStrokeColor("red"));
        drawList.push_back(DrawableStrokeWidth(1));
        drawList.push_back(DrawableFillOpacity(0));
        drawList.push_back(DrawableCircle(blurX,blurY,blurXa,blurYa));
    }
    labeledMagnitude.draw(drawList);
    FFTRealComponentShown=true;
    displayMagickImage(labeledMagnitude);
}

void DStation::on_gaussianBlurSpin_valueChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Updating FFT real component in real-time as filtering radius is changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (FFTRealComponentShown) {
        on_showFFTMagnitudeButton_clicked();
    }
}

void DStation::updateDisplayedImage()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates main scene display. It shows post processed image if available, otherwise shows input image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image postProcessedImage;
    if (postProcessedImageBlob.length()>0) postProcessedImage=Image(postProcessedImageBlob);
    FFTRealComponentShown=false;
    if (postProcessedImageBlob.length()>0 && deconvolvedImageShown && postProcessedImage.rows()==inputImage.rows() && postProcessedImage.columns()==inputImage.columns()) displayMagickImage(postProcessedImage);
    else
        if (inputImage.rows()>0) displayMagickImage(inputImage);                                        // Do not update anything if there is no input image available.
}

void DStation::on_actionNew_Preview_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Deploying new preview area.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->actionRemove_Preview->setEnabled(true);
    ui->actionMeasure_NSR->setEnabled(true);
    previewDeployed=true;
    checkPreviewSize();
    FFTRealComponentShown=false;
    updateDisplayedImage();
}

void DStation::on_actionRemove_Preview_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Deleting preview area.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->actionRemove_Preview->setEnabled(false);
    ui->actionMeasure_NSR->setEnabled(false);
    previewX=0;
    previewY=0;
    previewDeployed=false;
    FFTRealComponentShown=false;
    updateDisplayedImage();

}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Set of functions responsible for preview area menu choice.
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DStation::on_action64x64_triggered()
{
    previewH=64;
    previewW=64;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action1024x1024->setChecked(false);
    ui->action256x256->setChecked(false);
    ui->action512x512->setChecked(false);
    ui->action128x128->setChecked(false);
    ui->action64x64->setChecked(true);
    ui->action32x32->setChecked(false);
}

void DStation::on_action32x32_triggered()
{
    previewH=32;
    previewW=32;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action1024x1024->setChecked(false);
    ui->action256x256->setChecked(false);
    ui->action512x512->setChecked(false);
    ui->action128x128->setChecked(false);
    ui->action64x64->setChecked(false);
    ui->action32x32->setChecked(true);

}


void DStation::on_action128x128_triggered()
{
    previewH=128;
    previewW=128;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action1024x1024->setChecked(false);
    ui->action256x256->setChecked(false);
    ui->action512x512->setChecked(false);
    ui->action128x128->setChecked(true);
    ui->action64x64->setChecked(false);
    ui->action32x32->setChecked(false);

}

void DStation::on_action256x256_triggered()
{
    previewH=256;
    previewW=256;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action1024x1024->setChecked(false);
    ui->action128x128->setChecked(false);
    ui->action512x512->setChecked(false);
    ui->action256x256->setChecked(true);
    ui->action64x64->setChecked(false);
    ui->action32x32->setChecked(false);

}

void DStation::on_action512x512_triggered()
{
    previewH=512;
    previewW=512;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action1024x1024->setChecked(false);
    ui->action128x128->setChecked(false);
    ui->action256x256->setChecked(false);
    ui->action512x512->setChecked(true);
    ui->action64x64->setChecked(false);
    ui->action32x32->setChecked(false);

}

void DStation::on_action1024x1024_triggered()
{
    previewH=1024;
    previewW=1024;
    checkPreviewSize();
    updateDisplayedImage();
    ui->action512x512->setChecked(false);
    ui->action128x128->setChecked(false);
    ui->action256x256->setChecked(false);
    ui->action1024x1024->setChecked(true);
    ui->action64x64->setChecked(false);
    ui->action32x32->setChecked(false);

}

void DStation::changePreviewCoordinates()
{
    previewX=scene->mousePressedX;
    previewY=scene->mousePressedY;
    checkPreviewSize();
    updateDisplayedImage();
}

void DStation::checkPreviewSize()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function makes sure preview is always inside the image boundary.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if ((previewX+previewW)>(int)inputImage.columns()) previewX=inputImage.columns()-previewW;
    if ((previewX)<0) previewX=0;
    if ((previewY+previewH)>(int)inputImage.rows()) previewY=inputImage.rows()-previewH;
    if ((previewY)<0) previewY=0;

}

void DStation::on_applyPostProcessing_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Apply post-processing button.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (haveDeconvolvedImage) {
        postProcessing();
        displayMagickBlob(postProcessedImageBlob);
        FFTRealComponentShown=false;
    }
}

void DStation::on_realTimePostProcessing_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Apply Post Processing in Real Time button.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

Image DStation::lowLevel_log_gain(Image filterImage, const double logFactor, const double gain)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=ln(1+filterImage*logFactor*gain)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*log(pixel->red/QuantumRange*logFactor*gain+1);
            pixel->green=QuantumRange*log(pixel->green/QuantumRange*logFactor*gain+1);
            pixel->blue=QuantumRange*log(pixel->blue/QuantumRange*logFactor*gain+1);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_thresholdMax(Image filterImage, const double threshold, vector<int>& thresholdPixelMapX, vector<int>& thresholdPixelMapY, int& pixelsThresholded)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Replace all pixel with values more than threshold to threshold value.
    // Working with std::vectors to allow very large arrays of data.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int pixelCount=0;
    bool thresholded=false;

    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            thresholded=false;
            if (pixel->red>=(threshold)) {
                pixel->red=(double)threshold;
                thresholded=true;
            }

            if (pixel->blue>=(threshold)) {
                pixel->blue=(double)threshold;
                thresholded=true;
            }

            if (pixel->green>=(threshold)) {
                pixel->green=(double)threshold;
                thresholded=true;
            }

            if (thresholded) {
                thresholdPixelMapX.push_back(x);
                thresholdPixelMapY.push_back(y);
                pixelCount=pixelCount+1;
            }
        }
    }
    filterImage.syncPixels();
    pixelsThresholded=pixelCount;
    return (filterImage);
}

Image DStation::lowLevel_mixTwoImages(Image filterImage, Image filterImageB, vector<int>& thresholdPixelMapX, vector<int>& thresholdPixelMapY, int& pixelsThresholded)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mix two images together using threshold maps. Whenever threshold is met, filterImage pixel is replaced with filterImageB pixel.
    // Working with std::vectors to allow very large arrays of data.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    filterImageB.modifyImage();
    int x;
    int y;
    PixelPacket *filterImagePixels = filterImage.getPixels(0, 0, filterImage.columns(), filterImage.rows());
    PixelPacket *filterImageBPixels = filterImageB.getPixels(0, 0, filterImageB.columns(), filterImageB.rows());
    for (int w=0; w<pixelsThresholded; w++) {
        x=thresholdPixelMapY[w]; // inverted, too lazy to find out why...
        y=thresholdPixelMapX[w];
        PixelPacket *pixel=filterImagePixels+x*filterImage.columns()+y;
        PixelPacket *pixelB=filterImageBPixels+x*filterImageB.columns()+y;
        *pixel=*pixelB;

    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_thresholdMin(Image filterImage, const double threshold)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Replace all pixel with values less than threshold to threshold value. Does not return map.
    // Working with std::vectors to allow very large arrays of data.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int pixelCount=0;
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            if (pixel->red<=(threshold)) {
                pixel->red=(double)threshold;
            }

            if (pixel->blue<=(threshold)) {
                pixel->blue=(double)threshold;
            }

            if (pixel->green<=(threshold)) {
                pixel->green=(double)threshold;
            }
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

std::vector<double> DStation::lowLevel_imageToVector(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Converts image to a vector of doubles. Uses red channel only.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    std::vector<double> imageVector;
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            imageVector.push_back((double)pixel->red/QuantumRange);
        }
    }
    filterImage.syncPixels();
    return(imageVector);
}

double DStation::lowLevel_chiSquared(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Sums all pixel values, divides by amount of pixels and squares the result. Uses only red channel.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    double chi=0;
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            chi=chi+(double)pixel->red/QuantumRange;
        }
    }
    filterImage.syncPixels();
    chi=(double)chi/(filterImage.rows()*filterImage.columns());
    chi=pow(chi,2);
    return(chi);
}

Image DStation::lowLevel_mixTwoImagesWithBlur(Image filterImage, Image filterImageB, std::vector<int>& thresholdPixelMapX, std::vector<int>& thresholdPixelMapY, int& pixelsThresholded, int blur)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mix two images together using threshold maps. Whenever threshold is met, filterImage pixel is replaced with filterImageB pixel. Blurs the threshold map.
    // Usatov deringing method, using threshold map as geometric mean.
    // Working with std::vectors to allow very large arrays of data.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Image thresholdMap=filterImage;
    thresholdMap.backgroundColor(Color(0,0,0));
    thresholdMap.erase();                                                                                   // Clean black threshold map
    thresholdMap.modifyImage();

    PixelPacket *thresholdMapPixels = thresholdMap.getPixels(0, 0, thresholdMap.columns(), thresholdMap.rows());
    for (int w=0; w<pixelsThresholded; w++) {                                                               // Construct black-and-white threshold map
        int x=thresholdPixelMapY[w]; // inverted, too lazy to find out why...
        int y=thresholdPixelMapX[w];
        PixelPacket *pixel=thresholdMapPixels+x*thresholdMap.columns()+y;
        *pixel=Color(QuantumRange,QuantumRange,QuantumRange);
    }

    thresholdMap.syncPixels();

    if (ui->deringingSmoothness->value()>0) {
        if (ui->deringingSmoothingMode->currentIndex()==0) thresholdMap.blur(blur,1000000);    // Blur map
        if (ui->deringingSmoothingMode->currentIndex()==1) thresholdMap.blur(0,blur);
    }

    thresholdMap.normalize();

    if (DEBUG) thresholdMap.write("/temp/thresholdmap.png");

    filterImage.modifyImage();
    filterImageB.modifyImage();

    PixelPacket *filterImagePixels = filterImage.getPixels(0, 0, filterImage.columns(), filterImage.rows());
    PixelPacket *filterImageBPixels = filterImageB.getPixels(0, 0, filterImageB.columns(), filterImageB.rows());
    PixelPacket *thresholdMapPixelsA = thresholdMap.getPixels(0, 0, thresholdMap.columns(), thresholdMap.rows());


    for (int x=0; x<filterImage.columns(); x++) {                                                           // Use blurred map as geometric mean
        for (int y=0; y<filterImage.rows(); y++) {
            PixelPacket *pixel=filterImagePixels+x*filterImage.columns()+y;
            PixelPacket *pixelB=filterImageBPixels+x*filterImageB.columns()+y;
            PixelPacket *pixelMap=thresholdMapPixelsA+x*thresholdMap.columns()+y;
            double alphaRed=(double)(pixelMap->red/QuantumRange);
            double alphaGreen=(double)(pixelMap->green/QuantumRange);
            double alphaBlue=(double)(pixelMap->blue/QuantumRange);

            pixel->red=pow((double)pixel->red,(double)(1-alphaRed))*pow((double)pixelB->red,(double)alphaRed);
            pixel->green=pow((double)pixel->green,(double)(1-alphaGreen))*pow((double)pixelB->green,(double)alphaGreen);
            pixel->blue=pow((double)pixel->blue,(double)(1-alphaBlue))*pow((double)pixelB->blue,(double)alphaBlue);

        }
    }
    filterImage.syncPixels();
    return(filterImage);
}


Image DStation::lowLevel_logPlusOne(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=ln(filterImage+1)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*log(pixel->red/QuantumRange+1);
            pixel->green=QuantumRange*log(pixel->green/QuantumRange+1);
            pixel->blue=QuantumRange*log(pixel->blue/QuantumRange+1);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_log(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=ln(filterImage)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*log(pixel->red/QuantumRange);
            pixel->green=QuantumRange*log(pixel->green/QuantumRange);
            pixel->blue=QuantumRange*log(pixel->blue/QuantumRange);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_exp(Image filterImage, const double factor)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=exp(filterImage)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*exp((double)factor*pixel->red/QuantumRange);
            pixel->green=QuantumRange*exp((double)factor*pixel->green/QuantumRange);
            pixel->blue=QuantumRange*exp((double)factor*pixel->blue/QuantumRange);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::smooth(Image filterImage, const double filterSize)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Smoothing (filtering) of image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->smoothingMode->currentIndex()==0) filterImage.blur(filterSize,1000000);
    if (ui->smoothingMode->currentIndex()==1) filterImage.blur(0,filterSize);
    return (filterImage);
}

Image DStation::lowLevel_normalized_log_gain(Image filterImage, const double logFactor, const double gain)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=ln(1+filterImage*logFactor*gain)/ln(1+logFactor)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*log(pixel->red/QuantumRange*logFactor*gain+1)/log(1+logFactor);
            pixel->green=QuantumRange*log(pixel->green/QuantumRange*logFactor*gain+1)/log(1+logFactor);
            pixel->blue=QuantumRange*log(pixel->blue/QuantumRange*logFactor*gain+1)/log(1+logFactor);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_exponential_decay(Image filterImage, const double sigma)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. After Fred's IM:
    //    sig=0.5
    //    w=256
    //    h=256
    //    xc=$(($w/2))
    //    yc=$(($h/2))
    //    echo "w=$w; h=$h; xc=$xc; yc=$yc; xl=$xl; yl=$yl;"
    //    convert -size ${w}x${h} xc: -fx "xx=(i-$xc)/$xc; yy=(j-$yc)/$yc; rr=sqrt(xx^2+yy^2); exp(-rr/$sig)" tmp_exp.png
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    double xc=filterImage.columns()/2;
    double yc=filterImage.rows()/2;

    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;

            double xx=(double)(x-xc)/xc;
            double yy=(double)(y-yc)/yc;
            double rr=sqrt(pow(xx,2)+pow(yy,2));
            //double value=QuantumRange*exp((double)-rr/sigma);                                           // Exponential decay.
            double value=QuantumRange*exp(-pow((double)(rr/sigma),2));                                  // Exponential decay.

            pixel->red=value;
            pixel->green=value;
            pixel->blue=value;
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_radial_gradient(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. After Fred's IM:
    //    sig=0.5
    //    w=256
    //    h=256
    //    xc=$(($w/2))
    //    yc=$(($h/2))
    //    echo "w=$w; h=$h; xc=$xc; yc=$yc; xl=$xl; yl=$yl;"
    //    convert -size ${w}x${h} xc: -fx "xx=(i-$xc)/$xc; yy=(j-$yc)/$yc; rr=sqrt(xx^2+yy^2); exp(-rr/$sig)" tmp_exp.png
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    double xc=filterImage.columns()/2;
    double yc=filterImage.rows()/2;

    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;

            double xx=(double)(x-xc)/xc;
            double yy=(double)(y-yc)/yc;
            double value=sqrt(pow(xx,2)+pow(yy,2));
            pixel->red=value;
            pixel->green=value;
            pixel->blue=value;
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_linear_decay(Image filterImage, const double decay)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Simulates IM +level $(decay)x100%
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;

            pixel->red=QuantumRange*(((100-decay)/100)*(pixel->red/QuantumRange) + (double)decay/100);
            pixel->green=QuantumRange*(((100-decay)/100)*(pixel->green/QuantumRange) + (double)decay/100);
            pixel->blue=QuantumRange*(((100-decay)/100)*(pixel->blue/QuantumRange) + (double)decay/100);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_arc(Image filterImage, const double arcFactor)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. After Fred's IM without gain:
    // xc=`convert xc: -format "%[fx:1+sqrt($arcfactor)]" info:`
    // yc=`convert xc: -format "%[fx:-sqrt($arcfactor)]" info:`
    // rsq=`convert xc: -format "%[fx:$xc^2+$yc^2]" info:`
    // convert $dir/tmpF.mpc -evaluate multiply $gainF \
    //      -monitor -fx "sqrt($rsq-(u-$xc)^2)+$yc" +monitor $dir/tmpF.mpc
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    double xc=1+sqrt(arcFactor);
    double yc=-sqrt(arcFactor);
    double rsq=pow(xc,2)+pow(yc,2);

    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=QuantumRange*(sqrt(rsq-pow((pixel->red/QuantumRange-xc),2))+yc);
            pixel->green=QuantumRange*(sqrt(rsq-pow((pixel->green/QuantumRange-xc),2))+yc);
            pixel->blue=QuantumRange*(sqrt(rsq-pow((pixel->blue/QuantumRange-xc),2))+yc);
        }
    }
    filterImage.syncPixels();
    return (filterImage);
}

Image DStation::lowLevel_WU(Image atmosphericImage, Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=sqrt(atmosphericImage*filterImage)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        PixelPacket *atmPixels = atmosphericImage.getPixels(0, y, atmosphericImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            PixelPacket *atmPixel = atmPixels+x;
            pixel->red=sqrt(pixel->red*atmPixel->red);
            pixel->green=sqrt(pixel->green*atmPixel->green);
            pixel->blue=sqrt(pixel->blue*atmPixel->blue);
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_sqrt(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=sqrt(filterImage)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=sqrt(pixel->red*QuantumRange);
            pixel->green=sqrt(pixel->green*QuantumRange);
            pixel->blue=sqrt(pixel->blue*QuantumRange);
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_power(Image filterImage, const double power)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage^power
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=pow(pixel->red/QuantumRange,power)*QuantumRange;
            pixel->green=pow(pixel->green/QuantumRange,power)*QuantumRange;
            pixel->blue=pow(pixel->blue/QuantumRange,power)*QuantumRange;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_squared_plus_noise(Image filterImage, const double noise)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage^2+noise
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(pow(pixel->red/QuantumRange,double(2))+noise)*QuantumRange;
            pixel->green=(pow(pixel->green/QuantumRange,double(2))+noise)*QuantumRange;
            pixel->blue=(pow(pixel->blue/QuantumRange,double(2))+noise)*QuantumRange;

            //            pixel->red=(((pixel->red)*(pixel->red)/QuantumRange+noise))*QuantumRange;
            //            pixel->green=(((pixel->green)*(pixel->green)/QuantumRange+noise))*QuantumRange;
            //            pixel->blue=(((pixel->blue)*(pixel->blue)/QuantumRange+noise))*QuantumRange;

        }
    }
    filterImage.syncPixels();
    return(filterImage);
}


Image DStation::lowLevel_compress(Image filterImage, const double ratio, const double threshold)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Compresses signal. R=Input/(((Input-Threshold)*Ratio)+Threshold)
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(pixel->red/QuantumRange/(((pixel->red/QuantumRange-threshold)*ratio)+threshold))*QuantumRange;
            pixel->green=(pixel->green/QuantumRange/(((pixel->green/QuantumRange-threshold)*ratio)+threshold))*QuantumRange;
            pixel->blue=(pixel->blue/QuantumRange/(((pixel->blue/QuantumRange-threshold)*ratio)+threshold))*QuantumRange;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_add(Image filterImage, const double constant)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage+constant
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(pixel->red/QuantumRange+constant)*QuantumRange;
            pixel->green=(pixel->green/QuantumRange+constant)*QuantumRange;
            pixel->blue=(pixel->blue/QuantumRange+constant)*QuantumRange;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_subtract(Image filterImage, const double constant)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage-constant
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(pixel->red/QuantumRange-constant)*QuantumRange;
            pixel->green=(pixel->green/QuantumRange-constant)*QuantumRange;
            pixel->blue=(pixel->blue/QuantumRange-constant)*QuantumRange;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_mirrorRight(Image filterImage, int x_, int y_, int w_, int h_)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mirrors region x,y,w,h in the filterImage to the right of the region
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int buffer=filterImage.columns()-(x_+w_);
    int start=x_+w_-buffer;

    for (int y=y_; y<y_+h_; y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=start; x<x_+w_; x++) {
            PixelPacket *source = pixels+x;
            PixelPacket *destination = pixels+filterImage.columns()-x+start-1;
            destination->red=source->red;
            destination->green=source->green;
            destination->blue=source->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_mirrorLeft(Image filterImage, int x_, int y_, int w_, int h_)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mirrors region x,y,w,h in the filterImage to the left of the region
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int buffer=filterImage.columns()-(x_+w_);
    int start=x_+buffer;

    for (int y=y_; y<y_+h_; y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=start; x>x_; x--) {
            PixelPacket *source = pixels+x;
            PixelPacket *destination = pixels-x+start;
            destination->red=source->red;
            destination->green=source->green;
            destination->blue=source->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_mirrorUp(Image filterImage, int y_, int h_)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mirrors region 0,y,Max,h in the filterImage to above of the region
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int buffer=filterImage.rows()-(y_+h_);
    int start=y_+buffer;

    for (int y=0; y<buffer; y++) {
        PixelPacket *destinationPixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        PixelPacket *sourcePixels = filterImage.getPixels(0, start-y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *source = sourcePixels+x;
            PixelPacket *destination = destinationPixels+x;
            destination->red=source->red;
            destination->green=source->green;
            destination->blue=source->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_mirrorDown(Image filterImage, int y_, int h_)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. Mirrors region 0,y,Max,h in the filterImage to below of the region
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    int buffer=filterImage.rows()-(y_+h_);
    int start=y_+h_-buffer;

    for (int y=0; y<buffer; y++) {
        PixelPacket *sourcePixels = filterImage.getPixels(0, start+y, filterImage.columns(), 1);
        PixelPacket *destinationPixels = filterImage.getPixels(0, filterImage.rows()-y-1, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *source = sourcePixels+x;
            PixelPacket *destination = destinationPixels+x;
            destination->red=source->red;
            destination->green=source->green;
            destination->blue=source->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_divide(Image filterImage, const double denominator)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage/denominator
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(double)pixel->red/denominator;
            pixel->green=(double)pixel->green/denominator;
            pixel->blue=(double)pixel->blue/denominator;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_multiply(Image filterImage, const double denominator)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=filterImage*denominator
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(double)pixel->red*denominator;
            pixel->green=(double)pixel->green*denominator;
            pixel->blue=(double)pixel->blue*denominator;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_sineRelaxation(Image filterImage, const double gamma)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. See "Handbook of Astronomical Image Processing" p. 453
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Magick::Image::ImageStatistics inputImageStatistics;

    filterImage.statistics(&inputImageStatistics);

    double redMin=(double)inputImageStatistics.red.minimum/QuantumRange;
    double redMax=(double)inputImageStatistics.red.maximum/QuantumRange*2;

    double greenMin=(double)inputImageStatistics.green.minimum/QuantumRange;
    double greenMax=(double)inputImageStatistics.green.maximum/QuantumRange*2;

    double blueMin=(double)inputImageStatistics.blue.minimum/QuantumRange;
    double blueMax=(double)inputImageStatistics.blue.maximum/QuantumRange*2;

    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;

            //Color
            double pixelred=(double)pixel->red/QuantumRange;
            if (pixelred<redMin) pixel->red=0; else
                if (pixelred>redMax) pixel->red=QuantumRange; else
                {
                    double m=(double)(pixelred-redMin)/(redMax-pixelred);
                    double w=(sin((double)PI/2*m));
                    double b=pow(w*QuantumRange,gamma);
                    pixel->red=b;
                }

            //Color
            double pixelgreen=(double)pixel->green/QuantumRange;
            if (pixelgreen<greenMin) pixel->green=0; else
                if (pixelgreen>greenMax) pixel->green=QuantumRange; else
                {
                    double m=(double)(pixelgreen-greenMin)/(greenMax-pixelgreen);
                    double w=(sin((double)PI/2*m));
                    double b=pow(w*QuantumRange,gamma);
                    pixel->green=b;
                }

            //Color
            double pixelblue=(double)pixel->blue/QuantumRange;
            if (pixelblue<blueMin) pixel->blue=0; else
                if (pixelblue>blueMax) pixel->blue=QuantumRange; else
                {
                    double m=(double)(pixelblue-blueMin)/(blueMax-pixelblue);
                    double w=(sin((double)PI/2*m));
                    double b=pow(w*QuantumRange,gamma);
                    pixel->blue=b;
                }
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_inverse(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=1/filterImage
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=(double)1/pixel->red;
            pixel->green=(double)1/pixel->green;
            pixel->blue=(double)1/pixel->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_negate(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=-filterImage
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            pixel->red=-pixel->red;
            pixel->green=-pixel->green;
            pixel->blue=-pixel->blue;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_clamp_negatives(Image filterImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function to clamp negative values.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    filterImage.modifyImage();
    for (int y=0; y<(int)filterImage.rows(); y++) {
        PixelPacket *pixels = filterImage.getPixels(0, y, filterImage.columns(), 1);
        for (int x=0; x<(int)filterImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;

            if (pixel->red<0) pixel->red=0;
            if (pixel->green<0) pixel->green=0;
            if (pixel->blue<0) pixel->blue=0;
        }
    }
    filterImage.syncPixels();
    return(filterImage);
}

Image DStation::lowLevel_divide_by_image(Image dividedImage, const Image denominatorImage)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function. R=dividedImage/denominatorImage. Not used as DivideCompositeOp works faster.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image tempDenominator=denominatorImage;
    dividedImage.modifyImage();
    for (int y=0; y<(int)dividedImage.rows(); y++) {
        PixelPacket *pixels = dividedImage.getPixels(0, y, dividedImage.columns(), 1);
        PixelPacket *denominatorPixels = tempDenominator.getPixels(0, y, tempDenominator.columns(), 1);
        for (int x=0; x<(int)dividedImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            PixelPacket *denominatorPixel = denominatorPixels+x;
            pixel->red=(double)pixel->red/denominatorPixel->red*QuantumRange;
            pixel->green=(double)pixel->green/denominatorPixel->green*QuantumRange;
            pixel->blue=(double)pixel->blue/denominatorPixel->blue*QuantumRange;
        }
    }
    dividedImage.syncPixels();
    return(dividedImage);
}

void DStation::on_actionSave_Filter_As_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Saving filter to file.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QFileDialog saveDialog;
    QString fileName = saveDialog.getSaveFileName(this, "Save filter image", QFileInfo(workingDirectory).absolutePath().append(QString("/")).append(QFileInfo(workingDirectory).baseName()),tr("Uncompressed Memory Cache (*.mpc);;TIFF Image (*.tiff);;FITS Image (*.fits)"));
    if (!fileName.isEmpty()) {
        Image imageToSave=filterImage;
        imageToSave.write(fileName.toAscii().data());
        ui->consoleEdit->appendPlainText(QString("Filter image saved as ").append(fileName).append(QString(".")));
        QDir dir(fileName);
        workingDirectory=dir.absolutePath();
    }
}

void DStation::on_actionLoad_Filter_Image_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Loading filter from file.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QString fileName = QFileDialog::getOpenFileName(this, "Choose filter image", workingDirectory, "Filter Images (*.mpc *.tiff *.fits)");
    if (!fileName.isEmpty()) {
        ui->consoleEdit->appendPlainText(QString("Loading filter ").append(fileName).append(QString("...")));
        qApp->processEvents(); /* Required to update console screen before doing something intensive */
        filterImage.read(fileName.toAscii().data());
        ui->consoleEdit->appendPlainText("Ready.");
        haveExternalFilter=true;
        QDir dir(fileName);
        workingDirectory=dir.absolutePath();
    }
}

void DStation::on_actionBatch_Deconvolve_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Batch deconvolution.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QString queuedImage;
    QString deconvolvedImage;

    QString dirName = QFileDialog::getExistingDirectory(this, "Choose a folder to batch apply external filter", "", QFileDialog::ShowDirsOnly);
    if (!dirName.isEmpty()) {
        ui->consoleEdit->appendPlainText(QString("Batch deconvolving ").append(dirName).append(QString("...")));

        if (ui->deconvolutionAlgorithm->currentIndex()==3 && !haveExternalFilter) {                     // Checking if we have external filter if we need it. -0.312-
            ui->consoleEdit->appendPlainText(QString("No external filter available. Please load a filter image to deconvolve using an external filter."));
            return;
        }
        QDir dirToDeconvolve(dirName);
        QStringList batchFormats;                                                                       // Batch-convert only these extensions.
        batchFormats << "*.fit";
        batchFormats << "*.png";
        batchFormats << "*.fts";
        batchFormats << "*.fits";
        batchFormats << "*.tif";
        batchFormats << "*.tiff";
        QFileInfoList fileList=dirToDeconvolve.entryInfoList(QStringList(batchFormats));
        for (int i=0; i<fileList.size(); i++) {
            QFileInfo fileInfo = fileList.at(i);
            queuedImage=QString(dirName).append(QString("/")).append(QString(fileInfo.fileName()));
            deconvolvedImage=QString(dirName).append(QString("/")).append(QString(fileInfo.baseName())).append(QString("-deconvolved."));
            if (ui->forceBatchTIFF->isChecked()) deconvolvedImage.append(QString("tiff"));
            else
                deconvolvedImage.append(QString(fileInfo.suffix()));
            openImage(queuedImage);
            deconvolve();
            Image imageToSave(postProcessedImageBlob);
            if (ui->savedImagePrecision->currentIndex()==0) imageToSave.depth(16);
            if (ui->savedImagePrecision->currentIndex()==1) imageToSave.depth(32);
            imageToSave.write(deconvolvedImage.toAscii().data());
        }
        ui->consoleEdit->appendPlainText(QString("Batch deconvolution complete."));
    }
}

void DStation::on_actionMeasure_NSR_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Measure Noise To Signal Ratio in the preview area and set the Noise spinbox value to measured value.
    // NSR=(Preview_StdDev/Image_StdDev)^2
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Magick::Image::ImageStatistics inputImageStatistics;
    Magick::Image::ImageStatistics previewImageStatistics;
    double redNSR;
    double greenNSR;
    double blueNSR;
    double NSR;
    char bufferA[256];

    Image previewImage=inputImage;
    previewImage.crop(Geometry(previewW,previewH,previewX,previewY));
    inputImage.statistics(&inputImageStatistics);
    previewImage.statistics(&previewImageStatistics);

    redNSR=pow((previewImageStatistics.red.standard_deviation/inputImageStatistics.red.standard_deviation),2);
    greenNSR=pow((previewImageStatistics.green.standard_deviation/inputImageStatistics.green.standard_deviation),2);
    blueNSR=pow((previewImageStatistics.blue.standard_deviation/inputImageStatistics.blue.standard_deviation),2);

    NSR=(double)(redNSR+greenNSR+blueNSR)/3;
    sprintf(bufferA, "%.5f", NSR*1000);
    ui->consoleEdit->appendPlainText(QString("Noise to Signal Ratio (x1000) in preview area: ").append(QString(bufferA)));
    ui->noiseSpin->setValue((double)NSR*1000);
}

void DStation::on_redrawHistogramButton_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Redraw ristogram image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (haveDeconvolvedImage) {
        Image postProcessedImage(postProcessedImageBlob);
        Image histogramImage(Geometry(SIDEBAR_IMAGE_WIDTH,SIDEBAR_IMAGE_HEIGHT),Color("black"));        // Construct a new black histogram image.
        if (ui->logarithmicHistogram->isChecked()) histogramImage=lowLevel_log_histogram(histogramImage,postProcessedImage);
        else
            histogramImage=lowLevel_histogram(histogramImage,postProcessedImage);
        displayMagickImageInHistogram(histogramImage);

    }
}

void DStation::clearHistogram()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Clear histogram image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image histogramImage(Geometry(SIDEBAR_IMAGE_WIDTH,SIDEBAR_IMAGE_HEIGHT),Color("black")); // Construct a new black histogram image
    displayMagickImageInHistogram(histogramImage);
}


Image DStation::lowLevel_histogram(Image histogramImage, const Image input)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function to create linear histogram image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int histogramBin=QuantumRange/histogramImage.columns();
    int bins=histogramImage.columns();
    int redHistogram [bins];
    int greenHistogram [bins];
    int blueHistogram [bins];
    int thisPixelsBin;
    int z;
    int scaleToHeight;
    std::list<Magick::Drawable> drawList;

    for (z=0; z<bins; z++) {                                                                            // Resetting aray.
        redHistogram[z]=0;
        greenHistogram[z]=0;
        blueHistogram[z]=0;
    }

    Image tempImage=input;
    tempImage.channelDepth(RedChannel,16);                                                              // Reduce input image depth to 16-bit for histogramming - saves cycles.
    tempImage.channelDepth(GreenChannel,16);
    tempImage.channelDepth(BlueChannel,16);

    for (int y=0; y<(int)tempImage.rows(); y++) {
        PixelPacket *pixels = tempImage.getPixels(0, y, tempImage.columns(), 1);
        for (int x=0; x<(int)tempImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            thisPixelsBin=ceil(pixel->red/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) redHistogram[thisPixelsBin]++;

            thisPixelsBin=ceil(pixel->green/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) greenHistogram[thisPixelsBin]++;

            thisPixelsBin=ceil(pixel->blue/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) blueHistogram[thisPixelsBin]++;

        }
    }

    scaleToHeight=0;                                                                                    // Finding maximum to scale histogram to image.
    for (z=1; z<bins; z++) {
        if (redHistogram[z]>scaleToHeight) scaleToHeight=redHistogram[z];
        if (greenHistogram[z]>scaleToHeight) scaleToHeight=greenHistogram[z];
        if (blueHistogram[z]>scaleToHeight) scaleToHeight=blueHistogram[z];
    }

    scaleToHeight=scaleToHeight/ui->histogramVerticalScale->value();

    drawList.push_back(DrawableStrokeWidth(1));                                                         // Drawing histogram.
    drawList.push_back(DrawableStrokeColor("blue"));
    for (int i=1; i<bins; i++) {
        int value=blueHistogram[i]*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    drawList.push_back(DrawableStrokeColor("green"));
    for (int i=1; i<bins; i++) {
        int value=greenHistogram[i]*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    drawList.push_back(DrawableStrokeColor("red"));
    for (int i=1; i<bins; i++) {
        int value=redHistogram[i]*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    histogramImage.draw(drawList);
    return(histogramImage);
}

Image DStation::lowLevel_log_histogram(Image histogramImage, const Image input)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Low level function to create logarithmic histogram image. See linear histogram function for comments as these are almost identical.
    //
    // HISTOGRAM NEEDS FIXING!!!!
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int histogramBin=QuantumRange/histogramImage.columns();
    int bins=histogramImage.columns();
    int redHistogram [bins];
    int greenHistogram [bins];
    int blueHistogram [bins];
    int thisPixelsBin;
    int z;
    double scaleToHeight;
    std::list<Magick::Drawable> drawList;

    for (z=0; z<bins; z++) {
        redHistogram[z]=0;
        greenHistogram[z]=0;
        blueHistogram[z]=0;
    }

    Image tempImage=input;
    tempImage.channelDepth(RedChannel,16);
    tempImage.channelDepth(GreenChannel,16);
    tempImage.channelDepth(BlueChannel,16);

    for (int y=0; y<(int)tempImage.rows(); y++) {
        PixelPacket *pixels = tempImage.getPixels(0, y, tempImage.columns(), 1);
        for (int x=0; x<(int)tempImage.columns(); x++) {
            PixelPacket *pixel = pixels+x;
            thisPixelsBin=ceil(pixel->red/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) redHistogram[thisPixelsBin]++;

            thisPixelsBin=ceil(pixel->green/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) greenHistogram[thisPixelsBin]++;

            thisPixelsBin=ceil(pixel->blue/histogramBin);
            if (thisPixelsBin>0 && thisPixelsBin<=bins) blueHistogram[thisPixelsBin]++;

        }
    }

    scaleToHeight=0;
    for (z=1; z<bins; z++) {
        if (log(redHistogram[z])>scaleToHeight) scaleToHeight=log(redHistogram[z]);
        if (log(greenHistogram[z])>scaleToHeight) scaleToHeight=log(greenHistogram[z]);
        if (log(blueHistogram[z])>scaleToHeight) scaleToHeight=log(blueHistogram[z]);
    }

    scaleToHeight=(double)scaleToHeight/ui->histogramVerticalScale->value();

    drawList.push_back(DrawableStrokeWidth(1));
    drawList.push_back(DrawableStrokeColor("blue"));
    for (int i=1; i<bins; i++) {
        int value=log(blueHistogram[i])*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        if (log(blueHistogram[i])>0) drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    drawList.push_back(DrawableStrokeColor("green"));
    for (int i=1; i<bins; i++) {
        int value=log(greenHistogram[i])*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        if (log(greenHistogram[i])>0) drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    drawList.push_back(DrawableStrokeColor("red"));
    for (int i=1; i<bins; i++) {
        int value=log(redHistogram[i])*histogramImage.rows()/scaleToHeight;
        int x=i;
        int ya=histogramImage.rows();
        int yb=ya-value;
        if (log(redHistogram[i])>0) drawList.push_back(DrawableLine(x,ya,x,yb));
    }

    histogramImage.draw(drawList);
    return(histogramImage);
}

void DStation::on_histogramVerticalScale_valueChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Change vertical scale of histogram.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    on_redrawHistogramButton_clicked();
}

void DStation::on_logarithmicHistogram_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Change histogram mode - linear/log.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    on_redrawHistogramButton_clicked();
}

void DStation::on_actionAbout_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Prepare and show about dialog.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    aboutDialog about;
    Qt::WindowFlags aboutFlags;
    aboutFlags = Qt::CustomizeWindowHint;
    QString appString;
    appString=QString(APPNAME).append(QString(" ")).append(VERSION_STRING(VERSION_NUMBER)).append(QString(" for ")).append(OSv);
    about.setApplicationLabel(appString, QString(APPCOPYRIGHTS));
    about.setWindowFlags(aboutFlags);
    about.exec();
}

void DStation::openPresetFromFile(QString fileName)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Open preset from file.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (!fileName.isEmpty()) {
        QSettings preset(fileName, QSettings::IniFormat);

        ui->wavelengthRSpin->setValue(preset.value("WavelengthR").toInt());
        ui->wavelengthGSpin->setValue(preset.value("WavelengthG").toInt());
        ui->wavelengthBSpin->setValue(preset.value("WavelengthB").toInt());
        ui->dSpin->setValue(preset.value("ObjectiveDiameter").toInt());
        ui->r0Spin->setValue(preset.value("r0").toInt());
        ui->fSpin->setValue(preset.value("FocalLength").toInt());
        ui->pixelSpin->setValue(preset.value("CCDPixelSize").toDouble());
        ui->noiseSpin->setValue(preset.value("NoiseEstimation").toDouble());
        ui->gaussianBlurSpin->setValue(preset.value("Filtering").toInt());
        ui->deconvolutionAlgorithm->setCurrentIndex(preset.value("Algorithm").toInt());
        ui->postProcessingEnabledCheckBox->setChecked(preset.value("PostProcessingEnabled").toBool());
        ui->realTimePostProcessing->setChecked(preset.value("ApplyInRealTimeEnabled").toBool());
        ui->normalizeCheckBox->setChecked(preset.value("NormalizeEnabled").toBool());
        ui->enhanceCheckBox->setChecked(preset.value("AutoNoiseFilter").toBool());
        ui->dynamicRangeExtensionSpin->setValue(preset.value("DRE").toInt());
        ui->histogramVerticalScale->setValue(preset.value("HistogramVerticalScale").toInt());
        ui->logarithmicHistogram->setChecked(preset.value("LogHistogramEnabled").toBool());
        ui->FriedAlpha->setCurrentIndex(preset.value("TurbulenceModel").toInt());
        ui->processingMode->setCurrentIndex(preset.value("ProcessingMode").toInt());
        ui->savedImagePrecision->setCurrentIndex(preset.value("SavedImagePrecision").toInt());
        ui->supersamplingFactorSpin->setValue(preset.value("Supersampling", 1).toDouble());
        ui->bufferSpin->setValue(preset.value("AntiArtifactBuffer").toInt());
        ui->gammaSpinBox->setValue(preset.value("FilterWeights").toDouble());
        ui->forceBatchTIFF->setChecked(preset.value("ForceBatchTIFFSaveEnabled").toBool());
        ui->useHDRI->setChecked(preset.value("UseHDRIEnabled").toBool());
        ui->doNotSaveFilterCheckBox->setChecked(preset.value("DoNotSaveFilterEnabled").toBool());
        ui->doNotDownsampleCheckBox->setChecked(preset.value("DoNotDownsampleEnabled").toBool());
        ui->stop32bitSpaceExceededCheckBox->setChecked(preset.value("Stop32bitRAMExceeded").toBool());
        ui->barlowSpin->setValue(preset.value("Barlow").toDouble());
        ui->noiseFilterStrengthSpin->setValue(preset.value("NoiseFilterStrength").toInt());
        ui->briDial->setValue(preset.value("Brightness").toInt());
        ui->conDial->setValue(preset.value("Contrast").toInt());
        ui->briConEnabled->setChecked(preset.value("BriConEnabled").toBool());
        ui->supersamplingFilter->setCurrentIndex(preset.value("SupersamplingFilter", 5).toInt());       // Hamming by default.
        ui->filteringMethod->setCurrentIndex(preset.value("FilteringMethod", 0).toInt());               // Wiener by default.
        ui->LaplacianAlpha->setValue(preset.value("LaplacianAlpha", 0.25).toDouble());
        ui->logFactorSpin->setValue(preset.value("LogFactor").toDouble());
        ui->supersamplingFilterDown->setCurrentIndex(preset.value("SupersamplingFilterDown", 12).toInt()); // Lanczos by default.
        ui->smoothingMode->setCurrentIndex(preset.value("SmoothingMode", 0).toInt());                      // Radius by default.
        ui->equalizerSlider_1->setValue(preset.value("EqualizerSlider1", 50).toInt());
        ui->equalizerSlider_2->setValue(preset.value("EqualizerSlider2", 50).toInt());
        ui->equalizerSlider_3->setValue(preset.value("EqualizerSlider3", 50).toInt());
        ui->equalizerSlider_4->setValue(preset.value("EqualizerSlider4", 50).toInt());
        ui->equalizerSlider_5->setValue(preset.value("EqualizerSlider5", 50).toInt());
        ui->equalizerSlider_6->setValue(preset.value("EqualizerSlider6", 50).toInt());
        ui->trackImageStatisticsCheckBox->setChecked(preset.value("TrackStatistics", true).toBool());
        ui->postProcessedImageStatisticsCheckBox->setChecked(preset.value("PostProcessedImageStatistics", true).toBool());
        ui->deringingThreshold->setValue(preset.value("DeringingThreshold", 0.25).toDouble());
        ui->deringingFactor->setValue(preset.value("DeringingFactor", 20).toInt());
        ui->deringingEnabledCheckBox->setChecked(preset.value("DeringingEnabled", false).toBool());
        ui->deringingSmoothness->setValue(preset.value("DeringingSmoothness", 20).toInt());
        ui->deringingSmoothMax->setChecked(preset.value("DeringingSmoothMax", true).toBool());
        ui->deringingApplyMinThreshold->setChecked(preset.value("DeringingApplyMinThreshold", false).toBool());
        ui->deringingSmoothingMode->setCurrentIndex(preset.value("DeringingSmoothingMode", 0).toInt());
        ui->iterationsSpin->setValue(preset.value("IterativeIterations", 5).toInt());
        ui->convergenceSpin->setValue(preset.value("IterativeConvergence", 1).toDouble());
        ui->spatialFilterSize->setValue(preset.value("IterativeSpatialFilterSize", 11).toInt());
        ui->subtractBias->setChecked(preset.value("SubtractBias", false).toBool());


        ui->consoleEdit->appendPlainText(QString("Preset loaded: ").append(fileName).append(QString(".")));
        QDir dir(fileName);
        workingDirectory=dir.absolutePath();
        updateEqualizerImage();
    }}

void DStation::savePresetToFile(QString fileName)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Save preset to file.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    if (!fileName.isEmpty()) {
        QSettings preset(fileName, QSettings::IniFormat);
        preset.setValue("Application", QString(APPNAME).append(QString(" ")).append(VERSION_STRING(VERSION_NUMBER)).append(QString(" for ")).append(OSv));
        preset.setValue("WavelengthR",ui->wavelengthRSpin->value());
        preset.setValue("WavelengthG",ui->wavelengthGSpin->value());
        preset.setValue("WavelengthB",ui->wavelengthBSpin->value());
        preset.setValue("ObjectiveDiameter",ui->dSpin->value());
        preset.setValue("r0",ui->r0Spin->value());
        preset.setValue("FocalLength",ui->fSpin->value());
        preset.setValue("CCDPixelSize",ui->pixelSpin->value());
        preset.setValue("NoiseEstimation",ui->noiseSpin->value());
        preset.setValue("Filtering",ui->gaussianBlurSpin->value());
        preset.setValue("Algorithm",ui->deconvolutionAlgorithm->currentIndex());
        preset.setValue("PostProcessingEnabled",ui->postProcessingEnabledCheckBox->isChecked());
        preset.setValue("ApplyInRealTimeEnabled",ui->realTimePostProcessing->isChecked());
        preset.setValue("NormalizeEnabled",ui->normalizeCheckBox->isChecked());
        preset.setValue("AutoNoiseFilter",ui->enhanceCheckBox->isChecked());
        preset.setValue("DRE",ui->dynamicRangeExtensionSpin->value());
        preset.setValue("HistogramVerticalScale",ui->histogramVerticalScale->value());
        preset.setValue("LogHistogramEnabled",ui->logarithmicHistogram->isChecked());
        preset.setValue("TurbulenceModel",ui->FriedAlpha->currentIndex());
        preset.setValue("ProcessingMode",ui->processingMode->currentIndex());
        preset.setValue("SavedImagePrecision",ui->savedImagePrecision->currentIndex());
        preset.setValue("Supersampling",ui->supersamplingFactorSpin->value());
        preset.setValue("AntiArtifactBuffer",ui->bufferSpin->value());
        preset.setValue("FilterWeights",ui->gammaSpinBox->value());
        preset.setValue("DoNotDownsampleEnabled",ui->doNotDownsampleCheckBox->isChecked());
        preset.setValue("ForceBatchTIFFSaveEnabled",ui->forceBatchTIFF->isChecked());
        preset.setValue("UseHDRIEnabled",ui->useHDRI->isChecked());
        preset.setValue("DoNotSaveFilterEnabled",ui->doNotSaveFilterCheckBox->isChecked());
        preset.setValue("Stop32bitRAMExceeded",ui->stop32bitSpaceExceededCheckBox->isChecked());
        preset.setValue("Barlow",ui->barlowSpin->value());
        preset.setValue("NoiseFilterStrength",ui->noiseFilterStrengthSpin->value());
        preset.setValue("Brightness",ui->briDial->value());
        preset.setValue("Contrast",ui->conDial->value());
        preset.setValue("BriConEnabled",ui->briConEnabled->isChecked());
        preset.setValue("SupersamplingFilter",ui->supersamplingFilter->currentIndex());
        preset.setValue("FilteringMethod",ui->filteringMethod->currentIndex());
        preset.setValue("LaplacianAlpha",ui->LaplacianAlpha->value());
        preset.setValue("LogFactor",ui->logFactorSpin->value());
        preset.setValue("SupersamplingFilterDown",ui->supersamplingFilterDown->currentIndex());
        preset.setValue("SmoothingMode",ui->smoothingMode->currentIndex());
        preset.setValue("EqualizerSlider1",ui->equalizerSlider_1->value());
        preset.setValue("EqualizerSlider2",ui->equalizerSlider_2->value());
        preset.setValue("EqualizerSlider3",ui->equalizerSlider_3->value());
        preset.setValue("EqualizerSlider4",ui->equalizerSlider_4->value());
        preset.setValue("EqualizerSlider5",ui->equalizerSlider_5->value());
        preset.setValue("EqualizerSlider6",ui->equalizerSlider_6->value());
        preset.setValue("TrackStatistics",ui->trackImageStatisticsCheckBox->isChecked());
        preset.setValue("PostProcessedImageStatistics",ui->postProcessedImageStatisticsCheckBox->isChecked());
        preset.setValue("DeringingThreshold",ui->deringingThreshold->value());
        preset.setValue("DeringingFactor",ui->deringingFactor->value());
        preset.setValue("DeringingSmoothness",ui->deringingSmoothness->value());
        preset.setValue("DeringingEnabled",ui->deringingEnabledCheckBox->isChecked());
        preset.setValue("DeringingSmoothMax",ui->deringingSmoothMax->isChecked());
        preset.setValue("DeringingApplyMinThreshold",ui->deringingApplyMinThreshold->isChecked());
        preset.setValue("DeringingSmoothingMode",ui->deringingSmoothingMode->currentIndex());
        preset.setValue("IterativeIterations",ui->iterationsSpin->value());
        preset.setValue("IterativeConvergence",ui->convergenceSpin->value());
        preset.setValue("IterativeSpatialFilterSize",ui->spatialFilterSize->value());
        preset.setValue("SubtractBias",ui->subtractBias->isChecked());

        preset.sync();
        ui->consoleEdit->appendPlainText(QString("Preset saved as ").append(fileName).append(QString(".")));
    }
}

void DStation::on_actionSave_preset_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Save preset to disk.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QFileDialog saveDialog;
    QString fileName = saveDialog.getSaveFileName(this, "Save preset", QFileInfo(workingDirectory).absolutePath().append(QString("/")).append(QFileInfo(workingDirectory).baseName()), tr("DStation Preset (*.d)"));
    savePresetToFile(fileName);
}

void DStation::on_actionOpen_Preset_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Read preset from disk.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QFileDialog openDialog;
    QString fileName = openDialog.getOpenFileName(this, "Choose a preset", workingDirectory, "DStation Presets (*.d)");
    openPresetFromFile(fileName);

}

void DStation::on_noiseFilterStrengthSpin_valueChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_briConEnabled_stateChanged(int )
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::checkBufferIsValid()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function checks whether anti-artifact buffer dimensions are at maximum allowed size which is twice the input image lesser dimension.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int dimension;
    if (inputImage.rows()>=inputImage.columns()) dimension=inputImage.rows()*2;
    else
        dimension=inputImage.columns()*2;

    if (ui->bufferSpin->value()>dimension) {
        ui->consoleEdit->appendPlainText("Anti-artifact buffer is too large, exceeding useful image area. Reset to maximum.");
        ui->bufferSpin->setValue(dimension);
    }
}


void DStation::on_actionLoad_Reference_Image_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function loads reference image used by the Lim blind deconvolution filter.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    QString fileName = QFileDialog::getOpenFileName(this, "Choose reference image", workingDirectory, "Images (*.png *.fts *.fits *.fit *.tif *.tiff)");
    if (!fileName.isEmpty()) {
        ui->consoleEdit->appendPlainText(QString("Loading reference image ").append(fileName).append(QString("...")));
        qApp->processEvents(); /* Required to update console screen before doing something intensive */
        LimReferenceImage.read(fileName.toAscii().data());
        ui->consoleEdit->appendPlainText("Ready.");
        haveReferenceImage=true;
        ui->showReferenceImage->setEnabled(true);
    }
}

void DStation::on_showReferenceImage_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function displays reference image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    displayMagickImage(LimReferenceImage);
}

void DStation::on_showOnlyInputButton_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function displays input image.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    displayMagickImage(inputImage);
}

void DStation::on_actionDeconvolve_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Deconvolve from menu
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    on_deconvolveButton_clicked();
}

void DStation::updateEqualizerImage()
{
    FDEfilter(500,500);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// These functions update image in real-time as frequency equalizer settings are changed.
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DStation::on_equalizerSlider_1_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

void DStation::on_equalizerSlider_2_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

void DStation::on_equalizerSlider_3_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

void DStation::on_equalizerSlider_4_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

void DStation::on_equalizerSlider_5_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

void DStation::on_equalizerSlider_6_sliderReleased()
{
    if (ui->realTimePostProcessing->isChecked()) updateEqualizerImage();
}

Image DStation::deconvolveSwitch(const Image *inputImage, const Image *tmpF, double noise, const double HDRIallowed)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function deconvolves inputImage with tmpF filter and noise estimate with deconvolution method selected in the UI.
    // Wiener HDRI deconvolution mode uses FFTContainer as the input image components.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Image processedImage;
    switch (ui->filteringMethod->currentIndex()) {
    case 0:                                                                                     // Wiener filtering
        if (ui->useHDRI->isChecked() && HDRIallowed) processedImage=deconvolutionWienerHDRI(tmpF,noise); else
            processedImage=deconvolutionWiener_nonHDRI(inputImage,tmpF,noise);
        break;

    case 1:                                                                                     // Constrained Least Squares
        processedImage=deconvolutionCLS_nonHDRI(inputImage,tmpF,noise);
        break;

    case 2:                                                                                     // Iterative Wiener filtering
        processedImage=deconvolutionIterativeWiener_nonHDRI(inputImage,tmpF);
        break;

    case 3:                                                                                     // VanCittert
        processedImage=deconvolutionVanCittert(inputImage,tmpF);
        break;

    case 4:                                                                                     // LR, sine relaxed
        processedImage=deconvolutionLR(inputImage,tmpF);
        break;

    case 5:                                                                                     // Maximum A Posteriori
        processedImage=deconvolutionMAP(inputImage,tmpF);
        break;

    case 6:                                                                                     // LR, constant regularized
        processedImage=deconvolutionLRConstant(inputImage,tmpF);
        break;

    case 7:                                                                                     // Iterative Wiener (Schafer) with FDE
        processedImage=deconvolutionIterativeWienerFDE_nonHDRI(inputImage,tmpF);
        break;

    case 8:                                                                                     // Landweber
        processedImage=deconvolutionLandweber(inputImage,tmpF);
        break;


    }
    return(processedImage);
}

void DStation::on_filteringMethod_currentIndexChanged(int index)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Enable/disable UI Elements depending on deconvolution (filtering) method chosen
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    switch (index) {
    case 0:                                                                                     // Wiener filtering
        ui->noiseSpin->setEnabled(true);
        ui->iterationsSpin->setEnabled(false);
        ui->convergenceSpin->setEnabled(false);
        ui->spatialFilterSize->setEnabled(false);
        ui->iterativeShowProgress->setEnabled(false);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(true);
        break;

    case 1:                                                                                     // Constrained Least Squares
        ui->noiseSpin->setEnabled(true);
        ui->iterationsSpin->setEnabled(false);
        ui->convergenceSpin->setEnabled(false);
        ui->spatialFilterSize->setEnabled(false);
        ui->iterativeShowProgress->setEnabled(false);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(true);
        break;

    case 2:                                                                                     // Iterative Wiener filtering
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(false);
        ui->iterativeShowProgress->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        break;

    case 3:                                                                                     // VanCittert
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(true);
        ui->iterativeShowProgress->setEnabled(true);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        break;

    case 4:                                                                                     // LR, sine relaxed
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(true);
        ui->iterativeShowProgress->setEnabled(true);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        break;

    case 5:                                                                                     // Maximum A Posteriori
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(true);
        ui->iterativeShowProgress->setEnabled(true);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        break;

    case 6:                                                                                     // LR, constant regularized
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(true);
        ui->iterativeShowProgress->setEnabled(true);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        break;

    case 7:                                                                                     // Iterative Wiener filtering with FDE
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(false);
        ui->iterativeShowProgress->setEnabled(false);
        ui->equalizerSlider_1->setEnabled(true);
        ui->equalizerSlider_2->setEnabled(true);
        ui->equalizerSlider_3->setEnabled(true);
        ui->equalizerSlider_4->setEnabled(true);
        ui->equalizerSlider_5->setEnabled(true);
        ui->equalizerSlider_6->setEnabled(true);
        ui->noiseLabel->setEnabled(false);
        break;

    case 8:                                                                                     // Landweber
        ui->noiseSpin->setEnabled(false);
        ui->iterationsSpin->setEnabled(true);
        ui->convergenceSpin->setEnabled(true);
        ui->spatialFilterSize->setEnabled(false);
        ui->iterativeShowProgress->setEnabled(false);
        ui->noiseLabel->setEnabled(false);
        ui->equalizerSlider_1->setEnabled(false);
        ui->equalizerSlider_2->setEnabled(false);
        ui->equalizerSlider_3->setEnabled(false);
        ui->equalizerSlider_4->setEnabled(false);
        ui->equalizerSlider_5->setEnabled(false);
        ui->equalizerSlider_6->setEnabled(false);
        break;

    }
}



void DStation::on_briDial_sliderReleased()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_conDial_sliderReleased()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates image in real-time as post-processing settings are changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::updateBriConLabels()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates brightness/contrast text labels.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->briLabel->setText(QString("Bri ").append(QString::number(ui->briDial->value())).append("%"));
    ui->conLabel->setText(QString("Con ").append(QString::number(ui->conDial->value())).append("%"));
}

void DStation::on_resetBriCon_clicked()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Reset bri/con dials to 100%.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ui->briDial->setValue(100);
    ui->conDial->setValue(100);
    if (ui->realTimePostProcessing->isChecked()) on_applyPostProcessing_clicked();
}

void DStation::on_briDial_valueChanged(int value)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates brightness/contrast text labels once brightness/contrast slider value is changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    updateBriConLabels();
}

void DStation::on_conDial_valueChanged(int value)
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // This function updates brightness/contrast text labels once brightness/contrast slider value is changed.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    updateBriConLabels();
}

void DStation::trackStatistics()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Track statistics and update table before post-processing.
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Magick::Image::ImageStatistics statistics;
    char format='f';
    int precision=6;

    if (ui->trackImageStatisticsCheckBox->isChecked()) {                                                // Select which image to obtain statistics from - processed (deconvolved) or post-processed image.
        if (ui->postProcessedImageStatisticsCheckBox->isChecked()) {
            Image *postProcessedImage = new Image(postProcessedImageBlob);
            postProcessedImage->statistics(&statistics);
        }
        else
            processedImage.statistics(&statistics);
        QTableWidgetItem *Rmin = new QTableWidgetItem(QString::number((double)statistics.red.minimum/QuantumRange, format, precision));
        QTableWidgetItem *Rmax = new QTableWidgetItem(QString::number((double)statistics.red.maximum/QuantumRange, format, precision));
        QTableWidgetItem *Rmean = new QTableWidgetItem(QString::number((double)statistics.red.mean/QuantumRange, format, precision));
        QTableWidgetItem *Rstddev = new QTableWidgetItem(QString::number((double)statistics.red.standard_deviation/QuantumRange, format, precision));
        QTableWidgetItem *Rvar = new QTableWidgetItem(QString::number((double)statistics.red.variance));
        QTableWidgetItem *Rkurtosis = new QTableWidgetItem(QString::number((double)statistics.red.kurtosis, format, precision));
        QTableWidgetItem *Rskew = new QTableWidgetItem(QString::number((double)statistics.red.skewness, format, precision));

        QTableWidgetItem *Gmin = new QTableWidgetItem(QString::number((double)statistics.green.minimum/QuantumRange, format, precision));
        QTableWidgetItem *Gmax = new QTableWidgetItem(QString::number((double)statistics.green.maximum/QuantumRange, format, precision));
        QTableWidgetItem *Gmean = new QTableWidgetItem(QString::number((double)statistics.green.mean/QuantumRange, format, precision));
        QTableWidgetItem *Gstddev = new QTableWidgetItem(QString::number((double)statistics.green.standard_deviation/QuantumRange, format, precision));
        QTableWidgetItem *Gvar = new QTableWidgetItem(QString::number((double)statistics.green.variance));
        QTableWidgetItem *Gkurtosis = new QTableWidgetItem(QString::number((double)statistics.green.kurtosis, format, precision));
        QTableWidgetItem *Gskew = new QTableWidgetItem(QString::number((double)statistics.green.skewness, format, precision));

        QTableWidgetItem *Bmin = new QTableWidgetItem(QString::number((double)statistics.blue.minimum/QuantumRange, format, precision));
        QTableWidgetItem *Bmax = new QTableWidgetItem(QString::number((double)statistics.blue.maximum/QuantumRange, format, precision));
        QTableWidgetItem *Bmean = new QTableWidgetItem(QString::number((double)statistics.blue.mean/QuantumRange, format, precision));
        QTableWidgetItem *Bstddev = new QTableWidgetItem(QString::number((double)statistics.blue.standard_deviation/QuantumRange, format, precision));
        QTableWidgetItem *Bvar = new QTableWidgetItem(QString::number((double)statistics.blue.variance));
        QTableWidgetItem *Bkurtosis = new QTableWidgetItem(QString::number((double)statistics.blue.kurtosis, format, precision));
        QTableWidgetItem *Bskew = new QTableWidgetItem(QString::number((double)statistics.blue.skewness, format, precision));

        ui->statisticsTable->setItem(1,1,Rmin);
        ui->statisticsTable->setItem(2,1,Rmax);
        ui->statisticsTable->setItem(3,1,Rmean);
        ui->statisticsTable->setItem(4,1,Rstddev);
        ui->statisticsTable->setItem(5,1,Rvar);
        ui->statisticsTable->setItem(6,1,Rkurtosis);
        ui->statisticsTable->setItem(7,1,Rskew);

        ui->statisticsTable->setItem(1,2,Gmin);
        ui->statisticsTable->setItem(2,2,Gmax);
        ui->statisticsTable->setItem(3,2,Gmean);
        ui->statisticsTable->setItem(4,2,Gstddev);
        ui->statisticsTable->setItem(5,2,Gvar);
        ui->statisticsTable->setItem(6,2,Gkurtosis);
        ui->statisticsTable->setItem(7,2,Gskew);

        ui->statisticsTable->setItem(1,3,Bmin);
        ui->statisticsTable->setItem(2,3,Bmax);
        ui->statisticsTable->setItem(3,3,Bmean);
        ui->statisticsTable->setItem(4,3,Bstddev);
        ui->statisticsTable->setItem(5,3,Bvar);
        ui->statisticsTable->setItem(6,3,Bkurtosis);
        ui->statisticsTable->setItem(7,3,Bskew);
    }
}


void DStation::on_actionUse_Deconvolved_Image_as_Reference_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Uses current deconvolved and post processed image as reference
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    LimReferenceImage=Image(postProcessedImageBlob);
    haveReferenceImage=true;
    ui->showReferenceImage->setEnabled(true);
}

void DStation::on_actionSave_Preset_to_Memory_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Saves preset to a temporary file
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    savePresetToFile(QDir::tempPath().append("/temp.d"));
    ui->actionRestore_Preset_From_Memory->setEnabled(true);
}

void DStation::on_actionRestore_Preset_From_Memory_triggered()
{
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //
    // Restores preset from a temporary file
    //
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    openPresetFromFile(QDir::tempPath().append("/temp.d"));
}
