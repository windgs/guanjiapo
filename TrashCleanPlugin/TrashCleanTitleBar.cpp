#include "TrashCleanTitleBar.h"

TrashCleanTitleBar::TrashCleanTitleBar(QWidget  *parent, Qt::WFlags flags)
:CBaseTitleBar(parent,flags)
{
  SetTitleString(tr("系统优化--垃圾清理"));
  SetBackGroup("../SaftUI/Resources/min_button/title.png");
}

TrashCleanTitleBar::~TrashCleanTitleBar(void)
{
}
