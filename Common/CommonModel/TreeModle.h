#pragma once
#include <QAbstractItemModel>
#include <QStandardItem>
class  StandardItem;

class TreeModle : public QAbstractItemModel 
{
public:
  TreeModle(void);
  ~TreeModle(void);

public:
  void setRoot(StandardItem* Root); 
  void clear(); 
  StandardItem* getRoot() { return m_Root; }
  virtual QModelIndex index(int row, int column, 
    const QModelIndex &parent) const; 
  virtual QModelIndex parent(const QModelIndex &child) const; 

  virtual int rowCount(const QModelIndex &parent) const; 
  virtual int columnCount(const QModelIndex &parent) const; 
  virtual QVariant data(const QModelIndex &index, int role) const; 
  virtual QVariant headerData(int section, Qt::Orientation orientation, 
    int role) const;
  virtual bool	setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
  bool insertRow ( int row, const QModelIndex & parent = QModelIndex() );
private:
  StandardItem* FromIndex(const QModelIndex &index) const; 
private:
  StandardItem* m_Root;
};
