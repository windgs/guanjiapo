#pragma once
#include <QObject>
#include <QVector>
#include "..\Common\DefineCommon.h"
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>


//处理当前启动/禁止项
//保存被禁止项
//加载一键优化县里选项
class RecordLogItem : QObject
{
  Q_OBJECT
   RecordLogItem(void);
  ~RecordLogItem(void);
public:
  static RecordLogItem* Instance();
  //目录启动项操作
  void AddDisEnableArray(SafeRunInfo* pinfo) { m_DisEnableArray.append(pinfo);}
  SafeRunInfo* GetDisEnableArray(int i) { return m_DisEnableArray.at(i);}
  SafeRunInfo* GetDisEnableItem(const SafeRunInfo& info); 
  int GetCountDisEnableArray() { return m_DisEnableArray.count();}
  bool RemoveEnableItem(const SafeRunInfo* info);


  void AddEnableArray(SafeRunInfo* pinfo) { m_RunEnableArray.append(pinfo);}
  SafeRunInfo* GetEnableArray(int i) { return m_RunEnableArray.at(i);}
  SafeRunInfo* GetEnableItem(const SafeRunInfo& info); 
  int GetCountEnableArray() { return m_RunEnableArray.count();}

  //保存被禁止的项
  bool SaveDisEnableLogItem();
  void LoadDisEnableLogItem();
  //服务启动项目操作
  void AddServiceItem(ServiceConfig* pinfo) { m_ServiceRunArray.append(pinfo);}
  void AddServicePushBack(ServiceConfig* pinfo) { m_ServiceRunArray.push_back(pinfo);}
  void AddServicePushFront(ServiceConfig* pinfo) {m_ServiceRunArray.push_front(pinfo);}
  int  GetServiceCount() { return m_ServiceRunArray.count();}
  ServiceConfig* GetServiceItembyIndex(quint32 index) {return m_ServiceRunArray.at(index);}
  ServiceConfig* GetServiceItembyName(QString ServiceName);
  void RemoveServiceItembyName(QString ServiceName);

  //加载配置文件
  bool LoadRunOpt(QString path);
  RunOptItem* GetRunOptData(int type,QString appname);
  QString GetFileName(QString appname);
  QString GetAdviceStr(int nAdvice);

  void ClearAll();
private:
  QVector<SafeRunInfo*>  m_RunEnableArray; //目录和注册表启动项
  QVector<SafeRunInfo*>  m_DisEnableArray; //被禁用的目录和注册表启动项
  QVector<RunOptItem*> m_runoptarray;  //保存各个启动项数据
  QVector<ServiceConfig*>  m_ServiceRunArray;
};
