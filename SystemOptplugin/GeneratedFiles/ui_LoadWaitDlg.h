/********************************************************************************
** Form generated from reading UI file 'LoadWaitDlg.ui'
**
** Created: Wed May 16 16:52:53 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWAITDLG_H
#define UI_LOADWAITDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Run_Load_Wait
{
public:
    QLabel *label_Gif;
    QLabel *label_Text;

    void setupUi(QDialog *Dialog_Run_Load_Wait)
    {
        if (Dialog_Run_Load_Wait->objectName().isEmpty())
            Dialog_Run_Load_Wait->setObjectName(QString::fromUtf8("Dialog_Run_Load_Wait"));
        Dialog_Run_Load_Wait->resize(230, 73);
        label_Gif = new QLabel(Dialog_Run_Load_Wait);
        label_Gif->setObjectName(QString::fromUtf8("label_Gif"));
        label_Gif->setGeometry(QRect(40, 30, 21, 21));
        label_Text = new QLabel(Dialog_Run_Load_Wait);
        label_Text->setObjectName(QString::fromUtf8("label_Text"));
        label_Text->setGeometry(QRect(90, 20, 121, 31));

        retranslateUi(Dialog_Run_Load_Wait);

        QMetaObject::connectSlotsByName(Dialog_Run_Load_Wait);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Run_Load_Wait)
    {
        Dialog_Run_Load_Wait->setWindowTitle(QApplication::translate("Dialog_Run_Load_Wait", "Dialog", 0, QApplication::UnicodeUTF8));
        label_Gif->setText(QString());
        label_Text->setText(QApplication::translate("Dialog_Run_Load_Wait", "\346\255\243\345\234\250\345\212\240\350\275\275\357\274\214\350\257\267\347\250\215\345\200\231...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Run_Load_Wait: public Ui_Dialog_Run_Load_Wait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWAITDLG_H
