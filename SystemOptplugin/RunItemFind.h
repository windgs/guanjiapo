#pragma once
#include <QObject>
#include <QVector>
//����������
#include <Windows.h>
#include "..\Common\DefineCommon.h"
class RunItemFind :public QObject
{
  Q_OBJECT
private:
  RunItemFind(QObject* parent = NULL);
  ~RunItemFind(void);
private: 
  //�������lnk�ļ�����exe���������������
  bool ReversePaserLnk(QString filepath ,QString& strpath ,QString& strparam);
  QIcon GetExeIcon(QString path);
  //�û�����������
  void  UserDirRunItem(QString path,int type);
  //ϵͳͨ��������
  void  WindowsDirRunItem();
 
  void  EnumRegRunItem(HKEY hkey, QString Section, int type);
  DWORD SHEnumStringValue(HKEY hKey, DWORD iIndex, QString& strValue, QString& strData);
  bool  GetPEInfo(QString path,QString Section,QString& values);
  bool  GetFileInfo(unsigned char * pbyInfo,QString Section,QString& values);
  QString GetExePath(QString strData);
  void DirRunItemFind();
  //ע���������
  void  windowsRegRunItem();
  //�������������
  void EnumServiceRunItem(); 
  // �ж��Ƿ�Ϊ����״̬
  inline bool IsTypeStartEnable(DWORD nType)
  {
	  return (nType==SERVICE_AUTO_START)||(nType==SERVICE_BOOT_START)||(nType==SERVICE_SYSTEM_START);
  }
  bool GetServiceDLL(QString lpServiceName, QString& strDLL);
  DWORD SHGetStringValue(HKEY hRoot,QString lpSubKey,QString lpValue,QString& strData);
public:
  static RunItemFind* Instance();
  //����Ŀ¼����

  void FindStartItem();
  SafeRunInfo* GetRunInfo(int index);
public:
 // QVector<RUN_DIR_INFO*>  m_dir_run_array;
 //QVector<RegRunInfo>    m_Reg_run_array;
};
