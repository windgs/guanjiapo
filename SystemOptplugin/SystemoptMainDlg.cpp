#include "SystemoptMainDlg.h"
#include "RunItemFind.h"
#include <QPushButton>
#include "..\Common\CommonUI\CircleButtom.h"
#include <QCommandLinkButton>
#include "DisRunItem.h"
#include "RecordLogItem.h"
#include "SpecialFolderPath.h"
//#include "CmdLineParser2.h"
SystemoptMainDlg::SystemoptMainDlg(QWidget *parent, Qt::WindowFlags f)
:QDialog(parent,f)
{
  setWindowFlags(Qt::FramelessWindowHint); 
  m_Dialog.setupUi(this);
  SetSheetStyle();
  CreateMovieWidget();
  
  connect(&m_threadstub,SIGNAL(NotifyFindItem()),this,SLOT(OnReadFindItem()));
  connect(m_Dialog.toolButton_close,SIGNAL(clicked()), this, SLOT(OnCloseForm()));
  connect(m_Dialog.toolButton_Min,SIGNAL(clicked()), this, SLOT(OnMinimized()));
  RecordLogItem::Instance()->LoadRunOpt(RUNOPTNAME);
  
  m_init = false;
  m_buttongroup = new QButtonGroup(this);
}

SystemoptMainDlg::~SystemoptMainDlg(void)
{
}

void SystemoptMainDlg::OnCloseForm()
{
  close();
}

void SystemoptMainDlg::OnMinimized()
{
   showMinimized() ;
}

void SystemoptMainDlg::SetSheetStyle()
{ 
  m_Dialog.tabWidgetUI->setStyleSheet(
    "QTabWidget>QTabBar::tab:selected {"
    "color: blue;"
    "background-image: url(../SaftUI/Resources/min_button/tab_b.png);}"
    "QTabWidget>QTabBar::tab:!selected {"
    "color:rgb(0,0,0);"
    "background-image: url(:/back_group/Resources/min_button/tab_b.png);}"
    "QTabBar::tab{width:120}"
    "QTabBar::tab{height:30}"
    );
}

void SystemoptMainDlg::showEvent (QShowEvent * event)
{  
   if (!m_init)
   {
	   StartMovieWidget();
	   m_threadstub.start();
	   m_init = true;
   }
  
}

void SystemoptMainDlg::OnReadFindItem()
{
  CreateTableWidget();
  CreateServiceWidget();
  CreateDisenableItem();
  //停止播放动画，并隐藏控件
  StopMovice();
}

QTableWidget* SystemoptMainDlg::GetCurrentPagTable(int index)
{
   int pagcount = m_Dialog.tabWidgetUI->count();
   if (pagcount <= -1 || index > pagcount)
   {
	  return NULL;
   }
   switch (index)
   {
     case PAGE0:
       return NULL;
     case PAGE1:
		 return  m_Dialog.tableWidget_RunTable;
	 case PAGE2:
         return m_Dialog.tableWidget_Service;
	 case PAGE3:
		 return NULL;
   }
   return NULL;
}

QString SystemoptMainDlg::ConverServiceType(int servicetype)
{
   switch (servicetype)
   {
   case SERVICE_KERNEL_DRIVER:
	   return tr("关键进程");
   case SERVICE_FILE_SYSTEM_DRIVER:
	   return tr("系统服务进程");
   case SERVICE_WIN32_OWN_PROCESS:
	   return tr("用户服务");
   case SERVICE_WIN32_SHARE_PROCESS:
	   return tr("共享服务");
   }
   return "";
}

void SystemoptMainDlg::CreateDisenableItem()
{  
   RecordLogItem::Instance()->LoadDisEnableLogItem();
   QTableWidget* tablewidget = NULL;
   int count = RecordLogItem::Instance()->GetCountDisEnableArray();
   for (int i = 0;i < count; ++i)
   {
     SafeRunInfo* pinfo = RecordLogItem::Instance()->GetDisEnableArray(i);
	 if (!pinfo)
	 {
		 continue;
	 }
     switch (pinfo->nType)
	 {
	 case RUN_TYPE_STARTUP:
		 {
           AddRunTableWidgetItem(pinfo);
            
		 }break;
	 case RUN_TYPE_SERVICE:
		 {
		 }break;
	 case RUN_TYPE_TASK:
		 {
		 }break;
	 }
	
     
   }
   
}

