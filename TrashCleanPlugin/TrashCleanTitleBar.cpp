#include "TrashCleanTitleBar.h"

TrashCleanTitleBar::TrashCleanTitleBar(QWidget  *parent, Qt::WFlags flags)
:CBaseTitleBar(parent,flags)
{
  SetTitleString(tr("ϵͳ�Ż�--��������"));
  SetBackGroup("../SaftUI/Resources/min_button/title.png");
}

TrashCleanTitleBar::~TrashCleanTitleBar(void)
{
}
