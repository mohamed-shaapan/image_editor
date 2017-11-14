/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../android_try/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "load_is_done"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "imagePath"
QT_MOC_LITERAL(4, 35, 10), // "touchEvent"
QT_MOC_LITERAL(5, 46, 12), // "QTouchEvent*"
QT_MOC_LITERAL(6, 59, 2), // "ev"
QT_MOC_LITERAL(7, 62, 22), // "on_save_button_clicked"
QT_MOC_LITERAL(8, 85, 26), // "on_zoom_slider_sliderMoved"
QT_MOC_LITERAL(9, 112, 8), // "position"
QT_MOC_LITERAL(10, 121, 28), // "on_zoom_slider_sliderPressed"
QT_MOC_LITERAL(11, 150, 27), // "on_zoom_slider_valueChanged"
QT_MOC_LITERAL(12, 178, 5), // "value"
QT_MOC_LITERAL(13, 184, 29), // "on_zoom_slider_sliderReleased"
QT_MOC_LITERAL(14, 214, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(15, 235, 22), // "on_dial_sliderReleased"
QT_MOC_LITERAL(16, 258, 25), // "on_image_canvas_destroyed"
QT_MOC_LITERAL(17, 284, 4), // "arg1"
QT_MOC_LITERAL(18, 289, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(19, 312, 22) // "on_crop_button_clicked"

    },
    "MainWindow\0load_is_done\0\0imagePath\0"
    "touchEvent\0QTouchEvent*\0ev\0"
    "on_save_button_clicked\0"
    "on_zoom_slider_sliderMoved\0position\0"
    "on_zoom_slider_sliderPressed\0"
    "on_zoom_slider_valueChanged\0value\0"
    "on_zoom_slider_sliderReleased\0"
    "on_dial_valueChanged\0on_dial_sliderReleased\0"
    "on_image_canvas_destroyed\0arg1\0"
    "on_back_button_clicked\0on_crop_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    1,   90,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    1,   94,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load_is_done((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->touchEvent((*reinterpret_cast< QTouchEvent*(*)>(_a[1]))); break;
        case 2: _t->on_save_button_clicked(); break;
        case 4: _t->on_zoom_slider_sliderPressed(); break;
        case 5: _t->on_zoom_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_zoom_slider_sliderReleased(); break;
        case 7: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_dial_sliderReleased(); break;
        case 11: _t->on_back_button_clicked(); break;
        case 12: _t->on_crop_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
