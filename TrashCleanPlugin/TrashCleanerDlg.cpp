#include "TrashCleanerDlg.h"
#include "ConfigData.h"
#include <QFileInfo>
#include <math.h>
#include <QDir>
#include <QDebug>
#include "FilterItem.h"
TrashCleanerDlg::TrashCleanerDlg(QWidget *parent, Qt::WindowFlags f )
:QDialog(parent,f)
{
  setWindowFlags(Qt::FramelessWindowHint); 
  m_TrashDlgUI.setupUi(this);
  connect(m_TrashDlgUI.toolButton_Min_2,SIGNAL(clicked()),this,SLOT(OnMinimized()));
  connect(m_TrashDlgUI.toolButton_Close_2,SIGNAL(clicked()),this,SLOT(OnCloseForm()));
  
  m_invisibleRoot = m_TrashDlgUI.treeWidget_trash->invisibleRootItem ();
  QTreeWidgetItem* winsys_root = new QTreeWidgetItem(QStringList()<<tr("windows系统垃圾文件"));
  winsys_root->setIcon(0, QIcon("../SaftUI/Resources/button/TrashButton/sys.bmp"));  
  winsys_root->setCheckState(0, Qt::Checked);  
  winsys_root->setData(1,0,tr("windows系统垃圾文件"));
  // m_TrashDlgUI.treeWidget_trash->addTopLevelItem(winsys_root);  
  m_invisibleRoot->addChild(winsys_root); 

  QTreeWidgetItem* ie_root = new QTreeWidgetItem(QStringList()<<tr("浏览器缓存目录"));
  ie_root->setIcon(0, QIcon("../SaftUI/Resources/button/TrashButton/ie.bmp"));  
  ie_root->setCheckState(0, Qt::Checked);
  ie_root->setData(1,0,tr("浏览器缓存目录"));
  m_invisibleRoot->addChild(ie_root); 
  //m_TrashDlgUI.treeWidget_trash->addTopLevelItem(ie_root);  
  
  QTreeWidgetItem* vedio_root = new QTreeWidgetItem(QStringList()<<tr("视频播放缓存目录"));
  vedio_root->setIcon(0, QIcon("../SaftUI/Resources/button/TrashButton/baofeng.bmp"));  
  vedio_root->setCheckState(0, Qt::Checked);
  vedio_root->setData(1,0,tr("视频播放缓存目录"));
  m_invisibleRoot->addChild(vedio_root); 
  //m_TrashDlgUI.treeWidget_trash->addTopLevelItem(vedio_root);
  
  m_TrashDlgUI.pushButton_Clean->setEnabled(false);

  Q_ASSERT(connect(m_TrashDlgUI.treeWidget_trash, SIGNAL(itemClicked(QTreeWidgetItem *, int)),this, SLOT(itemClick(QTreeWidgetItem *, int))));
  Q_ASSERT(connect(m_TrashDlgUI.pushButton_Scan,SIGNAL(clicked()),this,SLOT(OnScan())));
  Q_ASSERT(connect(m_TrashDlgUI.pushButton_Clean,SIGNAL(clicked()),this,SLOT(OnRemve())));
  Q_ASSERT(connect(&m_thread,SIGNAL(ItemAdd(QStringList,QString,QString)),this,SLOT(OnItemAdd(QStringList,QString,QString))));

  Q_ASSERT(connect(&m_thread,SIGNAL(NotifyDeleteFile(QString)),this,SLOT(OnDeleteWidgetItem(QString))));
  Q_ASSERT(connect(&m_thread,SIGNAL(NotifyFinished()),this,SLOT(OnSacnFinished())));
  Q_ASSERT(connect(&m_thread,SIGNAL(NotifyCurrentFindDir(QString)),this,SLOT(OnCurrentFindDir(QString))));
  Q_ASSERT(connect(m_TrashDlgUI.treeWidget_trash,SIGNAL(itemPressed( QTreeWidgetItem*, int)),this,SLOT(OnTreeWidgetPress(QTreeWidgetItem*, int))));
  Q_ASSERT(connect(m_TrashDlgUI.treeWidget_trash,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(OnitemDoubleClicked(QTreeWidgetItem*,int))));
  Q_ASSERT(connect(&m_thread,SIGNAL(NotifyHuiShouZhan(quint32, quint64)),this,SLOT(OnHuiShouZhan(quint32,quint64))));

  m_TrashDlgUI.label_Trash_gif->setHidden(true);
  m_Runninggif.setFileName("../SaftUI/Resources/gif/running.gif");
  m_TrashDlgUI.label_Trash_gif->setMovie(&m_Runninggif);
  
  m_thread.setDlg(this);
  ConfigData::Instance()->ConvertPath();
  CreateTreeView();
}

