#include <QIcon>
#include <QPixmap>
#include "TreeModle.h"
#include "StandardItem.h"

TreeModle::TreeModle(void)
{
  m_Root = NULL;
}

TreeModle::~TreeModle(void)
{
  delete m_Root;
}

void TreeModle::setRoot(StandardItem* Root)
{   
   if (NULL != m_Root)
   {
     delete m_Root;
   }
   m_Root = Root;
   reset();
}
void TreeModle::clear()
{
	delete m_Root; 
	m_Root = NULL;
}
QModelIndex TreeModle::index(int row, 
                  int column, 
                  const QModelIndex &parent) const
{
    if (!m_Root || row < 0 || column < 0) 
    {
       return QModelIndex();
    }
    StandardItem* parentitem = FromIndex(parent);
    if (!parentitem)
    {
      return QModelIndex();
    }
    StandardItem* child = parentitem->GetChild(row);
    if (!child)
    {
      return QModelIndex();
    }
    QModelIndex modelindex = createIndex (row, column, child);
    return modelindex;
}

QModelIndex TreeModle::parent(const QModelIndex &child) const
{  
  StandardItem *node = FromIndex(child); 
  if (!node) 
    return QModelIndex(); 
  StandardItem *parentNode = node->GetParent(); 
  if (!parentNode) 
    return QModelIndex(); 
  StandardItem *grandparentNode = parentNode->GetParent(); 
  if (!grandparentNode) 
    return QModelIndex(); 

  int row = grandparentNode->GetChilds().indexOf(parentNode); 
  return createIndex(row, 0, parentNode); 
 
}

bool TreeModle::insertRow ( int postion,  const QModelIndex & parent )
{
   StandardItem * parent_item = FromIndex (parent);
   beginInsertRows (parent, postion,1);
;  StandardItem * child = new StandardItem("",parent_item);
   parent_item->AddChild(child);
   endInsertRows ();
   return true;
}

int TreeModle::rowCount(const QModelIndex &parent) const
{ 
  
  StandardItem* parentitem = FromIndex(parent);
  if (!parentitem)
  {
    return 0;
  }
  return parentitem->count();
}

int TreeModle::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant TreeModle::data(const QModelIndex &index, int role) const
{  
	if (!index.isValid())
	{
		return QVariant(); 
	}
	if (role == Qt::DecorationRole)
	{   
		StandardItem* item = FromIndex(index);
		return item->icon ();
	}
	if (role != Qt::DisplayRole) 
		return QVariant();

	StandardItem* item = FromIndex(index);
	return item->GetData();
}

QVariant TreeModle::headerData(int section, 
                    Qt::Orientation orientation, 
                    int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole) 
  { 
    if (section == 0) 
    { 
      return tr(""); 
    } 
  } 
  return QVariant(); 

}

bool TreeModle::setData ( const QModelIndex & index, 
                             const QVariant & value, 
                             int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
      
      QModelIndex & parent_index = parent(index);
      StandardItem* parent_item = FromIndex(parent_index);
      StandardItem* child_item = parent_item->GetChild(index.row());
	  child_item->SetData(value.toString());
      emit dataChanged(index, index);
      return true;
    }

	if (index.isValid() && role == Qt::DecorationRole)
	{
		QModelIndex & parent_index = parent(index);
		StandardItem* parent_item = FromIndex(parent_index);
		StandardItem* child_item = parent_item->GetChild(index.row());
	    child_item->setIcon(value.value<QIcon>());
		emit dataChanged(index, index);	
	}
   
    return true;
}

StandardItem* TreeModle::FromIndex(const QModelIndex &index) const
{
  if (index.isValid()) 
  { 
    return static_cast<StandardItem*>(index.internalPointer()); 
  } 
  else 
  { 
    return m_Root; 
  } 
  return NULL;
}
