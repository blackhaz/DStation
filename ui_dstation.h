/********************************************************************************
** Form generated from reading UI file 'dstation.ui'
**
** Created: Sun Feb 12 21:43:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSTATION_H
#define UI_DSTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DStation
{
public:
    QAction *actionOpen_Image;
    QAction *actionSave_Image_As;
    QAction *actionExit_DStation;
    QAction *actionNew_Preview;
    QAction *actionRemove_Preview;
    QAction *action128x128;
    QAction *action256x256;
    QAction *action512x512;
    QAction *action1024x1024;
    QAction *actionPreview_Sizes;
    QAction *actionSave_Filter_As;
    QAction *actionLoad_Filter_Image;
    QAction *actionBatch_Deconvolve;
    QAction *actionMeasure_NSR;
    QAction *action64x64;
    QAction *action32x32;
    QAction *actionAbout;
    QAction *actionSave_preset;
    QAction *actionOpen_Preset;
    QAction *actionLoad_Reference_Image;
    QAction *actionDeconvolve;
    QAction *actionUse_Deconvolved_Image_as_Reference;
    QAction *actionSave_Preset_to_Memory;
    QAction *actionRestore_Preset_From_Memory;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGraphicsView *imageView;
    QPlainTextEdit *consoleEdit;
    QGridLayout *gridLayout_4;
    QLabel *zoomLabel;
    QToolButton *zoomOutButton;
    QToolButton *zoomInButton;
    QToolButton *zoomFullButton;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *wavelengthRLabel;
    QSpinBox *wavelengthRSpin;
    QLabel *wavelengthGLabel;
    QSpinBox *wavelengthGSpin;
    QLabel *wavelengthBLabel;
    QSpinBox *wavelengthBSpin;
    QLabel *dLabel;
    QSpinBox *dSpin;
    QLabel *fLabel;
    QSpinBox *fSpin;
    QLabel *barlowLabel;
    QDoubleSpinBox *barlowSpin;
    QLabel *pixelLabel;
    QDoubleSpinBox *pixelSpin;
    QFrame *line;
    QLabel *gaussianBlurLabel;
    QSpinBox *gaussianBlurSpin;
    QLabel *r0Label;
    QSpinBox *r0Spin;
    QLabel *noiseLabel;
    QDoubleSpinBox *noiseSpin;
    QLabel *logFactorLabel;
    QDoubleSpinBox *logFactorSpin;
    QLabel *turbulenceModelLabel_2;
    QComboBox *deconvolutionAlgorithm;
    QWidget *tab;
    QToolBox *toolBox_2;
    QWidget *page_9;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QCheckBox *postProcessingEnabledCheckBox;
    QCheckBox *normalizeCheckBox;
    QCheckBox *enhanceCheckBox;
    QToolButton *applyPostProcessing;
    QWidget *layoutWidget;
    QFormLayout *formLayout_3;
    QLabel *dynamicRangeExtensionLabel;
    QSpinBox *dynamicRangeExtensionSpin;
    QLabel *noiseFilterStrengthLabel;
    QSpinBox *noiseFilterStrengthSpin;
    QGraphicsView *histogramView;
    QLabel *zoomLabel_2;
    QToolButton *resetBriCon;
    QToolButton *redrawHistogramButton;
    QLabel *briLabel;
    QCheckBox *briConEnabled;
    QCheckBox *logarithmicHistogram;
    QLabel *conLabel;
    QSpinBox *histogramVerticalScale;
    QSlider *briDial;
    QSlider *conDial;
    QCheckBox *realTimePostProcessing;
    QWidget *tabWidgetPage2;
    QToolBox *toolBox;
    QWidget *page;
    QLabel *supersamplingFilterLabel;
    QComboBox *supersamplingFilter;
    QLabel *supersamplingFilterDownLabel;
    QComboBox *supersamplingFilterDown;
    QLabel *supersamplingFactorLabel;
    QDoubleSpinBox *supersamplingFactorSpin;
    QCheckBox *doNotDownsampleCheckBox;
    QWidget *page_2;
    QComboBox *filteringMethod;
    QLabel *filteringLabel;
    QComboBox *processingMode;
    QLabel *ProcessingModeLabel;
    QLabel *bufferLabel;
    QSpinBox *bufferSpin;
    QLabel *gammaLabel;
    QDoubleSpinBox *gammaSpinBox;
    QLabel *turbulenceModelLabel;
    QComboBox *FriedAlpha;
    QComboBox *smoothingMode;
    QLabel *smoothingFilterLabel_2;
    QWidget *page_3;
    QLabel *supersamplingFactorLabel_2;
    QDoubleSpinBox *LaplacianAlpha;
    QWidget *page_4;
    QLabel *convergenceLabel;
    QLabel *iterationsLabel;
    QSpinBox *iterationsSpin;
    QDoubleSpinBox *convergenceSpin;
    QLabel *iterationsLabel_2;
    QSpinBox *spatialFilterSize;
    QCheckBox *iterativeShowProgress;
    QGraphicsView *PSFView;
    QWidget *page_7;
    QGraphicsView *equalizerView;
    QSlider *equalizerSlider_4;
    QSlider *equalizerSlider_3;
    QSlider *equalizerSlider_1;
    QSlider *equalizerSlider_6;
    QSlider *equalizerSlider_2;
    QSlider *equalizerSlider_5;
    QWidget *page_6;
    QLabel *iterationsLabel_3;
    QDoubleSpinBox *deringingThreshold;
    QLabel *iterationsLabel_4;
    QSpinBox *deringingFactor;
    QCheckBox *deringingEnabledCheckBox;
    QSpinBox *deringingSmoothness;
    QLabel *iterationsLabel_5;
    QCheckBox *deringingSmoothMax;
    QCheckBox *deringingApplyMinThreshold;
    QLabel *smoothingFilterLabel_3;
    QComboBox *deringingSmoothingMode;
    QComboBox *deringingMethod;
    QLabel *smoothingFilterLabel_4;
    QWidget *page_5;
    QCheckBox *trackImageStatisticsCheckBox;
    QTableWidget *statisticsTable;
    QCheckBox *postProcessedImageStatisticsCheckBox;
    QWidget *tab_2;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_6;
    QCheckBox *useHDRI;
    QCheckBox *doNotSaveFilterCheckBox;
    QCheckBox *forceBatchTIFF;
    QCheckBox *stop32bitSpaceExceededCheckBox;
    QCheckBox *subtractBias;
    QComboBox *savedImagePrecision;
    QLabel *savedImagePrecisionLabel;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *deconvolveButton;
    QToolButton *showInputButton;
    QToolButton *showOnlyInputButton;
    QToolButton *showFFTMagnitudeButton;
    QToolButton *showReferenceImage;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPreview;
    QMenu *menuHelp;
    QMenu *menuPreset;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DStation)
    {
        if (DStation->objectName().isEmpty())
            DStation->setObjectName(QString::fromUtf8("DStation"));
        DStation->resize(1076, 885);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DStation->sizePolicy().hasHeightForWidth());
        DStation->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(89, 89, 89, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(69, 69, 69, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(106, 104, 100, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush5(QColor(208, 208, 208, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        DStation->setPalette(palette);
        DStation->setTabShape(QTabWidget::Rounded);
        DStation->setUnifiedTitleAndToolBarOnMac(false);
        actionOpen_Image = new QAction(DStation);
        actionOpen_Image->setObjectName(QString::fromUtf8("actionOpen_Image"));
        actionOpen_Image->setSoftKeyRole(QAction::NoSoftKey);
        actionSave_Image_As = new QAction(DStation);
        actionSave_Image_As->setObjectName(QString::fromUtf8("actionSave_Image_As"));
        actionExit_DStation = new QAction(DStation);
        actionExit_DStation->setObjectName(QString::fromUtf8("actionExit_DStation"));
        actionExit_DStation->setCheckable(false);
        actionNew_Preview = new QAction(DStation);
        actionNew_Preview->setObjectName(QString::fromUtf8("actionNew_Preview"));
        actionNew_Preview->setEnabled(false);
        actionRemove_Preview = new QAction(DStation);
        actionRemove_Preview->setObjectName(QString::fromUtf8("actionRemove_Preview"));
        actionRemove_Preview->setEnabled(false);
        action128x128 = new QAction(DStation);
        action128x128->setObjectName(QString::fromUtf8("action128x128"));
        action128x128->setCheckable(true);
        action128x128->setChecked(false);
        action256x256 = new QAction(DStation);
        action256x256->setObjectName(QString::fromUtf8("action256x256"));
        action256x256->setCheckable(true);
        action256x256->setChecked(true);
        action512x512 = new QAction(DStation);
        action512x512->setObjectName(QString::fromUtf8("action512x512"));
        action512x512->setCheckable(true);
        action1024x1024 = new QAction(DStation);
        action1024x1024->setObjectName(QString::fromUtf8("action1024x1024"));
        action1024x1024->setCheckable(true);
        actionPreview_Sizes = new QAction(DStation);
        actionPreview_Sizes->setObjectName(QString::fromUtf8("actionPreview_Sizes"));
        actionSave_Filter_As = new QAction(DStation);
        actionSave_Filter_As->setObjectName(QString::fromUtf8("actionSave_Filter_As"));
        actionSave_Filter_As->setEnabled(false);
        actionLoad_Filter_Image = new QAction(DStation);
        actionLoad_Filter_Image->setObjectName(QString::fromUtf8("actionLoad_Filter_Image"));
        actionBatch_Deconvolve = new QAction(DStation);
        actionBatch_Deconvolve->setObjectName(QString::fromUtf8("actionBatch_Deconvolve"));
        actionMeasure_NSR = new QAction(DStation);
        actionMeasure_NSR->setObjectName(QString::fromUtf8("actionMeasure_NSR"));
        actionMeasure_NSR->setEnabled(false);
        action64x64 = new QAction(DStation);
        action64x64->setObjectName(QString::fromUtf8("action64x64"));
        action64x64->setCheckable(true);
        action32x32 = new QAction(DStation);
        action32x32->setObjectName(QString::fromUtf8("action32x32"));
        action32x32->setCheckable(true);
        actionAbout = new QAction(DStation);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSave_preset = new QAction(DStation);
        actionSave_preset->setObjectName(QString::fromUtf8("actionSave_preset"));
        actionOpen_Preset = new QAction(DStation);
        actionOpen_Preset->setObjectName(QString::fromUtf8("actionOpen_Preset"));
        actionLoad_Reference_Image = new QAction(DStation);
        actionLoad_Reference_Image->setObjectName(QString::fromUtf8("actionLoad_Reference_Image"));
        actionDeconvolve = new QAction(DStation);
        actionDeconvolve->setObjectName(QString::fromUtf8("actionDeconvolve"));
        actionDeconvolve->setEnabled(false);
        actionUse_Deconvolved_Image_as_Reference = new QAction(DStation);
        actionUse_Deconvolved_Image_as_Reference->setObjectName(QString::fromUtf8("actionUse_Deconvolved_Image_as_Reference"));
        actionUse_Deconvolved_Image_as_Reference->setEnabled(false);
        actionSave_Preset_to_Memory = new QAction(DStation);
        actionSave_Preset_to_Memory->setObjectName(QString::fromUtf8("actionSave_Preset_to_Memory"));
        actionRestore_Preset_From_Memory = new QAction(DStation);
        actionRestore_Preset_From_Memory->setObjectName(QString::fromUtf8("actionRestore_Preset_From_Memory"));
        actionRestore_Preset_From_Memory->setEnabled(false);
        centralWidget = new QWidget(DStation);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        imageView = new QGraphicsView(centralWidget);
        imageView->setObjectName(QString::fromUtf8("imageView"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        QBrush brush6(QColor(212, 208, 200, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        imageView->setPalette(palette1);
        imageView->setDragMode(QGraphicsView::NoDrag);
        imageView->setResizeAnchor(QGraphicsView::NoAnchor);

        gridLayout_5->addWidget(imageView, 0, 0, 1, 1);

        consoleEdit = new QPlainTextEdit(centralWidget);
        consoleEdit->setObjectName(QString::fromUtf8("consoleEdit"));
        consoleEdit->setMaximumSize(QSize(16777215, 128));
        QPalette palette2;
        QBrush brush7(QColor(193, 193, 193, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        QBrush brush8(QColor(48, 48, 48, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        consoleEdit->setPalette(palette2);
        consoleEdit->setUndoRedoEnabled(false);
        consoleEdit->setReadOnly(true);

        gridLayout_5->addWidget(consoleEdit, 3, 0, 3, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setContentsMargins(-1, -1, 0, -1);
        zoomLabel = new QLabel(centralWidget);
        zoomLabel->setObjectName(QString::fromUtf8("zoomLabel"));
        QPalette palette3;
        QBrush brush9(QColor(253, 253, 253, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        QBrush brush10(QColor(87, 87, 87, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        zoomLabel->setPalette(palette3);

        gridLayout_4->addWidget(zoomLabel, 0, 3, 1, 1);

        zoomOutButton = new QToolButton(centralWidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        zoomOutButton->setPalette(palette4);

        gridLayout_4->addWidget(zoomOutButton, 0, 2, 1, 1);

        zoomInButton = new QToolButton(centralWidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        zoomInButton->setPalette(palette5);

        gridLayout_4->addWidget(zoomInButton, 0, 0, 1, 1);

        zoomFullButton = new QToolButton(centralWidget);
        zoomFullButton->setObjectName(QString::fromUtf8("zoomFullButton"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        zoomFullButton->setPalette(palette6);

        gridLayout_4->addWidget(zoomFullButton, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_5->addLayout(horizontalLayout, 1, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(328, 16777215));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 313, 655));
        tabWidget = new QTabWidget(scrollAreaWidgetContents_4);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 300, 600));
        tabWidget->setMinimumSize(QSize(0, 600));
        tabWidget->setMaximumSize(QSize(300, 16777215));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        tabWidget->setPalette(palette7);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        formLayoutWidget = new QWidget(tabWidgetPage1);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 291, 496));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setContentsMargins(0, 0, 0, 0);
        wavelengthRLabel = new QLabel(formLayoutWidget);
        wavelengthRLabel->setObjectName(QString::fromUtf8("wavelengthRLabel"));
        wavelengthRLabel->setEnabled(false);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        wavelengthRLabel->setPalette(palette8);

        formLayout->setWidget(1, QFormLayout::LabelRole, wavelengthRLabel);

        wavelengthRSpin = new QSpinBox(formLayoutWidget);
        wavelengthRSpin->setObjectName(QString::fromUtf8("wavelengthRSpin"));
        wavelengthRSpin->setEnabled(false);
        wavelengthRSpin->setMinimumSize(QSize(90, 0));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        wavelengthRSpin->setPalette(palette9);
        wavelengthRSpin->setMinimum(1);
        wavelengthRSpin->setMaximum(2000);
        wavelengthRSpin->setValue(650);

        formLayout->setWidget(1, QFormLayout::FieldRole, wavelengthRSpin);

        wavelengthGLabel = new QLabel(formLayoutWidget);
        wavelengthGLabel->setObjectName(QString::fromUtf8("wavelengthGLabel"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        wavelengthGLabel->setPalette(palette10);

        formLayout->setWidget(2, QFormLayout::LabelRole, wavelengthGLabel);

        wavelengthGSpin = new QSpinBox(formLayoutWidget);
        wavelengthGSpin->setObjectName(QString::fromUtf8("wavelengthGSpin"));
        wavelengthGSpin->setEnabled(true);
        wavelengthGSpin->setMinimumSize(QSize(90, 0));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        wavelengthGSpin->setPalette(palette11);
        wavelengthGSpin->setMinimum(1);
        wavelengthGSpin->setMaximum(2000);
        wavelengthGSpin->setValue(550);

        formLayout->setWidget(2, QFormLayout::FieldRole, wavelengthGSpin);

        wavelengthBLabel = new QLabel(formLayoutWidget);
        wavelengthBLabel->setObjectName(QString::fromUtf8("wavelengthBLabel"));
        wavelengthBLabel->setEnabled(false);
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        wavelengthBLabel->setPalette(palette12);

        formLayout->setWidget(3, QFormLayout::LabelRole, wavelengthBLabel);

        wavelengthBSpin = new QSpinBox(formLayoutWidget);
        wavelengthBSpin->setObjectName(QString::fromUtf8("wavelengthBSpin"));
        wavelengthBSpin->setEnabled(false);
        wavelengthBSpin->setMinimumSize(QSize(90, 0));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        wavelengthBSpin->setPalette(palette13);
        wavelengthBSpin->setMinimum(1);
        wavelengthBSpin->setMaximum(2000);
        wavelengthBSpin->setValue(450);

        formLayout->setWidget(3, QFormLayout::FieldRole, wavelengthBSpin);

        dLabel = new QLabel(formLayoutWidget);
        dLabel->setObjectName(QString::fromUtf8("dLabel"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        dLabel->setPalette(palette14);

        formLayout->setWidget(4, QFormLayout::LabelRole, dLabel);

        dSpin = new QSpinBox(formLayoutWidget);
        dSpin->setObjectName(QString::fromUtf8("dSpin"));
        dSpin->setMinimumSize(QSize(90, 0));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        dSpin->setPalette(palette15);
        dSpin->setMinimum(1);
        dSpin->setMaximum(2000);
        dSpin->setValue(254);

        formLayout->setWidget(4, QFormLayout::FieldRole, dSpin);

        fLabel = new QLabel(formLayoutWidget);
        fLabel->setObjectName(QString::fromUtf8("fLabel"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        fLabel->setPalette(palette16);

        formLayout->setWidget(5, QFormLayout::LabelRole, fLabel);

        fSpin = new QSpinBox(formLayoutWidget);
        fSpin->setObjectName(QString::fromUtf8("fSpin"));
        fSpin->setMinimumSize(QSize(90, 0));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        fSpin->setPalette(palette17);
        fSpin->setMinimum(1);
        fSpin->setMaximum(50000);
        fSpin->setValue(3800);

        formLayout->setWidget(5, QFormLayout::FieldRole, fSpin);

        barlowLabel = new QLabel(formLayoutWidget);
        barlowLabel->setObjectName(QString::fromUtf8("barlowLabel"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        barlowLabel->setPalette(palette18);

        formLayout->setWidget(6, QFormLayout::LabelRole, barlowLabel);

        barlowSpin = new QDoubleSpinBox(formLayoutWidget);
        barlowSpin->setObjectName(QString::fromUtf8("barlowSpin"));
        barlowSpin->setMinimumSize(QSize(90, 0));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette19.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        barlowSpin->setPalette(palette19);
        barlowSpin->setDecimals(1);
        barlowSpin->setMinimum(0.1);
        barlowSpin->setMaximum(99.9);
        barlowSpin->setSingleStep(0.1);
        barlowSpin->setValue(1);

        formLayout->setWidget(6, QFormLayout::FieldRole, barlowSpin);

        pixelLabel = new QLabel(formLayoutWidget);
        pixelLabel->setObjectName(QString::fromUtf8("pixelLabel"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette20.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pixelLabel->setPalette(palette20);

        formLayout->setWidget(7, QFormLayout::LabelRole, pixelLabel);

        pixelSpin = new QDoubleSpinBox(formLayoutWidget);
        pixelSpin->setObjectName(QString::fromUtf8("pixelSpin"));
        pixelSpin->setMinimumSize(QSize(90, 0));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette21.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pixelSpin->setPalette(palette21);
        pixelSpin->setDecimals(2);
        pixelSpin->setMinimum(0.01);
        pixelSpin->setMaximum(9.99);
        pixelSpin->setSingleStep(0.01);
        pixelSpin->setValue(4.65);

        formLayout->setWidget(7, QFormLayout::FieldRole, pixelSpin);

        line = new QFrame(formLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setMinimumSize(QSize(180, 3));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette22.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette22.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        line->setPalette(palette22);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(9, QFormLayout::LabelRole, line);

        gaussianBlurLabel = new QLabel(formLayoutWidget);
        gaussianBlurLabel->setObjectName(QString::fromUtf8("gaussianBlurLabel"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette23.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette23.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        gaussianBlurLabel->setPalette(palette23);

        formLayout->setWidget(10, QFormLayout::LabelRole, gaussianBlurLabel);

        gaussianBlurSpin = new QSpinBox(formLayoutWidget);
        gaussianBlurSpin->setObjectName(QString::fromUtf8("gaussianBlurSpin"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gaussianBlurSpin->sizePolicy().hasHeightForWidth());
        gaussianBlurSpin->setSizePolicy(sizePolicy2);
        gaussianBlurSpin->setMinimumSize(QSize(90, 0));
        gaussianBlurSpin->setSizeIncrement(QSize(0, 0));
        gaussianBlurSpin->setBaseSize(QSize(0, 0));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette24.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        gaussianBlurSpin->setPalette(palette24);
        gaussianBlurSpin->setAutoFillBackground(false);
        gaussianBlurSpin->setWrapping(false);
        gaussianBlurSpin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        gaussianBlurSpin->setMinimum(1);
        gaussianBlurSpin->setMaximum(500);
        gaussianBlurSpin->setValue(25);

        formLayout->setWidget(10, QFormLayout::FieldRole, gaussianBlurSpin);

        r0Label = new QLabel(formLayoutWidget);
        r0Label->setObjectName(QString::fromUtf8("r0Label"));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette25.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        r0Label->setPalette(palette25);

        formLayout->setWidget(11, QFormLayout::LabelRole, r0Label);

        r0Spin = new QSpinBox(formLayoutWidget);
        r0Spin->setObjectName(QString::fromUtf8("r0Spin"));
        r0Spin->setMinimumSize(QSize(90, 0));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette26.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette26.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        r0Spin->setPalette(palette26);
        r0Spin->setMinimum(1);
        r0Spin->setMaximum(2000);
        r0Spin->setValue(160);

        formLayout->setWidget(11, QFormLayout::FieldRole, r0Spin);

        noiseLabel = new QLabel(formLayoutWidget);
        noiseLabel->setObjectName(QString::fromUtf8("noiseLabel"));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette27.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette27.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        noiseLabel->setPalette(palette27);

        formLayout->setWidget(12, QFormLayout::LabelRole, noiseLabel);

        noiseSpin = new QDoubleSpinBox(formLayoutWidget);
        noiseSpin->setObjectName(QString::fromUtf8("noiseSpin"));
        noiseSpin->setMinimumSize(QSize(90, 0));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette28.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette28.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette28.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette28.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette28.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette28.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        noiseSpin->setPalette(palette28);
        noiseSpin->setDecimals(2);
        noiseSpin->setMinimum(0.01);
        noiseSpin->setMaximum(9999);
        noiseSpin->setSingleStep(0.1);
        noiseSpin->setValue(0.5);

        formLayout->setWidget(12, QFormLayout::FieldRole, noiseSpin);

        logFactorLabel = new QLabel(formLayoutWidget);
        logFactorLabel->setObjectName(QString::fromUtf8("logFactorLabel"));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette29.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette29.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette29.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        logFactorLabel->setPalette(palette29);

        formLayout->setWidget(13, QFormLayout::LabelRole, logFactorLabel);

        logFactorSpin = new QDoubleSpinBox(formLayoutWidget);
        logFactorSpin->setObjectName(QString::fromUtf8("logFactorSpin"));
        sizePolicy2.setHeightForWidth(logFactorSpin->sizePolicy().hasHeightForWidth());
        logFactorSpin->setSizePolicy(sizePolicy2);
        logFactorSpin->setMinimumSize(QSize(90, 0));
        logFactorSpin->setSizeIncrement(QSize(0, 0));
        logFactorSpin->setBaseSize(QSize(0, 0));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette30.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette30.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette30.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        logFactorSpin->setPalette(palette30);
        logFactorSpin->setAutoFillBackground(false);
        logFactorSpin->setWrapping(false);
        logFactorSpin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        logFactorSpin->setMinimum(0.01);
        logFactorSpin->setMaximum(1);
        logFactorSpin->setSingleStep(0.1);
        logFactorSpin->setValue(0.75);

        formLayout->setWidget(13, QFormLayout::FieldRole, logFactorSpin);

        turbulenceModelLabel_2 = new QLabel(tabWidgetPage1);
        turbulenceModelLabel_2->setObjectName(QString::fromUtf8("turbulenceModelLabel_2"));
        turbulenceModelLabel_2->setGeometry(QRect(4, 440, 190, 10));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette31.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette31.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette31.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        turbulenceModelLabel_2->setPalette(palette31);
        deconvolutionAlgorithm = new QComboBox(tabWidgetPage1);
        deconvolutionAlgorithm->setObjectName(QString::fromUtf8("deconvolutionAlgorithm"));
        deconvolutionAlgorithm->setGeometry(QRect(0, 460, 291, 26));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette32.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette32.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette32.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette32.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette32.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette32.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette32.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette32.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette32.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette32.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette32.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette32.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        deconvolutionAlgorithm->setPalette(palette32);
        tabWidget->addTab(tabWidgetPage1, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        toolBox_2 = new QToolBox(tab);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        toolBox_2->setGeometry(QRect(0, 40, 301, 491));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette33.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette33.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette33.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette33.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette33.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette33.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette33.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette33.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette33.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        toolBox_2->setPalette(palette33);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        page_9->setGeometry(QRect(0, 0, 301, 457));
        formLayoutWidget_2 = new QWidget(page_9);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 0, 301, 91));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        postProcessingEnabledCheckBox = new QCheckBox(formLayoutWidget_2);
        postProcessingEnabledCheckBox->setObjectName(QString::fromUtf8("postProcessingEnabledCheckBox"));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette34.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette34.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette34.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette34.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette34.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette34.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette34.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette34.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette34.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette34.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette34.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette34.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        postProcessingEnabledCheckBox->setPalette(palette34);
        postProcessingEnabledCheckBox->setChecked(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, postProcessingEnabledCheckBox);

        normalizeCheckBox = new QCheckBox(formLayoutWidget_2);
        normalizeCheckBox->setObjectName(QString::fromUtf8("normalizeCheckBox"));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette35.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette35.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette35.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette35.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette35.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette35.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette35.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette35.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette35.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette35.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette35.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette35.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette35.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette35.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        normalizeCheckBox->setPalette(palette35);
        normalizeCheckBox->setChecked(true);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, normalizeCheckBox);

        enhanceCheckBox = new QCheckBox(formLayoutWidget_2);
        enhanceCheckBox->setObjectName(QString::fromUtf8("enhanceCheckBox"));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette36.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette36.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette36.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette36.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette36.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette36.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette36.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette36.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette36.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette36.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette36.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette36.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette36.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette36.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        enhanceCheckBox->setPalette(palette36);
        enhanceCheckBox->setChecked(false);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, enhanceCheckBox);

        applyPostProcessing = new QToolButton(formLayoutWidget_2);
        applyPostProcessing->setObjectName(QString::fromUtf8("applyPostProcessing"));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush12(QColor(188, 188, 188, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette37.setBrush(QPalette::Active, QPalette::Button, brush12);
        palette37.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush13(QColor(221, 221, 221, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette37.setBrush(QPalette::Active, QPalette::Midlight, brush13);
        QBrush brush14(QColor(94, 94, 94, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette37.setBrush(QPalette::Active, QPalette::Dark, brush14);
        QBrush brush15(QColor(125, 125, 125, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette37.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette37.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette37.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette37.setBrush(QPalette::Active, QPalette::Base, brush);
        palette37.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette37.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette37.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette37.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette37.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette37.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::Midlight, brush13);
        palette37.setBrush(QPalette::Inactive, QPalette::Dark, brush14);
        palette37.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette37.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette37.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette37.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette37.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette37.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette37.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette37.setBrush(QPalette::Disabled, QPalette::Midlight, brush13);
        palette37.setBrush(QPalette::Disabled, QPalette::Dark, brush14);
        palette37.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette37.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette37.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette37.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette37.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette37.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette37.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette37.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette37.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        applyPostProcessing->setPalette(palette37);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, applyPostProcessing);

        layoutWidget = new QWidget(page_9);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 90, 301, 71));
        formLayout_3 = new QFormLayout(layoutWidget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        dynamicRangeExtensionLabel = new QLabel(layoutWidget);
        dynamicRangeExtensionLabel->setObjectName(QString::fromUtf8("dynamicRangeExtensionLabel"));
        dynamicRangeExtensionLabel->setEnabled(false);
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette38.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette38.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette38.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette38.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette38.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette38.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette38.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette38.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette38.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette38.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette38.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette38.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette38.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette38.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette38.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette38.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette38.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette38.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette38.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette38.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette38.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        dynamicRangeExtensionLabel->setPalette(palette38);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, dynamicRangeExtensionLabel);

        dynamicRangeExtensionSpin = new QSpinBox(layoutWidget);
        dynamicRangeExtensionSpin->setObjectName(QString::fromUtf8("dynamicRangeExtensionSpin"));
        dynamicRangeExtensionSpin->setEnabled(false);
        sizePolicy2.setHeightForWidth(dynamicRangeExtensionSpin->sizePolicy().hasHeightForWidth());
        dynamicRangeExtensionSpin->setSizePolicy(sizePolicy2);
        dynamicRangeExtensionSpin->setMinimumSize(QSize(75, 0));
        dynamicRangeExtensionSpin->setSizeIncrement(QSize(0, 0));
        dynamicRangeExtensionSpin->setBaseSize(QSize(0, 0));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette39.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette39.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette39.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette39.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette39.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette39.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette39.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette39.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette39.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette39.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette39.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette39.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette39.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette39.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        dynamicRangeExtensionSpin->setPalette(palette39);
        dynamicRangeExtensionSpin->setAutoFillBackground(false);
        dynamicRangeExtensionSpin->setWrapping(false);
        dynamicRangeExtensionSpin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dynamicRangeExtensionSpin->setMinimum(0);
        dynamicRangeExtensionSpin->setMaximum(99);
        dynamicRangeExtensionSpin->setSingleStep(10);
        dynamicRangeExtensionSpin->setValue(0);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dynamicRangeExtensionSpin);

        noiseFilterStrengthLabel = new QLabel(layoutWidget);
        noiseFilterStrengthLabel->setObjectName(QString::fromUtf8("noiseFilterStrengthLabel"));
        noiseFilterStrengthLabel->setEnabled(true);
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette40.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette40.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette40.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette40.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette40.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette40.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette40.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette40.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette40.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette40.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette40.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette40.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette40.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette40.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        noiseFilterStrengthLabel->setPalette(palette40);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, noiseFilterStrengthLabel);

        noiseFilterStrengthSpin = new QSpinBox(layoutWidget);
        noiseFilterStrengthSpin->setObjectName(QString::fromUtf8("noiseFilterStrengthSpin"));
        noiseFilterStrengthSpin->setEnabled(true);
        sizePolicy2.setHeightForWidth(noiseFilterStrengthSpin->sizePolicy().hasHeightForWidth());
        noiseFilterStrengthSpin->setSizePolicy(sizePolicy2);
        noiseFilterStrengthSpin->setMinimumSize(QSize(75, 0));
        noiseFilterStrengthSpin->setSizeIncrement(QSize(0, 0));
        noiseFilterStrengthSpin->setBaseSize(QSize(0, 0));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette41.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette41.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette41.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette41.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette41.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette41.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette41.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette41.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette41.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette41.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette41.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette41.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette41.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette41.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        noiseFilterStrengthSpin->setPalette(palette41);
        noiseFilterStrengthSpin->setAutoFillBackground(false);
        noiseFilterStrengthSpin->setWrapping(false);
        noiseFilterStrengthSpin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        noiseFilterStrengthSpin->setMinimum(0);
        noiseFilterStrengthSpin->setMaximum(99);
        noiseFilterStrengthSpin->setSingleStep(10);
        noiseFilterStrengthSpin->setValue(50);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, noiseFilterStrengthSpin);

        histogramView = new QGraphicsView(page_9);
        histogramView->setObjectName(QString::fromUtf8("histogramView"));
        histogramView->setGeometry(QRect(0, 160, 291, 151));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette42.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette42.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        histogramView->setPalette(palette42);
        zoomLabel_2 = new QLabel(page_9);
        zoomLabel_2->setObjectName(QString::fromUtf8("zoomLabel_2"));
        zoomLabel_2->setGeometry(QRect(70, 320, 97, 23));
        QPalette palette43;
        palette43.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette43.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette43.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette43.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette43.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette43.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette43.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette43.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette43.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette43.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette43.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette43.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette43.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette43.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette43.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        zoomLabel_2->setPalette(palette43);
        resetBriCon = new QToolButton(page_9);
        resetBriCon->setObjectName(QString::fromUtf8("resetBriCon"));
        resetBriCon->setGeometry(QRect(0, 400, 51, 23));
        QPalette palette44;
        palette44.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush16(QColor(192, 192, 192, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette44.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette44.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush17(QColor(223, 223, 223, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette44.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        QBrush brush18(QColor(96, 96, 96, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette44.setBrush(QPalette::Active, QPalette::Dark, brush18);
        QBrush brush19(QColor(128, 128, 128, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette44.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette44.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette44.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette44.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette44.setBrush(QPalette::Active, QPalette::Base, brush);
        palette44.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette44.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette44.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette44.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette44.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette44.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette44.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette44.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette44.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        palette44.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette44.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette44.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette44.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette44.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette44.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette44.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette44.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette44.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette44.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette44.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette44.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette44.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette44.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette44.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette44.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette44.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        resetBriCon->setPalette(palette44);
        redrawHistogramButton = new QToolButton(page_9);
        redrawHistogramButton->setObjectName(QString::fromUtf8("redrawHistogramButton"));
        redrawHistogramButton->setGeometry(QRect(0, 320, 51, 23));
        QPalette palette45;
        palette45.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette45.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette45.setBrush(QPalette::Active, QPalette::Light, brush);
        palette45.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        palette45.setBrush(QPalette::Active, QPalette::Dark, brush18);
        palette45.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette45.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette45.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette45.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette45.setBrush(QPalette::Active, QPalette::Base, brush);
        palette45.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette45.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette45.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette45.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette45.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette45.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette45.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette45.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette45.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        palette45.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette45.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette45.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette45.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette45.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette45.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette45.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette45.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette45.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette45.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette45.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette45.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette45.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette45.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette45.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette45.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette45.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        redrawHistogramButton->setPalette(palette45);
        briLabel = new QLabel(page_9);
        briLabel->setObjectName(QString::fromUtf8("briLabel"));
        briLabel->setGeometry(QRect(220, 350, 61, 23));
        QPalette palette46;
        palette46.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette46.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette46.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette46.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette46.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette46.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette46.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette46.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette46.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette46.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette46.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette46.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette46.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette46.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette46.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        briLabel->setPalette(palette46);
        briConEnabled = new QCheckBox(page_9);
        briConEnabled->setObjectName(QString::fromUtf8("briConEnabled"));
        briConEnabled->setGeometry(QRect(60, 400, 231, 20));
        QPalette palette47;
        palette47.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette47.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette47.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette47.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette47.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette47.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette47.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette47.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette47.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette47.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette47.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette47.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette47.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette47.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette47.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        briConEnabled->setPalette(palette47);
        briConEnabled->setChecked(true);
        logarithmicHistogram = new QCheckBox(page_9);
        logarithmicHistogram->setObjectName(QString::fromUtf8("logarithmicHistogram"));
        logarithmicHistogram->setGeometry(QRect(230, 320, 90, 20));
        QPalette palette48;
        palette48.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette48.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette48.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette48.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette48.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette48.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette48.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette48.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette48.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette48.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette48.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette48.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette48.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette48.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette48.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        logarithmicHistogram->setPalette(palette48);
        logarithmicHistogram->setChecked(true);
        conLabel = new QLabel(page_9);
        conLabel->setObjectName(QString::fromUtf8("conLabel"));
        conLabel->setGeometry(QRect(220, 370, 71, 23));
        QPalette palette49;
        palette49.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette49.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette49.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette49.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette49.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette49.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette49.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette49.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette49.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette49.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette49.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette49.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette49.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette49.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette49.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        conLabel->setPalette(palette49);
        histogramVerticalScale = new QSpinBox(page_9);
        histogramVerticalScale->setObjectName(QString::fromUtf8("histogramVerticalScale"));
        histogramVerticalScale->setGeometry(QRect(160, 320, 57, 25));
        QPalette palette50;
        palette50.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette50.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette50.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette50.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette50.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette50.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette50.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette50.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette50.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette50.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette50.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette50.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette50.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette50.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette50.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        histogramVerticalScale->setPalette(palette50);
        histogramVerticalScale->setMinimum(1);
        briDial = new QSlider(page_9);
        briDial->setObjectName(QString::fromUtf8("briDial"));
        briDial->setGeometry(QRect(0, 350, 211, 22));
        briDial->setMaximum(200);
        briDial->setValue(100);
        briDial->setOrientation(Qt::Horizontal);
        conDial = new QSlider(page_9);
        conDial->setObjectName(QString::fromUtf8("conDial"));
        conDial->setGeometry(QRect(0, 370, 211, 22));
        conDial->setMinimum(0);
        conDial->setMaximum(200);
        conDial->setValue(100);
        conDial->setOrientation(Qt::Horizontal);
        toolBox_2->addItem(page_9, QString::fromUtf8("Basic Post-Processing"));
        realTimePostProcessing = new QCheckBox(tab);
        realTimePostProcessing->setObjectName(QString::fromUtf8("realTimePostProcessing"));
        realTimePostProcessing->setGeometry(QRect(0, 10, 271, 20));
        QPalette palette51;
        palette51.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette51.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette51.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette51.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette51.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette51.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette51.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette51.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette51.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette51.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette51.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette51.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette51.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette51.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette51.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        realTimePostProcessing->setPalette(palette51);
        realTimePostProcessing->setChecked(true);
        tabWidget->addTab(tab, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        toolBox = new QToolBox(tabWidgetPage2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 10, 301, 561));
        QPalette palette52;
        palette52.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette52.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette52.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette52.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette52.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette52.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette52.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette52.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette52.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette52.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette52.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette52.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette52.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette52.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette52.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette52.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette52.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette52.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        toolBox->setPalette(palette52);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 98, 28));
        supersamplingFilterLabel = new QLabel(page);
        supersamplingFilterLabel->setObjectName(QString::fromUtf8("supersamplingFilterLabel"));
        supersamplingFilterLabel->setGeometry(QRect(10, 0, 191, 25));
        supersamplingFilter = new QComboBox(page);
        supersamplingFilter->setObjectName(QString::fromUtf8("supersamplingFilter"));
        supersamplingFilter->setGeometry(QRect(10, 20, 281, 26));
        supersamplingFilter->setFrame(true);
        supersamplingFilterDownLabel = new QLabel(page);
        supersamplingFilterDownLabel->setObjectName(QString::fromUtf8("supersamplingFilterDownLabel"));
        supersamplingFilterDownLabel->setGeometry(QRect(10, 50, 191, 25));
        supersamplingFilterDown = new QComboBox(page);
        supersamplingFilterDown->setObjectName(QString::fromUtf8("supersamplingFilterDown"));
        supersamplingFilterDown->setGeometry(QRect(10, 70, 281, 26));
        supersamplingFilterDown->setFrame(true);
        supersamplingFactorLabel = new QLabel(page);
        supersamplingFactorLabel->setObjectName(QString::fromUtf8("supersamplingFactorLabel"));
        supersamplingFactorLabel->setGeometry(QRect(70, 120, 136, 25));
        supersamplingFactorSpin = new QDoubleSpinBox(page);
        supersamplingFactorSpin->setObjectName(QString::fromUtf8("supersamplingFactorSpin"));
        supersamplingFactorSpin->setGeometry(QRect(210, 120, 75, 25));
        supersamplingFactorSpin->setMinimumSize(QSize(75, 0));
        supersamplingFactorSpin->setMinimum(1);
        supersamplingFactorSpin->setValue(1);
        doNotDownsampleCheckBox = new QCheckBox(page);
        doNotDownsampleCheckBox->setObjectName(QString::fromUtf8("doNotDownsampleCheckBox"));
        doNotDownsampleCheckBox->setGeometry(QRect(10, 170, 284, 20));
        doNotDownsampleCheckBox->setChecked(false);
        toolBox->addItem(page, QString::fromUtf8("Supersampling"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 301, 323));
        filteringMethod = new QComboBox(page_2);
        filteringMethod->setObjectName(QString::fromUtf8("filteringMethod"));
        filteringMethod->setGeometry(QRect(0, 20, 291, 26));
        QPalette palette53;
        palette53.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette53.setBrush(QPalette::Active, QPalette::Text, brush);
        palette53.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette53.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette53.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette53.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette53.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette53.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette53.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette53.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette53.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette53.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        filteringMethod->setPalette(palette53);
        filteringLabel = new QLabel(page_2);
        filteringLabel->setObjectName(QString::fromUtf8("filteringLabel"));
        filteringLabel->setGeometry(QRect(0, 0, 191, 25));
        processingMode = new QComboBox(page_2);
        processingMode->setObjectName(QString::fromUtf8("processingMode"));
        processingMode->setGeometry(QRect(0, 70, 291, 26));
        QPalette palette54;
        palette54.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette54.setBrush(QPalette::Active, QPalette::Text, brush);
        palette54.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette54.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette54.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette54.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette54.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette54.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette54.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette54.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette54.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette54.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        processingMode->setPalette(palette54);
        ProcessingModeLabel = new QLabel(page_2);
        ProcessingModeLabel->setObjectName(QString::fromUtf8("ProcessingModeLabel"));
        ProcessingModeLabel->setGeometry(QRect(0, 50, 141, 25));
        bufferLabel = new QLabel(page_2);
        bufferLabel->setObjectName(QString::fromUtf8("bufferLabel"));
        bufferLabel->setGeometry(QRect(50, 210, 165, 25));
        bufferSpin = new QSpinBox(page_2);
        bufferSpin->setObjectName(QString::fromUtf8("bufferSpin"));
        bufferSpin->setEnabled(true);
        bufferSpin->setGeometry(QRect(220, 210, 75, 25));
        bufferSpin->setMinimumSize(QSize(75, 0));
        bufferSpin->setMaximum(5000);
        bufferSpin->setValue(20);
        gammaLabel = new QLabel(page_2);
        gammaLabel->setObjectName(QString::fromUtf8("gammaLabel"));
        gammaLabel->setEnabled(true);
        gammaLabel->setGeometry(QRect(34, 240, 181, 25));
        gammaSpinBox = new QDoubleSpinBox(page_2);
        gammaSpinBox->setObjectName(QString::fromUtf8("gammaSpinBox"));
        gammaSpinBox->setGeometry(QRect(220, 240, 75, 25));
        gammaSpinBox->setMinimumSize(QSize(75, 0));
        gammaSpinBox->setDecimals(2);
        gammaSpinBox->setMinimum(0);
        gammaSpinBox->setMaximum(1);
        gammaSpinBox->setSingleStep(0.1);
        gammaSpinBox->setValue(0.5);
        turbulenceModelLabel = new QLabel(page_2);
        turbulenceModelLabel->setObjectName(QString::fromUtf8("turbulenceModelLabel"));
        turbulenceModelLabel->setGeometry(QRect(0, 100, 141, 25));
        FriedAlpha = new QComboBox(page_2);
        FriedAlpha->setObjectName(QString::fromUtf8("FriedAlpha"));
        FriedAlpha->setGeometry(QRect(0, 120, 291, 26));
        QPalette palette55;
        palette55.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette55.setBrush(QPalette::Active, QPalette::Text, brush);
        palette55.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette55.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette55.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette55.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette55.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette55.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette55.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette55.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette55.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette55.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        FriedAlpha->setPalette(palette55);
        smoothingMode = new QComboBox(page_2);
        smoothingMode->setObjectName(QString::fromUtf8("smoothingMode"));
        smoothingMode->setGeometry(QRect(0, 170, 291, 26));
        QPalette palette56;
        palette56.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette56.setBrush(QPalette::Active, QPalette::Text, brush);
        palette56.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette56.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette56.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette56.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette56.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette56.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette56.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette56.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette56.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette56.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        smoothingMode->setPalette(palette56);
        smoothingFilterLabel_2 = new QLabel(page_2);
        smoothingFilterLabel_2->setObjectName(QString::fromUtf8("smoothingFilterLabel_2"));
        smoothingFilterLabel_2->setGeometry(QRect(0, 150, 241, 25));
        toolBox->addItem(page_2, QString::fromUtf8("Deconvolution and Filtering"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 98, 28));
        supersamplingFactorLabel_2 = new QLabel(page_3);
        supersamplingFactorLabel_2->setObjectName(QString::fromUtf8("supersamplingFactorLabel_2"));
        supersamplingFactorLabel_2->setGeometry(QRect(80, 10, 141, 25));
        LaplacianAlpha = new QDoubleSpinBox(page_3);
        LaplacianAlpha->setObjectName(QString::fromUtf8("LaplacianAlpha"));
        LaplacianAlpha->setGeometry(QRect(223, 10, 75, 25));
        LaplacianAlpha->setMinimumSize(QSize(75, 0));
        LaplacianAlpha->setDecimals(2);
        LaplacianAlpha->setMinimum(0);
        LaplacianAlpha->setMaximum(9);
        LaplacianAlpha->setSingleStep(0.1);
        LaplacianAlpha->setValue(0.25);
        toolBox->addItem(page_3, QString::fromUtf8("CLS Deconvolution"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 98, 28));
        convergenceLabel = new QLabel(page_4);
        convergenceLabel->setObjectName(QString::fromUtf8("convergenceLabel"));
        convergenceLabel->setGeometry(QRect(30, 40, 191, 25));
        iterationsLabel = new QLabel(page_4);
        iterationsLabel->setObjectName(QString::fromUtf8("iterationsLabel"));
        iterationsLabel->setGeometry(QRect(152, 5, 60, 25));
        iterationsSpin = new QSpinBox(page_4);
        iterationsSpin->setObjectName(QString::fromUtf8("iterationsSpin"));
        iterationsSpin->setGeometry(QRect(220, 5, 75, 25));
        sizePolicy2.setHeightForWidth(iterationsSpin->sizePolicy().hasHeightForWidth());
        iterationsSpin->setSizePolicy(sizePolicy2);
        iterationsSpin->setMinimumSize(QSize(75, 0));
        iterationsSpin->setSizeIncrement(QSize(0, 0));
        iterationsSpin->setBaseSize(QSize(0, 0));
        iterationsSpin->setAutoFillBackground(false);
        iterationsSpin->setWrapping(false);
        iterationsSpin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        iterationsSpin->setMinimum(1);
        iterationsSpin->setMaximum(5000);
        iterationsSpin->setValue(5);
        convergenceSpin = new QDoubleSpinBox(page_4);
        convergenceSpin->setObjectName(QString::fromUtf8("convergenceSpin"));
        convergenceSpin->setGeometry(QRect(220, 40, 75, 25));
        convergenceSpin->setMinimumSize(QSize(75, 0));
        convergenceSpin->setDecimals(3);
        convergenceSpin->setMinimum(0);
        convergenceSpin->setMaximum(9);
        convergenceSpin->setSingleStep(0.01);
        convergenceSpin->setValue(1);
        iterationsLabel_2 = new QLabel(page_4);
        iterationsLabel_2->setObjectName(QString::fromUtf8("iterationsLabel_2"));
        iterationsLabel_2->setGeometry(QRect(59, 75, 151, 25));
        spatialFilterSize = new QSpinBox(page_4);
        spatialFilterSize->setObjectName(QString::fromUtf8("spatialFilterSize"));
        spatialFilterSize->setGeometry(QRect(218, 75, 75, 25));
        sizePolicy2.setHeightForWidth(spatialFilterSize->sizePolicy().hasHeightForWidth());
        spatialFilterSize->setSizePolicy(sizePolicy2);
        spatialFilterSize->setMinimumSize(QSize(75, 0));
        spatialFilterSize->setSizeIncrement(QSize(0, 0));
        spatialFilterSize->setBaseSize(QSize(0, 0));
        spatialFilterSize->setAutoFillBackground(false);
        spatialFilterSize->setWrapping(false);
        spatialFilterSize->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spatialFilterSize->setMinimum(3);
        spatialFilterSize->setMaximum(256);
        spatialFilterSize->setValue(11);
        iterativeShowProgress = new QCheckBox(page_4);
        iterativeShowProgress->setObjectName(QString::fromUtf8("iterativeShowProgress"));
        iterativeShowProgress->setGeometry(QRect(10, 120, 284, 20));
        iterativeShowProgress->setChecked(false);
        PSFView = new QGraphicsView(page_4);
        PSFView->setObjectName(QString::fromUtf8("PSFView"));
        PSFView->setGeometry(QRect(10, 150, 91, 91));
        QPalette palette57;
        palette57.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette57.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette57.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        PSFView->setPalette(palette57);
        PSFView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PSFView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PSFView->setDragMode(QGraphicsView::NoDrag);
        PSFView->setResizeAnchor(QGraphicsView::NoAnchor);
        toolBox->addItem(page_4, QString::fromUtf8("Iterative Deconvolution"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 98, 28));
        equalizerView = new QGraphicsView(page_7);
        equalizerView->setObjectName(QString::fromUtf8("equalizerView"));
        equalizerView->setGeometry(QRect(0, 0, 291, 151));
        QPalette palette58;
        palette58.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette58.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette58.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        equalizerView->setPalette(palette58);
        equalizerSlider_4 = new QSlider(page_7);
        equalizerSlider_4->setObjectName(QString::fromUtf8("equalizerSlider_4"));
        equalizerSlider_4->setGeometry(QRect(160, 160, 22, 161));
        equalizerSlider_4->setMaximum(100);
        equalizerSlider_4->setSliderPosition(50);
        equalizerSlider_4->setOrientation(Qt::Vertical);
        equalizerSlider_4->setTickPosition(QSlider::TicksBothSides);
        equalizerSlider_3 = new QSlider(page_7);
        equalizerSlider_3->setObjectName(QString::fromUtf8("equalizerSlider_3"));
        equalizerSlider_3->setGeometry(QRect(110, 160, 22, 161));
        equalizerSlider_3->setMaximum(100);
        equalizerSlider_3->setSliderPosition(50);
        equalizerSlider_3->setOrientation(Qt::Vertical);
        equalizerSlider_3->setTickPosition(QSlider::TicksBothSides);
        equalizerSlider_1 = new QSlider(page_7);
        equalizerSlider_1->setObjectName(QString::fromUtf8("equalizerSlider_1"));
        equalizerSlider_1->setGeometry(QRect(10, 160, 22, 161));
        equalizerSlider_1->setMaximum(100);
        equalizerSlider_1->setValue(50);
        equalizerSlider_1->setSliderPosition(50);
        equalizerSlider_1->setOrientation(Qt::Vertical);
        equalizerSlider_1->setTickPosition(QSlider::TicksBothSides);
        equalizerSlider_6 = new QSlider(page_7);
        equalizerSlider_6->setObjectName(QString::fromUtf8("equalizerSlider_6"));
        equalizerSlider_6->setGeometry(QRect(260, 160, 22, 161));
        equalizerSlider_6->setMaximum(100);
        equalizerSlider_6->setSliderPosition(50);
        equalizerSlider_6->setOrientation(Qt::Vertical);
        equalizerSlider_6->setTickPosition(QSlider::TicksBothSides);
        equalizerSlider_2 = new QSlider(page_7);
        equalizerSlider_2->setObjectName(QString::fromUtf8("equalizerSlider_2"));
        equalizerSlider_2->setGeometry(QRect(60, 160, 22, 161));
        equalizerSlider_2->setMaximum(100);
        equalizerSlider_2->setSliderPosition(50);
        equalizerSlider_2->setOrientation(Qt::Vertical);
        equalizerSlider_2->setTickPosition(QSlider::TicksBothSides);
        equalizerSlider_5 = new QSlider(page_7);
        equalizerSlider_5->setObjectName(QString::fromUtf8("equalizerSlider_5"));
        equalizerSlider_5->setGeometry(QRect(210, 160, 22, 161));
        equalizerSlider_5->setMaximum(100);
        equalizerSlider_5->setSliderPosition(50);
        equalizerSlider_5->setOrientation(Qt::Vertical);
        equalizerSlider_5->setTickPosition(QSlider::TicksBothSides);
        toolBox->addItem(page_7, QString::fromUtf8("Frequency Domain Equalizer"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 98, 28));
        iterationsLabel_3 = new QLabel(page_6);
        iterationsLabel_3->setObjectName(QString::fromUtf8("iterationsLabel_3"));
        iterationsLabel_3->setGeometry(QRect(50, 120, 171, 25));
        deringingThreshold = new QDoubleSpinBox(page_6);
        deringingThreshold->setObjectName(QString::fromUtf8("deringingThreshold"));
        deringingThreshold->setGeometry(QRect(220, 120, 75, 25));
        deringingThreshold->setMinimumSize(QSize(75, 0));
        deringingThreshold->setDecimals(2);
        deringingThreshold->setMinimum(0.01);
        deringingThreshold->setMaximum(0.99);
        deringingThreshold->setSingleStep(0.05);
        deringingThreshold->setValue(0.25);
        iterationsLabel_4 = new QLabel(page_6);
        iterationsLabel_4->setObjectName(QString::fromUtf8("iterationsLabel_4"));
        iterationsLabel_4->setGeometry(QRect(170, 150, 51, 25));
        deringingFactor = new QSpinBox(page_6);
        deringingFactor->setObjectName(QString::fromUtf8("deringingFactor"));
        deringingFactor->setEnabled(true);
        deringingFactor->setGeometry(QRect(220, 150, 75, 25));
        deringingFactor->setMinimumSize(QSize(75, 0));
        deringingFactor->setMinimum(1);
        deringingFactor->setMaximum(5000);
        deringingFactor->setValue(20);
        deringingEnabledCheckBox = new QCheckBox(page_6);
        deringingEnabledCheckBox->setObjectName(QString::fromUtf8("deringingEnabledCheckBox"));
        deringingEnabledCheckBox->setGeometry(QRect(0, 0, 284, 20));
        deringingEnabledCheckBox->setChecked(false);
        deringingSmoothness = new QSpinBox(page_6);
        deringingSmoothness->setObjectName(QString::fromUtf8("deringingSmoothness"));
        deringingSmoothness->setEnabled(true);
        deringingSmoothness->setGeometry(QRect(220, 180, 75, 25));
        deringingSmoothness->setMinimumSize(QSize(75, 0));
        deringingSmoothness->setMinimum(0);
        deringingSmoothness->setMaximum(5000);
        deringingSmoothness->setValue(20);
        iterationsLabel_5 = new QLabel(page_6);
        iterationsLabel_5->setObjectName(QString::fromUtf8("iterationsLabel_5"));
        iterationsLabel_5->setGeometry(QRect(134, 180, 81, 25));
        deringingSmoothMax = new QCheckBox(page_6);
        deringingSmoothMax->setObjectName(QString::fromUtf8("deringingSmoothMax"));
        deringingSmoothMax->setGeometry(QRect(0, 210, 284, 20));
        deringingSmoothMax->setChecked(true);
        deringingApplyMinThreshold = new QCheckBox(page_6);
        deringingApplyMinThreshold->setObjectName(QString::fromUtf8("deringingApplyMinThreshold"));
        deringingApplyMinThreshold->setGeometry(QRect(0, 230, 284, 20));
        deringingApplyMinThreshold->setChecked(false);
        smoothingFilterLabel_3 = new QLabel(page_6);
        smoothingFilterLabel_3->setObjectName(QString::fromUtf8("smoothingFilterLabel_3"));
        smoothingFilterLabel_3->setGeometry(QRect(0, 70, 241, 25));
        deringingSmoothingMode = new QComboBox(page_6);
        deringingSmoothingMode->setObjectName(QString::fromUtf8("deringingSmoothingMode"));
        deringingSmoothingMode->setGeometry(QRect(0, 90, 291, 26));
        QPalette palette59;
        palette59.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette59.setBrush(QPalette::Active, QPalette::Text, brush);
        palette59.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette59.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette59.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette59.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette59.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette59.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette59.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette59.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette59.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette59.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        deringingSmoothingMode->setPalette(palette59);
        deringingMethod = new QComboBox(page_6);
        deringingMethod->setObjectName(QString::fromUtf8("deringingMethod"));
        deringingMethod->setGeometry(QRect(0, 40, 291, 26));
        QPalette palette60;
        palette60.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette60.setBrush(QPalette::Active, QPalette::Text, brush);
        palette60.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette60.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette60.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette60.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette60.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette60.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette60.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette60.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette60.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette60.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette60.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette60.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette60.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        deringingMethod->setPalette(palette60);
        smoothingFilterLabel_4 = new QLabel(page_6);
        smoothingFilterLabel_4->setObjectName(QString::fromUtf8("smoothingFilterLabel_4"));
        smoothingFilterLabel_4->setGeometry(QRect(0, 20, 241, 25));
        toolBox->addItem(page_6, QString::fromUtf8("Deringing"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 98, 28));
        trackImageStatisticsCheckBox = new QCheckBox(page_5);
        trackImageStatisticsCheckBox->setObjectName(QString::fromUtf8("trackImageStatisticsCheckBox"));
        trackImageStatisticsCheckBox->setGeometry(QRect(0, 10, 284, 20));
        trackImageStatisticsCheckBox->setChecked(true);
        statisticsTable = new QTableWidget(page_5);
        if (statisticsTable->columnCount() < 4)
            statisticsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        statisticsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (statisticsTable->rowCount() < 8)
            statisticsTable->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        statisticsTable->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        statisticsTable->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        statisticsTable->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        statisticsTable->setItem(0, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        statisticsTable->setItem(1, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        statisticsTable->setItem(2, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        statisticsTable->setItem(3, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        statisticsTable->setItem(4, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        statisticsTable->setItem(5, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        statisticsTable->setItem(6, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        statisticsTable->setItem(7, 0, __qtablewidgetitem21);
        statisticsTable->setObjectName(QString::fromUtf8("statisticsTable"));
        statisticsTable->setGeometry(QRect(0, 80, 301, 271));
        QPalette palette61;
        palette61.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette61.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette61.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette61.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette61.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette61.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        statisticsTable->setPalette(palette61);
        statisticsTable->setFrameShape(QFrame::NoFrame);
        statisticsTable->setFrameShadow(QFrame::Sunken);
        statisticsTable->setShowGrid(true);
        statisticsTable->setGridStyle(Qt::DashLine);
        statisticsTable->setSortingEnabled(false);
        statisticsTable->setWordWrap(true);
        statisticsTable->setCornerButtonEnabled(true);
        statisticsTable->horizontalHeader()->setVisible(false);
        statisticsTable->horizontalHeader()->setCascadingSectionResizes(false);
        statisticsTable->horizontalHeader()->setDefaultSectionSize(75);
        statisticsTable->horizontalHeader()->setHighlightSections(true);
        statisticsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        statisticsTable->horizontalHeader()->setStretchLastSection(false);
        statisticsTable->verticalHeader()->setVisible(false);
        statisticsTable->verticalHeader()->setCascadingSectionResizes(false);
        postProcessedImageStatisticsCheckBox = new QCheckBox(page_5);
        postProcessedImageStatisticsCheckBox->setObjectName(QString::fromUtf8("postProcessedImageStatisticsCheckBox"));
        postProcessedImageStatisticsCheckBox->setGeometry(QRect(0, 30, 284, 20));
        postProcessedImageStatisticsCheckBox->setChecked(true);
        toolBox->addItem(page_5, QString::fromUtf8("Image Statistics"));
        tabWidget->addTab(tabWidgetPage2, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget_2 = new QWidget(tab_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 10, 557, 131));
        formLayout_6 = new QFormLayout(layoutWidget_2);
        formLayout_6->setSpacing(6);
        formLayout_6->setContentsMargins(11, 11, 11, 11);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_6->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_6->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_6->setContentsMargins(0, 0, 10, 0);
        useHDRI = new QCheckBox(layoutWidget_2);
        useHDRI->setObjectName(QString::fromUtf8("useHDRI"));
        QPalette palette62;
        palette62.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette62.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette62.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette62.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette62.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette62.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette62.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette62.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette62.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette62.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette62.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette62.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette62.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette62.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette62.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette62.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette62.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette62.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        useHDRI->setPalette(palette62);
        useHDRI->setChecked(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, useHDRI);

        doNotSaveFilterCheckBox = new QCheckBox(layoutWidget_2);
        doNotSaveFilterCheckBox->setObjectName(QString::fromUtf8("doNotSaveFilterCheckBox"));
        QPalette palette63;
        palette63.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette63.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette63.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette63.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette63.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette63.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette63.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette63.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette63.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette63.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette63.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette63.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette63.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette63.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette63.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette63.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette63.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette63.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        doNotSaveFilterCheckBox->setPalette(palette63);
        doNotSaveFilterCheckBox->setChecked(false);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, doNotSaveFilterCheckBox);

        forceBatchTIFF = new QCheckBox(layoutWidget_2);
        forceBatchTIFF->setObjectName(QString::fromUtf8("forceBatchTIFF"));
        QPalette palette64;
        palette64.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette64.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette64.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette64.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette64.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette64.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette64.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette64.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette64.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette64.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette64.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette64.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette64.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette64.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette64.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette64.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette64.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette64.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        forceBatchTIFF->setPalette(palette64);
        forceBatchTIFF->setChecked(true);

        formLayout_6->setWidget(2, QFormLayout::FieldRole, forceBatchTIFF);

        stop32bitSpaceExceededCheckBox = new QCheckBox(layoutWidget_2);
        stop32bitSpaceExceededCheckBox->setObjectName(QString::fromUtf8("stop32bitSpaceExceededCheckBox"));
        QPalette palette65;
        palette65.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette65.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette65.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette65.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette65.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette65.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette65.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette65.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette65.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette65.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette65.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette65.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette65.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette65.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette65.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette65.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette65.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette65.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        stop32bitSpaceExceededCheckBox->setPalette(palette65);
        stop32bitSpaceExceededCheckBox->setChecked(false);

        formLayout_6->setWidget(4, QFormLayout::FieldRole, stop32bitSpaceExceededCheckBox);

        subtractBias = new QCheckBox(layoutWidget_2);
        subtractBias->setObjectName(QString::fromUtf8("subtractBias"));
        QPalette palette66;
        palette66.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette66.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette66.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette66.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette66.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette66.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette66.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette66.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette66.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette66.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette66.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette66.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette66.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette66.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette66.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette66.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette66.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette66.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        subtractBias->setPalette(palette66);
        subtractBias->setChecked(false);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, subtractBias);

        savedImagePrecision = new QComboBox(tab_2);
        savedImagePrecision->setObjectName(QString::fromUtf8("savedImagePrecision"));
        savedImagePrecision->setGeometry(QRect(0, 190, 281, 26));
        QPalette palette67;
        palette67.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette67.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette67.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette67.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette67.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette67.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette67.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette67.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette67.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette67.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette67.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette67.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette67.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette67.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette67.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette67.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette67.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette67.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        savedImagePrecision->setPalette(palette67);
        savedImagePrecisionLabel = new QLabel(tab_2);
        savedImagePrecisionLabel->setObjectName(QString::fromUtf8("savedImagePrecisionLabel"));
        savedImagePrecisionLabel->setGeometry(QRect(0, 170, 151, 25));
        QPalette palette68;
        palette68.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette68.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette68.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette68.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette68.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette68.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette68.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette68.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette68.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette68.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette68.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette68.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette68.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette68.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette68.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette68.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette68.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette68.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        savedImagePrecisionLabel->setPalette(palette68);
        tabWidget->addTab(tab_2, QString());
        scrollArea->setWidget(scrollAreaWidgetContents_4);

        gridLayout_5->addWidget(scrollArea, 0, 2, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 19, 331, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        deconvolveButton = new QToolButton(verticalLayoutWidget);
        deconvolveButton->setObjectName(QString::fromUtf8("deconvolveButton"));
        deconvolveButton->setEnabled(false);
        deconvolveButton->setMinimumSize(QSize(0, 50));
        QPalette palette69;
        palette69.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette69.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette69.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette69.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette69.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette69.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette69.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette69.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette69.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette69.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette69.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette69.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette69.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette69.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette69.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette69.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette69.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette69.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette69.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette69.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette69.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        deconvolveButton->setPalette(palette69);

        horizontalLayout_4->addWidget(deconvolveButton);

        showInputButton = new QToolButton(verticalLayoutWidget);
        showInputButton->setObjectName(QString::fromUtf8("showInputButton"));
        showInputButton->setEnabled(false);
        QPalette palette70;
        palette70.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette70.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette70.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette70.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette70.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette70.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette70.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette70.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette70.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette70.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette70.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette70.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette70.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette70.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette70.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette70.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette70.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette70.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette70.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette70.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette70.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        showInputButton->setPalette(palette70);

        horizontalLayout_4->addWidget(showInputButton);

        showOnlyInputButton = new QToolButton(verticalLayoutWidget);
        showOnlyInputButton->setObjectName(QString::fromUtf8("showOnlyInputButton"));
        showOnlyInputButton->setEnabled(false);
        QPalette palette71;
        palette71.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette71.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette71.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette71.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette71.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette71.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette71.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette71.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette71.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette71.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette71.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette71.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette71.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette71.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette71.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette71.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette71.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette71.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette71.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette71.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette71.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        showOnlyInputButton->setPalette(palette71);

        horizontalLayout_4->addWidget(showOnlyInputButton);

        showFFTMagnitudeButton = new QToolButton(verticalLayoutWidget);
        showFFTMagnitudeButton->setObjectName(QString::fromUtf8("showFFTMagnitudeButton"));
        showFFTMagnitudeButton->setEnabled(false);
        QPalette palette72;
        palette72.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette72.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette72.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette72.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette72.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette72.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette72.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette72.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette72.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette72.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette72.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette72.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette72.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette72.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette72.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette72.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette72.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette72.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette72.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette72.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette72.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        showFFTMagnitudeButton->setPalette(palette72);

        horizontalLayout_4->addWidget(showFFTMagnitudeButton);

        showReferenceImage = new QToolButton(verticalLayoutWidget);
        showReferenceImage->setObjectName(QString::fromUtf8("showReferenceImage"));
        showReferenceImage->setEnabled(false);
        QPalette palette73;
        palette73.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette73.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette73.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette73.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette73.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette73.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette73.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette73.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette73.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette73.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette73.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette73.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette73.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette73.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette73.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette73.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette73.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette73.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette73.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette73.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette73.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        showReferenceImage->setPalette(palette73);

        horizontalLayout_4->addWidget(showReferenceImage);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_5->addWidget(frame, 4, 2, 2, 1);

        DStation->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DStation);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1076, 22));
        QPalette palette74;
        palette74.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette74.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette74.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette74.setBrush(QPalette::Active, QPalette::BrightText, brush9);
        palette74.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette74.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette74.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette74.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette74.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette74.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette74.setBrush(QPalette::Inactive, QPalette::BrightText, brush9);
        palette74.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette74.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette74.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette74.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette74.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette74.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette74.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
        palette74.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette74.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette74.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        menuBar->setPalette(palette74);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuPreview = new QMenu(menuBar);
        menuPreview->setObjectName(QString::fromUtf8("menuPreview"));
        menuPreview->setEnabled(true);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuPreset = new QMenu(menuBar);
        menuPreset->setObjectName(QString::fromUtf8("menuPreset"));
        DStation->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DStation);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        DStation->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DStation);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(false);
        statusBar->setSizeGripEnabled(true);
        DStation->setStatusBar(statusBar);
        QWidget::setTabOrder(zoomInButton, zoomFullButton);
        QWidget::setTabOrder(zoomFullButton, zoomOutButton);
        QWidget::setTabOrder(zoomOutButton, deconvolveButton);
        QWidget::setTabOrder(deconvolveButton, showInputButton);
        QWidget::setTabOrder(showInputButton, showFFTMagnitudeButton);
        QWidget::setTabOrder(showFFTMagnitudeButton, useHDRI);
        QWidget::setTabOrder(useHDRI, doNotSaveFilterCheckBox);
        QWidget::setTabOrder(doNotSaveFilterCheckBox, deconvolutionAlgorithm);
        QWidget::setTabOrder(deconvolutionAlgorithm, wavelengthBSpin);
        QWidget::setTabOrder(wavelengthBSpin, wavelengthGSpin);
        QWidget::setTabOrder(wavelengthGSpin, wavelengthRSpin);
        QWidget::setTabOrder(wavelengthRSpin, noiseSpin);
        QWidget::setTabOrder(noiseSpin, imageView);
        QWidget::setTabOrder(imageView, consoleEdit);
        QWidget::setTabOrder(consoleEdit, dSpin);
        QWidget::setTabOrder(dSpin, fSpin);
        QWidget::setTabOrder(fSpin, barlowSpin);
        QWidget::setTabOrder(barlowSpin, pixelSpin);
        QWidget::setTabOrder(pixelSpin, gaussianBlurSpin);
        QWidget::setTabOrder(gaussianBlurSpin, r0Spin);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPreset->menuAction());
        menuBar->addAction(menuPreview->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_Image);
        menuFile->addAction(actionSave_Image_As);
        menuFile->addAction(actionDeconvolve);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Filter_As);
        menuFile->addAction(actionLoad_Filter_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_Reference_Image);
        menuFile->addAction(actionUse_Deconvolved_Image_as_Reference);
        menuFile->addSeparator();
        menuFile->addAction(actionBatch_Deconvolve);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_DStation);
        menuPreview->addAction(actionNew_Preview);
        menuPreview->addAction(actionRemove_Preview);
        menuPreview->addSeparator();
        menuPreview->addAction(actionMeasure_NSR);
        menuPreview->addSeparator();
        menuPreview->addAction(action32x32);
        menuPreview->addAction(action64x64);
        menuPreview->addAction(action128x128);
        menuPreview->addAction(action256x256);
        menuPreview->addAction(action512x512);
        menuPreview->addAction(action1024x1024);
        menuHelp->addAction(actionAbout);
        menuPreset->addAction(actionOpen_Preset);
        menuPreset->addAction(actionSave_preset);
        menuPreset->addSeparator();
        menuPreset->addAction(actionSave_Preset_to_Memory);
        menuPreset->addAction(actionRestore_Preset_From_Memory);

        retranslateUi(DStation);

        tabWidget->setCurrentIndex(0);
        toolBox_2->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);
        supersamplingFilter->setCurrentIndex(5);
        supersamplingFilterDown->setCurrentIndex(12);
        filteringMethod->setCurrentIndex(0);
        smoothingMode->setCurrentIndex(1);
        deringingSmoothingMode->setCurrentIndex(1);
        deringingMethod->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DStation);
    } // setupUi

    void retranslateUi(QMainWindow *DStation)
    {
        DStation->setWindowTitle(QApplication::translate("DStation", "DStation", 0, QApplication::UnicodeUTF8));
        actionOpen_Image->setText(QApplication::translate("DStation", "Open Image...", 0, QApplication::UnicodeUTF8));
        actionOpen_Image->setShortcut(QApplication::translate("DStation", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave_Image_As->setText(QApplication::translate("DStation", "Save Image As...", 0, QApplication::UnicodeUTF8));
        actionSave_Image_As->setShortcut(QApplication::translate("DStation", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionExit_DStation->setText(QApplication::translate("DStation", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit_DStation->setShortcut(QApplication::translate("DStation", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionNew_Preview->setText(QApplication::translate("DStation", "New Preview", 0, QApplication::UnicodeUTF8));
        actionNew_Preview->setShortcut(QApplication::translate("DStation", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionRemove_Preview->setText(QApplication::translate("DStation", "Remove Preview", 0, QApplication::UnicodeUTF8));
        actionRemove_Preview->setShortcut(QApplication::translate("DStation", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        action128x128->setText(QApplication::translate("DStation", "128x128", 0, QApplication::UnicodeUTF8));
        action256x256->setText(QApplication::translate("DStation", "256x256", 0, QApplication::UnicodeUTF8));
        action512x512->setText(QApplication::translate("DStation", "512x512", 0, QApplication::UnicodeUTF8));
        action1024x1024->setText(QApplication::translate("DStation", "1024x1024", 0, QApplication::UnicodeUTF8));
        actionPreview_Sizes->setText(QApplication::translate("DStation", "Preview Sizes:", 0, QApplication::UnicodeUTF8));
        actionSave_Filter_As->setText(QApplication::translate("DStation", "Save Filter Image As...", 0, QApplication::UnicodeUTF8));
        actionLoad_Filter_Image->setText(QApplication::translate("DStation", "Load Filter Image...", 0, QApplication::UnicodeUTF8));
        actionBatch_Deconvolve->setText(QApplication::translate("DStation", "Batch Deconvolve...", 0, QApplication::UnicodeUTF8));
        actionMeasure_NSR->setText(QApplication::translate("DStation", "Measure Noise", 0, QApplication::UnicodeUTF8));
        actionMeasure_NSR->setShortcut(QApplication::translate("DStation", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action64x64->setText(QApplication::translate("DStation", "64x64", 0, QApplication::UnicodeUTF8));
        action32x32->setText(QApplication::translate("DStation", "32x32", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("DStation", "About...", 0, QApplication::UnicodeUTF8));
        actionSave_preset->setText(QApplication::translate("DStation", "Save Preset As...", 0, QApplication::UnicodeUTF8));
        actionOpen_Preset->setText(QApplication::translate("DStation", "Open Preset...", 0, QApplication::UnicodeUTF8));
        actionLoad_Reference_Image->setText(QApplication::translate("DStation", "Load Reference Image...", 0, QApplication::UnicodeUTF8));
        actionDeconvolve->setText(QApplication::translate("DStation", "Deconvolve", 0, QApplication::UnicodeUTF8));
        actionDeconvolve->setShortcut(QApplication::translate("DStation", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionUse_Deconvolved_Image_as_Reference->setText(QApplication::translate("DStation", "Use Current as Reference", 0, QApplication::UnicodeUTF8));
        actionSave_Preset_to_Memory->setText(QApplication::translate("DStation", "Save Preset To Memory", 0, QApplication::UnicodeUTF8));
        actionSave_Preset_to_Memory->setShortcut(QApplication::translate("DStation", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionRestore_Preset_From_Memory->setText(QApplication::translate("DStation", "Restore Preset From Memory", 0, QApplication::UnicodeUTF8));
        actionRestore_Preset_From_Memory->setShortcut(QApplication::translate("DStation", "Ctrl+/", 0, QApplication::UnicodeUTF8));
        consoleEdit->setPlainText(QString());
        zoomLabel->setText(QApplication::translate("DStation", "None", 0, QApplication::UnicodeUTF8));
        zoomOutButton->setText(QApplication::translate("DStation", "Zoom Out", 0, QApplication::UnicodeUTF8));
        zoomInButton->setText(QApplication::translate("DStation", "Zoom In", 0, QApplication::UnicodeUTF8));
        zoomFullButton->setText(QApplication::translate("DStation", "100%", 0, QApplication::UnicodeUTF8));
        wavelengthRLabel->setText(QApplication::translate("DStation", "Wavelength, nm (Channel R)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        wavelengthRSpin->setToolTip(QApplication::translate("DStation", "Wavelength of the input image red channel, used to build atmospheric MTF. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        wavelengthRSpin->setSuffix(QString());
        wavelengthGLabel->setText(QApplication::translate("DStation", "Wavelength, nm (Central)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        wavelengthGSpin->setToolTip(QApplication::translate("DStation", "Wavelength of the input image green channel, used to build atmospheric MTF. If processing in the central wavelength mode then this wavelength is used for all RGB channels of the input image. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        wavelengthGSpin->setSuffix(QString());
        wavelengthBLabel->setText(QApplication::translate("DStation", "(Channel B)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        wavelengthBSpin->setToolTip(QApplication::translate("DStation", "Wavelength of the input image blue channel, used to build atmospheric MTF. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        wavelengthBSpin->setSuffix(QString());
        dLabel->setText(QApplication::translate("DStation", "Objective Diameter, mm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dSpin->setToolTip(QApplication::translate("DStation", "Objective (telescope) diameter used to build atmospheric MTF. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        dSpin->setSuffix(QString());
        fLabel->setText(QApplication::translate("DStation", "Objective Focal Length, mm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        fSpin->setToolTip(QApplication::translate("DStation", "Objective (telescope) focal length, used to build atmospheric MTF. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fSpin->setSuffix(QString());
        barlowLabel->setText(QApplication::translate("DStation", "Focal Length Multiplier, X", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        barlowSpin->setToolTip(QApplication::translate("DStation", "If a Barlow lens is used, specifies the multiplication factor for the focal length. By default is 1, i.e. no Barlow lens. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pixelLabel->setText(QApplication::translate("DStation", "CCD Pixel Size, microns", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pixelSpin->setToolTip(QApplication::translate("DStation", "CCD sensor pixel size, used to build atmospheric MTF. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        gaussianBlurLabel->setText(QApplication::translate("DStation", "Filter Size, pixels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gaussianBlurSpin->setToolTip(QApplication::translate("DStation", "Smoothing filter size to separate low and high frequency components of the input image. Primary blind deconvolution parameter.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        r0Label->setText(QApplication::translate("DStation", "Fried's r0 Parameter, mm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        r0Spin->setToolTip(QApplication::translate("DStation", "Fried's r0 parameter specifying atmospheric turbulence strength. Does not apply to deconvolution algorithms that do not employ atmospheric component.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        r0Spin->setSuffix(QString());
        noiseLabel->setText(QApplication::translate("DStation", "Noise Estimation (x1000)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        noiseSpin->setToolTip(QApplication::translate("DStation", "Input image noise estimation. High noise values prevent deconvolution of useless signal in the input image, i.e. noise.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        logFactorLabel->setText(QApplication::translate("DStation", "Compression Ratio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        logFactorSpin->setToolTip(QApplication::translate("DStation", "Blind deconvolution parameter. Smaller values emphasize lower frequencies in deconvolution process. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        turbulenceModelLabel_2->setText(QApplication::translate("DStation", "Deconvolution Algorithm:", 0, QApplication::UnicodeUTF8));
        deconvolutionAlgorithm->clear();
        deconvolutionAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Usatov, Atmospheric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Atmospheric MTF only", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Usatov, Atmospheric (Weighted)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "External Filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Lim (Reference Image)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Usatov", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "None", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("DStation", "Primary", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        postProcessingEnabledCheckBox->setToolTip(QApplication::translate("DStation", "Enables all post processing stages. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        postProcessingEnabledCheckBox->setText(QApplication::translate("DStation", "Enable Post Processing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        normalizeCheckBox->setToolTip(QApplication::translate("DStation", "The intensity values are stretched to cover the entire range of possible values. While doing so, black-out at most 2% of the pixels and white-out at most 1% of the pixels.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        normalizeCheckBox->setText(QApplication::translate("DStation", "Normalize", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        enhanceCheckBox->setToolTip(QApplication::translate("DStation", "Apply low pass noise filter to the image, strength of the filter controlled by LP Noise Filter Strength. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        enhanceCheckBox->setText(QApplication::translate("DStation", "Low Pass Noise Filter", 0, QApplication::UnicodeUTF8));
        applyPostProcessing->setText(QApplication::translate("DStation", "Apply Post Processing", 0, QApplication::UnicodeUTF8));
        dynamicRangeExtensionLabel->setText(QApplication::translate("DStation", "Dynamic Range Extension, %", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dynamicRangeExtensionSpin->setToolTip(QApplication::translate("DStation", "Applies division operator to the output image to compress histogram. Helps to avoid white clipping.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        noiseFilterStrengthLabel->setText(QApplication::translate("DStation", "LP Noise Filter Strength, %", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        noiseFilterStrengthSpin->setToolTip(QApplication::translate("DStation", "Low pass noise filter strength. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        zoomLabel_2->setText(QApplication::translate("DStation", "Vertical Scale:", 0, QApplication::UnicodeUTF8));
        resetBriCon->setText(QApplication::translate("DStation", "Reset", 0, QApplication::UnicodeUTF8));
        redrawHistogramButton->setText(QApplication::translate("DStation", "Redraw", 0, QApplication::UnicodeUTF8));
        briLabel->setText(QApplication::translate("DStation", "Bri 100%", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        briConEnabled->setToolTip(QApplication::translate("DStation", "Enables brightness/contrast adjustment.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        briConEnabled->setText(QApplication::translate("DStation", "Enable Brightness/Contrast", 0, QApplication::UnicodeUTF8));
        logarithmicHistogram->setText(QApplication::translate("DStation", "Log Y", 0, QApplication::UnicodeUTF8));
        conLabel->setText(QApplication::translate("DStation", "Con 100%", 0, QApplication::UnicodeUTF8));
        toolBox_2->setItemText(toolBox_2->indexOf(page_9), QApplication::translate("DStation", "Basic Post-Processing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        realTimePostProcessing->setToolTip(QApplication::translate("DStation", "Apply post processing immediately after settings are changed. If disabled, you will need to press Apply Post Processing button for any changes to take effect.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        realTimePostProcessing->setText(QApplication::translate("DStation", "Apply Post-Processing In Real Time", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DStation", "Proc", 0, QApplication::UnicodeUTF8));
        supersamplingFilterLabel->setText(QApplication::translate("DStation", "Supersampling Filter (Up):", 0, QApplication::UnicodeUTF8));
        supersamplingFilter->clear();
        supersamplingFilter->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Point", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Triangle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hermite", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hanning", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hamming", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Blackman", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Gaussian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Quadratic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Cubic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Catrom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Mitchell", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Lanczos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Bessel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Sinc", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        supersamplingFilter->setToolTip(QApplication::translate("DStation", "Filter applied when supersampling image. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        supersamplingFilterDownLabel->setText(QApplication::translate("DStation", "Supersampling Filter (Down):", 0, QApplication::UnicodeUTF8));
        supersamplingFilterDown->clear();
        supersamplingFilterDown->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Point", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Box", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Triangle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hermite", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hanning", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Hamming", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Blackman", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Gaussian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Quadratic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Cubic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Catrom", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Mitchell", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Lanczos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Bessel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Sinc", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        supersamplingFilterDown->setToolTip(QApplication::translate("DStation", "Filter applied when downsampling image back to original size.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        supersamplingFactorLabel->setText(QApplication::translate("DStation", "Supersampling factor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        supersamplingFactorSpin->setToolTip(QApplication::translate("DStation", "Supersample input image before applying deconvolution process. Factor=2 corresponds to 200% image size. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        doNotDownsampleCheckBox->setToolTip(QApplication::translate("DStation", "Leaves image supersampled after deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        doNotDownsampleCheckBox->setText(QApplication::translate("DStation", "Do not downsample deconvolved images", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("DStation", "Supersampling", 0, QApplication::UnicodeUTF8));
        filteringMethod->clear();
        filteringMethod->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Wiener", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Constrained Least Squares", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Schafer Inverse Filter (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Van Cittert (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Sine Relaxed Lucy-Richardson (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Maximum A Posteriori (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Regularized Lucy-Richardson (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Schafer with Equalizer (Iterative)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Landweber (Iterative)", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        filteringMethod->setToolTip(QApplication::translate("DStation", "Method used to apply deconvolution filter to the input image.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        filteringLabel->setText(QApplication::translate("DStation", "Deconvolution Method:", 0, QApplication::UnicodeUTF8));
        processingMode->clear();
        processingMode->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Central Wavelength", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Separate RGB Wavelengths", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        processingMode->setToolTip(QApplication::translate("DStation", "Defines how atmospheric MTF is processed. Central wavelength mode uses the same MTF for all RGB channels of the input image. Separate wavelength mode builds individual MTF per each channel and is more accurate.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ProcessingModeLabel->setText(QApplication::translate("DStation", "Processing Mode:", 0, QApplication::UnicodeUTF8));
        bufferLabel->setText(QApplication::translate("DStation", "Anti-artifact Buffer, pixels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        bufferSpin->setToolTip(QApplication::translate("DStation", "Pads input image with a mirrored buffer. Prevents border artifacts to appear in deconvolved images.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bufferSpin->setSuffix(QString());
        gammaLabel->setText(QApplication::translate("DStation", "Weighted U-W Filter Weights", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gammaSpinBox->setToolTip(QApplication::translate("DStation", "Specifies blind and atmospheric filter weights in the Weighted U-W algorithm. Weights=0.5 means that filters have equal weights. Weights=0 means blind filter is given 0% weight. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        turbulenceModelLabel->setText(QApplication::translate("DStation", "Turbulence Model:", 0, QApplication::UnicodeUTF8));
        FriedAlpha->clear();
        FriedAlpha->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Long exposure (Stacked)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Short exposure", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        FriedAlpha->setToolTip(QApplication::translate("DStation", "Fried's alpha parameter configuring atmospheric MTF. Long exposure (stacked) works well for lucky imaging approach and long exposure frames. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        smoothingMode->clear();
        smoothingMode->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Uniform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Gaussian", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        smoothingMode->setToolTip(QApplication::translate("DStation", "Averaging method to use for the blind deconvolution smoothing filter.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        smoothingFilterLabel_2->setText(QApplication::translate("DStation", "Smoothing Filter Weighted Average:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("DStation", "Deconvolution and Filtering", 0, QApplication::UnicodeUTF8));
        supersamplingFactorLabel_2->setText(QApplication::translate("DStation", "CLS Laplacian Factor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        LaplacianAlpha->setToolTip(QApplication::translate("DStation", "Laplacian factor to use in Constrained Least Squares deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("DStation", "CLS Deconvolution", 0, QApplication::UnicodeUTF8));
        convergenceLabel->setText(QApplication::translate("DStation", "Iterative Convergence Factor", 0, QApplication::UnicodeUTF8));
        iterationsLabel->setText(QApplication::translate("DStation", "Iterations", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        iterationsSpin->setToolTip(QApplication::translate("DStation", "Amount of iterations to use. Applicable only if iterative deconvolution method is selected. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        iterationsLabel_2->setText(QApplication::translate("DStation", "Filter Size (X, Y), pixels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spatialFilterSize->setToolTip(QApplication::translate("DStation", "Amount of iterations to use. Applicable only if iterative deconvolution method is selected. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        iterativeShowProgress->setToolTip(QApplication::translate("DStation", "Leaves image supersampled after deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        iterativeShowProgress->setText(QApplication::translate("DStation", "Show progress in real time", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("DStation", "Iterative Deconvolution", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("DStation", "Frequency Domain Equalizer", 0, QApplication::UnicodeUTF8));
        iterationsLabel_3->setText(QApplication::translate("DStation", "Threshold Image Intensity", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deringingThreshold->setToolTip(QApplication::translate("DStation", "Laplacian factor to use in Constrained Least Squares deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        iterationsLabel_4->setText(QApplication::translate("DStation", "Factor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deringingFactor->setToolTip(QApplication::translate("DStation", "Pads input image with a mirrored buffer. Prevents border artifacts to appear in deconvolved images.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingFactor->setSuffix(QString());
#ifndef QT_NO_TOOLTIP
        deringingEnabledCheckBox->setToolTip(QApplication::translate("DStation", "Leaves image supersampled after deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingEnabledCheckBox->setText(QApplication::translate("DStation", "Deringing Enabled", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deringingSmoothness->setToolTip(QApplication::translate("DStation", "Pads input image with a mirrored buffer. Prevents border artifacts to appear in deconvolved images.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingSmoothness->setSuffix(QString());
        iterationsLabel_5->setText(QApplication::translate("DStation", "Smoothness", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deringingSmoothMax->setToolTip(QApplication::translate("DStation", "Leaves image supersampled after deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingSmoothMax->setText(QApplication::translate("DStation", "Smooth maximums", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deringingApplyMinThreshold->setToolTip(QApplication::translate("DStation", "Leaves image supersampled after deconvolution.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingApplyMinThreshold->setText(QApplication::translate("DStation", "Apply minimum threshold", 0, QApplication::UnicodeUTF8));
        smoothingFilterLabel_3->setText(QApplication::translate("DStation", "Smoothing Filter Weighted Average:", 0, QApplication::UnicodeUTF8));
        deringingSmoothingMode->clear();
        deringingSmoothingMode->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Uniform", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "Gaussian", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        deringingSmoothingMode->setToolTip(QApplication::translate("DStation", "Averaging method to use for the blind deconvolution smoothing filter.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deringingMethod->clear();
        deringingMethod->insertItems(0, QStringList()
         << QApplication::translate("DStation", "Threshold Partitioning", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        deringingMethod->setToolTip(QApplication::translate("DStation", "Averaging method to use for the blind deconvolution smoothing filter.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        smoothingFilterLabel_4->setText(QApplication::translate("DStation", "Method:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("DStation", "Deringing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        trackImageStatisticsCheckBox->setToolTip(QApplication::translate("DStation", "Update table once image is deconvolved.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        trackImageStatisticsCheckBox->setText(QApplication::translate("DStation", "Track Image Statistics", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = statisticsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DStation", "Head", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = statisticsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DStation", "Red", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = statisticsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DStation", "Green", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = statisticsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DStation", "Blue", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = statisticsTable->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("DStation", "Channel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = statisticsTable->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("DStation", "Minimum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = statisticsTable->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("DStation", "Maximum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = statisticsTable->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("DStation", "Mean", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = statisticsTable->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("DStation", "Std Dev", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = statisticsTable->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("DStation", "Variance", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = statisticsTable->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("DStation", "Kurtosis", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = statisticsTable->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QApplication::translate("DStation", "Skewness", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = statisticsTable->isSortingEnabled();
        statisticsTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = statisticsTable->item(0, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("DStation", "Red", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = statisticsTable->item(0, 2);
        ___qtablewidgetitem13->setText(QApplication::translate("DStation", "Green", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = statisticsTable->item(0, 3);
        ___qtablewidgetitem14->setText(QApplication::translate("DStation", "Blue", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = statisticsTable->item(1, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("DStation", "Min", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = statisticsTable->item(2, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("DStation", "Max", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = statisticsTable->item(3, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("DStation", "Mean", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = statisticsTable->item(4, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("DStation", "Std Dev", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = statisticsTable->item(5, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("DStation", "Variance", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = statisticsTable->item(6, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("DStation", "Kurtosis", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = statisticsTable->item(7, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("DStation", "Skew", 0, QApplication::UnicodeUTF8));
        statisticsTable->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        postProcessedImageStatisticsCheckBox->setToolTip(QApplication::translate("DStation", "If checked, statistics is obtained from post-processed image, otherwise from raw deconvolved image.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        postProcessedImageStatisticsCheckBox->setText(QApplication::translate("DStation", "Use Post-Processed Image Statistics", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("DStation", "Image Statistics", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QApplication::translate("DStation", "Advanced", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        useHDRI->setToolTip(QApplication::translate("DStation", "Uses slightly faster HDRI processing for Wiener deconvolution. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        useHDRI->setText(QApplication::translate("DStation", "Use HDRI Wiener deconvolution mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        doNotSaveFilterCheckBox->setToolTip(QApplication::translate("DStation", "Do not save derived deconvolution filter to RAM. Preserves memory usage, however you will not be able to save derived filter to disk. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        doNotSaveFilterCheckBox->setText(QApplication::translate("DStation", "Do not save filter to memory", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        forceBatchTIFF->setToolTip(QApplication::translate("DStation", "Forces deconvolution batch mode to always save in TIFF format.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        forceBatchTIFF->setText(QApplication::translate("DStation", "Force batch process to save TIFF", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        stop32bitSpaceExceededCheckBox->setToolTip(QApplication::translate("DStation", "Applicable to 32-bit builds only. Stops deconvolution if anticipated RAM usage is above maximum supported addressed space. (Usually around 2 GB for 32-bit.)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stop32bitSpaceExceededCheckBox->setText(QApplication::translate("DStation", "Stop if RAM usage exceeds 32-bit space", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        subtractBias->setToolTip(QApplication::translate("DStation", "Applicable to 32-bit builds only. Stops deconvolution if anticipated RAM usage is above maximum supported addressed space. (Usually around 2 GB for 32-bit.)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        subtractBias->setText(QApplication::translate("DStation", "Subtract 90% bias before deconvolve", 0, QApplication::UnicodeUTF8));
        savedImagePrecision->clear();
        savedImagePrecision->insertItems(0, QStringList()
         << QApplication::translate("DStation", "16-bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DStation", "32-bit", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        savedImagePrecision->setToolTip(QApplication::translate("DStation", "Forces to save results with specified precision.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savedImagePrecisionLabel->setText(QApplication::translate("DStation", "Saved Image Precision:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DStation", "System", 0, QApplication::UnicodeUTF8));
        deconvolveButton->setText(QApplication::translate("DStation", "Deconvolve", 0, QApplication::UnicodeUTF8));
        deconvolveButton->setShortcut(QApplication::translate("DStation", "Ctrl+D", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        showInputButton->setToolTip(QApplication::translate("DStation", "Hold this button to blink input and deconvolved images. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        showInputButton->setText(QApplication::translate("DStation", "Blink", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        showOnlyInputButton->setToolTip(QApplication::translate("DStation", "Show input image.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        showOnlyInputButton->setText(QApplication::translate("DStation", "Input", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        showFFTMagnitudeButton->setToolTip(QApplication::translate("DStation", "Show Fourier transformation of the input image. ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        showFFTMagnitudeButton->setText(QApplication::translate("DStation", "FFT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        showReferenceImage->setToolTip(QApplication::translate("DStation", "Show reference image.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        showReferenceImage->setText(QApplication::translate("DStation", "Ref", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("DStation", "File", 0, QApplication::UnicodeUTF8));
        menuPreview->setTitle(QApplication::translate("DStation", "Preview", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("DStation", "Help", 0, QApplication::UnicodeUTF8));
        menuPreset->setTitle(QApplication::translate("DStation", "Preset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class DStation: public Ui_DStation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSTATION_H