TrashCleanerDlg::~TrashCleanerDlg(void)
{
}

void TrashCleanerDlg::StartGif()
{
  m_TrashDlgUI.graphicsView_2->setHidden(true);
  if (QMovie::NotRunning == m_Runninggif.state())
  {
      m_Runninggif.start();
  }
 
  m_TrashDlgUI.label_Trash_gif->show();
}

void TrashCleanerDlg::StopGif()
{
   m_TrashDlgUI.graphicsView_2->show();
   m_Runninggif.stop();
   m_TrashDlgUI.label_Trash_gif->setHidden(true);
}
 
void TrashCleanerDlg::OnitemDoubleClicked ( QTreeWidgetItem * item, int column )
{
  QString text = item->text(column);
  if (text == tr("双击查看详情"))
  {   
      //打开回收站
     	ShellExecute(NULL, L"open", L"Explorer.exe", L"/n,::{645FF040-5081-101B-9F08-00AA002F954E}", NULL, SW_SHOWNORMAL);
  }
}

void TrashCleanerDlg::OnHuiShouZhan(quint32 count, quint64 size)
{
  QTreeWidgetItem* item = GetItem(m_invisibleRoot,tr("回收站"));
  
  QTreeWidgetItem* itemhuisz = new QTreeWidgetItem(QStringList() << tr("双击查看详情"));
  itemhuisz->setIcon(0,item->icon(0));
  item->addChild(itemhuisz);

  QString scount;
  QString ssize;
  scount.setNum(count);
  ssize.setNum(size);
  QString text = item->text(0) + tr("(共") + scount + tr("个文件") + tr("共") + ssize + tr("kb)") ;
  item->setText(0,text);
}

quint64 TrashCleanerDlg::CacleSize(QString path,QStringList fiels)
{
   int count = fiels.count();
   quint64 tatol = 0;
   DWORD filesize;
   int clusterSize = 4096;
   for (int i = 0; i < count;++i)
   {
     QString filepath = path + "/" + fiels.at(i);
     if (CFilterItem::Instance()->IsFilterFile(fiels.at(i)))
         continue;
     QString nativpath = QDir::toNativeSeparators(filepath);
     QFileInfo fileinfo(nativpath);
     if ((fileinfo.size() % clusterSize) == 0)
     {
        tatol += fileinfo.size();
     }
     else
     {  
       double res = fileinfo.size() / clusterSize;
       int clu = ceil(res) + 1;
       float temp = clusterSize * clu;
       tatol += temp;
       
     }

   }
   return static_cast<quint64>(tatol / 1024);
}

void TrashCleanerDlg::OnCurrentFindDir(QString dir)
{
  QString str = tr("正在扫描:") + dir;
  if (m_TrashDlgUI.label_notes->text() !=  str)
  {
    m_TrashDlgUI.label_notes->setText(str);
  }
}

void TrashCleanerDlg::OnSacnFinished()
{
  QString scansize;
  QString Text;
  if (m_SacnTotal < 1024)
  {
    scansize.setNum(m_SacnTotal);
    Text = tr("完成本次扫描 ,总发现垃圾文件 ") + scansize + tr("KB 建议立即清理!");
  }
  else if(m_SacnTotal < GBSIZE)
  {
    float sizebm = m_SacnTotal / MBSIZE;
    scansize.setNum(sizebm);
    Text = tr("完成本次扫描 ,总发现垃圾文件 ") + scansize + tr("MB 建议立即清理!");
  }
  else if(m_SacnTotal >= GBSIZE)
  {
    float sizebm = m_SacnTotal / (float)GBSIZE;
    scansize.setNum(sizebm);
    Text = tr("完成本次扫描 ,总发现垃圾文件 ") + scansize + tr("GB 建议立即清理!");
  }
  m_TrashDlgUI.label_notes->setText(Text);
  StopGif();
  CacleZeroItem();
}

void TrashCleanerDlg::OnDeleteWidgetItem(QString filename)
{  
   QTreeWidgetItem*	items = GetItem(m_invisibleRoot,filename);
   if (items)
   {
       QTreeWidgetItem* parent = items->parent();
       parent->removeChild(items);
   } 
   
}

