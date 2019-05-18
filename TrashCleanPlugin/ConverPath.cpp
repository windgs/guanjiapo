#include "ConverPath.h"
#include <Shlobj.h>
#include <QSettings>
#include <QFile>
#include "..\Common\OperatorRegedit.h"
ConverPath::ConverPath(void)
{
  InitCsidlNameEntry();
}

ConverPath::~ConverPath(void)
{
}

ConverPath* ConverPath::Instance()
{
  static ConverPath app;
  return &app;
}

void ConverPath::InitCsidlNameEntry()
{
  m_CsidlEntryMap.insert("CSIDL_DESKTOP",CSIDL_DESKTOP);
  m_CsidlEntryMap.insert("CSIDL_INTERNET",CSIDL_INTERNET);
  m_CsidlEntryMap.insert("CSIDL_PROGRAMS",CSIDL_PROGRAMS);
  m_CsidlEntryMap.insert("CSIDL_CONTROLS",CSIDL_CONTROLS);
  m_CsidlEntryMap.insert("CSIDL_PRINTERS",CSIDL_PRINTERS);
  m_CsidlEntryMap.insert("CSIDL_FAVORITES",CSIDL_FAVORITES);
  m_CsidlEntryMap.insert("CSIDL_STARTUP",CSIDL_STARTUP);
  m_CsidlEntryMap.insert("CSIDL_RECENT",CSIDL_RECENT);
  m_CsidlEntryMap.insert("CSIDL_SENDTO",CSIDL_SENDTO);
  m_CsidlEntryMap.insert("CSIDL_BITBUCKET",CSIDL_BITBUCKET);
  m_CsidlEntryMap.insert("CSIDL_STARTMENU",CSIDL_STARTMENU);
  m_CsidlEntryMap.insert("CSIDL_DESKTOPDIRECTORY",CSIDL_DESKTOPDIRECTORY);
  m_CsidlEntryMap.insert("CSIDL_DRIVES",CSIDL_DRIVES);
  m_CsidlEntryMap.insert("CSIDL_NETWORK",CSIDL_NETWORK);
  m_CsidlEntryMap.insert("CSIDL_NETHOOD",CSIDL_NETHOOD);
  m_CsidlEntryMap.insert("CSIDL_FONTS",CSIDL_FONTS);
  m_CsidlEntryMap.insert("CSIDL_TEMPLATES",CSIDL_TEMPLATES);
  m_CsidlEntryMap.insert("CSIDL_COMMON_STARTMENU",CSIDL_COMMON_STARTMENU);
  m_CsidlEntryMap.insert("CSIDL_COMMON_PROGRAMS",CSIDL_COMMON_PROGRAMS);
  m_CsidlEntryMap.insert("CSIDL_COMMON_STARTUP",CSIDL_COMMON_STARTUP);
  m_CsidlEntryMap.insert("CSIDL_COMMON_DESKTOPDIRECTORY",CSIDL_COMMON_DESKTOPDIRECTORY);
  m_CsidlEntryMap.insert("CSIDL_APPDATA",CSIDL_APPDATA);
  m_CsidlEntryMap.insert("CSIDL_PRINTHOOD",CSIDL_PRINTHOOD);
  m_CsidlEntryMap.insert("CSIDL_ALTSTARTUP",CSIDL_ALTSTARTUP);
  m_CsidlEntryMap.insert("CSIDL_COMMON_ALTSTARTUP",CSIDL_COMMON_ALTSTARTUP);
  m_CsidlEntryMap.insert("CSIDL_COMMON_FAVORITES",CSIDL_COMMON_FAVORITES);
  m_CsidlEntryMap.insert("CSIDL_INTERNET_CACHE",CSIDL_INTERNET_CACHE);
  m_CsidlEntryMap.insert("CSIDL_COOKIES",CSIDL_COOKIES);
  m_CsidlEntryMap.insert("CSIDL_HISTORY",CSIDL_HISTORY);
  m_CsidlEntryMap.insert("CSIDL_LOCAL_APPDATA",CSIDL_LOCAL_APPDATA);
  m_CsidlEntryMap.insert("CSIDL_COMMON_APPDATA",CSIDL_COMMON_APPDATA);

}

QString ConverPath::GetFolderPath(QString strEnvName)
{
  QMap<QString, int>::iterator iter = m_CsidlEntryMap.find(strEnvName);
  if (iter == m_CsidlEntryMap.end())
  {
    return "";
  }
  int cslid = iter.value();
  WCHAR szPath[MAX_PATH] = {0};
  QString strResult;
  if (::SHGetSpecialFolderPath( NULL, szPath, cslid, FALSE) )
    strResult = QString::fromStdWString(szPath);

  return strResult;
}

void  ConverPath::GetPrePos(QString path, int& first,int& second)
{
  first = path.indexOf('%');
  second = path.indexOf('%',first + 1);
}

QString ConverPath::ConverFindPath(QString dir)
{  
   //%windir%/temp  C:\windows\
   
   QString EvnPath;
   int firstpos = dir.indexOf('%');
   int second = dir.indexOf('%',firstpos + 1);
   if (-1 == firstpos || -1 == second)
   {
     return "";
   }
   QString strEnvName = dir.mid(firstpos + 1, second - 1);
   EvnPath = GetEnvVariable(strEnvName);
   if (EvnPath == "")
   {
     EvnPath = GetFolderPath(strEnvName);
   }
   QString rightstr =  dir.right(dir.length() - second - 1);
   if (!rightstr.isEmpty())
   {
     EvnPath = EvnPath + rightstr;
   }
   
   return EvnPath;
}

