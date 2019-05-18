/********************************************************************************
** Form generated from reading UI file 'TrashCleanDlg.ui'
**
** Created: Wed May 16 16:52:32 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRASHCLEANDLG_H
#define UI_TRASHCLEANDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include "trashcleantitlebar.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    TrashCleanTitleBar *widget;
    QGraphicsView *graphicsView;
    QToolButton *toolButton_Min_2;
    QToolButton *toolButton_Close_2;
    QToolButton *toolButton_Close;
    QToolButton *toolButton_Min;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Clean;
    QLabel *label_notes;
    QTreeWidget *treeWidget_trash;
    QCheckBox *checkBox_All;
    QLabel *label_2;
    QGraphicsView *graphicsView_2;
    QLabel *label_Trash_gif;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(803, 550);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        Dialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/plugin_706.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        widget = new TrashCleanTitleBar(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 811, 21));
        widget->setAutoFillBackground(true);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 16, 16));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        toolButton_Min_2 = new QToolButton(widget);
        toolButton_Min_2->setObjectName(QString::fromUtf8("toolButton_Min_2"));
        toolButton_Min_2->setGeometry(QRect(760, 0, 23, 16));
        toolButton_Min_2->setAutoFillBackground(false);
        toolButton_Min_2->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/minb1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Min_2->setIcon(icon1);
        toolButton_Min_2->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Min_2->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Min_2->setArrowType(Qt::NoArrow);
        toolButton_Close_2 = new QToolButton(widget);
        toolButton_Close_2->setObjectName(QString::fromUtf8("toolButton_Close_2"));
        toolButton_Close_2->setGeometry(QRect(780, 0, 23, 16));
        toolButton_Close_2->setAutoFillBackground(false);
        toolButton_Close_2->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Close_2->setIcon(icon2);
        toolButton_Close_2->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Close_2->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Close_2->setArrowType(Qt::NoArrow);
        toolButton_Close = new QToolButton(Dialog);
        toolButton_Close->setObjectName(QString::fromUtf8("toolButton_Close"));
        toolButton_Close->setGeometry(QRect(1130, 210, 23, 16));
        toolButton_Close->setAutoFillBackground(false);
        toolButton_Close->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        toolButton_Close->setIcon(icon2);
        toolButton_Close->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Close->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Close->setArrowType(Qt::NoArrow);
        toolButton_Min = new QToolButton(Dialog);
        toolButton_Min->setObjectName(QString::fromUtf8("toolButton_Min"));
        toolButton_Min->setGeometry(QRect(1110, 210, 23, 16));
        toolButton_Min->setAutoFillBackground(false);
        toolButton_Min->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        toolButton_Min->setIcon(icon1);
        toolButton_Min->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Min->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Min->setArrowType(Qt::NoArrow);
        pushButton_Scan = new QPushButton(Dialog);
        pushButton_Scan->setObjectName(QString::fromUtf8("pushButton_Scan"));
        pushButton_Scan->setGeometry(QRect(590, 510, 101, 31));
        pushButton_Scan->setFont(font);
        pushButton_Clean = new QPushButton(Dialog);
        pushButton_Clean->setObjectName(QString::fromUtf8("pushButton_Clean"));
        pushButton_Clean->setGeometry(QRect(700, 510, 101, 31));
        pushButton_Clean->setFont(font);
        label_notes = new QLabel(Dialog);
        label_notes->setObjectName(QString::fromUtf8("label_notes"));
        label_notes->setGeometry(QRect(40, 30, 751, 16));
        QFont font1;
        font1.setPointSize(10);
        label_notes->setFont(font1);
        treeWidget_trash = new QTreeWidget(Dialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_trash->setHeaderItem(__qtreewidgetitem);
        treeWidget_trash->setObjectName(QString::fromUtf8("treeWidget_trash"));
        treeWidget_trash->setGeometry(QRect(-10, 50, 811, 451));
        treeWidget_trash->setFrameShape(QFrame::StyledPanel);
        treeWidget_trash->setTextElideMode(Qt::ElideRight);
        treeWidget_trash->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        checkBox_All = new QCheckBox(Dialog);
        checkBox_All->setObjectName(QString::fromUtf8("checkBox_All"));
        checkBox_All->setGeometry(QRect(0, 520, 51, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 520, 54, 16));
        graphicsView_2 = new QGraphicsView(Dialog);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 30, 16, 16));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/cloudsearch_error_tips.png);\n"
"border-image: url(:/back_group/Resources/min_button/cloudsearch_error_tips.png);"));
        graphicsView_2->setFrameShape(QFrame::NoFrame);
        label_Trash_gif = new QLabel(Dialog);
        label_Trash_gif->setObjectName(QString::fromUtf8("label_Trash_gif"));
        label_Trash_gif->setGeometry(QRect(10, 30, 16, 16));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        toolButton_Min_2->setText(QString());
        toolButton_Close_2->setText(QString());
        toolButton_Close->setText(QString());
        toolButton_Min->setText(QString());
        pushButton_Scan->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213\346\211\253\346\217\217", 0, QApplication::UnicodeUTF8));
        pushButton_Clean->setText(QApplication::translate("Dialog", "\347\253\213\345\215\263\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        label_notes->setText(QApplication::translate("Dialog", "\345\236\203\345\234\276\346\226\207\344\273\266\350\277\207\345\244\232\344\274\232\346\213\226\346\205\242\347\263\273\347\273\237\351\200\237\345\272\246\357\274\214\345\273\272\350\256\256\345\256\232\346\227\266\346\270\205\347\220\206", 0, QApplication::UnicodeUTF8));
        checkBox_All->setText(QApplication::translate("Dialog", "\345\205\250\351\200\211", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "<a href=\"www.baidu.com\">\346\216\250\350\215\220\351\200\211\351\241\271</a>", 0, QApplication::UnicodeUTF8));
        label_Trash_gif->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRASHCLEANDLG_H