//初始化服务项启动UI
void SystemoptMainDlg::CreateServiceWidget()
{
	QStringList titleList;
	titleList << tr("软件名称") << tr("服务类型") << tr("建议") << tr("状态") << tr("操作");
	m_Dialog.tableWidget_RunTable->setHorizontalHeaderLabels(titleList);
	//m_buttongroup = new QButtonGroup(this);
	int count = RecordLogItem::Instance()->GetServiceCount();
	int runcount = RecordLogItem::Instance()->GetCountEnableArray();
	int page_total = runcount;
	m_Dialog.tableWidget_Service->setColumnCount(5); 
	m_Dialog.tableWidget_Service->setRowCount(count);
	m_Dialog.tableWidget_Service->setHorizontalHeaderLabels(titleList);
	m_Dialog.tableWidget_Service->setColumnWidth(0,400);
	m_Dialog.tableWidget_Service->setColumnWidth(1,100);
	m_Dialog.tableWidget_Service->setColumnWidth(2,80);
	m_Dialog.tableWidget_Service->setColumnWidth(3,100);
	m_Dialog.tableWidget_Service->horizontalHeader()->setVisible(true);
	for (int i = 0;i < count; ++i)
	{
      ServiceConfig* config = RecordLogItem::Instance()->GetServiceItembyIndex(i);
	  if (!config)
	  {
		  continue;
	  }
	  QString strdesc;
	  QString displayname;
	  QString strServ;
	  if (config->strServDLL.isEmpty())
	  {
          strServ = config->strName;
	  }
	  else
	  {
           strServ = config->strServDLL;
	  }
      RunOptItem* optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_SERVICE,strServ);
      if (optitem)
      {
         strdesc = optitem->decs;
         displayname = optitem->dispayname;
      }
	  else
	  {
         strdesc = config->strDesc;
		 displayname = config->strName;
		 
	  }
	  displayname.append("\n");
	  QString softname = displayname + tr("描述: ") + strdesc;
	  QTableWidgetItem * item = new QTableWidgetItem(config->hIcon ,softname);
	  m_Dialog.tableWidget_Service->setItem(i, 0, item);

	
	  QString strType = ConverServiceType(config->lpqscfg->dwServiceType);
	  item = new QTableWidgetItem(strType);
	  item->setTextAlignment(Qt::AlignCenter);
	  m_Dialog.tableWidget_Service->setItem(i, 1, item);
	  //
	  if (optitem)
	  {   
          QString stradvice = RecordLogItem::Instance()->GetAdviceStr(optitem->advice);
	      item = new QTableWidgetItem(stradvice);	  
	  }
	  else
	  {
          item = new QTableWidgetItem(tr("保持现状"));
	  }
	  //设置“可以禁止项”并且为启动状态为红色字体
	  m_Dialog.tableWidget_Service->setItem(i, 2, item);
	  if (optitem)
	  {
		  if (0 == optitem->advice && config->Enable)
		  {
			  SetTextColorColumn(PAGE2,i,2,QColor(240,0,0));
		  }
	  }
	 
	  //
	  QString id;
	  id.setNum(i);
	  QWidget * cell = new QWidget();
	  CircleButton* pushbut = new CircleButton("","../SaftUI/Resources/min_button/qy.png",cell);
	  QString buttonname = "PushButton%1";
	  pushbut->setObjectName(QString::fromUtf8(buttonname.arg(id).toUtf8()));
	  pushbut->setAutoFillBackground(true);
	  pushbut->setFixedWidth(57);
	  pushbut->setFixedHeight(25);
	  pushbut->move(pushbut->pos().x() + 20 ,pushbut->pos().y() + 20);
	  m_buttongroup->addButton(pushbut,page_total + i);
	  m_Dialog.tableWidget_Service->setCellWidget(i, 3,cell);
	  //
	  QWidget * pcell4 = new QWidget();
	  QCommandLinkButton* commandLinkButton = new QCommandLinkButton(pcell4);
	  QString commlink("commandLinkButton%1");

	  commandLinkButton->setObjectName(QString::fromUtf8(commlink.arg(id).toUtf8()));
	  //commandLinkButton->setGeometry(QRect(0, 0, 31, 31));
	  commandLinkButton->setFixedWidth(31);
	  commandLinkButton->setFixedHeight(31);
	  commandLinkButton->move(commandLinkButton->pos().x() + 10 ,commandLinkButton->pos().y() + 20);
	  commandLinkButton->setLayoutDirection(Qt::LeftToRight);
	  QIcon icon2;
	  icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/xlsel.png"), QSize(), QIcon::Normal, QIcon::Off);
	  commandLinkButton->setIcon(icon2);
	  m_Dialog.tableWidget_Service->setCellWidget(i, 4,pcell4);
      m_Dialog.tableWidget_Service->setRowHeight(i,60);

	  //设置禁止项状态
	  if (!config->Enable)
	  {
        SetTextColor(PAGE2, i ,QColor(143,143,143));
        pushbut->SetBackGroup("../SaftUI/Resources/min_button/jy.png");
	  }
	  
	}
}

