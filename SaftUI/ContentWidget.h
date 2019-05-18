#pragma once
#include <QWidget>
#include <QSplitter>
#include "ConectLeft.h"
#include "ConectRightWidth.h"
#include <QVBoxLayout>
class QLabel;
class ContentWidget : public QWidget
{
  Q_OBJECT
public:
  ContentWidget(QWidget *parent = 0, Qt::WFlags flags = 0);
  ~ContentWidget(void);
private:
  QLabel* m_pLabel;
  //QSplitter*  m_rightSplitter;
  QSplitter* mainSplitter;
  ConectLeft*  m_LeftWidget;
  ConectRightWidth* m_rightWidget;
  QVBoxLayout* m_pMainLayout;
};
