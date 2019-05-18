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
  //QPainter������λͼ�ϻ滭
  QPainter painter(&objBitmap);
  //���λͼ���ο�(�ð�ɫ���)
  painter.fillRect(rect(),Qt::white);
  painter.setBrush(QColor(0,0,0));
  //��λͼ�ϻ�Բ�Ǿ���(�ú�ɫ���)
  painter.drawRoundedRect(this->rect(),5,5);
  
  ////ʹ��setmask���˼���
  setMask(objBitmap);
  QPushButton::paintEvent(event);
}