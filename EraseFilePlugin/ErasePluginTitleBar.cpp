#include "ErasePluginTitleBar.h"

ErasePluginTitleBar::ErasePluginTitleBar(QWidget *parent, Qt::WFlags flags)
:CBaseTitleBar(parent,flags)
{ 
  SetTitleString(tr("�ļ�����"));
  SetBackGroup("../SaftUI/Resources/min_button/title.png");
}

ErasePluginTitleBar::~ErasePluginTitleBar(void)
{
}

