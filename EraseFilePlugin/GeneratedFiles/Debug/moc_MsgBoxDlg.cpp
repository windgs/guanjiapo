/****************************************************************************
** Meta object code from reading C++ file 'MsgBoxDlg.h'
**
** Created: Wed May 16 16:52:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Common/CommonUI/MsgBoxDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MsgBoxDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MsgBoxDlg[] = {

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
      11,   10,   10,   10, 0x0a,
      18,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MsgBoxDlg[] = {
    "MsgBoxDlg\0\0OnOk()\0OnCancel()\0"
};

const QMetaObject MsgBoxDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MsgBoxDlg,
      qt_meta_data_MsgBoxDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MsgBoxDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MsgBoxDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MsgBoxDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MsgBoxDlg))
        return static_cast<void*>(const_cast< MsgBoxDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int MsgBoxDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnOk(); break;
        case 1: OnCancel(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
