#include "ToolButtonEx.h"
#include <QBitmap>
#include <QPainter>
ToolButtonEx::ToolButtonEx(QWidget *parent)
:QToolButton(parent)
{
  //�ı���ɫ
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::ButtonText, QColor(220,220,220));
  setPalette(objPalette);
  //�ı�����
  QFont &objFont = const_cast<QFont &>(font());
  objFont.setWeight(QFont::Bold);
 
  //��ʽ
  setStyleSheet("QToolButton{border:0px;}");
  //��С
  setIconSize(QSize(TOOLWIDGET_W ,TOOLWIDGET_H));
  resize(TOOLWIDGET_W,TOOLWIDGET_H);
  setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  //����ͼ���ı�
  setIcon(QPixmap("./Resources/button/safe.png"));
 // setText(strInfo);
  show();
}

ToolButtonEx::~ToolButtonEx(void)
{
}

void ToolButtonEx::paintEvent ( QPaintEvent * event )
{
  QBitmap objBitmap(size());
  //QPainter������λͼ�ϻ滭
  QPainter painter(&objBitmap);
  //���λͼ���ο�(�ð�ɫ���)
  painter.fillRect(rect(),Qt::white);
  painter.setBrush(QColor(0,0,0));
  //��λͼ�ϻ�Բ�Ǿ���(�ú�ɫ���)
  painter.drawRoundedRect(this->rect(),10,10);
  ////ʹ��setmask���˼���
  setMask(objBitmap);
}