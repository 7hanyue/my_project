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
    QByteArrayData data[21];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClockWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClockWidget_t qt_meta_stringdata_ClockWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClockWidget"
QT_MOC_LITERAL(1, 12, 25), // "signalUpdataAllPointsData"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 31), // "signalUpdatataSelectedPointData"
QT_MOC_LITERAL(4, 71, 6), // "number"
QT_MOC_LITERAL(5, 78, 11), // "clockNumber"
QT_MOC_LITERAL(6, 90, 21), // "onUpdataAllPointsData"
QT_MOC_LITERAL(7, 112, 11), // "onStartMark"
QT_MOC_LITERAL(8, 124, 10), // "onStopMark"
QT_MOC_LITERAL(9, 135, 14), // "onTaskFinished"
QT_MOC_LITERAL(10, 150, 6), // "result"
QT_MOC_LITERAL(11, 157, 12), // "onApplyParam"
QT_MOC_LITERAL(12, 170, 15), // "onOpenDlgSetCfg"
QT_MOC_LITERAL(13, 186, 25), // "onUpdataSelectedPointData"
QT_MOC_LITERAL(14, 212, 4), // "data"
QT_MOC_LITERAL(15, 217, 5), // "data2"
QT_MOC_LITERAL(16, 223, 22), // "onAddDataToTableWidget"
QT_MOC_LITERAL(17, 246, 15), // "onSaveCalibData"
QT_MOC_LITERAL(18, 262, 18), // "onOpenMarkParamSet"
QT_MOC_LITERAL(19, 281, 26), // "onOpenPositionDatumsDialog"
QT_MOC_LITERAL(20, 308, 10) // "onSetZBase"

    },
    "ClockWidget\0signalUpdataAllPointsData\0"
    "\0signalUpdatataSelectedPointData\0"
    "number\0clockNumber\0onUpdataAllPointsData\0"
    "onStartMark\0onStopMark\0onTaskFinished\0"
    "result\0onApplyParam\0onOpenDlgSetCfg\0"
    "onUpdataSelectedPointData\0data\0data2\0"
    "onAddDataToTableWidget\0onSaveCalibData\0"
    "onOpenMarkParamSet\0onOpenPositionDatumsDialog\0"
    "onSetZBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClockWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    2,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   90,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    1,   93,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    2,   98,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,
      17,    0,  104,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,
      19,    0,  106,    2, 0x0a /* Public */,
      20,    0,  107,    2, 0x0a /* Public */,

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
        case 0: _t->signalUpdataAllPointsData(); break;
        case 1: _t->signalUpdatataSelectedPointData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onUpdataAllPointsData(); break;
        case 3: _t->onStartMark(); break;
        case 4: _t->onStopMark(); break;
        case 5: _t->onTaskFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onApplyParam(); break;
        case 7: _t->onOpenDlgSetCfg(); break;
        case 8: _t->onUpdataSelectedPointData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->onAddDataToTableWidget(); break;
        case 10: _t->onSaveCalibData(); break;
        case 11: _t->onOpenMarkParamSet(); break;
        case 12: _t->onOpenPositionDatumsDialog(); break;
        case 13: _t->onSetZBase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClockWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClockWidget::signalUpdataAllPointsData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClockWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClockWidget::signalUpdatataSelectedPointData)) {
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ClockWidget::signalUpdataAllPointsData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClockWidget::signalUpdatataSelectedPointData(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
