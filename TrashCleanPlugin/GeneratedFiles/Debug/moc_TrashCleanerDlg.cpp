/****************************************************************************
** Meta object code from reading C++ file 'TrashCleanerDlg.h'
**
** Created: Wed May 16 16:52:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TrashCleanerDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrashCleanerDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrashCleanerDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      31,   16,   16,   16, 0x0a,
      47,   45,   16,   16, 0x0a,
      79,   16,   16,   16, 0x0a,
      88,   16,   16,   16, 0x0a,
     123,   98,   16,   16, 0x0a,
     174,  162,   16,   16, 0x0a,
     223,  214,   16,   16, 0x0a,
     255,  251,   16,   16, 0x0a,
     281,   16,   16,   16, 0x0a,
     298,  162,   16,   16, 0x0a,
     351,  340,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrashCleanerDlg[] = {
    "TrashCleanerDlg\0\0OnCloseForm()\0"
    "OnMinimized()\0,\0itemClick(QTreeWidgetItem*,int)\0"
    "OnScan()\0OnRemve()\0scanitem,path,FriendName\0"
    "OnItemAdd(QStringList,QString,QString)\0"
    "item,column\0OnTreeWidgetPress(QTreeWidgetItem*,int)\0"
    "filename\0OnDeleteWidgetItem(QString)\0"
    "dir\0OnCurrentFindDir(QString)\0"
    "OnSacnFinished()\0"
    "OnitemDoubleClicked(QTreeWidgetItem*,int)\0"
    "count,size\0OnHuiShouZhan(quint32,quint64)\0"
};

const QMetaObject TrashCleanerDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TrashCleanerDlg,
      qt_meta_data_TrashCleanerDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrashCleanerDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrashCleanerDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrashCleanerDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrashCleanerDlg))
        return static_cast<void*>(const_cast< TrashCleanerDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int TrashCleanerDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnCloseForm(); break;
        case 1: OnMinimized(); break;
        case 2: itemClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: OnScan(); break;
        case 4: OnRemve(); break;
        case 5: OnItemAdd((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: OnTreeWidgetPress((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: OnDeleteWidgetItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: OnCurrentFindDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: OnSacnFinished(); break;
        case 10: OnitemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: OnHuiShouZhan((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
