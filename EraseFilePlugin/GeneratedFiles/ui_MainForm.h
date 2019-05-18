/********************************************************************************
** Form generated from reading UI file 'MainForm.ui'
**
** Created: Wed May 16 16:52:32 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "eraseplugintitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableView *tableView_Fiels;
    QPushButton *pushButton_AddFile;
    QPushButton *pushButton_Add_Dir;
    QPushButton *pushButton_Erase_File;
    ErasePluginTitleBar *widget;
    QToolButton *toolButton_Min;
    QGraphicsView *graphicsView;
    QToolButton *toolButton_Close;
    QPushButton *pushButton_Delete;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton_FreeSpace;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar_FreeSpace;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(745, 435);
        Dialog->setAutoFillBackground(false);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        tableView_Fiels = new QTableView(Dialog);
        tableView_Fiels->setObjectName(QString::fromUtf8("tableView_Fiels"));
        tableView_Fiels->setGeometry(QRect(0, 50, 741, 331));
        tableView_Fiels->setFrameShape(QFrame::NoFrame);
        pushButton_AddFile = new QPushButton(Dialog);
        pushButton_AddFile->setObjectName(QString::fromUtf8("pushButton_AddFile"));
        pushButton_AddFile->setGeometry(QRect(10, 390, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        pushButton_AddFile->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/back_group/Resources/button/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_AddFile->setIcon(icon);
        pushButton_AddFile->setAutoRepeat(false);
        pushButton_AddFile->setAutoDefault(false);
        pushButton_AddFile->setFlat(false);
        pushButton_Add_Dir = new QPushButton(Dialog);
        pushButton_Add_Dir->setObjectName(QString::fromUtf8("pushButton_Add_Dir"));
        pushButton_Add_Dir->setGeometry(QRect(120, 390, 101, 31));
        pushButton_Add_Dir->setFont(font);
        pushButton_Erase_File = new QPushButton(Dialog);
        pushButton_Erase_File->setObjectName(QString::fromUtf8("pushButton_Erase_File"));
        pushButton_Erase_File->setGeometry(QRect(640, 390, 101, 31));
        pushButton_Erase_File->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../SaftUI/Resources/feture_button/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Erase_File->setIcon(icon1);
        widget = new ErasePluginTitleBar(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 751, 21));
        widget->setAutoFillBackground(true);
        widget->setStyleSheet(QString::fromUtf8(""));
        toolButton_Min = new QToolButton(widget);
        toolButton_Min->setObjectName(QString::fromUtf8("toolButton_Min"));
        toolButton_Min->setGeometry(QRect(700, 0, 23, 16));
        toolButton_Min->setAutoFillBackground(false);
        toolButton_Min->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/minb1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Min->setIcon(icon2);
        toolButton_Min->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Min->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Min->setArrowType(Qt::NoArrow);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 16, 16));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        toolButton_Close = new QToolButton(widget);
        toolButton_Close->setObjectName(QString::fromUtf8("toolButton_Close"));
        toolButton_Close->setGeometry(QRect(720, 0, 23, 16));
        toolButton_Close->setAutoFillBackground(false);
        toolButton_Close->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Close->setIcon(icon3);
        toolButton_Close->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Close->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Close->setArrowType(Qt::NoArrow);
        pushButton_Delete = new QPushButton(Dialog);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(340, 390, 101, 31));
        pushButton_Delete->setFont(font);
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(59, 460, 591, 234));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_FreeSpace = new QPushButton(Dialog);
        pushButton_FreeSpace->setObjectName(QString::fromUtf8("pushButton_FreeSpace"));
        pushButton_FreeSpace->setGeometry(QRect(230, 390, 101, 31));
        pushButton_FreeSpace->setFont(font);
        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(0, 20, 741, 27));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        progressBar_FreeSpace = new QProgressBar(widget1);
        progressBar_FreeSpace->setObjectName(QString::fromUtf8("progressBar_FreeSpace"));
        progressBar_FreeSpace->setFont(font);
        progressBar_FreeSpace->setValue(0);

        horizontalLayout->addWidget(progressBar_FreeSpace);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\226\207\344\273\266\347\262\211\347\242\216", 0, QApplication::UnicodeUTF8));
        pushButton_AddFile->setText(QApplication::translate("Dialog", "\346\267\273\345\212\240\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        pushButton_Add_Dir->setText(QApplication::translate("Dialog", "\346\267\273\345\212\240\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_Erase_File->setText(QApplication::translate("Dialog", "\347\262\211\347\242\216", 0, QApplication::UnicodeUTF8));
        toolButton_Min->setText(QString());
        toolButton_Close->setText(QString());
        pushButton_Delete->setText(QApplication::translate("Dialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_FreeSpace->setText(QApplication::translate("Dialog", "\346\270\205\347\220\206\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\346\202\250\345\217\257\344\273\245\345\275\273\345\272\225\347\262\211\347\242\216\346\227\240\346\263\225\345\210\240\351\231\244\347\232\204\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
