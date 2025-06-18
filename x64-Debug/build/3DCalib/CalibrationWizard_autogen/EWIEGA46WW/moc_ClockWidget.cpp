/****************************************************************************
** Meta object code from reading C++ file 'ClockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../3DCalib/ClockWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClockWidget_t {
    QByteArrayData data[19];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClockWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClockWidget_t qt_meta_stringdata_ClockWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClockWidget"
QT_MOC_LITERAL(1, 12, 22), // "signalUpdataPointsData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "signalUpdatataTablewData"
QT_MOC_LITERAL(4, 61, 6), // "number"
QT_MOC_LITERAL(5, 68, 11), // "clockNumber"
QT_MOC_LITERAL(6, 80, 18), // "onUpdataPointsData"
QT_MOC_LITERAL(7, 99, 11), // "onStartMark"
QT_MOC_LITERAL(8, 111, 10), // "onStopMark"
QT_MOC_LITERAL(9, 122, 14), // "onTaskFinished"
QT_MOC_LITERAL(10, 137, 6), // "result"
QT_MOC_LITERAL(11, 144, 12), // "onApplyParam"
QT_MOC_LITERAL(12, 157, 15), // "onOpenDlgSetCfg"
QT_MOC_LITERAL(13, 173, 18), // "onUpdataTablewData"
QT_MOC_LITERAL(14, 192, 4), // "data"
QT_MOC_LITERAL(15, 197, 5), // "data2"
QT_MOC_LITERAL(16, 203, 22), // "onAddDataToTableWidget"
QT_MOC_LITERAL(17, 226, 15), // "onSaveCalibData"
QT_MOC_LITERAL(18, 242, 18) // "onOpenMarkParamSet"

    },
    "ClockWidget\0signalUpdataPointsData\0\0"
    "signalUpdatataTablewData\0number\0"
    "clockNumber\0onUpdataPointsData\0"
    "onStartMark\0onStopMark\0onTaskFinished\0"
    "result\0onApplyParam\0onOpenDlgSetCfg\0"
    "onUpdataTablewData\0data\0data2\0"
    "onAddDataToTableWidget\0onSaveCalibData\0"
    "onOpenMarkParamSet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClockWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    2,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   80,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    2,   88,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,
      17,    0,   94,    2, 0x0a /* Public */,
      18,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClockWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdataPointsData(); break;
        case 1: _t->signalUpdatataTablewData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onUpdataPointsData(); break;
        case 3: _t->onStartMark(); break;
        case 4: _t->onStopMark(); break;
        case 5: _t->onTaskFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onApplyParam(); break;
        case 7: _t->onOpenDlgSetCfg(); break;
        case 8: _t->onUpdataTablewData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->onAddDataToTableWidget(); break;
        case 10: _t->onSaveCalibData(); break;
        case 11: _t->onOpenMarkParamSet(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClockWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClockWidget::signalUpdataPointsData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClockWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClockWidget::signalUpdatataTablewData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClockWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ClockWidget.data,
    qt_meta_data_ClockWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClockWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ClockWidget::signalUpdataPointsData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClockWidget::signalUpdatataTablewData(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
