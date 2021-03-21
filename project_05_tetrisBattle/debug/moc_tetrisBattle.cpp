/****************************************************************************
** Meta object code from reading C++ file 'tetrisBattle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tetrisBattle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tetrisBattle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TetrisBattle_t {
    QByteArrayData data[12];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TetrisBattle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TetrisBattle_t qt_meta_stringdata_TetrisBattle = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TetrisBattle"
QT_MOC_LITERAL(1, 13, 16), // "createRectSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "componentName"
QT_MOC_LITERAL(4, 45, 1), // "x"
QT_MOC_LITERAL(5, 47, 1), // "y"
QT_MOC_LITERAL(6, 49, 5), // "color"
QT_MOC_LITERAL(7, 55, 12), // "startHandler"
QT_MOC_LITERAL(8, 68, 11), // "stopHandler"
QT_MOC_LITERAL(9, 80, 15), // "keyboardHandler"
QT_MOC_LITERAL(10, 96, 3), // "dir"
QT_MOC_LITERAL(11, 100, 13) // "updateHandler"

    },
    "TetrisBattle\0createRectSignal\0\0"
    "componentName\0x\0y\0color\0startHandler\0"
    "stopHandler\0keyboardHandler\0dir\0"
    "updateHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TetrisBattle[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   48,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,
       9,    1,   50,    2, 0x0a /* Public */,
      11,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void TetrisBattle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TetrisBattle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->createRectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->startHandler(); break;
        case 2: _t->stopHandler(); break;
        case 3: _t->keyboardHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TetrisBattle::*)(QString , int , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TetrisBattle::createRectSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TetrisBattle::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TetrisBattle.data,
    qt_meta_data_TetrisBattle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TetrisBattle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TetrisBattle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TetrisBattle.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TetrisBattle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TetrisBattle::createRectSignal(QString _t1, int _t2, int _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
