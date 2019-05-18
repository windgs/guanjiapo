#pragma once
#include <QLabel>
#include "../Common/DefineCommon.h"
#include "../Common/CommonUI/CommonTitleBar.h"
class SystemoptTitleBar : public CBaseTitleBar
{
public:
  SystemoptTitleBar(QWidget  *parent = 0, Qt::WFlags flags = 0);
  virtual ~SystemoptTitleBar(void);
};
