#include "StandardItem.h"

StandardItem::StandardItem(QString data, StandardItem* parent)
{
   m_data = data;
   m_parent = parent;
}

StandardItem::StandardItem (QString data ,const QIcon & icon, StandardItem* parent)
:QStandardItem(icon, data)
{
	m_data = data;
	m_parent = parent;
}

StandardItem::~StandardItem(void)
{   
	int count = m_childs.count();
	for (int i = 0; i < count; ++i)
	{
		delete m_childs.at(i);
	}
    m_childs.clear();
}



StandardItem* StandardItem::GetChild(int index)
{
   if (index >= m_childs.count())
   {
     return NULL;
   }
   return m_childs.at(index);
}