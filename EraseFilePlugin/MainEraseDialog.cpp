#include "MainEraseDialog.h"
#include <QStringList>
#include <QCloseEvent>
#include <QBitmap>
#include <QPainter>
#include "MainPlugin.h"
#include <QFileDialog>
#include <QDir>
#include <QStandardItem>

#include "../Common/CommonUI/MsgBoxDlg.h"

MainEraseDialog::MainEraseDialog(CMainPlugin*  plugin,QDialog* parent)
:QDialog(parent)
,m_EraseFile(this)
{ 
  setWindowFlags(Qt::FramelessWindowHint); 
 /* QPalette palette_back;
  palette_back.setBrush(QPalette::Background, QBrush(QPixmap("../SaftUI/Resources/b4.png")));
  setPalette(palette_back);*/
  //setCellWidget
  m_MainDiglog.setupUi(this);
  QStringList headerlabels;
  headerlabels << tr("名称") << tr("路径");
  m_tableModel.setHorizontalHeaderLabels(headerlabels);
  m_MainDiglog.tableView_Fiels->setModel(&m_tableModel);
  m_MainDiglog.tableView_Fiels->setColumnWidth(0,300);
  m_MainDiglog.tableView_Fiels->setColumnWidth(1,500);
  m_MainDiglog.progressBar_FreeSpace->setVisible(false);
 
  m_parent_plugin = plugin;
  m_MainDiglog.pushButton_Erase_File->setEnabled(false);

  //bool suc = AdjustPurview();
  Connect();
 
}


bool MainEraseDialog::AdjustPurview()
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


void MainEraseDialog::Connect()
{
 // bool ret = connect(this,SIGNAL(SignalClose()), plugin, SLOT(SlotCloseWindow()));
  connect(m_MainDiglog.pushButton_AddFile,SIGNAL(clicked()), this, SLOT(AddFile()));
  connect(m_MainDiglog.pushButton_Add_Dir,SIGNAL(clicked()), this, SLOT(OnAddDir()));
  connect(m_MainDiglog.pushButton_Delete,SIGNAL(clicked()), this, SLOT(OnDeleteItem()));
  connect(m_MainDiglog.toolButton_Close,SIGNAL(clicked()), this, SLOT(OnCloseForm()));
  connect(m_MainDiglog.toolButton_Min,SIGNAL(clicked()), this, SLOT(OnMinimized()));
  connect(m_MainDiglog.pushButton_Erase_File,SIGNAL(clicked()), this, SLOT(OnEraseStart()));
  connect(m_MainDiglog.pushButton_FreeSpace,SIGNAL(clicked()), this, SLOT(OnFreeSpace()));
}

MainEraseDialog::~MainEraseDialog(void)
{

}

void MainEraseDialog::OnEraseStart()
{   
  int count = m_tableModel.rowCount();
  QStringList pathList;
  for (int i = 0;i < count; ++i)
  {
     QStandardItem* item_name = m_tableModel.item(i,0);
     QStandardItem* item_dir = m_tableModel.item(i,1);
     pathList.append(item_dir->text() +"/" + item_name->text());
  }
  if (!pathList.isEmpty())
  {
     if(m_EraseFile.StartEraseFile(pathList))
     {
        OnDeleteItemAll();
     }
  }
 
}

void MainEraseDialog::OnAddDir()
{
  QString Dir = QFileDialog::getExistingDirectory(this, tr("选择文件夹"),
  "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
  
  if (Dir.isEmpty())
  {
    return;
  }
  QDir qdir(Dir);
  QString dirname = qdir.dirName();
  int index = qdir.path().lastIndexOf('/');
  if (-1 == index)
  {
    return;
  }
  QString path = qdir.path().left(index);
  int size = m_tableModel.rowCount();
  QStandardItem *item_name = new QStandardItem(dirname);
  QStandardItem *item_dir = new QStandardItem(path);
  m_tableModel.setItem(size, 0, item_name);
  m_tableModel.setItem(size, 1, item_dir);
  m_MainDiglog.pushButton_Erase_File->setEnabled(true);
}

void MainEraseDialog::AddFile()
{
 QFileDialog QSelectDlg(this);
 QStringList files = QSelectDlg.getOpenFileNames(this, tr("选择文件"),"./");
 
 if (files.isEmpty())
 {
	 return;
 }
 QString filename;
 QString path;
 int count = files.count();
 int size = m_tableModel.rowCount();
 for (int i = 0;i < count; ++i)
 {
   QDir dir(files.at(i));
   filename = dir.dirName();
   QString filepath = dir.path();
   int index = filepath.lastIndexOf('/');
	 if (-1 == index)
	 {
		 continue;
	 }
   path = filepath.left(index);
   QStandardItem *item_name = new QStandardItem(filename);
   QStandardItem *item_dir = new QStandardItem(path);
   m_tableModel.setItem(i + size , 0, item_name);
   m_tableModel.setItem(i + size, 1, item_dir);
	 //m_MainDiglog.tableView_Fiels->setCellWidget(i,0,new QCheckBox());
 }
   m_MainDiglog.pushButton_Erase_File->setEnabled(true);
}

void MainEraseDialog::OnCloseForm()
{
   close();
}

void MainEraseDialog::OnMinimized()
{
   showMinimized() ;
}

void MainEraseDialog::OnProgressValue(int iValue)
{
   m_MainDiglog.progressBar_FreeSpace->setValue(iValue);
}

void MainEraseDialog::OnMaximized()
{  
  if (isMaximized ())
  {
    showNormal ();
  }
  else
  {
     showMaximized () ;
  }
}

void MainEraseDialog::OnDeleteItemAll()
{
  m_tableModel.removeRows(0,m_tableModel.rowCount());
  m_MainDiglog.pushButton_Erase_File->setEnabled(false);
}

void MainEraseDialog::OnFreeSpace()
{  
   MsgBoxDlg msgbox(tr("文件粉碎"),tr("是否擦除存在于磁盘的未分配部分中的任意文件数据"),this);
   if (msgbox.exec() == QDialog::Accepted)
   {   
       m_MainDiglog.progressBar_FreeSpace->setVisible(true);
       m_EraseFile.CleanFreeSpace();
   }
   
}

void MainEraseDialog::OnDeleteItem()
{
   QModelIndex curent_index = m_MainDiglog.tableView_Fiels->currentIndex() ;
   if (!curent_index.isValid())
   {
     return;
   }
   //QVariant var = m_tableModel.data(curent_index);
   m_tableModel.removeRow(curent_index.row());
   if (m_tableModel.rowCount() == 0)
   {
     m_MainDiglog.pushButton_Erase_File->setEnabled(false);
   }
}

void MainEraseDialog::closeEvent(QCloseEvent *event)
{
  
  event->accept();
  emit SignalClose();
}

void MainEraseDialog::paintEvent ( QPaintEvent * event )
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