void SystemoptMainDlg::AddRunTableWidgetItem(SafeRunInfo* info)
{  
   int rowcount = m_Dialog.tableWidget_RunTable->rowCount();
   m_Dialog.tableWidget_RunTable->setRowCount(rowcount + 1);
  
   QString strdesc;
   QString displayname;
   RunOptItem* optitem = NULL;
   if (info->nRegType == DIR_RUN_TYPE_WINDOW_USER)
   {
	   optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,info->strPath);
   }
   else if(info->nRegType == REG_RUN_TYPE_WINDOW_HKLM)
   {
	   optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,info->strName);
   }
   if (optitem)
   {
	   strdesc = optitem->decs;
	   displayname = optitem->dispayname;
   }
   else
   {
	   strdesc = info->strDesc;
	   displayname = info->strName;

   }
   displayname.append("\n");
   QString softname = displayname + tr("描述: ") + strdesc;
   QTableWidgetItem * item = new QTableWidgetItem(info->hIcon ,softname);
   m_Dialog.tableWidget_RunTable->setItem(rowcount, 0, item);

   item = new QTableWidgetItem(info->strPath);
   m_Dialog.tableWidget_RunTable->setItem(rowcount, 1, item);
   //////////////////////////////////////////////////////////////////////////
   if (optitem)
   {   
	   QString stradvice = RecordLogItem::Instance()->GetAdviceStr(optitem->advice);
	   item = new QTableWidgetItem(stradvice);	  
   }
   else
   {
	   item = new QTableWidgetItem(tr("保持现状"));
   }
   m_Dialog.tableWidget_RunTable->setItem(rowcount, 2, item);
   //设置“可以禁止项”为红色字体
   if (optitem && 0 == optitem->advice && info->bEnable)
   {
	   SetTextColorColumn(PAGE1,rowcount,2,QColor(240,0,0));
   }

   //////////////////////////////////////////////////////////////////////////
   QString id;
   id.setNum(rowcount);
   QWidget * cell = new QWidget();
   CircleButton* pushbut = NULL;
   if (info->bEnable)
   {
      pushbut = new CircleButton("","../SaftUI/Resources/min_button/qy.png",cell);
   }
   else
   {
      pushbut = new CircleButton("","../SaftUI/Resources/min_button/jy.png",cell);
   }
   //CircleButton* pushbut = new CircleButton("","../SaftUI/Resources/min_button/qy.png",cell);
   QString buttonname = "PushButton%1";
   pushbut->setObjectName(QString::fromUtf8(buttonname.arg(id).toUtf8()));
   pushbut->setAutoFillBackground(true);
   pushbut->setFixedWidth(57);
   pushbut->setFixedHeight(25);
   pushbut->move(pushbut->pos().x() + 20 ,pushbut->pos().y() + 20);
   m_buttongroup->addButton(pushbut,rowcount);
   m_Dialog.tableWidget_RunTable->setCellWidget(rowcount, 3,cell);
   //////////////////////////////////////////////////////////////////////////
   QWidget * pcell4 = new QWidget();
   QCommandLinkButton* commandLinkButton = new QCommandLinkButton(pcell4);
   QString commlink("commandLinkButton%1");

   commandLinkButton->setObjectName(QString::fromUtf8(commlink.arg(id).toUtf8()));
   //commandLinkButton->setGeometry(QRect(0, 0, 31, 31));
   commandLinkButton->setFixedWidth(31);
   commandLinkButton->setFixedHeight(31);
   commandLinkButton->move(commandLinkButton->pos().x() + 10 ,commandLinkButton->pos().y() + 20);
   commandLinkButton->setLayoutDirection(Qt::LeftToRight);
   QIcon icon2;
   icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/xlsel.png"), QSize(), QIcon::Normal, QIcon::Off);
   commandLinkButton->setIcon(icon2);
   m_Dialog.tableWidget_RunTable->setCellWidget(rowcount, 4,pcell4);
   
   if (!info->bEnable)
   {
      SetTextColor(PAGE1,rowcount ,QColor(143,143,143));
   }
   m_Dialog.tableWidget_RunTable->setRowHeight(rowcount,60);

}

