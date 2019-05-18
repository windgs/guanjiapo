#pragma once
#include <QObject>
#include <QVector>
#include "..\Common\DefineCommon.h"
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>


//����ǰ����/��ֹ��
//���汻��ֹ��
//����һ���Ż�����ѡ��
class RecordLogItem : QObject
{
  Q_OBJECT
   RecordLogItem(void);
  ~RecordLogItem(void);
public:
  static RecordLogItem* Instance();
  //Ŀ¼���������
  void AddDisEnableArray(SafeRunInfo* pinfo) { m_DisEnableArray.append(pinfo);}
  SafeRunInfo* GetDisEnableArray(int i) { return m_DisEnableArray.at(i);}
  SafeRunInfo* GetDisEnableItem(const SafeRunInfo& info); 
  int GetCountDisEnableArray() { return m_DisEnableArray.count();}
  bool RemoveEnableItem(const SafeRunInfo* info);


  void AddEnableArray(SafeRunInfo* pinfo) { m_RunEnableArray.append(pinfo);}
  SafeRunInfo* GetEnableArray(int i) { return m_RunEnableArray.at(i);}
  SafeRunInfo* GetEnableItem(const SafeRunInfo& info); 
  int GetCountEnableArray() { return m_RunEnableArray.count();}

  //���汻��ֹ����
  bool SaveDisEnableLogItem();
  void LoadDisEnableLogItem();
  //����������Ŀ����
  void AddServiceItem(ServiceConfig* pinfo) { m_ServiceRunArray.append(pinfo);}
  void AddServicePushBack(ServiceConfig* pinfo) { m_ServiceRunArray.push_back(pinfo);}
  void AddServicePushFront(ServiceConfig* pinfo) {m_ServiceRunArray.push_front(pinfo);}
  int  GetServiceCount() { return m_ServiceRunArray.count();}
  ServiceConfig* GetServiceItembyIndex(quint32 index) {return m_ServiceRunArray.at(index);}
  ServiceConfig* GetServiceItembyName(QString ServiceName);
  void RemoveServiceItembyName(QString ServiceName);

  //���������ļ�
  bool LoadRunOpt(QString path);
  RunOptItem* GetRunOptData(int type,QString appname);
  QString GetFileName(QString appname);
  QString GetAdviceStr(int nAdvice);

  void ClearAll();
private:
  QVector<SafeRunInfo*>  m_RunEnableArray; //Ŀ¼��ע���������
  QVector<SafeRunInfo*>  m_DisEnableArray; //�����õ�Ŀ¼��ע���������
  QVector<RunOptItem*> m_runoptarray;  //�����������������
  QVector<ServiceConfig*>  m_ServiceRunArray;
};
