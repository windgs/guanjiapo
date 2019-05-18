#include "RunItemFind.h"
#include <QDir>
#include <ShlObj.h>
#include <QIcon>
#include <QFileIconProvider>
#include <QFileInfo>
#include <QPixmap>
#include <Shlwapi.h>
#include "RecordLogItem.h"
#include "CmdLineParser.h"
#pragma comment(lib,"ShFolder.Lib")
#pragma comment(lib,"Version.lib")
RunItemFind::RunItemFind(QObject* parent)
:QObject(parent)
{
}

RunItemFind::~RunItemFind(void)
{
}

RunItemFind* RunItemFind::Instance()
{
  static RunItemFind app;
  return & app;
}

SafeRunInfo* RunItemFind::GetRunInfo(int index)
{  
	SafeRunInfo* runinfo = RecordLogItem::Instance()->GetEnableArray(index);
	
   //SafeRunInfo* runinfo = new SafeRunInfo;
   //if (m_dir_run_array.count() > index)
   //{
   //  RUN_DIR_INFO* dirinfo = m_dir_run_array.at(index);
   //  runinfo->nRegType = dirinfo->nDirType;
   //  runinfo->strName = dirinfo->strName;
   //  runinfo->strPath = dirinfo->strPath;
   //  runinfo->strExePath = dirinfo->strogripath;
   //  runinfo->nType = RUN_TYPE_STARTUP;
   //  runinfo->nRegType = dirinfo->nDirType;
   //  runinfo->bEnable = true;
   //}
   //else
   //{
   //  //注册表启动项目
   //   ;
   //}

   return runinfo;
}
void RunItemFind::WindowsDirRunItem()
{
  //获得用户启动目录
  TCHAR	szPath[MAX_PATH] = {0};
  SHGetSpecialFolderPath( NULL, szPath, CSIDL_COMMON_STARTUP, FALSE );
  QString RunPath = QString::fromStdWString(szPath);
  RunPath = RunPath.trimmed();
  UserDirRunItem(RunPath,DIR_RUN_TYPE_WINDOW_COMM);

}

void  RunItemFind::windowsRegRunItem()
{
  EnumRegRunItem(HKEY_LOCAL_MACHINE, QString::fromStdWString(STR_RUN_REG_KEY), REG_RUN_TYPE_WINDOW_HKLM);
  EnumRegRunItem(HKEY_CURRENT_USER,QString::fromStdWString(STR_RUN_REG_KEY), REG_RUN_TYPE_WINDOW_HKCU);
}

// 获取注册表键里的string值
DWORD RunItemFind::SHEnumStringValue(HKEY hKey, DWORD iIndex, QString& strValue, QString& strData)
{
  DWORD	nRet	= ERROR_SUCCESS;
  DWORD	nValue	= MAX_PATH;
  DWORD	nData	= MAX_PATH;
  DWORD	nType	= REG_SZ;
  TCHAR*	btrValue= new TCHAR[nValue];
  TCHAR*	btrData = new TCHAR[nValue];

  do 
  {
    memset(btrValue,0,nValue*sizeof(TCHAR));
    memset(btrData,0,nData*sizeof(TCHAR));

    nRet = SHEnumValue(hKey,iIndex,btrValue,&nValue,&nType,btrData,&nData);

    if (nRet==ERROR_SUCCESS)
    {
      // 成功
      if (nType==REG_SZ||nType==REG_EXPAND_SZ)
      {
        strValue = QString::fromStdWString(btrValue);
        strData	 = QString::fromStdWString(btrData);
      }
      else
        nRet = ERROR_BAD_FORMAT;

      delete btrData;
      delete btrValue;
      break;			
    }
    else if (nRet==ERROR_MORE_DATA)
    {
      // 缓冲区大小不够
      nValue+=MAX_PATH;
      nData+=MAX_PATH;
      delete btrData;
      delete btrValue;
      btrValue = new TCHAR[nValue];
      btrData	 = new TCHAR[nData];
    }
    else
    {
      // 失败
      delete btrData;
      delete btrValue;
      break;
    }

  } while (TRUE);

  return nRet;
}