void TrashCleanerDlg::OnTreeWidgetPress(QTreeWidgetItem * item, int column )
{
   if (item->childCount () == 0)
   {
       return;
   }
   if (item->checkState(0) == Qt::Checked)
   {
       int count = item->childCount();
       ConfigData::Instance()->setNodeSelect(item->data(1,0).toString(),false);
       for (int i = 0;i < count; ++i)
       {   
         Qt::ItemFlags flags = item->child(i)->flags();
         if (Qt::ItemIsUserCheckable & flags)
         {
           item->child(i)->setCheckState(0,Qt::Unchecked);
           ConfigData::Instance()->setNodeSelect(item->child(i)->data(1,0).toString(),false);
         }
       }

    }
   
   else
   {
     int count = item->childCount();
     for (int i = 0;i < count; ++i)
     {
        
       Qt::ItemFlags flags = item->child(i)->flags();
         ConfigData::Instance()->setNodeSelect(item->data(1,0).toString(),true);
       if (Qt::ItemIsUserCheckable & flags)
       {
         item->child(i)->setCheckState(0,Qt::Checked);
         ConfigData::Instance()->setNodeSelect(item->child(i)->data(1,0).toString(),true);
       }
      
     }
   }
}

QStringList TrashCleanerDlg::GetClearItem(int id)
{
   QMap<int,QStringList>::iterator iter = m_ClearMap.find(id);
   if (iter == m_ClearMap.end())
   {
     return QStringList();
   }
   return iter.value();
} 

void TrashCleanerDlg::InsertClearItem(int id, QStringList itemlist)
{
  QMap<int,QStringList>::iterator iter = m_ClearMap.find(id);
  if (iter == m_ClearMap.end())
  {
      m_ClearMap.insert(id,itemlist);
  }
  else
  {
      iter.value() << itemlist;
  }

}

void TrashCleanerDlg::ClearSizeMap()
{
   m_sizemap.clear();
}

void TrashCleanerDlg::InsertSizeMap(int id, quint64 ssize)
{
  QMap<int,quint64>::iterator iter = m_sizemap.find(id);
  if (iter == m_sizemap.end())
  {
     m_sizemap.insert(id,ssize);
  }
  else
  {
     iter.value() += ssize;
  }
}

quint64 TrashCleanerDlg::GetSizeMap(int id)
{
  QMap<int,quint64>::iterator iter = m_sizemap.find(id);
  if (iter != m_sizemap.end())
  {
    return iter.value();
  }
  return 0;
}

void TrashCleanerDlg::CacleZeroItem()
{
   int count = m_invisibleRoot->childCount();
   for (int i = 0;i < count; ++i)
   {
       QTreeWidgetItem* childitem = m_invisibleRoot->child(i);
       if (!childitem || childitem->checkState(0) == Qt::Unchecked)
       {
         continue;
       }
       int childcount = childitem->childCount();
       for (int j = 0; j < childcount; ++j)
       {
         //判断该选项是否为空

         const FindDirInfo& info = ConfigData::Instance()->GetItem(childitem->child(j)->data(1,0).toString());
         QMap<int,quint64>::iterator iter = m_sizemap.find(info.id);
         if (iter == m_sizemap.end() && childitem->child(j)->checkState(0) == Qt::Checked)
         {
           QString Text = childitem->child(j)->text(0) + tr("(无)");
           childitem->child(j)->setText(0,Text);
         }
       }
    }
}