void SystemoptMainDlg::CreateTableWidget()
{
  QStringList titleList;
  titleList << tr("软件名称") << tr("启动路径") << tr("建议") << tr("状态") << tr("操作");
  m_Dialog.tableWidget_RunTable->setHorizontalHeaderLabels(titleList);
  //获得目录和注册表启动项个数
  int count = RecordLogItem::Instance()->GetCountEnableArray();
  m_Dialog.tableWidget_RunTable->setColumnCount(5); 
  m_Dialog.tableWidget_RunTable->setRowCount(count);
  m_Dialog.tableWidget_RunTable->setHorizontalHeaderLabels(titleList);
  m_Dialog.tableWidget_RunTable->setColumnWidth(0,250);
  m_Dialog.tableWidget_RunTable->setColumnWidth(1,250);
  m_Dialog.tableWidget_RunTable->setColumnWidth(2,80);
  m_Dialog.tableWidget_RunTable->setColumnWidth(3,100);
  m_Dialog.tableWidget_RunTable->horizontalHeader()->setVisible(true);
  
  for (int i = 0;i < count; ++i)
  {   
      //const RUN_DIR_INFO* info = RunItemFind::Instance()->m_dir_run_array.at(i);
      SafeRunInfo* info = RecordLogItem::Instance()->GetEnableArray(i);
	  QString strdesc;
	  QString displayname;
	  RunOptItem* optitem = NULL;
	  if (info->nRegType == DIR_RUN_TYPE_WINDOW_USER)
	  {
          optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,info->strPath);
	  }
	  else if(info->nRegType == REG_RUN_TYPE_WINDOW_HKLM)
	  {
          optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,info->strName);
	  }
	  if (optitem)
	  {
		  strdesc = optitem->decs;
		  displayname = optitem->dispayname;
	  }
	  else
	  {
		  strdesc = info->strDesc;
		  displayname = info->strName;

	  }
	  displayname.append("\n");
	  QString softname = displayname + tr("描述: ") + strdesc;
      QTableWidgetItem * item = new QTableWidgetItem(info->hIcon ,softname);
      m_Dialog.tableWidget_RunTable->setItem(i, 0, item);

      item = new QTableWidgetItem(info->strPath);
      m_Dialog.tableWidget_RunTable->setItem(i, 1, item);
      //////////////////////////////////////////////////////////////////////////
	  if (optitem)
	  {   
		  QString stradvice = RecordLogItem::Instance()->GetAdviceStr(optitem->advice);
		  item = new QTableWidgetItem(stradvice);	  
	  }
	  else
	  {
		  item = new QTableWidgetItem(tr("保持现状"));
	  }
	  m_Dialog.tableWidget_RunTable->setItem(i, 2, item);
	  //设置“可以禁止项”为红色字体
	  if (optitem && 0 == optitem->advice)
	  {
         SetTextColorColumn(PAGE1,i,2,QColor(240,0,0));
	  }
	  
      //////////////////////////////////////////////////////////////////////////
      QString id;
      id.setNum(i);
      QWidget * cell = new QWidget();
      CircleButton* pushbut = new CircleButton("","../SaftUI/Resources/min_button/qy.png",cell);
      QString buttonname = "PushButton%1";
      pushbut->setObjectName(QString::fromUtf8(buttonname.arg(id).toUtf8()));
      pushbut->setAutoFillBackground(true);
      pushbut->setFixedWidth(57);
      pushbut->setFixedHeight(25);
      pushbut->move(pushbut->pos().x() + 20 ,pushbut->pos().y() + 20);
      m_buttongroup->addButton(pushbut,i);
      m_Dialog.tableWidget_RunTable->setCellWidget(i, 3,cell);
      //////////////////////////////////////////////////////////////////////////
      QWidget * pcell4 = new QWidget();
      QCommandLinkButton* commandLinkButton = new QCommandLinkButton(pcell4);
      QString commlink("commandLinkButton%1");
    
      commandLinkButton->setObjectName(QString::fromUtf8(commlink.arg(id).toUtf8()));
      //commandLinkButton->setGeometry(QRect(0, 0, 31, 31));
      commandLinkButton->setFixedWidth(31);
      commandLinkButton->setFixedHeight(31);
      commandLinkButton->move(commandLinkButton->pos().x() + 10 ,commandLinkButton->pos().y() + 20);
      commandLinkButton->setLayoutDirection(Qt::LeftToRight);
      QIcon icon2;
      icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/xlsel.png"), QSize(), QIcon::Normal, QIcon::Off);
      commandLinkButton->setIcon(icon2);
      m_Dialog.tableWidget_RunTable->setCellWidget(i, 4,pcell4);

      m_Dialog.tableWidget_RunTable->setRowHeight(i,60);

  }

