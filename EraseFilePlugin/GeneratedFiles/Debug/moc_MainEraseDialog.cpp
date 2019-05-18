/****************************************************************************
** Meta object code from reading C++ file 'MainEraseDialog.h'
**
** Created: Wed May 16 16:52:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainEraseDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainEraseDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainEraseDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   16,   16,   16, 0x0a,
      41,   16,   16,   16, 0x0a,
      52,   16,   16,   16, 0x0a,
      67,   16,   16,   16, 0x0a,
      82,   16,   16,   16, 0x0a,
      96,   16,   16,   16, 0x0a,
     110,   16,   16,   16, 0x0a,
     124,   16,   16,   16, 0x0a,
     145,  138,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainEraseDialog[] = {
    "MainEraseDialog\0\0SignalClose()\0AddFile()\0"
    "OnAddDir()\0OnEraseStart()\0OnDeleteItem()\0"
    "OnFreeSpace()\0OnCloseForm()\0OnMinimized()\0"
    "OnMaximized()\0iValue\0OnProgressValue(int)\0"
};

const QMetaObject MainEraseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainEraseDialog,
      qt_meta_data_MainEraseDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainEraseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainEraseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainEraseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainEraseDialog))
        return static_cast<void*>(const_cast< MainEraseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainEraseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SignalClose(); break;
        case 1: AddFile(); break;
        case 2: OnAddDir(); break;
        case 3: OnEraseStart(); break;
        case 4: OnDeleteItem(); break;
        case 5: OnFreeSpace(); break;
        case 6: OnCloseForm(); break;
        case 7: OnMinimized(); break;
        case 8: OnMaximized(); break;
        case 9: OnProgressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainEraseDialog::SignalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
