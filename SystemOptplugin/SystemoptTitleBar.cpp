#include "SystemoptTitleBar.h"

SystemoptTitleBar::SystemoptTitleBar(QWidget  *parent, Qt::WFlags flags)
:CBaseTitleBar(parent,flags)
{
  SetTitleString(tr("系统优化---"));
  SetBackGroup("../SaftUI/Resources/min_button/title.png");
}

SystemoptTitleBar::~SystemoptTitleBar(void)
{
}