//static inline LPCTSTR skip_quotation(LPCTSTR lpStr)
//{
//  TCHAR c;
//  while ( (c = *lpStr) != 0 )
//  {
//    if ( c != _T('\"') )
//    {
//      return lpStr;
//    }
//
//    lpStr++;
//  }
//
//  return lpStr;
//}

//获得启动路径
QString RunItemFind::GetExePath(QString strData)
{ 
  /*
  QChar qchar = strData[0]; 
  if (qchar == '%')
  {
	WCHAR szPath[MAX_PATH] = {0};
	QString strResult;
	if (::SHGetSpecialFolderPath( NULL, szPath, CSIDL_PROGRAM_FILES, FALSE) )
		strResult = QString::fromStdWString(szPath);

	int pos = strData.lastIndexOf('%');
	strResult += strData.mid(pos + 1,strData.length() - pos);
	return strResult;
  }
  CCmdLineParser2  cmdParser(strData.toStdWString().c_str());
  */
 CCmdLineParser cmdLine(strData.toStdWString().c_str());
 if (cmdLine.GetCmd()==NULL)
     return "";
 return QString::fromStdWString(cmdLine.GetCmd());
}

void  RunItemFind::EnumRegRunItem(HKEY hkey, QString Section, int type)
{
  HKEY	subhKey = NULL;
  //QVector<RegRunInfo> Reg_run_array;
  if (ERROR_SUCCESS == ::RegOpenKeyEx(hkey,Section.toStdWString().c_str(),0,KEY_READ,&subhKey))
  {
    DWORD	iIndex = 0;
    QString	strData;
    QString	strValue;
    while (SHEnumStringValue(subhKey,iIndex++,strValue,strData)==ERROR_SUCCESS)
    {
      if (strData.isEmpty())//如果路径为空，会被CommandLineToArgvW解析到当前路径,所以就跳过
        continue;
      
     
	  //RegRunInfo	runinfo;
      //runinfo.strName	= strValue;
      //runinfo.strPath	= strData;
      //runinfo.nRegType= type;
      //runinfo.bDisabledBy3xx = false;
     
      //////////////////////////////////////////////////////////////////////////
	  SafeRunInfo* safeinfo = new SafeRunInfo;
	  safeinfo->strName = strValue;
      safeinfo->nType = RUN_TYPE_STARTUP;
	  safeinfo->nRegType = REG_RUN_TYPE_WINDOW_HKLM;
	  safeinfo->strPath = GetExePath(strData);
	  GetPEInfo(safeinfo->strPath, "FileDescription",safeinfo->strDesc);
	  safeinfo->hIcon = GetExeIcon(safeinfo->strPath);
	  safeinfo->bEnable = true;
	  RecordLogItem::Instance()->AddEnableArray(safeinfo);
	  //////////////////////////////////////////////////////////////////////////
      //runinfo.strPath = GetExePath(strData);
      //GetPEInfo(runinfo.strPath,"FileDescription",runinfo.strDesc);
      //runinfo.hIcon = GetExeIcon(runinfo.strPath);
      //m_Reg_run_array.append(runinfo);
      strData = "";
      strValue = "";

    }
  }

}

