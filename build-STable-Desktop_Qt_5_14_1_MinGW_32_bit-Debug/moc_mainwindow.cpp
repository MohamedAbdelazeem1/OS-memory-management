/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../STable/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_holesNumber_Changed"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "text"
QT_MOC_LITERAL(4, 40, 21), // "on_memorySize_Changed"
QT_MOC_LITERAL(5, 62, 21), // "on_addProcess_clicked"
QT_MOC_LITERAL(6, 84, 22), // "on_addToMemory_clicked"
QT_MOC_LITERAL(7, 107, 28), // "on_removeLastProcess_clicked"
QT_MOC_LITERAL(8, 136, 22), // "on_myTable_itemChanged"
QT_MOC_LITERAL(9, 159, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(10, 177, 4), // "item"
QT_MOC_LITERAL(11, 182, 20), // "on_drawHoles_clicked"
QT_MOC_LITERAL(12, 203, 16), // "on_reset_clicked"
QT_MOC_LITERAL(13, 220, 12), // "submitTables"
QT_MOC_LITERAL(14, 233, 19), // "on_algorithm_change"
QT_MOC_LITERAL(15, 253, 23), // "on_processSelect_change"
QT_MOC_LITERAL(16, 277, 28) // "on_deallocateProcess_clicked"

    },
    "MainWindow\0on_holesNumber_Changed\0\0"
    "text\0on_memorySize_Changed\0"
    "on_addProcess_clicked\0on_addToMemory_clicked\0"
    "on_removeLastProcess_clicked\0"
    "on_myTable_itemChanged\0QTableWidgetItem*\0"
    "item\0on_drawHoles_clicked\0on_reset_clicked\0"
    "submitTables\0on_algorithm_change\0"
    "on_processSelect_change\0"
    "on_deallocateProcess_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    0,   80,    2, 0x08 /* Private */,
       6,    0,   81,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    1,   89,    2, 0x08 /* Private */,
      15,    1,   92,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_holesNumber_Changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_memorySize_Changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_addProcess_clicked(); break;
        case 3: _t->on_addToMemory_clicked(); break;
        case 4: _t->on_removeLastProcess_clicked(); break;
        case 5: _t->on_myTable_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_drawHoles_clicked(); break;
        case 7: _t->on_reset_clicked(); break;
        case 8: _t->submitTables(); break;
        case 9: _t->on_algorithm_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_processSelect_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_deallocateProcess_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
