#pragma once
#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QLabel>
class CBaseTitleBar: public QWidget
{
  Q_OBJECT
public:
  CBaseTitleBar(QWidget *parent = 0, Qt::WFlags flags = 0);
 
  virtual ~CBaseTitleBar(void);
  void SetTitleString(QString title) { m_title = title;}
  void SetBackGroup(QString group) { m_backgroup = group;}
protected: 
  //virtual void resizeEvent ( QResizeEvent * event ) ;
  //virtual void paintEvent ( QPaintEvent * event );
  virtual void resizeEvent ( QResizeEvent * event ) ;
protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
private:

  QPoint  m_ptPress;
  QPoint  m_ptMove;
  bool    m_bLeftButtonPress;
  QLabel* m_pLabel;
  QString m_title;
  QString m_backgroup;
};
