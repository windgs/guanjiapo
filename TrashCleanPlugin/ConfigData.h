#pragma once
#include <QVector>
#include "FindDirInfo.h"
class ConfigData :public QObject
{
   Q_OBJECT
private:
  ConfigData(void);
  ~ConfigData(void);
public:
  static ConfigData* Instance();
  int count() {return m_path_data.count();}
  bool IsEmpty() {return m_path_data.isEmpty();}
  const  FindDirInfo& GetData(int index) { return m_path_data.at(index);}
  void ConvertPath();
  FindDirInfo GetItem(QString FriendName);
  //设置某个节点的选择状态
  void setNodeSelect(QString text, bool select);
private:
  FindDirInfo* GetItemByName(QString text); 
private:

   QVector<FindDirInfo>  m_path_data;
};
