#include "ConectLeft.h"

ConectLeft::ConectLeft(QWidget *parent, Qt::WFlags flags)
:QWidget(parent,flags)
{
  setAutoFillBackground(true);
  QPalette palette_back;
  palette_back.setBrush(QPalette::Background, QBrush(QPixmap("./Resources/conectright.png")));
  setPalette(palette_back);
}

ConectLeft::~ConectLeft(void)
{
}
