#include "CommonTitleBar.h"
#include "../Common/DefineCommon.h"
#include <QFile>
CBaseTitleBar::CBaseTitleBar(QWidget *parent, Qt::WFlags flags)
:QWidget(parent,flags)
{
  m_pLabel = new QLabel(tr(""),this);
  
}

CBaseTitleBar::~CBaseTitleBar(void)
{
}
void CBaseTitleBar::resizeEvent ( QResizeEvent * event )
{ 
  QPalette palette_back;
  palette_back.setBrush(QPalette::Background, QBrush(QPixmap(m_backgroup)));
 
  setPalette(palette_back);
  m_pLabel->setText(m_title);
  QPalette objPalette = palette();
  objPalette.setColor(QPalette::WindowText, Qt::white);
  m_pLabel->setPalette(objPalette);
  //文本粗体
  QFont &objFont = const_cast<QFont&>(font());
  objFont.setWeight(QFont::Bold);
  m_pLabel->setFont ( objFont );
  //样式
  m_pLabel->setStyleSheet("QToolButton{border:0px;}");
  m_pLabel->move(rect().x() +30,rect().y() + 5);
}

void CBaseTitleBar::mousePressEvent ( QMouseEvent * event )
{
  if (event->button() == Qt::LeftButton)
  {
    if(event->y() < VALUE_DIS || event->x() < VALUE_DIS || rect().width() - event->x() < 5)
    {
      event->ignore();
      return;
    }
    m_ptPress = event->globalPos();
    m_bLeftButtonPress = true;
  }
  event->ignore();
}

void CBaseTitleBar::mouseMoveEvent ( QMouseEvent * event )
{
  if(m_bLeftButtonPress)
  {
    m_ptMove = event->globalPos();
    //移动主窗口
    QWidget *pMainWindow = (qobject_cast<QWidget *>(parent()));
    pMainWindow->move(pMainWindow->pos() + m_ptMove - m_ptPress);
    //重新设置m_ptPress;
    m_ptPress = m_ptMove;
  }
  event->ignore();
}

void CBaseTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    m_bLeftButtonPress = false;
  }
  event->ignore();
}