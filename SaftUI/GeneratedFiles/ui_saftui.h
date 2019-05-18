/********************************************************************************
** Form generated from reading UI file 'saftui.ui'
**
** Created: Wed May 16 16:52:30 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFTUI_H
#define UI_SAFTUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "conectrightwidth.h"
#include "feturelistview.h"
#include "statubar.h"
#include "titlebar.h"
#include "toolbar.h"

QT_BEGIN_NAMESPACE

class Ui_SaftUIClass
{
public:
    ToolBar *widget_ToolBar;
    TitleBar *widget_Title;
    QGraphicsView *graphicsView;
    QWidget *widget_Conect;
    CFetureListView *listView_Feture;
    ConectRightWidth *widget_List;
    QToolButton *toolButton_ckeck;
    QGraphicsView *graphicsView_check;
    QLabel *label_list_1;
    QLabel *label_list_2;
    QLabel *label_list_last_check;
    StatuBar *widget_status;
    QLabel *label_status_1;
    QLabel *label;
    QFrame *line;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QPushButton *pushButton_OpenSkinDlg;

    void setupUi(QWidget *SaftUIClass)
    {
        if (SaftUIClass->objectName().isEmpty())
            SaftUIClass->setObjectName(QString::fromUtf8("SaftUIClass"));
        SaftUIClass->resize(856, 575);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/back_group/Resources/min_button/plugin_706.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaftUIClass->setWindowIcon(icon);
        SaftUIClass->setAutoFillBackground(false);
        SaftUIClass->setStyleSheet(QString::fromUtf8(""));
        widget_ToolBar = new ToolBar(SaftUIClass);
        widget_ToolBar->setObjectName(QString::fromUtf8("widget_ToolBar"));
        widget_ToolBar->setGeometry(QRect(0, 20, 811, 71));
        widget_Title = new TitleBar(SaftUIClass);
        widget_Title->setObjectName(QString::fromUtf8("widget_Title"));
        widget_Title->setGeometry(QRect(0, 0, 811, 21));
        graphicsView = new QGraphicsView(widget_Title);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 2, 16, 16));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        widget_Conect = new QWidget(SaftUIClass);
        widget_Conect->setObjectName(QString::fromUtf8("widget_Conect"));
        widget_Conect->setGeometry(QRect(0, 110, 281, 441));
        widget_Conect->setAutoFillBackground(false);
        widget_Conect->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/conect.png);"));
        listView_Feture = new CFetureListView(widget_Conect);
        listView_Feture->setObjectName(QString::fromUtf8("listView_Feture"));
        listView_Feture->setGeometry(QRect(0, -10, 281, 451));
        listView_Feture->setAutoFillBackground(true);
        listView_Feture->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/conect.png);"));
        widget_List = new ConectRightWidth(SaftUIClass);
        widget_List->setObjectName(QString::fromUtf8("widget_List"));
        widget_List->setGeometry(QRect(280, 110, 581, 441));
        widget_List->setAutoFillBackground(false);
        widget_List->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/conect.png);"));
        toolButton_ckeck = new QToolButton(widget_List);
        toolButton_ckeck->setObjectName(QString::fromUtf8("toolButton_ckeck"));
        toolButton_ckeck->setGeometry(QRect(210, 160, 191, 61));
        toolButton_ckeck->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/button/safe.png);"));
        graphicsView_check = new QGraphicsView(widget_List);
        graphicsView_check->setObjectName(QString::fromUtf8("graphicsView_check"));
        graphicsView_check->setGeometry(QRect(30, 10, 81, 81));
        graphicsView_check->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/check.png);"));
        graphicsView_check->setFrameShape(QFrame::NoFrame);
        graphicsView_check->setFrameShadow(QFrame::Sunken);
        label_list_1 = new QLabel(widget_List);
        label_list_1->setObjectName(QString::fromUtf8("label_list_1"));
        label_list_1->setGeometry(QRect(140, 20, 351, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_list_1->setFont(font);
        label_list_2 = new QLabel(widget_List);
        label_list_2->setObjectName(QString::fromUtf8("label_list_2"));
        label_list_2->setGeometry(QRect(150, 250, 321, 31));
        label_list_2->setFont(font);
        label_list_last_check = new QLabel(widget_List);
        label_list_last_check->setObjectName(QString::fromUtf8("label_list_last_check"));
        label_list_last_check->setGeometry(QRect(150, 280, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_list_last_check->setFont(font1);
        widget_status = new StatuBar(SaftUIClass);
        widget_status->setObjectName(QString::fromUtf8("widget_status"));
        widget_status->setGeometry(QRect(10, 550, 841, 21));
        label_status_1 = new QLabel(widget_status);
        label_status_1->setObjectName(QString::fromUtf8("label_status_1"));
        label_status_1->setGeometry(QRect(10, 0, 81, 16));
        label_status_1->setFont(font1);
        label = new QLabel(widget_status);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 0, 71, 20));
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        line = new QFrame(SaftUIClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(273, 110, 16, 441));
        line->setAutoFillBackground(false);
        line->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/conect.png);"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::VLine);
        splitter = new QSplitter(SaftUIClass);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 0, 0));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(SaftUIClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(SaftUIClass);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(0, 0, 0, 0));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(SaftUIClass);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(0, 0, 0, 0));
        splitter_3->setOrientation(Qt::Horizontal);
        pushButton_OpenSkinDlg = new QPushButton(SaftUIClass);
        pushButton_OpenSkinDlg->setObjectName(QString::fromUtf8("pushButton_OpenSkinDlg"));
        pushButton_OpenSkinDlg->setGeometry(QRect(821, 80, 16, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/cskin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenSkinDlg->setIcon(icon1);
        pushButton_OpenSkinDlg->setFlat(false);

        retranslateUi(SaftUIClass);

        QMetaObject::connectSlotsByName(SaftUIClass);
    } // setupUi

    void retranslateUi(QWidget *SaftUIClass)
    {
        SaftUIClass->setWindowTitle(QApplication::translate("SaftUIClass", "SaftUI", 0, QApplication::UnicodeUTF8));
        toolButton_ckeck->setText(QString());
        label_list_1->setText(QApplication::translate("SaftUIClass", "\345\256\236\346\227\266\351\230\262\346\212\244\345\267\262\345\205\250\351\203\250\345\274\200\345\220\257\357\274\214\347\224\265\350\204\221\346\255\243\345\234\250\350\242\253\344\277\235\346\212\244\344\270\255...", 0, QApplication::UnicodeUTF8));
        label_list_2->setText(QApplication::translate("SaftUIClass", "\345\256\211\345\205\250\344\275\223\346\243\200\345\217\257\344\273\245\345\205\250\351\235\242\344\272\206\350\247\243\347\224\265\350\204\221\347\212\266\345\206\265\357\274\214\351\230\262\346\202\243\344\272\216\346\234\252\347\204\266", 0, QApplication::UnicodeUTF8));
        label_list_last_check->setText(QApplication::translate("SaftUIClass", "\344\270\212\346\254\241\344\275\223\346\243\200 :", 0, QApplication::UnicodeUTF8));
        label_status_1->setText(QApplication::translate("SaftUIClass", "\344\270\273\347\250\213\345\272\217\347\211\210\346\234\254\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SaftUIClass", "<a href=\"www.baidu.com\">\346\243\200\346\237\245\346\233\264\346\226\260</a>", 0, QApplication::UnicodeUTF8));
        pushButton_OpenSkinDlg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SaftUIClass: public Ui_SaftUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFTUI_H
