/****************************************************************************
** Meta object code from reading C++ file 'FilePlanter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FilePlanter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilePlanter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StudentFileTransfer_t {
    QByteArrayData data[12];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudentFileTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudentFileTransfer_t qt_meta_stringdata_StudentFileTransfer = {
    {
QT_MOC_LITERAL(0, 0, 19), // "StudentFileTransfer"
QT_MOC_LITERAL(1, 20, 25), // "on_btn_choosefile_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 23), // "on_btn_sendfile_clicked"
QT_MOC_LITERAL(4, 71, 24), // "on_btn_userfresh_clicked"
QT_MOC_LITERAL(5, 96, 10), // "RecvClnMsg"
QT_MOC_LITERAL(6, 107, 7), // "clnAddr"
QT_MOC_LITERAL(7, 115, 7), // "clnPort"
QT_MOC_LITERAL(8, 123, 5), // "bytes"
QT_MOC_LITERAL(9, 129, 10), // "NewDisConn"
QT_MOC_LITERAL(10, 140, 10), // "RemoveUser"
QT_MOC_LITERAL(11, 151, 3) // "sIp"

    },
    "StudentFileTransfer\0on_btn_choosefile_clicked\0"
    "\0on_btn_sendfile_clicked\0"
    "on_btn_userfresh_clicked\0RecvClnMsg\0"
    "clnAddr\0clnPort\0bytes\0NewDisConn\0"
    "RemoveUser\0sIp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudentFileTransfer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    3,   47,    2, 0x08 /* Private */,
       9,    2,   54,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void StudentFileTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StudentFileTransfer *_t = static_cast<StudentFileTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_choosefile_clicked(); break;
        case 1: _t->on_btn_sendfile_clicked(); break;
        case 2: _t->on_btn_userfresh_clicked(); break;
        case 3: _t->RecvClnMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 4: _t->NewDisConn((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 5: _t->RemoveUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StudentFileTransfer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StudentFileTransfer.data,
      qt_meta_data_StudentFileTransfer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StudentFileTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentFileTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StudentFileTransfer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int StudentFileTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