void TrashCleanerDlg::OnItemAdd(QStringList scanitems,QString path,QString FriendName)
{  
   QTreeWidgetItem* parent = GetItem(m_invisibleRoot,FriendName);
   if (!parent)
   {
     return;
   }
  
   if (FriendName == tr("回收站"))
   {
       QTreeWidgetItem* item = new QTreeWidgetItem(QStringList() << path);
       item->setIcon(0,parent->icon(0));
       parent->addChild(item);
       
       return;
   }
  
   const FindDirInfo& info = ConfigData::Instance()->GetItem(FriendName);
  
   int count = scanitems.count();
   quint64 scansize = CacleSize(path, scanitems);
   m_SacnTotal += scansize;
   QString ssize;
   int cleatid = info.id;
   InsertSizeMap(cleatid, scansize);
   quint64 total_size = GetSizeMap(cleatid);
   //不大于1024以字节显示，大于的以M显示
   float tsize = 0;
   bool ismb = false;
   QString kborbm = "KB)";
   if (total_size > GBSIZE)
   {
      tsize = total_size / (float)GBSIZE;
      kborbm = "GB)";
      ismb = true;
   }
   else if (total_size > 1024)
   {
      tsize = total_size / 1024.0;
      ismb = true;
      kborbm = "MB)";
   }
   if (!ismb)
      ssize.setNum(total_size);
   else
      ssize.setNum(tsize);
   QString text;
   if (!info.bRecursive)
   {
      text = parent->data(1,0).toString()+ "[" + path + "]" +"(" + ssize + kborbm;
   }
   else
   {
      text = parent->data(1,0).toString() +"(" + ssize + kborbm;
   }
  
   parent->setText(0,text);
   if (parent->isExpanded())
   {
     parent->setExpanded(false);
   }
   QStringList clearlist;
   for (int i = 0;i < count; ++i)
   {
     QString text = scanitems.at(i);
     //判断是否需要被过滤
     if (CFilterItem::Instance()->IsFilterFile(text))
         continue;
     QTreeWidgetItem* item = new QTreeWidgetItem();
     item->setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled);
     item->setIcon(0, QIcon(info.iconName));
     //保存需要清楚的文件
     
     if (parent)
     {
        parent->addChild(item);
        QString absoltpath = path + "/" + text;
        absoltpath = QDir::toNativeSeparators(absoltpath);
       
       
        if (info.bRecursive)
        {
           item->setText(0,absoltpath);
           item->setToolTip(0,absoltpath);
        }
        else
        {
           item->setText(0,text);
        }
        clearlist.append(absoltpath);
     }
     
   }
   if (!clearlist.isEmpty())
   {
     InsertClearItem(cleatid,clearlist);
    
   }
   
}

QTreeWidgetItem* TrashCleanerDlg::GetItem(QTreeWidgetItem* curitem ,QString FirendName)
{
 
  QTreeWidgetItem* find_item = NULL; 
  if (curitem->data(1,0).toString() == FirendName)
  {
    return curitem;
  }
  if (curitem->childCount() > 0)
  {
    int count = curitem->childCount();
    for (int i = 0;i < count; ++i)
    {
      find_item = GetItem(curitem->child(i),FirendName);
      if (NULL != find_item)
      {
        return find_item;
      }
    }
    
  }
  return NULL;
}

void TrashCleanerDlg::OnScan()
{ 
  StartGif();
  int count = m_invisibleRoot->childCount();
  m_SacnTotal = 0;
  ClearSizeMap();
  m_thread.setAction(ACTIONSCAN);
  for (int i = 0;i < count; ++i)
  {  
     QTreeWidgetItem* topitem = m_invisibleRoot->child(i);
     
     QString text = topitem->text(0);
     if (!topitem)
     {
       continue;
     }
     for (int childindex = 0;childindex < topitem->childCount(); ++childindex)
     {
        QTreeWidgetItem* childitem = topitem->child(childindex);
        QString text = childitem->text(0);
        Qt::CheckState state = childitem->checkState(0);
        if (Qt::Unchecked == state)
        {
          continue;
        }
        const FindDirInfo& info =  ConfigData::Instance()->GetItem(text);
        m_thread.Append(info);
     }
    
   }

  if (m_thread.count() > 0)
  {
    m_thread.start();
  }
   m_TrashDlgUI.pushButton_Clean->setEnabled(true);
}

void TrashCleanerDlg::OnRemve()
{
  int count = ConfigData::Instance()->count();
  m_thread.setAction(ACTIONCLEAR);
  m_thread.start();
}

void TrashCleanerDlg::CreateTreeView()
{
   int count = ConfigData::Instance()->count();
   for (int i = 0;i < count; ++i)
   {
     const FindDirInfo& info = ConfigData::Instance()->GetData(i);
     QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<info.strFriendName);
     item->setIcon(0, QIcon(info.iconName));  
     item->setCheckState(0, Qt::Checked);
     item->setData(1,0,info.strFriendName); //设置该节点唯一名称
     QTreeWidgetItem* parentitem = m_invisibleRoot->child(info.parent);
     //QString text = parentitem->text(0);
     if (parentitem)
     {
       parentitem->addChild(item);
     }
     
   }

   m_TrashDlgUI.treeWidget_trash->expandAll();
}

void TrashCleanerDlg::itemClick(QTreeWidgetItem* item, int column)
{
    
}

void TrashCleanerDlg::OnCloseForm()
{
  close();
}

void TrashCleanerDlg::OnMinimized()
{
  showMinimized() ;
}