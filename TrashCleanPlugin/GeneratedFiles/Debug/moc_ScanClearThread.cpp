/****************************************************************************
** Meta object code from reading C++ file 'ScanClearThread.h'
**
** Created: Wed May 16 16:52:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScanClearThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScanClearThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScanClearThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   17,   16,   16, 0x05,
      59,   57,   16,   16, 0x05,
      94,   16,   16,   16, 0x05,
     120,   16,   16,   16, 0x05,
     137,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ScanClearThread[] = {
    "ScanClearThread\0\0,,\0"
    "ItemAdd(QStringList,QString,QString)\0"
    ",\0NotifyHuiShouZhan(quint32,quint64)\0"
    "NotifyDeleteFile(QString)\0NotifyFinished()\0"
    "NotifyCurrentFindDir(QString)\0"
};

const QMetaObject ScanClearThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ScanClearThread,
      qt_meta_data_ScanClearThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScanClearThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScanClearThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScanClearThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScanClearThread))
        return static_cast<void*>(const_cast< ScanClearThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ScanClearThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ItemAdd((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: NotifyHuiShouZhan((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 2: NotifyDeleteFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: NotifyFinished(); break;
        case 4: NotifyCurrentFindDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ScanClearThread::ItemAdd(QStringList _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScanClearThread::NotifyHuiShouZhan(quint32 _t1, quint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScanClearThread::NotifyDeleteFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScanClearThread::NotifyFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ScanClearThread::NotifyCurrentFindDir(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
