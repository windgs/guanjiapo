#include "saftui.h"
#include <QBitmap>
#include <QPainter>
#include <QPixmap>

//ui
//#include "TitleBar.h"
#include "ToolBar.h"
#include "ContentWidget.h"
#include <StatuBar.h>
#include "PluginManager.h"
#include "../Common/CommonUI/MsgBoxDlg.h"
#include "../Common/DefineInterface.h"

#include "psapi.h"
#pragma comment(lib,"psapi.lib")
SaftUI::SaftUI(QWidget *
			   parent, Qt::WFlags flags)
	: QWidget(parent, flags)
 ,  m_SkinDlg(parent)
{
  // http://www.cnblogs.com/appsucc/archive/2012/03/14/2395657.html
  setWindowFlags(Qt::FramelessWindowHint);
  QPalette palette_back;
  LastBackSkin = "./Resources/new_back/bk8.png";
 
  palette_back.setBrush(QPalette::Background, QBrush(QPixmap(LastBackSkin)));
  //m_Back_Pixmap.load("./Resources/b1.png");
 
  setPalette(palette_back);
  ui.setupUi(this);
  InitSkinList();
  ui.listView_Feture->setIconSize(QSize(48, 48));
  ui.listView_Feture->setModel(&m_feture_Model);
  //设置QListWidget的显示模式
  //ui.listView_Feture->setViewMode(QListView::IconMode);
  //设置QListWidget中的单元项不可被拖动
  ui.listView_Feture->setMovement(QListView::Static);
  //设置QListWidget中的单元项的间距
  ui.listView_Feture->setSpacing(2);
  
  LoadPlugin();
  CreateFetureWidget();
  connect( ui.listView_Feture,SIGNAL(clicked(const QModelIndex&)),this,SLOT(OnClickFetureListView(const QModelIndex &)));
  connect( ui.pushButton_OpenSkinDlg,SIGNAL(clicked()),this,SLOT(OnOpenSkinDialog()));
 
  setMinimumWidth(850);
  setMinimumHeight(550);
  AdjustPurview();
  //IsNeedAdministratorCall();
}
SaftUI::~SaftUI()
{

}

BOOL SaftUI::IsNeedAdministratorCall()
{
  BOOL bRet = FALSE, bNeedSvcCall = FALSE;
  HANDLE hToken = NULL;
  DWORD dwBytesNeeded = 0;
  MY_TOKEN_MANDATORY_LABEL *pTIL = NULL;

 /* if (!RunTimeHelper::IsVista())
    goto Exit0;*/

  bRet = ::OpenProcessToken(::GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);
  if (NULL == hToken)
    return FALSE;

  bRet = ::GetTokenInformation(
    hToken,
    (TOKEN_INFORMATION_CLASS)MYTokenIntegrityLevel,
    NULL, 0, &dwBytesNeeded);

  pTIL = (MY_TOKEN_MANDATORY_LABEL *)new BYTE[dwBytesNeeded];
  if (!pTIL)
    goto Exit0;

  bRet = ::GetTokenInformation(
    hToken,
    (TOKEN_INFORMATION_CLASS)MYTokenIntegrityLevel,
    pTIL, dwBytesNeeded, &dwBytesNeeded);
  if (!bRet || !pTIL)
    goto Exit0;

  SID* pSid = static_cast<SID*>(pTIL->Label.Sid);
  if (!pSid)
    goto Exit0;

  if (SECURITY_MANDATORY_HIGH_RID > pSid->SubAuthority[0])
    bNeedSvcCall = TRUE;

Exit0:

  if (NULL != pTIL)
  {
    delete[] (LPBYTE)pTIL;
    pTIL = NULL;
  }

  if (hToken)
  {
    ::CloseHandle(hToken);
    hToken = NULL;
  }

  return bNeedSvcCall;
}

bool SaftUI::AdjustPurview()
{
  TOKEN_PRIVILEGES TokenPrivileges;
  BOOL bRet;
  HANDLE hToken;

  LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &TokenPrivileges.Privileges[0].Luid);   
  OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);

  TokenPrivileges.PrivilegeCount = 1;   
  TokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

  bRet = AdjustTokenPrivileges(hToken, FALSE, &TokenPrivileges, 0, NULL, NULL);

  CloseHandle(hToken);
  return bRet == TRUE;
}

void SaftUI::OnOpenSkinDialog()
{
   m_SkinDlg.show();
}

void SaftUI::InitSkinList()
{
  m_SkinDlg.SetFrom(this);
  m_SkinDlg.CreatePictureListItem();
} 

void SaftUI::RestoreBackGropu()
{
  if (m_Back_Pixmap.isDetached())
  {
    m_Back_Pixmap.detach();
  }
  m_Back_Pixmap.load(LastBackSkin);
  QPalette palette_back;
  palette_back.setBrush(QPalette::Background, m_Back_Pixmap);
  setPalette(palette_back);
}

void SaftUI::ChangeBackSkin(QString pciture)
{
  if (m_Back_Pixmap.isDetached())
  {
    m_Back_Pixmap.detach();
  }
  LastBackSkin = pciture;
  m_Back_Pixmap.load(pciture);
  QPalette palette_back;
  palette_back.setBrush(QPalette::Background, m_Back_Pixmap);
  setPalette(palette_back);
}

void SaftUI::ReViewChangeBackSkin(QString pciture)
{   
  if (m_Review_Back_Pixmap.isDetached())
  {
    m_Review_Back_Pixmap.detach();
  }

  m_Review_Back_Pixmap.load(pciture);
  QPalette palette_back;
  palette_back.setBrush(QPalette::Background, m_Review_Back_Pixmap);
  setPalette(palette_back);
}


