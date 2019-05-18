#include "SkinListWidth.h"
#include <QDebug>
#include <QMouseEvent>

#include "ListWidthItem.h"
#include "saftui.h"
SkinListWidth::SkinListWidth(QWidget *parent)
:QListWidget(parent)
{
	bool success = connect(this, SIGNAL(itemPressed(QListWidgetItem*)),this, SLOT(OnClickItem(QListWidgetItem*)));
}

SkinListWidth::~SkinListWidth(void)
{
}


void SkinListWidth::OnClickItem(QListWidgetItem* item)
{ 
  ListWidthItem* listitem = static_cast<ListWidthItem*>(item);
  m_MainFrom->ChangeBackSkin(listitem->GetPicture());
}

void  SkinListWidth::enterEvent ( QEvent * event )
{
 
}
void  SkinListWidth::leaveEvent ( QEvent * event )
{
    
}

void SkinListWidth::moveEvent ( QMoveEvent * event )
{}

void SkinListWidth::mouseMoveEvent(QMouseEvent *event)
{
  
  QPoint point = event->pos();
  ListWidthItem* item = (ListWidthItem*)itemAt(point);
  if (item)
  {  
     item->painter();
  }
  event->ignore();
}