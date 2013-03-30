#ifndef DSTATION_H
#define DSTATION_H

#define VERSION_NUMBER 0.5-alpha5
#define VERSION_STRING_HELPER(X) #X
#define VERSION_STRING(X) VERSION_STRING_HELPER(X)
#define APPNAME "DStation"
#define APPCOPYRIGHTS "Copyright (C) 2013 by Maxim Usatov."
#define TEMPORARY_CONTAINER_FORMAT "TIFF"

#define SIDEBAR_IMAGE_WIDTH 280
#define SIDEBAR_IMAGE_HEIGHT 140
#define PI 3.1415926535897932384626433832795028841968
#define ZOOMSTEP 1.1

// Debug works only on my Mac OS X build environment - should be false when releasing!
#define DEBUG false

#include <QMainWindow>
#include <QGraphicsScene>
#include "Magick++.h"
#include "dgraphicsscene.h"
#include <QDir>

namespace Ui {
    class DStation;
}

using namespace Magick;
using MagickCore::DivideCompositeOp;

class DStation : public QMainWindow
{
    Q_OBJECT

public:
    explicit DStation(QWidget *parent = 0);
    ~DStation();

private:
    Ui::DStation *ui;
    void openImage(const QString &fileName);
    void zoomImage(const double zoom);
    void deconvolve();
    void clearHistogram();
    void showPreview();
    void buildAtmosphericFx(char atmosphericMTF[], const double lambda, const double pixel, const double cutOff, const int r0, const double falpha, const int d, const bool orientation);
    void checkBufferIsValid();
    QImage imageToQImage(const Image tempImage);
    Image deconvolveSwitch(const Image *inputImage, const Image *tmpF, double noise, const double HDRIallowed);
    Image deconvolutionWienerHDRI(const Image *filter, double noise);
    Image deconvolutionWiener_nonHDRI(const Image *inputImage, const Image *filter, double noise);
    Image deconvolutionIterativeWiener_nonHDRI(const Image *inputImage, const Image *filter);
    Image deconvolutionIterativeWienerFDE_nonHDRI(const Image *inputImage, const Image *filter);
    Image deconvolutionLandweber(const Image *inputImage, const Image *filter);
    Image FDEfilter(int width, int height);
    void updateEqualizerImage();
    Image deconvolutionCLS_nonHDRI(const Image *inputImage, const Image *filter, double noise);
    Image deconvolutionVanCittert(const Image *inputImage, const Image *filter);
    Image deconvolutionLR(const Image *inputImage, const Image *filter);
    Image deconvolutionLRConstant(const Image *inputImage, const Image *filter);
    Image deconvolutionMAP(const Image *inputImage, const Image *filter);
    Image deconvolutionMEM(const Image *inputImage, const Image *filter);
    std::vector<double> lowLevel_imageToVector(Image filterImage);
    double lowLevel_chiSquared(Image filterImage);
    Image lowLevel_sineRelaxation(Image filterImage, const double gamma);
    Image smooth(Image filterImage, const double filterSize);
    void displayMagickImageInPSF(const Image imageToDisplay);
    Image lowLevel_compress(Image filterImage, const double ratio, const double threshold);
    Image lowLevel_mirrorRight(Image filterImage, int x_, int y_, int w_, int h_);
    Image lowLevel_mirrorLeft(Image filterImage, int x_, int y_, int w_, int h_);
    Image lowLevel_mirrorUp(Image filterImage, int y_, int h_);
    Image lowLevel_mirrorDown(Image filterImage, int y_, int h_);
    Image lowLevel_negate(Image filterImage);
    Image lowLevel_exponential_decay(Image filterImage, const double sigma);
    Image lowLevel_linear_decay(Image filterImage, const double decay);
    Image lowLevel_radial_gradient(Image filterImage);
    Image lowLevel_exp(Image filterImage, const double factor);
    Image lowLevel_inverse(Image filterImage);
    Image lowLevel_clamp_negatives(Image filterImage);
    Image lowLevel_add(Image filterImage, const double constant);
    Image lowLevel_subtract(Image filterImage, const double constant);
    Image lowLevel_histogram(Image histogramImage, const Image input);
    Image lowLevel_log_histogram(Image histogramImage, const Image input);
    Image lowLevel_log_gain(Image filterImage, const double logFactor, const double gain);
    Image lowLevel_arc(Image filterImage, const double arcFactor);
    Image lowLevel_logPlusOne(Image filterImage);
    Image lowLevel_normalized_log_gain(Image filterImage, const double logFactor, const double gain);
    Image lowLevel_squared_plus_noise(Image filterImage, const double noise);
    Image lowLevel_sqrt(Image filterImage);
    Image lowLevel_power(Image filterImage, const double power);
    Image lowLevel_divide(Image filterImage, const double denominator);
    Image lowLevel_multiply(Image filterImage, const double denominator);
    Image lowLevel_WU(Image atmosphericImage, Image filterImage);
    Image lowLevel_divide_by_image(Image dividedImage, const Image denominatorImage);
    Image lowLevel_log(Image filterImage);
    Image lowLevel_thresholdMax(Image filterImage, const double threshold, std::vector<int>& thresholdPixelMapX, std::vector <int>& thresholdPixelMapY, int& pixelsThresholded);
    Image lowLevel_thresholdMin(Image filterImage, const double threshold);
    Image lowLevel_mixTwoImages(Image filterImage, Image filterImageB, std::vector<int>& thresholdPixelMapX, std::vector<int>& thresholdPixelMapY, int& pixelsThresholded);
    Image lowLevel_mixTwoImagesWithBlur(Image filterImage, Image filterImageB, std::vector<int>& thresholdPixelMapX, std::vector<int>& thresholdPixelMapY, int& pixelsThresholded, int blur);
    void displayMagickImage(const Image imageToDisplay);
    void displayMagickImageInHistogram(const Image imageToDisplay);
    void displayMagickBlob(const Blob imageToDisplay);
    void updateDisplayedImage();
    void postProcessing();
    void checkPreviewSize();
    void updateBriConLabels();
    void trackStatistics();
    void savePresetToFile(QString fileName);
    void openPresetFromFile(QString fileName);
    QString shellCommand(const QString process, const QStringList arguments, const bool debug);
    DGraphicsScene *scene;
    DGraphicsScene *histogramScene;
    DGraphicsScene *equalizerScene;
    DGraphicsScene *PSFScene;
    QString inputImageFileName;
    QString workingDirectory;
    QString OSv;
    Blob processedImageBlob;
    Blob postProcessedImageBlob;
    Blob FFTRealComponentImageBlob;
    Blob filterImageBlob;
    Image processedImage;
    Image processedPreviewImage;
    Image filterImage;
    Image inputImage;
    Image LimReferenceImage;
    Image deringingSupportImage;
    std::list<Image> FFTContainer;
    std::list<Image> PSF_FFTContainer;
    std::list<Image> FFTContainerReference;
    float zoomFactor;
    bool HDRIenabled;
    bool FFTRealComponentShown;
    bool haveExternalFilter;
    char TMPDIR[256];
    int previewX;
    int previewY;
    int previewW;
    int previewH;
    bool previewDeployed;
    bool deconvolvedImageShown;
    bool haveReferenceImage;
    bool haveDeconvolvedImage;
    FilterTypes IMfilters[15];

private slots:
    void on_conDial_valueChanged(int value);
    void on_briDial_valueChanged(int value);
    void on_conDial_sliderReleased();
    void on_briDial_sliderReleased();
    void on_equalizerSlider_6_sliderReleased();
    void on_equalizerSlider_5_sliderReleased();
    void on_equalizerSlider_4_sliderReleased();
    void on_equalizerSlider_3_sliderReleased();
    void on_equalizerSlider_2_sliderReleased();
    void on_equalizerSlider_1_sliderReleased();
    void on_actionDeconvolve_triggered();
    void on_showOnlyInputButton_clicked();
    void on_showReferenceImage_clicked();
    void on_actionLoad_Reference_Image_triggered();
    void on_briConEnabled_stateChanged(int );
    void on_resetBriCon_clicked();
    void on_noiseFilterStrengthSpin_valueChanged(int );
    void on_actionOpen_Preset_triggered();
    void on_actionSave_preset_triggered();
    void on_actionAbout_triggered();
    void on_logarithmicHistogram_stateChanged(int );
    void on_histogramVerticalScale_valueChanged(int );
    void on_redrawHistogramButton_clicked();
    void on_action32x32_triggered();
    void on_action64x64_triggered();
    void on_actionMeasure_NSR_triggered();
    void on_actionBatch_Deconvolve_triggered();
    void on_actionLoad_Filter_Image_triggered();
    void on_actionSave_Filter_As_triggered();
    void on_realTimePostProcessing_stateChanged(int );
    void on_applyPostProcessing_clicked();
    void changePreviewCoordinates();
    void on_action1024x1024_triggered();
    void on_action512x512_triggered();
    void on_action256x256_triggered();
    void on_action128x128_triggered();
    void on_actionRemove_Preview_triggered();
    void on_actionNew_Preview_triggered();
    void on_gaussianBlurSpin_valueChanged(int );
    void on_showFFTMagnitudeButton_clicked();
    void on_enhanceCheckBox_stateChanged(int );
    void on_processingMode_currentIndexChanged(int index);
    void on_deconvolutionAlgorithm_currentIndexChanged(int index);
    void on_postProcessingEnabledCheckBox_stateChanged(int );
    void on_normalizeCheckBox_stateChanged(int );
    void on_dynamicRangeExtensionSpin_valueChanged(int );
    void on_dynamicRangeExtensionSpin_editingFinished();
    void on_actionExit_DStation_triggered();
    void on_showInputButton_released();
    void on_showInputButton_pressed();
    void on_actionSave_Image_As_triggered();
    void on_deconvolveButton_clicked();
    void on_zoomOutButton_clicked();
    void on_zoomFullButton_clicked();
    void on_zoomInButton_clicked();
    void on_actionOpen_Image_triggered();
    void on_filteringMethod_currentIndexChanged(int index);
    void on_actionUse_Deconvolved_Image_as_Reference_triggered();
    void on_actionSave_Preset_to_Memory_triggered();
    void on_actionRestore_Preset_From_Memory_triggered();
};

#endif // DSTATION_H


