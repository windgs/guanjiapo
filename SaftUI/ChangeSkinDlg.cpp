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
  //设置QListWidget中的单元项的图片大小
  m_Dlg.listWidget_Skin->setIconSize(QSize(150, 100));
  m_Dlg.listWidget_Skin->setResizeMode(QListView::Adjust);
  //设置QListWidget的显示模式
  m_Dlg.listWidget_Skin->setViewMode(QListView::IconMode);
  //设置QListWidget中的单元项不可被拖动
  m_Dlg.listWidget_Skin->setMovement(QListView::Static);
  //设置QListWidget中的单元项的间距
  m_Dlg.listWidget_Skin->setSpacing(5);
  m_Dlg.listWidget_Skin->SetFrom(m_Parent);
  for(int nIndex = 0;nIndex < 6;++nIndex)
  {
    //获得图片路径
    QString strPath = QString("./Resources/new_back/%1.png").arg(nIndex + 1);
    QString pciture_path = QString("./Resources/new_back/bk%1.png").arg(nIndex + 1);
    //生成图像objPixmap
    QPixmap objPixmap(strPath);
    //生成QListWidgetItem对象(注意：其Icon图像进行了伸缩[96*96])---scaled函数
    ListWidthItem *pItem = new ListWidthItem(QIcon(objPixmap.scaled(QSize(150,100))),"");
    pItem->SetMainFrom(m_Parent);
    pItem->SetPicture(pciture_path);
    //pItem->setFrameShape(Box);

    //设置单元项的宽度和高度
    pItem->setSizeHint(QSize(150,100));
    m_Dlg.listWidget_Skin->insertItem(nIndex, pItem);

  }
}

void ChangeSkinDlg::CreateTitle()
{
  m_Dlg.widget_change_Title->SetTitleString(tr("换肤中心"));
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
