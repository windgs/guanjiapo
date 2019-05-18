#include "SpecialFolderPath.h"
#include <ShlObj.h>
#include <QFileInfo>
#include <QFileIconProvider>
CSpecialFolderPath::CSpecialFolderPath(void)
{
}

CSpecialFolderPath::~CSpecialFolderPath(void)
{
}

QString CSpecialFolderPath::GetDirStartUserPath()
{
  TCHAR szPath[MAX_PATH] = {0};
  ::SHGetSpecialFolderPath( NULL, szPath, CSIDL_STARTUP, FALSE );
  return QString::fromStdWString(szPath);
}

QString CSpecialFolderPath::GetDirStartCommonPath()
{ 
  TCHAR szPath[MAX_PATH] = {0};
  SHGetSpecialFolderPath( NULL, szPath, CSIDL_COMMON_STARTUP, FALSE );
  return QString::fromStdWString(szPath);
}

QIcon CSpecialFolderPath::GetExeIcon(QString path)
{ 

  QFileInfo fileInfo(path);
  QFileIconProvider seekIcon;
  QIcon icon = seekIcon.icon(fileInfo);
  if (icon.isNull())
  { 
	 return QIcon();
  }
  return icon;
}