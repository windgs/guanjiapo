#pragma once
#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <Windows.h>
//�洢��Ҫ���˵��ļ���Ŀ¼
class CFilterItem :public QObject
{
  Q_OBJECT
private:
   CFilterItem(void);
  ~CFilterItem(void);
public:
  static CFilterItem* Instance();
  bool IsFilterFile(QString filename);
  bool IsFilterDir(QString dirname);
  QString GetFileExtend(QString filename);

  typedef bool (CFilterItem::*Filteroperator)(QString file);
  //���ҹ���
  bool FindFuncMap(QString strFuncName, QString strFileName);
public:
  bool CheckWindowsPath(QString strFilePath);
  //bool CheckDrivePath(QString strFilePath);
  bool CheckProgramPath(QString strFilePath);
  bool CheckDownloadProPath(QString strFilePath);
  bool CheckSpecFile(QString strFile);
private:
   QStringList m_Filterfiles; //ָ����Ҫ���˵��ļ�
   QStringList m_FilterDir;   //��Ҫ���˵�Ŀ¼
   QStringList     m_FilterfilesEx; //��Ҫ��������չ��
   QStringList m_DownFilterfiles; //����Ŀ¼�����ļ� 
   QMap<QString, Filteroperator> m_FilterFuncMap;       //����ӳ���
};
