#include "ContentWidget.h"
#include <QLabel>
ContentWidget::ContentWidget(QWidget *parent , Qt::WFlags flags )
:QWidget(parent,flags)
{
  //设置背景

  //创建布局
  m_pMainLayout = new QVBoxLayout(this);
  m_LeftWidget = new ConectLeft(this);
  m_rightWidget = new ConectRightWidth;
  mainSplitter = new QSplitter(Qt::Horizontal);
  mainSplitter->addWidget(m_LeftWidget);
  mainSplitter->addWidget(m_rightWidget);
  //mainSplitter->setStretchFactor(0, 0);
  //mainSplitter->setStretchFactor(1, 1);
  m_pMainLayout->addWidget(mainSplitter);
  m_pMainLayout->setSpacing(0);
  m_pMainLayout->setContentsMargins(0,0,0,0);
  setLayout(m_pMainLayout);
 // addWidget(mainSplitter);
}

ContentWidget::~ContentWidget(void)
{
}
