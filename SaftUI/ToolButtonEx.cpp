#include "ToolButtonEx.h"
#include <QBitmap>
#include <QPainter>
ToolButtonEx::ToolButtonEx(QWidget *parent)
:QToolButton(parent)
{
  //文本颜色
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::ButtonText, QColor(220,220,220));
  setPalette(objPalette);
  //文本粗体
  QFont &objFont = const_cast<QFont &>(font());
  objFont.setWeight(QFont::Bold);
 
  //样式
  setStyleSheet("QToolButton{border:0px;}");
  //大小
  setIconSize(QSize(TOOLWIDGET_W ,TOOLWIDGET_H));
  resize(TOOLWIDGET_W,TOOLWIDGET_H);
  setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  //设置图像文本
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
  //QPainter用于在位图上绘画
  QPainter painter(&objBitmap);
  //填充位图矩形框(用白色填充)
  painter.fillRect(rect(),Qt::white);
  painter.setBrush(QColor(0,0,0));
  //在位图上画圆角矩形(用黑色填充)
  painter.drawRoundedRect(this->rect(),10,10);
  ////使用setmask过滤即可
  setMask(objBitmap);
}