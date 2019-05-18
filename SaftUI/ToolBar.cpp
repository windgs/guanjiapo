#include "ToolBar.h"
#include "ToolButton.h"
ToolBar::ToolBar(QWidget *parent, Qt::WFlags flags)
:QWidget(parent,flags)
{
  CreateWidget();
}

ToolBar::~ToolBar(void)
{
}

void ToolBar::CreateWidget()
{
  //文本例子
  m_listMyStr<<tr("主页")<<tr("查杀木马")<<tr("功能大全")<<tr("插件清理")<<tr("软件管家")
    <<tr("优化加速")<<tr("系统修复")<<tr("电脑清理")<<tr("修复漏洞");
  //创建toolbutton
  for(int nIndex = 0;nIndex<WIDGET_CNT;++nIndex)
  {
    //图像资源路径 ./Resources/sky.png
    QString strImage = QString("./Resources/button/%1.png").arg(nIndex+1);
    m_listMyBtnPoint.append(new ToolButton(strImage,m_listMyStr[nIndex],this));
    //设置toolbutton的位置
    m_listMyBtnPoint.at(nIndex)->move(nIndex * TOOLWIDGET_H + VALUE_DIS,5);
    //该信号槽设置其他按钮的按下状态bool值
    connect(m_listMyBtnPoint.at(nIndex),SIGNAL(signal_parent(void*)),this,SLOT(slot_set(void*)));
  }
  //创建label
  m_pLabel = new QLabel(this);
  m_pLabel->setPixmap(QPixmap("./Resources/logo1.png"));
}

void ToolBar:: slot_set(void *pObject)
{
  for(int nIndex = 0;nIndex<WIDGET_CNT;++nIndex)
  {
    if(m_listMyBtnPoint.at(nIndex)!=pObject)
    {
      m_listMyBtnPoint.at(nIndex)->SetPress(false);
    }
  }
}

void ToolBar::resizeEvent ( QResizeEvent * event ) 
{
  m_pLabel->move(rect().width()-m_pLabel->pixmap()->width()+ VALUE_DIS + 2 ,(rect().height()-m_pLabel->pixmap()->height())/6);
}