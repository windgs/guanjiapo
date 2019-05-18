#pragma once
#include <QObject>
#include <QVector>
//启动项搜索
#include <Windows.h>
#include "..\Common\DefineCommon.h"
class RunItemFind :public QObject
{
  Q_OBJECT
private:
  RunItemFind(QObject* parent = NULL);
  ~RunItemFind(void);
private: 
  //反相解析lnk文件返回exe启动项和启动参数
  bool ReversePaserLnk(QString filepath ,QString& strpath ,QString& strparam);
  QIcon GetExeIcon(QString path);
  //用户设置启动项
  void  UserDirRunItem(QString path,int type);
  //系统通用启动项
  void  WindowsDirRunItem();
 
  void  EnumRegRunItem(HKEY hkey, QString Section, int type);
  DWORD SHEnumStringValue(HKEY hKey, DWORD iIndex, QString& strValue, QString& strData);
  bool  GetPEInfo(QString path,QString Section,QString& values);
  bool  GetFileInfo(unsigned char * pbyInfo,QString Section,QString& values);
  QString GetExePath(QString strData);
  void DirRunItemFind();
  //注册表启动项
  void  windowsRegRunItem();
  //获得启动服务项
  void EnumServiceRunItem(); 
  // 判断是否为启用状态
  inline bool IsTypeStartEnable(DWORD nType)
  {
	  return (nType==SERVICE_AUTO_START)||(nType==SERVICE_BOOT_START)||(nType==SERVICE_SYSTEM_START);
  }
  bool GetServiceDLL(QString lpServiceName, QString& strDLL);
  DWORD SHGetStringValue(HKEY hRoot,QString lpSubKey,QString lpValue,QString& strData);
public:
  static RunItemFind* Instance();
  //启动目录搜索

  void FindStartItem();
  SafeRunInfo* GetRunInfo(int index);
public:
 // QVector<RUN_DIR_INFO*>  m_dir_run_array;
 //QVector<RegRunInfo>    m_Reg_run_array;
};
