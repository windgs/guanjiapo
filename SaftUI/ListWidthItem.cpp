#include "ListWidthItem.h"
#include <QPen>
#include <QLinearGradient>
#include "saftui.h"
ListWidthItem::ListWidthItem(const QIcon &icon, const QString &text,
							 QListWidget *view, int type)
							 :QListWidgetItem(icon,text,view,type)
{
  m_MainFrom = NULL;
}

ListWidthItem::~ListWidthItem(void)
{
}


void ListWidthItem::SetOver(bool bEnable)
{
	if(bEnable!=m_bOver)
	{
		//����m_bOver��־λ
		m_bOver = bEnable;
		//����
		listWidget()->update();
	}
}

void ListWidthItem::SetPress(bool bEnable)
{
	if(bEnable!=m_bPress)
	{
		//����m_bOver��־λ
		m_bPress = bEnable;
		//����
		listWidget()->update();
	}
}

void ListWidthItem::painter()
{  
   m_MainFrom->ReViewChangeBackSkin(m_sPicture);
}

