#include "CircleButtom.h"
#include <QBitmap>
#include <QPainter>

CircleButton::CircleButton(QString text,QString backgroup, QWidget * parent)
:QPushButton(text,parent),m_backgroup(backgroup)
{
  QString sheetback = "background-image: url(" + backgroup + ")";
  setStyleSheet(QString::fromUtf8(sheetback.toUtf8()));
}

CircleButton::~CircleButton()
{

}

void CircleButton::SetBackGroup(QString backgroup)
{
  QString sheetback = "background-image: url(" + backgroup + ")";
  setStyleSheet(QString::fromUtf8(sheetback.toUtf8()));
}

void CircleButton::paintEvent ( QPaintEvent * event )
{
  QBitmap objBitmap(size());
  //QPainter用于在位图上绘画
  QPainter painter(&objBitmap);
  //填充位图矩形框(用白色填充)
  painter.fillRect(rect(),Qt::white);
  painter.setBrush(QColor(0,0,0));
  //在位图上画圆角矩形(用黑色填充)
  painter.drawRoundedRect(this->rect(),5,5);
  
  ////使用setmask过滤即可
  setMask(objBitmap);
  QPushButton::paintEvent(event);
}