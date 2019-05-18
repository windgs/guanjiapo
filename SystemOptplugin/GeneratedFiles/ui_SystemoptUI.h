/********************************************************************************
** Form generated from reading UI file 'SystemoptUI.ui'
**
** Created: Wed May 16 16:52:31 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMOPTUI_H
#define UI_SYSTEMOPTUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "SystemoptTitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    SystemoptTitleBar *widget;
    QGraphicsView *graphicsView;
    QToolButton *toolButton_Min;
    QToolButton *toolButton_close;
    QTabWidget *tabWidgetUI;
    QWidget *tab_start;
    QWidget *tab_server;
    QLabel *label_tips;
    QCheckBox *checkBox_Startitem;
    QLabel *label_2;
    QTableWidget *tableWidget_RunTable;
    QLabel *label_tips_2;
    QWidget *tab_2;
    QTableWidget *tableWidget_Service;
    QLabel *label;
    QCheckBox *checkBox;
    QWidget *tab;
    QWidget *tab_starttime;
    QLabel *label_Load_Tips;
    QLabel *label_Opt_Load_Gif;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(811, 486);
        widget = new SystemoptTitleBar(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 811, 21));
        widget->setAutoFillBackground(true);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 16, 16));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        toolButton_Min = new QToolButton(widget);
        toolButton_Min->setObjectName(QString::fromUtf8("toolButton_Min"));
        toolButton_Min->setGeometry(QRect(770, 0, 23, 16));
        toolButton_Min->setAutoFillBackground(false);
        toolButton_Min->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/minb1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Min->setIcon(icon);
        toolButton_Min->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Min->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Min->setArrowType(Qt::NoArrow);
        toolButton_close = new QToolButton(widget);
        toolButton_close->setObjectName(QString::fromUtf8("toolButton_close"));
        toolButton_close->setGeometry(QRect(790, 0, 23, 16));
        toolButton_close->setAutoFillBackground(false);
        toolButton_close->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close->setIcon(icon1);
        toolButton_close->setPopupMode(QToolButton::DelayedPopup);
        toolButton_close->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_close->setArrowType(Qt::NoArrow);
        tabWidgetUI = new QTabWidget(Dialog);
        tabWidgetUI->setObjectName(QString::fromUtf8("tabWidgetUI"));
        tabWidgetUI->setGeometry(QRect(0, 20, 821, 461));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        tabWidgetUI->setFont(font);
        tabWidgetUI->setLayoutDirection(Qt::LeftToRight);
        tabWidgetUI->setTabPosition(QTabWidget::North);
        tabWidgetUI->setTabShape(QTabWidget::Rounded);
        tabWidgetUI->setElideMode(Qt::ElideMiddle);
        tabWidgetUI->setDocumentMode(false);
        tab_start = new QWidget();
        tab_start->setObjectName(QString::fromUtf8("tab_start"));
        tabWidgetUI->addTab(tab_start, QString());
        tab_server = new QWidget();
        tab_server->setObjectName(QString::fromUtf8("tab_server"));
        label_tips = new QLabel(tab_server);
        label_tips->setObjectName(QString::fromUtf8("label_tips"));
        label_tips->setGeometry(QRect(360, 10, 181, 21));
        QFont font1;
        font1.setPointSize(10);
        label_tips->setFont(font1);
        checkBox_Startitem = new QCheckBox(tab_server);
        checkBox_Startitem->setObjectName(QString::fromUtf8("checkBox_Startitem"));
        checkBox_Startitem->setGeometry(QRect(570, 10, 131, 16));
        checkBox_Startitem->setFont(font1);
        label_2 = new QLabel(tab_server);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 6, 31, 20));
        label_2->setFont(font1);
        tableWidget_RunTable = new QTableWidget(tab_server);
        tableWidget_RunTable->setObjectName(QString::fromUtf8("tableWidget_RunTable"));
        tableWidget_RunTable->setGeometry(QRect(0, 40, 811, 381));
        QFont font2;
        font2.setPointSize(9);
        tableWidget_RunTable->setFont(font2);
        tableWidget_RunTable->setStyleSheet(QString::fromUtf8(""));
        tableWidget_RunTable->setFrameShape(QFrame::NoFrame);
        tableWidget_RunTable->setFrameShadow(QFrame::Plain);
        tableWidget_RunTable->setLineWidth(0);
        tableWidget_RunTable->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableWidget_RunTable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_RunTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_RunTable->setIconSize(QSize(32, 32));
        tableWidget_RunTable->setTextElideMode(Qt::ElideLeft);
        tableWidget_RunTable->setShowGrid(false);
        tableWidget_RunTable->setGridStyle(Qt::NoPen);
        tableWidget_RunTable->horizontalHeader()->setVisible(false);
        tableWidget_RunTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_RunTable->verticalHeader()->setVisible(false);
        tableWidget_RunTable->verticalHeader()->setHighlightSections(false);
        tableWidget_RunTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        label_tips_2 = new QLabel(tab_server);
        label_tips_2->setObjectName(QString::fromUtf8("label_tips_2"));
        label_tips_2->setGeometry(QRect(0, 10, 331, 21));
        label_tips_2->setFont(font1);
        tabWidgetUI->addTab(tab_server, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidget_Service = new QTableWidget(tab_2);
        tableWidget_Service->setObjectName(QString::fromUtf8("tableWidget_Service"));
        tableWidget_Service->setGeometry(QRect(0, 30, 791, 391));
        tableWidget_Service->setFrameShape(QFrame::NoFrame);
        tableWidget_Service->setFrameShadow(QFrame::Plain);
        tableWidget_Service->setLineWidth(0);
        tableWidget_Service->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        tableWidget_Service->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Service->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Service->setIconSize(QSize(32, 32));
        tableWidget_Service->setShowGrid(false);
        tableWidget_Service->setGridStyle(Qt::NoPen);
        tableWidget_Service->verticalHeader()->setVisible(false);
        tableWidget_Service->verticalHeader()->setHighlightSections(false);
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 451, 16));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(600, 10, 111, 16));
        checkBox->setFont(font2);
        tabWidgetUI->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidgetUI->addTab(tab, QString());
        tab_starttime = new QWidget();
        tab_starttime->setObjectName(QString::fromUtf8("tab_starttime"));
        tabWidgetUI->addTab(tab_starttime, QString());
        label_Load_Tips = new QLabel(Dialog);
        label_Load_Tips->setObjectName(QString::fromUtf8("label_Load_Tips"));
        label_Load_Tips->setEnabled(true);
        label_Load_Tips->setGeometry(QRect(330, 260, 151, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        label_Load_Tips->setFont(font3);
        label_Opt_Load_Gif = new QLabel(Dialog);
        label_Opt_Load_Gif->setObjectName(QString::fromUtf8("label_Opt_Load_Gif"));
        label_Opt_Load_Gif->setGeometry(QRect(350, 190, 61, 51));

        retranslateUi(Dialog);

        tabWidgetUI->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\347\263\273\347\273\237\344\274\230\345\214\226-\347\256\241\345\256\266\345\251\206", 0, QApplication::UnicodeUTF8));
        toolButton_Min->setText(QString());
        toolButton_close->setText(QString());
        tabWidgetUI->setTabText(tabWidgetUI->indexOf(tab_start), QApplication::translate("Dialog", "\344\270\200\351\224\256\344\274\230\345\214\226", 0, QApplication::UnicodeUTF8));
        label_tips->setText(QApplication::translate("Dialog", "\344\275\240\347\232\204\347\224\265\350\204\221\345\205\261\346\234\21110\344\270\252\345\220\257\345\212\250\351\241\271", 0, QApplication::UnicodeUTF8));
        checkBox_Startitem->setText(QApplication::translate("Dialog", "\346\230\276\347\244\272\345\267\262\347\246\201\347\224\250\347\232\204\351\241\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "<a href=\"www.baidu.com\">\345\210\267\346\226\260</a>", 0, QApplication::UnicodeUTF8));
        label_tips_2->setText(QApplication::translate("Dialog", "\342\200\234\345\220\257\345\212\250\351\241\271\342\200\235\345\234\250\345\274\200\346\234\272\345\220\216\350\207\252\345\212\250\350\277\220\350\241\214\357\274\214\345\273\272\350\256\256\345\205\263\351\227\255\344\270\215\345\277\205\350\246\201\347\232\204\351\241\271", 0, QApplication::UnicodeUTF8));
        tabWidgetUI->setTabText(tabWidgetUI->indexOf(tab_server), QApplication::translate("Dialog", "\345\220\257\345\212\250\351\241\271", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\344\275\240\347\232\204\347\224\265\350\204\221\345\205\261\346\234\21148\344\270\252\345\274\200\346\234\272\345\220\257\345\212\250\346\234\215\345\212\241\351\241\271\357\274\214\347\246\201\347\224\250\344\270\215\351\234\200\350\246\201\347\232\204\345\220\257\345\212\250\351\241\271\345\217\257\344\273\245\345\212\240\345\277\253\345\274\200\346\234\272\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Dialog", "\346\230\276\347\244\272\350\242\253\347\246\201\346\255\242\347\232\204\351\241\271", 0, QApplication::UnicodeUTF8));
        tabWidgetUI->setTabText(tabWidgetUI->indexOf(tab_2), QApplication::translate("Dialog", "\346\234\215\345\212\241\351\241\271", 0, QApplication::UnicodeUTF8));
        tabWidgetUI->setTabText(tabWidgetUI->indexOf(tab), QApplication::translate("Dialog", "\350\256\241\345\210\222\344\273\273\345\212\241", 0, QApplication::UnicodeUTF8));
        tabWidgetUI->setTabText(tabWidgetUI->indexOf(tab_starttime), QApplication::translate("Dialog", "\345\274\200\346\234\272\346\227\266\351\227\264\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label_Load_Tips->setText(QApplication::translate("Dialog", "\346\255\243\345\234\250\346\211\253\346\217\217\345\274\200\346\234\272\351\241\271......", 0, QApplication::UnicodeUTF8));
        label_Opt_Load_Gif->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMOPTUI_H
