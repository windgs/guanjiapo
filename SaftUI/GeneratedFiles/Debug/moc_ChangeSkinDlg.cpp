/****************************************************************************
** Meta object code from reading C++ file 'ChangeSkinDlg.h'
**
** Created: Wed May 16 16:52:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChangeSkinDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChangeSkinDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangeSkinDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      29,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChangeSkinDlg[] = {
    "ChangeSkinDlg\0\0OnCloseForm()\0OnMinimized()\0"
};

const QMetaObject ChangeSkinDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChangeSkinDlg,
      qt_meta_data_ChangeSkinDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangeSkinDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangeSkinDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangeSkinDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeSkinDlg))
        return static_cast<void*>(const_cast< ChangeSkinDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChangeSkinDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnCloseForm(); break;
        case 1: OnMinimized(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