bool RunItemFind::ReversePaserLnk(QString filepath ,QString& strpath ,QString& sparam)
{
  IShellLink*	pShellLink;
  // 用IShellLink接口来解析lnk文件
  //QT插件已经调用该函数
  bool bReturn = (::CoInitialize(NULL) == S_OK);
  bReturn = true;
  if(bReturn)
  {
    bReturn = ::CoCreateInstance (CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
      IID_IShellLink, (void **)&pShellLink) >= 0;

    if(bReturn)
    {
      IPersistFile *ppf;
      bReturn = pShellLink->QueryInterface(IID_IPersistFile, (void **)&ppf) >= 0;
      bReturn = (ppf->Load(filepath.toStdWString().c_str(), TRUE) == S_OK);
      
      if(bReturn)
      {
        TCHAR		strIePath[MAX_PATH];
        TCHAR		strParam[MAX_PATH];
        TCHAR   strDescription[MAX_PATH];
        TCHAR   strIconLocation[MAX_PATH];
        QString sIconLocation;
        int piIcon;
        pShellLink->GetDescription(strDescription,MAX_PATH);
        pShellLink->GetPath( strIePath, MAX_PATH, NULL, SLGP_UNCPRIORITY );
        pShellLink->GetIconLocation(strIconLocation,MAX_PATH,&piIcon);
        pShellLink->GetArguments(strParam,MAX_PATH);

        strpath = QString::fromStdWString(strIePath);
        sparam = QString::fromStdWString(strParam);
        ppf->Release();
       
      }
      pShellLink->Release();
    }
    ::CoUninitialize();
  }

  return true;
}

void RunItemFind::UserDirRunItem(QString path,int type)
{
 
  //获得lnk文件
  QDir Dir(path);
  QStringList extend ;
  extend << "*.lnk";
  //QVector<RUN_DIR_INFO> dir_run_array;
  QStringList listfiles = Dir.entryList (extend,QDir::Files|QDir::NoDotAndDotDot);
  if (listfiles.isEmpty())
  {
     return;
  }
  QString strpath;
  QString strparam;
  int count = listfiles.count();
  for (int i = 0; i < count; ++i)
  {
    QString allpath = path + "\\" +  listfiles.at(i);
    if (!ReversePaserLnk(allpath,strpath,strparam))
    {
      return; 
    }
    QDir dirrunitem(allpath);
    QString name = dirrunitem.dirName();
    name = name.mid(0,name.length() - 4);
   /* RUN_DIR_INFO* dirinfo = new RUN_DIR_INFO;
    dirinfo->strName = name;
    dirinfo->strPath = strpath;
    dirinfo->strParam = strparam;
    dirinfo->nDirType = type;
    dirinfo->strogripath = allpath;
    dirinfo->hIcon = GetExeIcon(strpath);
    GetPEInfo(strpath,"FileDescription",dirinfo->strDesc);
    m_dir_run_array.append(dirinfo);*/

	//////////////////////////////////////////////////////////////////////////
	SafeRunInfo* safeinfo = new SafeRunInfo;
	safeinfo->strName = name;
	safeinfo->nType = RUN_TYPE_STARTUP;
	safeinfo->nRegType = DIR_RUN_TYPE_WINDOW_USER;
	safeinfo->strPath = strpath; //exe路径
	safeinfo->strExePath = allpath;
	GetPEInfo(safeinfo->strPath, "FileDescription",safeinfo->strDesc);
	safeinfo->hIcon = GetExeIcon(safeinfo->strPath);
	safeinfo->bEnable = true;
	RecordLogItem::Instance()->AddEnableArray(safeinfo);
	//////////////////////////////////////////////////////////////////////////
    
  }
  
}

QIcon RunItemFind::GetExeIcon(QString path)
{ 
  //SHFILEINFO		hFileInfo = {0};
  //path = QString::fromStdWString(L"C:\\Program Files\\Renesas Electronics\\USB 3.0 Host Controller Driver\\Application\\nusb3mon.exe");
  //::SHGetFileInfo(path.toStdWString().c_str(),FILE_ATTRIBUTE_NORMAL,&hFileInfo,sizeof(SHFILEINFO),SHGFI_ICON);
  QFileInfo fileInfo(path);
  QFileIconProvider seekIcon;
  QIcon icon = seekIcon.icon(fileInfo);
  //QIcon icon(QPixmap::fromWinHICON (hFileInfo.hIcon));
  if (icon.isNull())
  { 
    return QIcon();
  }
  return icon;
}

