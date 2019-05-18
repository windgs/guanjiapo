#include "FilterItem.h"

CFilterItem::CFilterItem(void)
{
  m_Filterfiles << "desktop.ini" << "index.dat" << "ntuser.dat" << "outlook.pst.tmp" <<
    "computer.lnk" << "control panel.lnk" << "run.lnk" << "help.lnk";
  
  m_DownFilterfiles << "FP_AX_CAB_INSTALLER.exe";
  
  m_FilterFuncMap.insert("%windir%",&CFilterItem::CheckWindowsPath);
  m_FilterFuncMap.insert("%program%",&CFilterItem::CheckProgramPath);
  m_FilterFuncMap.insert("%downloadlist%",&CFilterItem::CheckDownloadProPath);
  m_FilterFuncMap.insert("%specfiles%",&CFilterItem::CheckSpecFile);
}

CFilterItem::~CFilterItem(void)
{
}

CFilterItem* CFilterItem::Instance()
{
  static CFilterItem app;
  return &app;
}

QString CFilterItem::GetFileExtend(QString filename)
{
   int pos = filename.lastIndexOf('.');
   return filename.mid(pos + 1 ,filename.length() - pos);
}

bool CFilterItem::IsFilterFile(QString filename)
{  
   int count = m_Filterfiles.count(); 
   for (int i = 0;i < count;++i)
   {
     if (m_Filterfiles.at(i) == filename)
     {
         return true;
     }
   }
   
   int extend_count = m_FilterfilesEx.count();
   QString extendname = GetFileExtend(filename);
   for (int i = 0; i < extend_count;++i)
   {
      if (m_FilterfilesEx.at(i) == extendname)
      {
        return true;
      }
   }
   return false;
}

bool CFilterItem::IsFilterDir(QString dirname)
{
  int count = m_FilterDir.count(); 
  for (int i = 0;i < count;++i)
  {
    if (m_FilterDir.at(i) == dirname)
    {
      return true;
    }
  }
  return false;
}

bool CFilterItem::FindFuncMap(QString strFuncName, QString strFileName)
{
  QMap<QString, Filteroperator>::iterator iter = m_FilterFuncMap.find(strFuncName);
  if (iter == m_FilterFuncMap.end())
  {
    return false;
  }
  Filteroperator soperator = iter.value();
  return (this->*soperator)(strFileName);
}

bool CFilterItem::CheckWindowsPath(QString strFilePath)
{   
  WCHAR szPath[MAX_PATH] = { 0 };
  QString strWindir;
  if (0 != ::GetWindowsDirectory(szPath,MAX_PATH))
  {
    strWindir = QString::fromStdWString(szPath);
  }

  if (strFilePath.indexOf(strWindir) != -1)
  {
     return true;
  }
  return false;
}

bool CFilterItem::CheckProgramPath(QString strFilePath)
{
  WCHAR szPath[MAX_PATH] = { 0 };
  QString strSysdriver = "";

  if (0 != ::GetSystemDirectory(szPath,MAX_PATH))
  {
    QString syspath = QString::fromStdWString(szPath);
    strSysdriver += syspath[0];
    strSysdriver += syspath[1];
  }
  strSysdriver = strSysdriver + "\\program files";
  if (-1 != strFilePath.lastIndexOf(strSysdriver))
  {
     return true;
  }
  return false;
}

bool CFilterItem::CheckSpecFile(QString strFilePath)
{  
   int count = m_Filterfiles.count();
   for (int i = 0;i < count; ++i)
   {
       if (m_Filterfiles.at(i) == strFilePath)
       {
         return true;
       }
   }
   return false;
}

bool CFilterItem::CheckDownloadProPath(QString strFilePath)
{
  int count = m_DownFilterfiles.count();
  /*int pos = strFilePath.lastIndexOf("\\");
  if (pos == -1)
  {
    return false;
  }*/
  //QString filename = strFilePath.mid(0,pos - 1);
  for (int i = 0;i < count; ++i)
  {
    if (m_DownFilterfiles.at(i) == strFilePath)
    {
      return true;
    }
  }
  return false;
}