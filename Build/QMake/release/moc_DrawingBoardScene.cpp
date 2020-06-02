/****************************************************************************
** Meta object code from reading C++ file 'DrawingBoardScene.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Implementation/DrawingBoardScene.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawingBoardScene.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawingBoardScene_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawingBoardScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawingBoardScene_t qt_meta_stringdata_DrawingBoardScene = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DrawingBoardScene"
QT_MOC_LITERAL(1, 18, 10), // "mouseClick"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "point"
QT_MOC_LITERAL(4, 36, 15) // "FinishedDrawing"

    },
    "DrawingBoardScene\0mouseClick\0\0point\0"
    "FinishedDrawing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawingBoardScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    0,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,

       0        // eod
};

void DrawingBoardScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DrawingBoardScene *_t = static_cast<DrawingBoardScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->FinishedDrawing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DrawingBoardScene::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawingBoardScene::mouseClick)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DrawingBoardScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawingBoardScene::FinishedDrawing)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DrawingBoardScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_DrawingBoardScene.data,
      qt_meta_data_DrawingBoardScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DrawingBoardScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawingBoardScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DrawingBoardScene.stringdata0))
        return static_cast<void*>(const_cast< DrawingBoardScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int DrawingBoardScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DrawingBoardScene::mouseClick(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawingBoardScene::FinishedDrawing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