void RunItemFind::DirRunItemFind()
{  
  //获得用户启动目录
  TCHAR	szPath[MAX_PATH] = {0};
  SHGetSpecialFolderPath( NULL, szPath, CSIDL_STARTUP, FALSE );
  QString RunPath = QString::fromStdWString(szPath);
  RunPath = RunPath.trimmed();
  UserDirRunItem(RunPath,DIR_RUN_TYPE_WINDOW_USER);
  WindowsDirRunItem();

}

void RunItemFind::FindStartItem()
{
  //m_dir_run_array.clear();
  //m_Reg_run_array.clear();
	RecordLogItem::Instance()->ClearAll();
  DirRunItemFind();
  windowsRegRunItem();
  EnumServiceRunItem();
}

bool  RunItemFind::GetPEInfo(QString path,QString Section,QString& values)
{
   DWORD dwordsize;
   BYTE* pbyInfo  = NULL;
   
   //得到文件信息块的大小
   DWORD dwFileInfoSize = ::GetFileVersionInfoSize(path.toStdWString().c_str(), &dwordsize);
   if (!dwFileInfoSize)
   {
     return false;
   }

   pbyInfo = new BYTE[dwFileInfoSize];
   if (!pbyInfo)
     return false;

   //获取
   bool bRet = ::GetFileVersionInfo(path.toStdWString().c_str(), dwordsize, dwFileInfoSize, pbyInfo);
   if (!bRet)
     return false;

   GetFileInfo(pbyInfo,Section,values);
   return true;
}

bool RunItemFind::GetFileInfo(BYTE* pbyInfo,QString Section,QString& values)
{  
  BOOL bRet = FALSE;
  UINT uCount = 0;
  UINT uRetSize = MAX_PATH - 1;
  LPWSTR lpszValue = NULL;

  struct LANGANDCODEPAGE
  {
    WORD wLanguage;
    WORD wCodePage;
  } *lpTranslate;

  bRet = ::VerQueryValue(pbyInfo, L"\\VarFileInfo\\Translation", (LPVOID*)&lpTranslate, &uCount);
  if (!bRet || uCount == 0)
    return false;
   
  char buffer[512] = {0};
  sprintf_s(buffer,sizeof(buffer),"%04x%04x\\",lpTranslate->wLanguage,lpTranslate->wCodePage);
  QString strSubBlock = "\\StringFileInfo\\" + QString(buffer) + Section;

  bRet = ::VerQueryValue(
    pbyInfo, strSubBlock.toStdWString().c_str(), 
    (LPVOID *)&lpszValue, &uRetSize
    );
  if (!bRet)
    return false;

  values = QString::fromStdWString(lpszValue);
  return true;
}

