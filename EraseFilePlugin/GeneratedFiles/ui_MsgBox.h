/********************************************************************************
** Form generated from reading UI file 'MsgBox.ui'
**
** Created: Wed May 16 16:52:32 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBOX_H
#define UI_MSGBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_MsgBoxDialog
{
public:
    QGraphicsView *graphicsView;
    QLabel *label_Msg;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;
    QToolButton *toolButton_Close;
    QGraphicsView *graphicsView_2;

    void setupUi(QDialog *MsgBoxDialog)
    {
        if (MsgBoxDialog->objectName().isEmpty())
            MsgBoxDialog->setObjectName(QString::fromUtf8("MsgBoxDialog"));
        MsgBoxDialog->resize(568, 92);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        MsgBoxDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/min_button/plugin_706.png"), QSize(), QIcon::Normal, QIcon::Off);
        MsgBoxDialog->setWindowIcon(icon);
        MsgBoxDialog->setAutoFillBackground(false);
        MsgBoxDialog->setStyleSheet(QString::fromUtf8(""));
        MsgBoxDialog->setSizeGripEnabled(true);
        MsgBoxDialog->setModal(false);
        graphicsView = new QGraphicsView(MsgBoxDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 30, 31, 31));
        graphicsView->setAutoFillBackground(true);
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/msgbox.png);\n"
"border-image: url(:/back_group/Resources/min_button/msgbox.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        label_Msg = new QLabel(MsgBoxDialog);
        label_Msg->setObjectName(QString::fromUtf8("label_Msg"));
        label_Msg->setGeometry(QRect(100, 31, 411, 21));
        label_Msg->setFont(font);
        pushButton_OK = new QPushButton(MsgBoxDialog);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(400, 60, 75, 31));
        pushButton_OK->setFont(font);
        pushButton_Cancel = new QPushButton(MsgBoxDialog);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(480, 60, 75, 31));
        pushButton_Cancel->setFont(font);
        toolButton_Close = new QToolButton(MsgBoxDialog);
        toolButton_Close->setObjectName(QString::fromUtf8("toolButton_Close"));
        toolButton_Close->setGeometry(QRect(532, 0, 21, 16));
        toolButton_Close->setAutoFillBackground(false);
        toolButton_Close->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/min_button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Close->setIcon(icon1);
        toolButton_Close->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Close->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Close->setArrowType(Qt::NoArrow);
        graphicsView_2 = new QGraphicsView(MsgBoxDialog);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 0, 16, 16));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView_2->setFrameShape(QFrame::NoFrame);

        retranslateUi(MsgBoxDialog);

        QMetaObject::connectSlotsByName(MsgBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *MsgBoxDialog)
    {
        MsgBoxDialog->setWindowTitle(QString());
        label_Msg->setText(QString());
        pushButton_OK->setText(QApplication::translate("MsgBoxDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_Cancel->setText(QApplication::translate("MsgBoxDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        toolButton_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MsgBoxDialog: public Ui_MsgBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOX_H
