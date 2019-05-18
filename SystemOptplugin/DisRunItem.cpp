#include "DisRunItem.h"
#include <QDir>
#include <ShlObj.h>
DisRunItem::DisRunItem(void)
{
}

DisRunItem::~DisRunItem(void)
{
}

DisRunItem* DisRunItem::Instance()
{
   static DisRunItem app;
   return &app;
}

void DisRunItem::ControlRunProcess(bool nEnable, int Regtype,SafeRunInfo* ruinfo)
{
   if (!nEnable)
   {
      EnableRun(Regtype,ruinfo);
   }
   else
   { 
      DisEnableRun(Regtype,ruinfo);
   }
}

bool DisRunItem::EnableRun(int Regtype, SafeRunInfo* ruinfo)
{
  QString filename = GetFilename(ruinfo->strExePath);
  QString NewFilePath;
  //只处理目录启动项 
  if (!(ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_USER || ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_COMM))
  {
    return false;
  }
  TCHAR	szPath[MAX_PATH] = {0};
   
  if (ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_USER)
  {
    SHGetSpecialFolderPath( NULL, szPath, CSIDL_STARTUP, FALSE );
    NewFilePath = QString::fromStdWString(szPath);
  }
  else
  {
    SHGetSpecialFolderPath( NULL, szPath, CSIDL_COMMON_STARTUP, FALSE );
    NewFilePath = QString::fromStdWString(szPath);
  }
  
  NewFilePath += QString::fromStdWString(L"\\");
  NewFilePath += filename;
  QString ExistingFileName = ruinfo->strDisPath + "\\" + filename;
  if (::MoveFileEx(ExistingFileName.toStdWString().c_str(),NewFilePath.toStdWString().c_str(),
    MOVEFILE_COPY_ALLOWED|MOVEFILE_REPLACE_EXISTING))
  {
    ruinfo->bEnable = true;
    ruinfo->strDisPath = "";
    return true;
  }
  return false;
}

bool DisRunItem::GetDisDir(bool bCurrentUser, QString& strpath)
{
  if (bCurrentUser)
  {
     TCHAR	szBuffer[MAX_PATH] = {0};
     if (::SHGetSpecialFolderPath(NULL,szBuffer,CSIDL_APPDATA,TRUE) )
     {
       QString strDir = QString::fromStdWString(szBuffer);
       if (strDir.isEmpty())
       {
         return false;
       }
       strDir += QString::fromStdWString(L"\\GJQ\\");
       QDir qdir(strDir);
       if (!qdir.exists())
       {
          qdir.mkpath(strDir);
       }
       strDir += QString::fromStdWString(KSAFE_DISABLE_USER_RUN_DIR);
       QDir dir(strDir);
       if (!dir.exists())
       {
         dir.mkpath(strDir);
       }
       strpath =  strDir;
   }
 }
   else
   {
     ;
   }
     return true;
}

bool DisRunItem::DisEnableRun(int Regtype, SafeRunInfo* ruinfo)
{
    QString filename = GetFilename(ruinfo->strExePath);
    QString NewFilePath;
    //只处理目录启动项 
    if (!(ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_USER || ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_COMM))
    {
      return false;
    }
    if (ruinfo->nRegType == DIR_RUN_TYPE_WINDOW_USER)
    {
       GetDisDir(true,NewFilePath);
    }
    else
    {
       GetDisDir(false,NewFilePath);
    }
    QString disenablepath = NewFilePath;
    NewFilePath += QString::fromStdWString(L"\\");
    NewFilePath += filename;
    // 从启动项目录移动到禁用项保存目录
    if (::MoveFileEx(ruinfo->strExePath.toStdWString().c_str(),NewFilePath.toStdWString().c_str(),
                         MOVEFILE_COPY_ALLOWED|MOVEFILE_REPLACE_EXISTING))
    {
      ruinfo->strDisPath = disenablepath;
      ruinfo->bEnable = false;
      return true;
    }
    return false;
}

bool DisRunItem::ControlRun(bool nEnable, SafeRunInfo* ruinfo)
{
    if (ruinfo->nType == RUN_TYPE_STARTUP)
    {
      ControlRunProcess(nEnable, ruinfo->nRegType, ruinfo);
    }
    return true;
}

QString DisRunItem::GetFilename(QString path)
{
    int pos = path.lastIndexOf('\\');
    if (-1 == pos)
    {
      return "";
    }
    return path.mid(pos + 1,path.length() - pos);
}