void RunItemFind::EnumServiceRunItem()
{
	DWORD ServicesCount = 0;    
	DWORD size = 0;    
	SC_HANDLE hHandle = OpenSCManager(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);    

	if (hHandle == NULL)
		return;

	// 获取服务信息需要的缓冲区大小
	if(!EnumServicesStatus(hHandle, SERVICE_WIN32, SERVICE_STATE_ALL,     
		NULL, 0, &size, &ServicesCount, NULL))      
	{
     
		if (GetLastError() == ERROR_MORE_DATA)
		{
		   LPENUM_SERVICE_STATUS lpinfo = new ENUM_SERVICE_STATUS[size];
		   // 开辟内存，获取服务信息
		   if (EnumServicesStatus(hHandle, SERVICE_WIN32, SERVICE_STATE_ALL, 
			   (LPENUM_SERVICE_STATUS)lpinfo,    
			   size, &size, 
			   &ServicesCount, NULL)) 
		   {
             
              for (int i = 0; i < ServicesCount;++i)
              {
				  SC_HANDLE hService = ::OpenService(hHandle,lpinfo[i].lpServiceName,SERVICE_QUERY_CONFIG|SERVICE_QUERY_STATUS);
				  if (hService!=NULL)
				  {
					DWORD nNeedSize = 0;
					// 获取服务设置需要的缓冲区大小
					::QueryServiceConfig(hService,NULL,0,&nNeedSize);
					if (nNeedSize>0&&GetLastError()==ERROR_INSUFFICIENT_BUFFER)
					{
						ServiceConfig* svcfg = new ServiceConfig;
						LPQUERY_SERVICE_CONFIG	qscfg = (LPQUERY_SERVICE_CONFIG)new char[nNeedSize];
						// 开辟内存，获取特定服务信息
						if (::QueryServiceConfig(hService,qscfg,nNeedSize,&nNeedSize) )
						{
							svcfg->lpqscfg = qscfg;
							svcfg->strName = QString::fromStdWString(lpinfo[i].lpServiceName);
							GetServiceDLL(svcfg->strName,svcfg->strServDLL);
							if (TRUE)
							{
								DWORD	nSize = 0;
								::QueryServiceConfig2(hService,SERVICE_CONFIG_DESCRIPTION,NULL,0,&nSize);
								if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER)
								{
									nSize++;
									LPSERVICE_DESCRIPTION buffer = (LPSERVICE_DESCRIPTION)new BYTE[nSize];
									memset(buffer,0,nSize);
									if (::QueryServiceConfig2(hService,SERVICE_CONFIG_DESCRIPTION,(LPBYTE)buffer,nSize,&nSize))
									{   
										if (buffer->lpDescription)
										{
										   svcfg->strDesc = QString::fromStdWString(buffer->lpDescription);
										}
										
									}
									delete buffer;
								}

							}
							//解析服务exe路径
							QString binarypath = GetExePath(QString::fromStdWString(svcfg->lpqscfg->lpBinaryPathName));
						    
							svcfg->hIcon = GetExeIcon(binarypath);
							if (svcfg->hIcon.isNull())
							{
                               binarypath = "";
							}
							
							if (true == IsTypeStartEnable(svcfg->lpqscfg->dwStartType))
							{
                               svcfg->Enable = true; //标志服务项为启动状态
							   RecordLogItem::Instance()->AddServicePushFront(svcfg);
							}
							else
							{
                               RecordLogItem::Instance()->AddServicePushBack(svcfg);
							}
							//RecordLogItem::Instance()->AddServiceItem(svcfg);
						}

					}
					
                }
				  ::CloseServiceHandle(hService);
              }
		   }
		 delete []lpinfo;
		}
		
	}
	CloseServiceHandle(hHandle); 
}

// 从注册表获取服务对应dll
bool RunItemFind::GetServiceDLL(QString lpServiceName, QString& strDLL)
{
	QString	strFormat = QString::fromStdWString(KEY_SYS_SERVICE);
    strFormat = strFormat.arg(lpServiceName);
	return (SHGetStringValue(HKEY_LOCAL_MACHINE,strFormat,QString::fromStdWString(L"ServiceDll"),strDLL) ==ERROR_SUCCESS);
}

// 获取注册表键中的string值
DWORD RunItemFind::SHGetStringValue(HKEY hRoot,QString lpSubKey,QString lpValue,QString& strData)
{
	DWORD	nRet	= ERROR_SUCCESS;
	DWORD	nSize	= MAX_PATH;
	TCHAR*	buffer = new TCHAR[nSize];

	do
	{
		DWORD	nType = REG_SZ;
		memset(buffer,0,sizeof(MAX_PATH)*sizeof(TCHAR));
		nRet = SHGetValue(hRoot,lpSubKey.toStdWString().c_str(),lpValue.toStdWString().c_str(),&nType,buffer,&nSize);

		if (nRet==ERROR_SUCCESS)
		{
			if(nType==REG_SZ||nType==REG_EXPAND_SZ)
				strData = QString::fromStdWString(buffer);
			else
				nRet = ERROR_BAD_FORMAT;
			delete buffer;
			break;
		}
		else if (nRet==ERROR_MORE_DATA)
		{
			delete buffer;		
			nSize+=MAX_PATH;
			buffer = new TCHAR[nSize];
		}
		else
		{
			delete buffer;		
			break;
		}
	}while (TRUE);

	return nRet;
}