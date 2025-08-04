/****************************************************************************
** Meta object code from reading C++ file 'EGMServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../EGMServer/include/EGMServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EGMServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EGMServer_t {
    QByteArrayData data[12];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EGMServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EGMServer_t qt_meta_stringdata_EGMServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EGMServer"
QT_MOC_LITERAL(1, 10, 17), // "onChangeRobotType"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "type"
QT_MOC_LITERAL(4, 34, 20), // "onChangeProtocolType"
QT_MOC_LITERAL(5, 55, 26), // "onDisplayRealtimeRobotData"
QT_MOC_LITERAL(6, 82, 4), // "data"
QT_MOC_LITERAL(7, 87, 38), // "onUpdateStartOrStopListenBtnI..."
QT_MOC_LITERAL(8, 126, 8), // "isEnable"
QT_MOC_LITERAL(9, 135, 31), // "on_btnStratOrStopListen_clicked"
QT_MOC_LITERAL(10, 167, 22), // "on_btnSaveData_clicked"
QT_MOC_LITERAL(11, 190, 23) // "on_btnClearData_clicked"

    },
    "EGMServer\0onChangeRobotType\0\0type\0"
    "onChangeProtocolType\0onDisplayRealtimeRobotData\0"
    "data\0onUpdateStartOrStopListenBtnIconStatus\0"
    "isEnable\0on_btnStratOrStopListen_clicked\0"
    "on_btnSaveData_clicked\0on_btnClearData_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EGMServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       5,    1,   55,    2, 0x08 /* Private */,
       7,    1,   58,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

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

void EGMServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EGMServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onChangeRobotType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onChangeProtocolType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onDisplayRealtimeRobotData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onUpdateStartOrStopListenBtnIconStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_btnStratOrStopListen_clicked(); break;
        case 5: _t->on_btnSaveData_clicked(); break;
        case 6: _t->on_btnClearData_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EGMServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EGMServer.data,
    qt_meta_data_EGMServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EGMServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EGMServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EGMServer.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
