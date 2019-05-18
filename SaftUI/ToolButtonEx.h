#pragma once
#include "ToolButton.h"
class ToolButtonEx :public QToolButton
{
public:
  ToolButtonEx(QWidget *parent);
  ~ToolButtonEx(void);
  virtual void paintEvent ( QPaintEvent * event );
private:
  QWidget * m_parent ;
};
