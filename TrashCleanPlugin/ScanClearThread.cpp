#include "ScanClearThread.h"
#include <QDir>
#include "TrashCleanerDlg.h"
#include "ConfigData.h"
#include "FileDelete.h"
#include <QTest>
#include "FilterItem.h"
ScanClearThread::ScanClearThread(void)
{
  m_curaction = ACTIONNONE;
  m_WorkDir.clear();
}

ScanClearThread::~ScanClearThread(void)
{
}

void ScanClearThread::Append(const FindDirInfo& info)
{
  m_WorkDir.append(info);
}

void	ScanClearThread::run ()
{
    if (ACTIONNONE == m_curaction)
    {
      return;
    }
    switch (m_curaction)
    {
      case ACTIONSCAN:
        ActionSacn();
        break;
      case ACTIONCLEAR:
        ActionClear();
        break;
    }
    m_curaction = ACTIONNONE;
    m_WorkDir.clear();
    emit NotifyFinished();
}

bool ScanClearThread::FindFileWithExtInDirectory(QString path,
                                                 QStringList strExtArray, 
                                                 QStringList strFilt,
                                                 int index,
                                                 QString FriendName)
{

  QDir dir(path);
  QStringList entryfiles;
  QStringList afterfiles;
  if (strExtArray.at(0) == "*.*")
  {
    entryfiles = dir.entryList (QDir::Files | QDir::Hidden | QDir::System);
  }
  else
  {
    entryfiles = dir.entryList (strExtArray,QDir::Files | QDir::Hidden | QDir::System);
  }
 
  if (!entryfiles.isEmpty())
  {  
    //过滤文件
    int count = entryfiles.count();
    for (int i = 0; i < count; ++i)
    { 
      int filtercount = strFilt.count();
      bool isfilter = false;
      for (int index = 0; index < filtercount; ++index)
      {
        if (CFilterItem::Instance()->FindFuncMap(strFilt.at(index),entryfiles.at(i)))
        {
          //entryfiles.removeAt(i);
          //count = entryfiles.count();
          isfilter = true;
          break;
        }
      }
      if (!isfilter)
      {
        afterfiles.append(entryfiles.at(i));
      }
    }
    emit ItemAdd(afterfiles, path ,FriendName);
  }
  return true;
}

//获得目录下子目录
QStringList ScanClearThread::GetSubDir(QString path)
{
  QDir dir(path);
  QStringList entryDir;
  QStringList absoluteDir;
  entryDir = dir.entryList (QDir::AllDirs|QDir::NoDotAndDotDot|QDir::Hidden|QDir::System);
 
  int count = entryDir.count();
  for (int i = 0; i < count;++i)
  {
    QString absolutePath = path + "\\" + entryDir.at(i);
    absoluteDir.append(absolutePath);
  }
  return absoluteDir;
}

bool ScanClearThread::FindFileInDirectory(const FindDirInfo& info)
{  
  if (info.id == WIN_HUISHOUZHAN)
  {
    SHQUERYRBINFO syscleInfo = {0};
    syscleInfo.cbSize = sizeof(SHQUERYRBINFO);
    QString str = tr("双击查看详情");
    int iCount = SHQueryRecycleBin(NULL, &syscleInfo);
    if (syscleInfo.i64NumItems > 0)
    {
       // emit ItemAdd(QStringList(), str ,tr("回收站"));
       emit NotifyHuiShouZhan((quint32)syscleInfo.i64NumItems,(quint64)syscleInfo.i64Size / 1024);
    }
    
    return true;
  }
  int count = info.strDirectory.count();
  for (int i = 0;i < count; ++i)
  { 
    //处理掉不存在，或者不合法的目录
    QString finddir = info.strDirectory.at(i);
    QDir dir(finddir);
    if (!dir.exists())
    {
      continue;
    }
    emit NotifyCurrentFindDir(finddir);
    
    FindFileWithExtInDirectory(finddir,info.strExtArray,info.strFilt,info.id,info.strFriendName);
    QTest::qWait(100);
    //如果设置为递归搜索文件夹
    if (info.bRecursive)
    {
       QStringList subdir = GetSubDir(finddir);
       int si = subdir.count();
       for (int j = 0;j < si; ++j)
       {    
            FindDirInfo subinfo = info;
            subinfo.strDirectory.clear();
            subinfo.strDirectory << subdir.at(j);
            FindFileInDirectory(subinfo);
       }
    }
  }
  return true;
}

void ScanClearThread::ActionSacn()
{
    int count = m_WorkDir.count();
    for (int i = 0;i< count; ++i)
    {
        const FindDirInfo& info = m_WorkDir.at(i);
        FindFileInDirectory(info);
    }
}

void ScanClearThread::ActionClear()
{
     if (m_curaction != ACTIONCLEAR)
     {
       return;
     }
     //获得要处理的项
     int count = ConfigData::Instance()->count();
     for (int i = 0; i< count; ++i)
     {
        const FindDirInfo& info = ConfigData::Instance()->GetData(i);
        if (info.bselect)
        {
            QStringList listitem = m_Dlg->GetClearItem(info.id);
            if (listitem.isEmpty())
            {
              continue;
            }
            //开始删除垃圾文件
            int size = listitem.count();
            for (int j = 0; j< size; ++j)
            {
              int res = CFileDelete::Instance()->TrashFileDelete(listitem.at(j));
              //通知给UI
              QDir dirfile(listitem.at(j));
              QString filename = dirfile.dirName();
              emit NotifyDeleteFile(filename);
            }
            
        }
     }
}