/* 
  for (int i = 0;i < regcount; ++i)
  {
     const RegRunInfo& info = RunItemFind::Instance()->m_Reg_run_array.at(i);
	 QString strdesc;
	 QString displayname;
	 RunOptItem* optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,info.strPath);
	 if (optitem)
	 {
		 strdesc = optitem->decs;
		 displayname = optitem->dispayname;
	 }
	 else
	 {
		 strdesc = info.strDesc;
		 displayname = info.strName;

	 }
	 displayname.append("\n");

     int index = count + i;
     QString softname = displayname + tr("描述: ") + strdesc;
     QTableWidgetItem * item = new QTableWidgetItem(info.hIcon ,softname);
     m_Dialog.tableWidget_RunTable->setItem(index, 0, item);
     
     item = new QTableWidgetItem(info.strPath);
     m_Dialog.tableWidget_RunTable->setItem(index, 1, item);
     //////////////////////////////////////////////////////////////////////////
	 if (optitem)
	 {   
		 QString stradvice = RecordLogItem::Instance()->GetAdviceStr(optitem->advice);
		 item = new QTableWidgetItem(stradvice);	  
	 }
	  else
	  {
		  item = new QTableWidgetItem(tr("保持现状"));
	  }
     m_Dialog.tableWidget_RunTable->setItem(index, 2, item);
	 //////////////////////////////////////////////////////////////////////////
     QWidget * cell = new QWidget();
     CircleButton* pushbut = new CircleButton("","../SaftUI/Resources/min_button/qy.png",cell);
     pushbut->setAutoFillBackground(true);
     pushbut->setFixedWidth(57);
     pushbut->setFixedHeight(25);
     pushbut->move(pushbut->pos().x() + 20 ,pushbut->pos().y() + 20);
     m_Dialog.tableWidget_RunTable->setCellWidget(index, 3,cell);
     m_buttongroup->addButton(pushbut,index);
     QWidget * pcell4 = new QWidget();
     QCommandLinkButton* commandLinkButton = new QCommandLinkButton(pcell4);
     QString commlink("commandLinkButton%1");
     QString id;
     id.setNum(index);
     commandLinkButton->setObjectName(QString::fromUtf8(commlink.arg(index).toUtf8()));
     //commandLinkButton->setGeometry(QRect(0, 0, 31, 31));
     commandLinkButton->setFixedWidth(31);
     commandLinkButton->setFixedHeight(31);
     commandLinkButton->move(commandLinkButton->pos().x() + 10 ,commandLinkButton->pos().y() + 20);
     commandLinkButton->setLayoutDirection(Qt::LeftToRight);
     QIcon icon2;
     icon2.addFile(QString::fromUtf8("../SaftUI/Resources/min_button/xlsel.png"), QSize(), QIcon::Normal, QIcon::Off);
     commandLinkButton->setIcon(icon2);
     m_Dialog.tableWidget_RunTable->setCellWidget(index, 4,pcell4);

     m_Dialog.tableWidget_RunTable->setRowHeight(index,60);
  }
*/
  connect(m_buttongroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(OnbuttonClicked(QAbstractButton*)));
 
}

void SystemoptMainDlg::CreateMovieWidget()
{   
    m_Movegif.setFileName("../SaftUI/Resources/gif/load.gif");
    m_Dialog.label_Opt_Load_Gif->setMovie(&m_Movegif);
	
}

