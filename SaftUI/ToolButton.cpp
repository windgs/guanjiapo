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
	////����ͼ���ı�
	setIcon(QPixmap(image));
	setText(text);
	////����press�źŲۣ���ʾ��ť����ʱ
	connect(this,SIGNAL(pressed()),this,SLOT(slot_pressed()));
}

ToolButton::ToolButton(const QString &strImage,const QString &strInfo,QWidget *parent)
:QToolButton(parent),
m_bOver(false),
m_bPress(false),
m_strImage(strImage),
m_strInfo(strInfo)
{
  //�ı���ɫ
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::ButtonText, QColor(220,220,220));
  setPalette(objPalette);
  //�ı�����
  QFont &objFont = const_cast<QFont &>(font());
  objFont.setWeight(QFont::Bold);
  //QString family = objFont.family();
  //objFont.setFamily("΢���ź�");
  //��ʽ
  setStyleSheet("QToolButton{border:0px;}");
  //��С
  setIconSize(QSize(TOOLWIDGET_W ,TOOLWIDGET_H));
  resize(TOOLWIDGET_W,TOOLWIDGET_H);
  setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  //����ͼ���ı�
  setIcon(QPixmap(strImage));
  setText(strInfo);
  //����press�źŲۣ���ʾ��ť����ʱ
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
    //����m_bOver��־λ
    m_bOver = bEnable;
    //����
    update();
  }
}

void ToolButton::SetPress(bool bEnable)
{
  if(bEnable!=m_bPress)
  {
    //����m_bOver��־λ
    m_bPress = bEnable;
    //����
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
  //�����ť������
  if(m_bPress)
  {
    //���Ʊ�����ʱ��Ч��
    painterinfo(0,0,&painter);
  }
  else if(m_bOver)//�����ťû�б����²�������Ƶ���ť��
  {
    //��������Ƶ���ť�ϵİ�ťЧ��
    painterinfo(200,0,&painter);
  }
  //���û�����ػ��¼�����ʾͼ���ı���
  QToolButton::paintEvent(event);
}
void ToolButton::painterinfo(int nTopPartOpacity,int nBottomPartOpacity,QPainter *pPainter)
{
  //���û���
  QPen objPen(Qt::NoBrush,1);
  pPainter->setPen(objPen);
  //���ý��仭ˢ
  QLinearGradient objLinear(rect().topLeft(),rect().bottomLeft());
  //������ɫ��͸����
  objLinear.setColorAt(0,QColor(255,255,255,nTopPartOpacity));
  //�м���ɫ��͸����
 
  objLinear.setColorAt(0.5,QColor(200,200,200,255));
  //�ײ���ɫ��͸����
  objLinear.setColorAt(1,QColor(0,0,0,nBottomPartOpacity));
  QBrush objBrush(objLinear);
  pPainter->setBrush(objBrush);
  //��Բ�Ǿ���
  pPainter->drawRoundedRect(rect(),5,5);
}