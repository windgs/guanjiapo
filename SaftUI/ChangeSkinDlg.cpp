#include "ChangeSkinDlg.h"
#include "ListWidthItem.h"
#include "saftui.h"
ChangeSkinDlg::ChangeSkinDlg(QWidget *parent, Qt::WindowFlags f)
:QDialog(parent)
{ 
 
	m_Dlg.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint); 
  CreateTitle();
  connect(m_Dlg.toolButton_Close,SIGNAL(clicked()), this, SLOT(OnCloseForm()));
  connect(m_Dlg.toolButton_Min,SIGNAL(clicked()), this, SLOT(OnMinimized()));
	
 
}

void ChangeSkinDlg::OnCloseForm()
{
  close();
}

void ChangeSkinDlg::OnMinimized()
{
  showMinimized() ;
}

void ChangeSkinDlg::CreatePictureListItem()
{
  //����QListWidget�еĵ�Ԫ���ͼƬ��С
  m_Dlg.listWidget_Skin->setIconSize(QSize(150, 100));
  m_Dlg.listWidget_Skin->setResizeMode(QListView::Adjust);
  //����QListWidget����ʾģʽ
  m_Dlg.listWidget_Skin->setViewMode(QListView::IconMode);
  //����QListWidget�еĵ�Ԫ��ɱ��϶�
  m_Dlg.listWidget_Skin->setMovement(QListView::Static);
  //����QListWidget�еĵ�Ԫ��ļ��
  m_Dlg.listWidget_Skin->setSpacing(5);
  m_Dlg.listWidget_Skin->SetFrom(m_Parent);
  for(int nIndex = 0;nIndex < 6;++nIndex)
  {
    //���ͼƬ·��
    QString strPath = QString("./Resources/new_back/%1.png").arg(nIndex + 1);
    QString pciture_path = QString("./Resources/new_back/bk%1.png").arg(nIndex + 1);
    //����ͼ��objPixmap
    QPixmap objPixmap(strPath);
    //����QListWidgetItem����(ע�⣺��Iconͼ�����������[96*96])---scaled����
    ListWidthItem *pItem = new ListWidthItem(QIcon(objPixmap.scaled(QSize(150,100))),"");
    pItem->SetMainFrom(m_Parent);
    pItem->SetPicture(pciture_path);
    //pItem->setFrameShape(Box);

    //���õ�Ԫ��Ŀ�Ⱥ͸߶�
    pItem->setSizeHint(QSize(150,100));
    m_Dlg.listWidget_Skin->insertItem(nIndex, pItem);

  }
}

void ChangeSkinDlg::CreateTitle()
{
  m_Dlg.widget_change_Title->SetTitleString(tr("��������"));
  //C:\Users\sy\Desktop\QJP\SaftUI\Resources\min_button
  m_Dlg.widget_change_Title->SetBackGroup("../SaftUI/Resources/min_button/title.png");

}

ChangeSkinDlg::~ChangeSkinDlg(void)
{
}

void ChangeSkinDlg::closeEvent(QCloseEvent *event)
{
   m_Parent->RestoreBackGropu();
}