void SystemoptMainDlg::StartMovieWidget()
{   
	QTableWidget* currentTableWidget = GetCurrentPagTable(m_Dialog.tabWidgetUI->currentIndex());
    if (!currentTableWidget)
    {
		return;
    }
	currentTableWidget->setVisible(false);
	m_Dialog.label_Opt_Load_Gif->setVisible(true);
	m_Dialog.label_Load_Tips->setVisible(true);
	if (QMovie::NotRunning == m_Movegif.state())
	{
		m_Movegif.start();
	}
}

void SystemoptMainDlg::StopMovice()
{
	QTableWidget* currentTableWidget = GetCurrentPagTable(m_Dialog.tabWidgetUI->currentIndex());
	if (!currentTableWidget)
	{
		return;
	}
	currentTableWidget->setVisible(true);
	m_Dialog.label_Opt_Load_Gif->setVisible(false);
	m_Dialog.label_Load_Tips->setVisible(false);
	if (QMovie::Running == m_Movegif.state())
	{
		m_Movegif.stop();
	}
	
}

void SystemoptMainDlg::SetTextColor(int pageindex,int index ,QColor color)
{ 
  QTableWidget* tablewidget = GetCurrentPagTable(pageindex);
  if (!tablewidget)
  {
	  return;
  }
  for (int i = 0;i < 3;++i)
  {
    QTableWidgetItem * selectitem = tablewidget->item(index,i);
    selectitem->setTextColor(color);
  }
}

void SystemoptMainDlg::SetTextColorColumn(int pageindex,int index,int column,QColor color)
{
	QTableWidget* tablewidget = GetCurrentPagTable(pageindex);
	if (!tablewidget)
	{
		return;
	}
    QTableWidgetItem * selectitem = tablewidget->item(index,column);
	selectitem->setTextColor(color);
}

void SystemoptMainDlg::OnbuttonClicked (QAbstractButton * button )
{  
   int currentpage = m_Dialog.tabWidgetUI->currentIndex();
   int index = m_buttongroup->id(button);
   SafeRunInfo* runinfo = NULL;
   if (-1 != index)
   {  
      if (PAGE1 == currentpage)
      {   
		  if (index < RecordLogItem::Instance()->GetCountEnableArray())
		  {
               runinfo = RecordLogItem::Instance()->GetEnableArray(index);
		  }
		  else
		  {    
			   int newindex = index - RecordLogItem::Instance()->GetCountEnableArray();
               runinfo = RecordLogItem::Instance()->GetDisEnableArray(newindex);
		  }
          //runinfo  = RunItemFind::Instance()->GetRunInfo(index);
      }
      //获得禁用项目信息结构
      //SafeRunInfo* runinfo  = RunItemFind::Instance()->GetRunInfo(index);
      //判断
      //SafeRunInfo* Disitem = RecordLogItem::Instance()->GetDisEnableItem(*runinfo);
    
      bool Enable = runinfo->bEnable;
     /* if (!Disitem)
      {
        Enable = true;
        Disitem = runinfo;
      }
      else
      {
        Enable = false;
        delete runinfo;
      }*/
      if (DisRunItem::Instance()->ControlRun(Enable, runinfo))
      { 
        CircleButton* circlebutton = static_cast<CircleButton*>(button);
        //禁用
        if (Enable)
        {  
     
           RecordLogItem::Instance()->AddDisEnableArray(runinfo); //添加被禁止的项
           RecordLogItem::Instance()->SaveDisEnableLogItem();
		   SetTextColor(currentpage,index ,QColor(143,143,143));
           circlebutton->SetBackGroup("../SaftUI/Resources/min_button/jy.png");
        }
        else
        {  
          SetTextColor(currentpage,index ,QColor(0,0,0));
          RecordLogItem::Instance()->RemoveEnableItem(runinfo);  //添加
		  RunOptItem* optitem = RecordLogItem::Instance()->GetRunOptData(RUN_TYPE_STARTUP,runinfo->strPath);
          if (optitem)
          {
			  SetTextColorColumn(PAGE1,index,2,QColor(240,0,0));
          }
		  circlebutton->SetBackGroup("../SaftUI/Resources/min_button/qy.png");
        }
      }
   }
}