void SaftUI::OnClickFetureListView(const QModelIndex & index)
{
  if (index.row() == 0)
  {
	 /* MsgBoxDlg msgdlg(tr("提示对话框"),tr("确定粉碎选中文件,并且不能恢复!"),this);
    if(msgdlg.exec() == QDialog::Accepted)
    {
       return;
    }
    else
    {
      return;
    }*/

    return;
  }
  QString guid = m_feture_Model.GetGuid(index.row() - 1);
  ISafeCommon* ICommon = PluginManager::Instance()->GetInterfaceByGuid<ISafeCommon>(guid);
  ICommon->DoAction();
}

void SaftUI::LoadPlugin()
{  
   //加载插件
   m_plugin_path = qApp->applicationDirPath();
   PluginManager::Instance()->LoadPlugin(m_plugin_path);
}

void SaftUI::CreateFetureWidget()
{   
  QStringList title;
  title << tr("");
  m_feture_Model.Setitle(title);
  //插入一个空行，用于布局
  m_feture_Model.insertRows(0,1,QModelIndex());
  QModelIndex qindex = m_feture_Model.index(0,0,QModelIndex());
  m_feture_Model.setData(qindex,tr("      "));
  int count =  PluginManager::Instance()->count();
  //添加插件到主界面
  for (int i = 0;i < count;++i)
  { 
    ISafeCommon* ICommon = PluginManager::Instance()->GetInterfaceByindex<ISafeCommon>(i);
    QString picture = ICommon->GetPicture();
    QString  pacture_path = QString("./Resources/feture_button/%1").arg(picture);
    m_feture_Model.SetGuid(ICommon->GetGuid());
    m_feture_Model.insertRows(i + 1,1,QModelIndex());
    qindex = m_feture_Model.index(i + 1,0,QModelIndex());
    m_feture_Model.setData(qindex,ICommon->GetName() + "(" + ICommon->GetDescribe() + ")");
    m_feture_Model.setData(qindex,QIcon(QPixmap(pacture_path)),Qt::DecorationRole);
  }
  /*
  m_feture_Model.insertRows(0,1,QModelIndex());
  QModelIndex qindex = m_feture_Model.index(0,0,QModelIndex());
  m_feture_Model.setData(qindex,tr("      "));

  m_feture_Model.insertRows(1,1,QModelIndex());
	qindex = m_feture_Model.index(1,0,QModelIndex());
	m_feture_Model.setData(qindex,tr("清理垃圾(清理磁盘和注册表中的垃圾)"));
	m_feture_Model.setData(qindex,QIcon(QPixmap("./Resources/feture_button/1.png")),Qt::DecorationRole);

	m_feture_Model.insertRows(2,1,QModelIndex());
	qindex = m_feture_Model.index(2,0,QModelIndex());
	m_feture_Model.setData(qindex,tr("清楚痕迹(清楚个人痕迹,保护个人隐私)"));
	m_feture_Model.setData(qindex,QIcon(QPixmap("./Resources/feture_button/2.png")),Qt::DecorationRole);

	m_feture_Model.insertRows(3,1,QModelIndex());
	qindex = m_feture_Model.index(3,0,QModelIndex());
	m_feture_Model.setData(qindex,tr("系统加速(优化系统设置,提升运行速度)"));
	m_feture_Model.setData(qindex,QIcon(QPixmap("./Resources/feture_button/3.png")),Qt::DecorationRole);

	m_feture_Model.insertRows(4,1,QModelIndex());
	qindex = m_feture_Model.index(4,0,QModelIndex());
	m_feture_Model.setData(qindex,tr("清理插件(清理多余插件,运行更速度)"));
	m_feture_Model.setData(qindex,QIcon(QPixmap("./Resources/feture_button/4.png")),Qt::DecorationRole);
  */
}

void SaftUI::InitLayout()
{
  //创建标题栏
 // m_pTitleBar = new TitleBar(this);
 // int Height = m_pTitleBar-> rect().height();
 // m_pTitleBar->setFixedHeight(Height - 10);
 // //创建工具栏
 // m_pToolBar = new ToolBar(this);
 ///* Height = m_pToolBar-> rect().height();
 // m_pToolBar->setFixedHeight(Height - 5);*/
 // //创建内容区域
 // m_pContentWidget = new ContentWidget(this);
 ///* Height = m_pContentWidget-> rect().height();
 // m_pContentWidget->setFixedHeight(Height + 10);*/
 // //创建状态栏
 // m_pStatuBar = new StatuBar(this);
 // //创建布局
 // m_pMainLayout = new QVBoxLayout(this);
 // 
 // //将部件加入到布局中
 // m_pMainLayout->addWidget(m_pTitleBar);
 // m_pMainLayout->addWidget(m_pToolBar);
 // m_pMainLayout->addWidget(m_pContentWidget);
 // m_pMainLayout->addWidget(m_pStatuBar);
 // //设置间距与边缘空白
 // m_pMainLayout->setSpacing(0);
 // m_pMainLayout->setContentsMargins(0,0,0,0);
 // setLayout(m_pMainLayout);


}

void SaftUI::paintEvent ( QPaintEvent * event )
{
	QBitmap objBitmap(size());
	//QPainter用于在位图上绘画
	QPainter painter(&objBitmap);
	//填充位图矩形框(用白色填充)
	painter.fillRect(rect(),Qt::white);
	painter.setBrush(QColor(0,0,0));
	//在位图上画圆角矩形(用黑色填充)
	painter.drawRoundedRect(this->rect(),5,5);
	////使用setmask过滤即可
	setMask(objBitmap);
   
}