QString ConverPath::GetEnvironmentPath(QString ss)
{
  int firstpos = 0;
  int second = 0;
  GetPrePos(ss,firstpos,second);
  QString sleft = ss.mid(firstpos + 1, second - 1);
  QString dright = ss.mid(second + 1, sleft.length() - second);
  TCHAR szTempBuf[MAX_PATH] = {0};
  DWORD dwResult = GetEnvironmentVariable(sleft.toStdWString().c_str(), szTempBuf, MAX_PATH);
  QString strEnvVariable;
  if (dwResult > 0)
      strEnvVariable = QString::fromStdWString(szTempBuf);

  return strEnvVariable + dright;
}

QString ConverPath::GetEnvVariable(QString pszName)
{
   TCHAR szBuffer[MAX_PATH] = {0};
   TCHAR szLongPathBuffer[MAX_PATH] = {0};
   QString EvnPath = "";
   int firstpos = 0;
   int second = 0;
   if (pszName == "windir")
   {
      UINT uResult = GetWindowsDirectory(szBuffer, MAX_PATH);
      EvnPath = QString::fromStdWString(szBuffer);
      return EvnPath;
   }
   else if(pszName == "archivefiles")
   {
     TCHAR szLongPathBuffer[MAX_PATH];
     DWORD len = sizeof(szLongPathBuffer);
     //先读取注册表获得"windows错误报告"文件夹环境变量
     COPeratorRegedit::GetRegistryValue(HKEY_LOCAL_MACHINE,
       "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VolumeCaches\\Windows Error Reporting Archive Files",
       "Folder",
       NULL,
       (LPBYTE)szLongPathBuffer,
       &len
       );

     EvnPath = GetEnvironmentPath(QString::fromStdWString(szLongPathBuffer));;
     return EvnPath;
   }
   else if (pszName == "minidump")
   {
     TCHAR szLongPathBuffer[MAX_PATH];
     DWORD len = sizeof(szLongPathBuffer);
     //先读取注册表获得"mini dump"文件夹环境变量
     COPeratorRegedit::GetRegistryValue(HKEY_LOCAL_MACHINE,
       "SYSTEM\\CurrentControlSet\\Control\\CrashControl",
       "MinidumpDir",
       NULL,
       (LPBYTE)szLongPathBuffer,
       &len
       );
       
     EvnPath = GetEnvironmentPath(QString::fromStdWString(szLongPathBuffer));
     return EvnPath;
   }
   else if(pszName == "memdump")
   {
     TCHAR szLongPathBuffer[MAX_PATH];
     DWORD len = sizeof(szLongPathBuffer);
     //先读取注册表获得"mini dump"文件夹环境变量
     COPeratorRegedit::GetRegistryValue(HKEY_LOCAL_MACHINE,
       "SYSTEM\\CurrentControlSet\\Control\\CrashControl",
       "DumpFile",
       NULL,
       (LPBYTE)szLongPathBuffer,
       &len
       );

     EvnPath = GetEnvironmentPath(QString::fromStdWString(szLongPathBuffer));
     return EvnPath;
   }
   else if(pszName == "xunleikankan")
   { 
     TCHAR szLongPathBuffer[MAX_PATH];
     DWORD len = sizeof(szLongPathBuffer);
     COPeratorRegedit::GetRegistryValue(HKEY_LOCAL_MACHINE,
       "SOFTWARE\\Thunder network\\Xmp",
       "storepath",
       NULL,
       (LPBYTE)szLongPathBuffer,
       &len
       );
     EvnPath = GetEnvironmentPath(QString::fromStdWString(szLongPathBuffer));
     return EvnPath;
   }
   else if (pszName == "youku")
   {
     TCHAR szLongPathBuffer[MAX_PATH];
     DWORD len = sizeof(szLongPathBuffer);
     COPeratorRegedit::GetRegistryValue(HKEY_CURRENT_USER,
       "SOFTWARE\\youku\\iKuAcc",
       "CachePath",
       NULL,
       (LPBYTE)szLongPathBuffer,
       &len
       );
     EvnPath = GetEnvironmentPath(QString::fromStdWString(szLongPathBuffer));
     return EvnPath;
   }
   else if (pszName == "qqlive")
   {
     QString strTmp = GetFolderPath("CSIDL_APPDATA");
     strTmp += "\\Tencent\\QQLive\\user.ini";
     //读取配置文件里的缓存路径
     if (!QFile::exists(strTmp))
     {
       return "";
     }
     QSettings iniread(strTmp ,QSettings::IniFormat,0);
     EvnPath = iniread.value("Cache/Directory").toString();
   }
   else if (pszName == "pptv")
   {
     QString strTmp = GetFolderPath("CSIDL_COMMON_APPDATA");
     strTmp += "\\PPLive\\Core\\config.ini";
     if (!QFile::exists(strTmp))
     {
       return "";
     }
     QSettings iniread(strTmp ,QSettings::IniFormat,0);
     EvnPath = iniread.value("peer/cachepath").toString();
   }
   //通过环境变量名称查找路径
   if (!pszName.isEmpty())
   {
     TCHAR szTempBuf[MAX_PATH] = {0};
     DWORD dwResult = GetEnvironmentVariable(pszName.toStdWString().c_str(), szTempBuf, MAX_PATH);
     if (dwResult > 0)
       EvnPath = QString::fromStdWString(szTempBuf);
   }
   return EvnPath;
}