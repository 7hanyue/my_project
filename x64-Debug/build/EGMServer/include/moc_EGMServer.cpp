/****************************************************************************
** Meta object code from reading C++ file 'EGMServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../EGMServer/include/EGMServer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EGMServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSEGMServerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSEGMServerENDCLASS = QtMocHelpers::stringData(
    "EGMServer",
    "onChangeRobotType",
    "",
    "type",
    "onChangeProtocolType",
    "onDisplayRealtimeRobotData",
    "data",
    "onUpdateStartOrStopListenBtnIconStatus",
    "isEnable",
    "on_btnStratOrStopListen_clicked",
    "on_btnSaveData_clicked",
    "on_btnClearData_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEGMServerENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[21];
    char stringdata5[27];
    char stringdata6[5];
    char stringdata7[39];
    char stringdata8[9];
    char stringdata9[32];
    char stringdata10[23];
    char stringdata11[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEGMServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEGMServerENDCLASS_t qt_meta_stringdata_CLASSEGMServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "EGMServer"
        QT_MOC_LITERAL(10, 17),  // "onChangeRobotType"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 4),  // "type"
        QT_MOC_LITERAL(34, 20),  // "onChangeProtocolType"
        QT_MOC_LITERAL(55, 26),  // "onDisplayRealtimeRobotData"
        QT_MOC_LITERAL(82, 4),  // "data"
        QT_MOC_LITERAL(87, 38),  // "onUpdateStartOrStopListenBtnI..."
        QT_MOC_LITERAL(126, 8),  // "isEnable"
        QT_MOC_LITERAL(135, 31),  // "on_btnStratOrStopListen_clicked"
        QT_MOC_LITERAL(167, 22),  // "on_btnSaveData_clicked"
        QT_MOC_LITERAL(190, 23)   // "on_btnClearData_clicked"
    },
    "EGMServer",
    "onChangeRobotType",
    "",
    "type",
    "onChangeProtocolType",
    "onDisplayRealtimeRobotData",
    "data",
    "onUpdateStartOrStopListenBtnIconStatus",
    "isEnable",
    "on_btnStratOrStopListen_clicked",
    "on_btnSaveData_clicked",
    "on_btnClearData_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEGMServerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x08,    1 /* Private */,
       4,    1,   59,    2, 0x08,    3 /* Private */,
       5,    1,   62,    2, 0x08,    5 /* Private */,
       7,    1,   65,    2, 0x08,    7 /* Private */,
       9,    0,   68,    2, 0x08,    9 /* Private */,
      10,    0,   69,    2, 0x08,   10 /* Private */,
      11,    0,   70,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EGMServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSEGMServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEGMServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEGMServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EGMServer, std::true_type>,
        // method 'onChangeRobotType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onChangeProtocolType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onDisplayRealtimeRobotData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onUpdateStartOrStopListenBtnIconStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_btnStratOrStopListen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSaveData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnClearData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EGMServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EGMServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onChangeRobotType((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->onChangeProtocolType((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->onDisplayRealtimeRobotData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onUpdateStartOrStopListenBtnIconStatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_btnStratOrStopListen_clicked(); break;
        case 5: _t->on_btnSaveData_clicked(); break;
        case 6: _t->on_btnClearData_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *EGMServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EGMServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEGMServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EGMServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
