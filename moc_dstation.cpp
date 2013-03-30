/****************************************************************************
** Meta object code from reading C++ file 'dstation.h'
**
** Created: Sat Mar 30 01:06:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dstation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dstation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DStation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      45,   10,    9,    9, 0x08,
      74,    9,    9,    9, 0x08,
     102,    9,    9,    9, 0x08,
     130,    9,    9,    9, 0x08,
     168,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,
     244,    9,    9,    9, 0x08,
     282,    9,    9,    9, 0x08,
     320,    9,    9,    9, 0x08,
     358,    9,    9,    9, 0x08,
     390,    9,    9,    9, 0x08,
     423,    9,    9,    9, 0x08,
     455,    9,    9,    9, 0x08,
     497,    9,    9,    9, 0x08,
     532,    9,    9,    9, 0x08,
     557,    9,    9,    9, 0x08,
     602,    9,    9,    9, 0x08,
     635,    9,    9,    9, 0x08,
     668,    9,    9,    9, 0x08,
     695,    9,    9,    9, 0x08,
     737,    9,    9,    9, 0x08,
     781,    9,    9,    9, 0x08,
     816,    9,    9,    9, 0x08,
     843,    9,    9,    9, 0x08,
     870,    9,    9,    9, 0x08,
     903,    9,    9,    9, 0x08,
     941,    9,    9,    9, 0x08,
     980,    9,    9,    9, 0x08,
    1016,    9,    9,    9, 0x08,
    1060,    9,    9,    9, 0x08,
    1093,    9,    9,    9, 0x08,
    1120,    9,    9,    9, 0x08,
    1151,    9,    9,    9, 0x08,
    1180,    9,    9,    9, 0x08,
    1209,    9,    9,    9, 0x08,
    1238,    9,    9,    9, 0x08,
    1274,    9,    9,    9, 0x08,
    1307,    9,    9,    9, 0x08,
    1345,    9,    9,    9, 0x08,
    1381,    9,    9,    9, 0x08,
    1424, 1418,    9,    9, 0x08,
    1467, 1418,    9,    9, 0x08,
    1518,    9,    9,    9, 0x08,
    1569,    9,    9,    9, 0x08,
    1608,    9,    9,    9, 0x08,
    1655,    9,    9,    9, 0x08,
    1702,    9,    9,    9, 0x08,
    1737,    9,    9,    9, 0x08,
    1767,    9,    9,    9, 0x08,
    1796,    9,    9,    9, 0x08,
    1831,    9,    9,    9, 0x08,
    1861,    9,    9,    9, 0x08,
    1888,    9,    9,    9, 0x08,
    1916,    9,    9,    9, 0x08,
    1942,    9,    9,    9, 0x08,
    1974, 1418,    9,    9, 0x08,
    2018,    9,    9,    9, 0x08,
    2074,    9,    9,    9, 0x08,
    2117,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DStation[] = {
    "DStation\0\0value\0on_conDial_valueChanged(int)\0"
    "on_briDial_valueChanged(int)\0"
    "on_conDial_sliderReleased()\0"
    "on_briDial_sliderReleased()\0"
    "on_equalizerSlider_6_sliderReleased()\0"
    "on_equalizerSlider_5_sliderReleased()\0"
    "on_equalizerSlider_4_sliderReleased()\0"
    "on_equalizerSlider_3_sliderReleased()\0"
    "on_equalizerSlider_2_sliderReleased()\0"
    "on_equalizerSlider_1_sliderReleased()\0"
    "on_actionDeconvolve_triggered()\0"
    "on_showOnlyInputButton_clicked()\0"
    "on_showReferenceImage_clicked()\0"
    "on_actionLoad_Reference_Image_triggered()\0"
    "on_briConEnabled_stateChanged(int)\0"
    "on_resetBriCon_clicked()\0"
    "on_noiseFilterStrengthSpin_valueChanged(int)\0"
    "on_actionOpen_Preset_triggered()\0"
    "on_actionSave_preset_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_logarithmicHistogram_stateChanged(int)\0"
    "on_histogramVerticalScale_valueChanged(int)\0"
    "on_redrawHistogramButton_clicked()\0"
    "on_action32x32_triggered()\0"
    "on_action64x64_triggered()\0"
    "on_actionMeasure_NSR_triggered()\0"
    "on_actionBatch_Deconvolve_triggered()\0"
    "on_actionLoad_Filter_Image_triggered()\0"
    "on_actionSave_Filter_As_triggered()\0"
    "on_realTimePostProcessing_stateChanged(int)\0"
    "on_applyPostProcessing_clicked()\0"
    "changePreviewCoordinates()\0"
    "on_action1024x1024_triggered()\0"
    "on_action512x512_triggered()\0"
    "on_action256x256_triggered()\0"
    "on_action128x128_triggered()\0"
    "on_actionRemove_Preview_triggered()\0"
    "on_actionNew_Preview_triggered()\0"
    "on_gaussianBlurSpin_valueChanged(int)\0"
    "on_showFFTMagnitudeButton_clicked()\0"
    "on_enhanceCheckBox_stateChanged(int)\0"
    "index\0on_processingMode_currentIndexChanged(int)\0"
    "on_deconvolutionAlgorithm_currentIndexChanged(int)\0"
    "on_postProcessingEnabledCheckBox_stateChanged(int)\0"
    "on_normalizeCheckBox_stateChanged(int)\0"
    "on_dynamicRangeExtensionSpin_valueChanged(int)\0"
    "on_dynamicRangeExtensionSpin_editingFinished()\0"
    "on_actionExit_DStation_triggered()\0"
    "on_showInputButton_released()\0"
    "on_showInputButton_pressed()\0"
    "on_actionSave_Image_As_triggered()\0"
    "on_deconvolveButton_clicked()\0"
    "on_zoomOutButton_clicked()\0"
    "on_zoomFullButton_clicked()\0"
    "on_zoomInButton_clicked()\0"
    "on_actionOpen_Image_triggered()\0"
    "on_filteringMethod_currentIndexChanged(int)\0"
    "on_actionUse_Deconvolved_Image_as_Reference_triggered()\0"
    "on_actionSave_Preset_to_Memory_triggered()\0"
    "on_actionRestore_Preset_From_Memory_triggered()\0"
};

void DStation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DStation *_t = static_cast<DStation *>(_o);
        switch (_id) {
        case 0: _t->on_conDial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_briDial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_conDial_sliderReleased(); break;
        case 3: _t->on_briDial_sliderReleased(); break;
        case 4: _t->on_equalizerSlider_6_sliderReleased(); break;
        case 5: _t->on_equalizerSlider_5_sliderReleased(); break;
        case 6: _t->on_equalizerSlider_4_sliderReleased(); break;
        case 7: _t->on_equalizerSlider_3_sliderReleased(); break;
        case 8: _t->on_equalizerSlider_2_sliderReleased(); break;
        case 9: _t->on_equalizerSlider_1_sliderReleased(); break;
        case 10: _t->on_actionDeconvolve_triggered(); break;
        case 11: _t->on_showOnlyInputButton_clicked(); break;
        case 12: _t->on_showReferenceImage_clicked(); break;
        case 13: _t->on_actionLoad_Reference_Image_triggered(); break;
        case 14: _t->on_briConEnabled_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_resetBriCon_clicked(); break;
        case 16: _t->on_noiseFilterStrengthSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_actionOpen_Preset_triggered(); break;
        case 18: _t->on_actionSave_preset_triggered(); break;
        case 19: _t->on_actionAbout_triggered(); break;
        case 20: _t->on_logarithmicHistogram_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_histogramVerticalScale_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_redrawHistogramButton_clicked(); break;
        case 23: _t->on_action32x32_triggered(); break;
        case 24: _t->on_action64x64_triggered(); break;
        case 25: _t->on_actionMeasure_NSR_triggered(); break;
        case 26: _t->on_actionBatch_Deconvolve_triggered(); break;
        case 27: _t->on_actionLoad_Filter_Image_triggered(); break;
        case 28: _t->on_actionSave_Filter_As_triggered(); break;
        case 29: _t->on_realTimePostProcessing_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_applyPostProcessing_clicked(); break;
        case 31: _t->changePreviewCoordinates(); break;
        case 32: _t->on_action1024x1024_triggered(); break;
        case 33: _t->on_action512x512_triggered(); break;
        case 34: _t->on_action256x256_triggered(); break;
        case 35: _t->on_action128x128_triggered(); break;
        case 36: _t->on_actionRemove_Preview_triggered(); break;
        case 37: _t->on_actionNew_Preview_triggered(); break;
        case 38: _t->on_gaussianBlurSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_showFFTMagnitudeButton_clicked(); break;
        case 40: _t->on_enhanceCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_processingMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_deconvolutionAlgorithm_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_postProcessingEnabledCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_normalizeCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_dynamicRangeExtensionSpin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_dynamicRangeExtensionSpin_editingFinished(); break;
        case 47: _t->on_actionExit_DStation_triggered(); break;
        case 48: _t->on_showInputButton_released(); break;
        case 49: _t->on_showInputButton_pressed(); break;
        case 50: _t->on_actionSave_Image_As_triggered(); break;
        case 51: _t->on_deconvolveButton_clicked(); break;
        case 52: _t->on_zoomOutButton_clicked(); break;
        case 53: _t->on_zoomFullButton_clicked(); break;
        case 54: _t->on_zoomInButton_clicked(); break;
        case 55: _t->on_actionOpen_Image_triggered(); break;
        case 56: _t->on_filteringMethod_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_actionUse_Deconvolved_Image_as_Reference_triggered(); break;
        case 58: _t->on_actionSave_Preset_to_Memory_triggered(); break;
        case 59: _t->on_actionRestore_Preset_From_Memory_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DStation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DStation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DStation,
      qt_meta_data_DStation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DStation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DStation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DStation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DStation))
        return static_cast<void*>(const_cast< DStation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DStation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
