/****************************************************************************
** Meta object code from reading C++ file 'QtTCPServerHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LgNetwork/QtTCPServerHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtTCPServerHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtTCPServerHandler_t {
    QByteArrayData data[11];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtTCPServerHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtTCPServerHandler_t qt_meta_stringdata_QtTCPServerHandler = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QtTCPServerHandler"
QT_MOC_LITERAL(1, 19, 7), // "NewConn"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "clnAddr"
QT_MOC_LITERAL(4, 36, 7), // "clnPort"
QT_MOC_LITERAL(5, 44, 4), // "port"
QT_MOC_LITERAL(6, 49, 10), // "NewDisConn"
QT_MOC_LITERAL(7, 60, 12), // "NewDisConnEx"
QT_MOC_LITERAL(8, 73, 9), // "errString"
QT_MOC_LITERAL(9, 83, 10), // "RecvClnMsg"
QT_MOC_LITERAL(10, 94, 5) // "bytes"

    },
    "QtTCPServerHandler\0NewConn\0\0clnAddr\0"
    "clnPort\0port\0NewDisConn\0NewDisConnEx\0"
    "errString\0RecvClnMsg\0bytes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtTCPServerHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       6,    2,   56,    2, 0x06 /* Public */,
       7,    3,   61,    2, 0x06 /* Public */,
       9,    3,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       1,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::UShort,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QString,    3,    4,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray,    3,    4,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtTCPServerHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtTCPServerHandler *_t = static_cast<QtTCPServerHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewConn((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3]))); break;
        case 1: _t->NewDisConn((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 2: _t->NewDisConnEx((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->RecvClnMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 4: _t->NewConn(); break;
        case 5: _t->NewDisConn(); break;
        case 6: _t->RecvClnMsg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QtTCPServerHandler::*_t)(const QString & , const quint16 , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTCPServerHandler::NewConn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtTCPServerHandler::*_t)(const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTCPServerHandler::NewDisConn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QtTCPServerHandler::*_t)(const QString & , const quint16 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTCPServerHandler::NewDisConnEx)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QtTCPServerHandler::*_t)(const QString & , const quint16 , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTCPServerHandler::RecvClnMsg)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtTCPServerHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtTCPServerHandler.data,
      qt_meta_data_QtTCPServerHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtTCPServerHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtTCPServerHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtTCPServerHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtTCPServerHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QtTCPServerHandler::NewConn(const QString & _t1, const quint16 _t2, const quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtTCPServerHandler::NewDisConn(const QString & _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtTCPServerHandler::NewDisConnEx(const QString & _t1, const quint16 _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtTCPServerHandler::RecvClnMsg(const QString & _t1, const quint16 _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
