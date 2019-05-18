#pragma once
#include <QLabel>
#include "../Common/DefineCommon.h"
#include "../Common/CommonUI/CommonTitleBar.h"

class TrashCleanTitleBar: public CBaseTitleBar
{
public:
  TrashCleanTitleBar(QWidget  *parent = 0, Qt::WFlags flags = 0);
  virtual ~TrashCleanTitleBar(void);
};
