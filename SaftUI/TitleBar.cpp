#include "TitleBar.h"
#include <QLabel>
TitleBar::TitleBar(QWidget *parent, Qt::WFlags flags)
:CBaseTitleBar(parent,flags)
{
  
  m_pLabel = new QLabel(tr("管家婆1.0"),this);
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::WindowText, Qt::white);
  m_pLabel->setPalette(objPalette);
  //文本粗体
  QFont &objFont = const_cast<QFont&>(font());
  objFont.setWeight(QFont::Bold);
  m_pLabel->setFont ( objFont );
  //样式
  m_pLabel->setStyleSheet("QToolButton{border:0px;}");
  //m_pLabel->

}

TitleBar::~TitleBar(void)
{
}

void TitleBar::resizeEvent ( QResizeEvent * event )
{
  m_pLabel->move(rect().x() +30,rect().y() + 5);
}

//void TitleBar::mousePressEvent ( QMouseEvent * event )
//{
//  if (event->button() == Qt::LeftButton)
//  {
//    if(event->y() < VALUE_DIS || event->x() < VALUE_DIS || rect().width() - event->x() < 5)
//    {
//      event->ignore();
//      return;
//    }
//    m_ptPress = event->globalPos();
//    m_bLeftButtonPress = true;
//  }
//  event->ignore();
//}

//void TitleBar::mouseMoveEvent ( QMouseEvent * event )
//{
//  if(m_bLeftButtonPress)
//  {
//    m_ptMove = event->globalPos();
//    //移动主窗口
//    QWidget *pMainWindow = (qobject_cast<QWidget *>(parent()));
//    pMainWindow->move(pMainWindow->pos() + m_ptMove - m_ptPress);
//    //重新设置m_ptPress;
//    m_ptPress = m_ptMove;
//  }
//  event->ignore();
//}

//void TitleBar::mouseReleaseEvent(QMouseEvent *event)
//{
//  if (event->button() == Qt::LeftButton)
//  {
//    m_bLeftButtonPress = false;
//  }
//  event->ignore();
//}