#include "ToolButton.h"
#include <QPalette>
#include <QFont>
#include <QPixmap>
#include <QColor>
#include <QPen>
#include <QPainter>
#include <QEvent>
ToolButton::ToolButton(QWidget *parent)
:QToolButton(parent)
{
 
  
}

void ToolButton::InitToolButton(QString image,QString text)
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
	////设置图像文本
	setIcon(QPixmap(image));
	setText(text);
	////连接press信号槽，表示按钮按下时
	connect(this,SIGNAL(pressed()),this,SLOT(slot_pressed()));
}

ToolButton::ToolButton(const QString &strImage,const QString &strInfo,QWidget *parent)
:QToolButton(parent),
m_bOver(false),
m_bPress(false),
m_strImage(strImage),
m_strInfo(strInfo)
{
  //文本颜色
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::ButtonText, QColor(220,220,220));
  setPalette(objPalette);
  //文本粗体
  QFont &objFont = const_cast<QFont &>(font());
  objFont.setWeight(QFont::Bold);
  //QString family = objFont.family();
  //objFont.setFamily("微软雅黑");
  //样式
  setStyleSheet("QToolButton{border:0px;}");
  //大小
  setIconSize(QSize(TOOLWIDGET_W ,TOOLWIDGET_H));
  resize(TOOLWIDGET_W,TOOLWIDGET_H);
  setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  //设置图像文本
  setIcon(QPixmap(strImage));
  setText(strInfo);
  //连接press信号槽，表示按钮按下时
  connect(this,SIGNAL(pressed()),this,SLOT(slot_pressed()));
}

ToolButton::~ToolButton(void)
{
}

void ToolButton::slot_pressed()
{
  SetPress(true);
  emit signal_parent(this);
}

void ToolButton::SetOver(bool bEnable)
{
  if(bEnable!=m_bOver)
  {
    //设置m_bOver标志位
    m_bOver = bEnable;
    //更新
    update();
  }
}

void ToolButton::SetPress(bool bEnable)
{
  if(bEnable!=m_bPress)
  {
    //设置m_bOver标志位
    m_bPress = bEnable;
    //更新
    update();
  }
}

void	ToolButton::leaveEvent ( QEvent * event )
{
   SetOver(false);
}
void	ToolButton::enterEvent (QEvent * event )
{
  SetOver(true);
}

void  ToolButton::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  //如果按钮被按下
  if(m_bPress)
  {
    //绘制被按下时的效果
    painterinfo(0,0,&painter);
  }
  else if(m_bOver)//如果按钮没有被按下并且鼠标移到按钮上
  {
    //绘制鼠标移到按钮上的按钮效果
    painterinfo(200,0,&painter);
  }
  //调用基类的重绘事件以显示图像文本等
  QToolButton::paintEvent(event);
}
void ToolButton::painterinfo(int nTopPartOpacity,int nBottomPartOpacity,QPainter *pPainter)
{
  //设置画笔
  QPen objPen(Qt::NoBrush,1);
  pPainter->setPen(objPen);
  //设置渐变画刷
  QLinearGradient objLinear(rect().topLeft(),rect().bottomLeft());
  //顶部颜色和透明度
  objLinear.setColorAt(0,QColor(255,255,255,nTopPartOpacity));
  //中间颜色和透明度
 
  objLinear.setColorAt(0.5,QColor(200,200,200,255));
  //底部颜色和透明度
  objLinear.setColorAt(1,QColor(0,0,0,nBottomPartOpacity));
  QBrush objBrush(objLinear);
  pPainter->setBrush(objBrush);
  //画圆角矩形
  pPainter->drawRoundedRect(rect(),5,5);
}