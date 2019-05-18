#pragma once
#include <QStandardItem>
#include <QList>
class StandardItem :public QStandardItem
{
public:
  StandardItem(QString data, StandardItem* parent = NULL);
  StandardItem (QString data ,const QIcon & icon, StandardItem* parent);
  ~StandardItem(void);
  QList<StandardItem*> GetChilds() {return m_childs;}
  void AddChild(StandardItem* item) {m_childs.append(item);}
  StandardItem* GetParent() { return m_parent;}
  void SetParent(StandardItem* parent) {m_parent = parent;}
  StandardItem* GetChild(int index);
  int count() { return m_childs.count(); }
  QString GetData() { return m_data;}
  void SetData(QString data) {m_data = data;}
  
private:
  QString  m_data;
  StandardItem* m_parent;
  QList<StandardItem*> m_childs;
};
