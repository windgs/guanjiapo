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
  //�ı�����
  m_listMyStr<<tr("��ҳ")<<tr("��ɱľ��")<<tr("���ܴ�ȫ")<<tr("�������")<<tr("����ܼ�")
    <<tr("�Ż�����")<<tr("ϵͳ�޸�")<<tr("��������")<<tr("�޸�©��");
  //����toolbutton
  for(int nIndex = 0;nIndex<WIDGET_CNT;++nIndex)
  {
    //ͼ����Դ·�� ./Resources/sky.png
    QString strImage = QString("./Resources/button/%1.png").arg(nIndex+1);
    m_listMyBtnPoint.append(new ToolButton(strImage,m_listMyStr[nIndex],this));
    //����toolbutton��λ��
    m_listMyBtnPoint.at(nIndex)->move(nIndex * TOOLWIDGET_H + VALUE_DIS,5);
    //���źŲ�����������ť�İ���״̬boolֵ
    connect(m_listMyBtnPoint.at(nIndex),SIGNAL(signal_parent(void*)),this,SLOT(slot_set(void*)));
  }
  //����label
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