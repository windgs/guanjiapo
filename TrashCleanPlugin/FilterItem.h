#pragma once
#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <Windows.h>
//存储需要过滤的文件和目录
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
  //查找过滤
  bool FindFuncMap(QString strFuncName, QString strFileName);
public:
  bool CheckWindowsPath(QString strFilePath);
  //bool CheckDrivePath(QString strFilePath);
  bool CheckProgramPath(QString strFilePath);
  bool CheckDownloadProPath(QString strFilePath);
  bool CheckSpecFile(QString strFile);
private:
   QStringList m_Filterfiles; //指定需要过滤的文件
   QStringList m_FilterDir;   //需要过滤的目录
   QStringList     m_FilterfilesEx; //需要过来的扩展名
   QStringList m_DownFilterfiles; //下载目录过滤文件 
   QMap<QString, Filteroperator> m_FilterFuncMap;       //函数映射表
};
