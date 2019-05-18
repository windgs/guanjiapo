#pragma once
#include <QToolButton>
#include <QString>
#include <QPushButton>
#include <QToolButton>
#define  TOOLWIDGET_W 68
#define  TOOLWIDGET_H 68
class ToolButton : public QToolButton
{  
  Q_OBJECT
public:
  ToolButton(const QString &strImage,const QString &strInfo,QWidget *parent);
  ToolButton(QWidget *parent);
  ~ToolButton(void);
  void SetPress(bool bEnable);
  void SetOver(bool bEnable);
  void InitToolButton(QString image,QString text);
public slots:
  void slot_pressed();
signals:
  void signal_parent(void*);
protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void	enterEvent ( QEvent * event );
  virtual void	leaveEvent ( QEvent * event );
private:
  void painterinfo(int nTopPartOpacity,int nBottomPartOpacity,QPainter *pPainter);
private:
  QString m_strImage;
  QString m_strInfo;
  bool m_bOver;
  bool m_bPress;
};
