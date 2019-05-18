/****************************************************************************
** Meta object code from reading C++ file 'MainPlugin.h'
**
** Created: Wed May 16 16:52:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainPlugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMainPlugin[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CMainPlugin[] = {
    "CMainPlugin\0\0SlotCloseWindow()\0"
};

const QMetaObject CMainPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CMainPlugin,
      qt_meta_data_CMainPlugin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMainPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMainPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMainPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMainPlugin))
        return static_cast<void*>(const_cast< CMainPlugin*>(this));
    if (!strcmp(_clname, "ISafeCommon"))
        return static_cast< ISafeCommon*>(const_cast< CMainPlugin*>(this));
    if (!strcmp(_clname, "0895260D-9053-4e8a-B37C-9C05CCFE4A14"))
        return static_cast< ISafeCommon*>(const_cast< CMainPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int CMainPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SlotCloseWindow(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
