#pragma once
#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
//#define VALUE_DIS 5
#include "../Common/DefineCommon.h"
#include "../Common/CommonUI/CommonTitleBar.h"
class QLabel;
class TitleBar : public CBaseTitleBar
{
  //Q_OBJECT
public:
  TitleBar(QWidget  *parent = 0, Qt::WFlags flags = 0);
  virtual ~TitleBar(void);
protected: 
  virtual void resizeEvent ( QResizeEvent * event ) ;
protected:
  /*void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);*/
private:

 /* QPoint  m_ptPress;
  QPoint  m_ptMove;
  bool    m_bLeftButtonPress;*/
  QLabel* m_pLabel;
};
