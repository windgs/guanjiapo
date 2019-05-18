/********************************************************************************
** Form generated from reading UI file 'ChangeSkin.ui'
**
** Created: Wed May 16 16:52:30 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESKIN_H
#define UI_CHANGESKIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include "../Common/CommonUI/CommonTitleBar.h"
#include "skinlistwidth.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    SkinListWidth *listWidget_Skin;
    CBaseTitleBar *widget_change_Title;
    QToolButton *toolButton_Close;
    QToolButton *toolButton_Min;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(491, 271);
        Dialog->setAutoFillBackground(false);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        listWidget_Skin = new SkinListWidth(Dialog);
        listWidget_Skin->setObjectName(QString::fromUtf8("listWidget_Skin"));
        listWidget_Skin->setGeometry(QRect(0, 20, 491, 251));
        listWidget_Skin->setMouseTracking(true);
        listWidget_Skin->setLayoutDirection(Qt::LeftToRight);
        listWidget_Skin->setAutoFillBackground(false);
        listWidget_Skin->setStyleSheet(QString::fromUtf8(""));
        listWidget_Skin->setFrameShape(QFrame::Box);
        listWidget_Skin->setFrameShadow(QFrame::Plain);
        listWidget_Skin->setMovement(QListView::Static);
        listWidget_Skin->setFlow(QListView::LeftToRight);
        widget_change_Title = new CBaseTitleBar(Dialog);
        widget_change_Title->setObjectName(QString::fromUtf8("widget_change_Title"));
        widget_change_Title->setGeometry(QRect(0, 0, 491, 21));
        widget_change_Title->setAutoFillBackground(true);
        widget_change_Title->setStyleSheet(QString::fromUtf8(""));
        toolButton_Close = new QToolButton(widget_change_Title);
        toolButton_Close->setObjectName(QString::fromUtf8("toolButton_Close"));
        toolButton_Close->setGeometry(QRect(460, 0, 23, 16));
        toolButton_Close->setAutoFillBackground(false);
        toolButton_Close->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/min_button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Close->setIcon(icon);
        toolButton_Close->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Close->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Close->setArrowType(Qt::NoArrow);
        toolButton_Min = new QToolButton(widget_change_Title);
        toolButton_Min->setObjectName(QString::fromUtf8("toolButton_Min"));
        toolButton_Min->setGeometry(QRect(440, 0, 23, 16));
        toolButton_Min->setAutoFillBackground(false);
        toolButton_Min->setStyleSheet(QString::fromUtf8("border-image: url(:/back_group/Resources/min_button/minback.png);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Resources/min_button/minb1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Min->setIcon(icon1);
        toolButton_Min->setPopupMode(QToolButton::DelayedPopup);
        toolButton_Min->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        toolButton_Min->setArrowType(Qt::NoArrow);
        graphicsView = new QGraphicsView(widget_change_Title);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 16, 16));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/back_group/Resources/min_button/catalog_8.png);"));
        graphicsView->setFrameShape(QFrame::NoFrame);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\215\242\350\202\244\344\270\255\345\277\203", 0, QApplication::UnicodeUTF8));
        toolButton_Close->setText(QString());
        toolButton_Min->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESKIN_H
