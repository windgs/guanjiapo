#pragma once
#include <QWidget>
#include <QList> 
#include <QString>
#include <QLabel>
#define WIDGET_CNT 9
#define TOOLWIDGET_H 88
#define VALUE_DIS 5
class ToolButton;
class ToolBar :public QWidget
{
   Q_OBJECT
public:
  ToolBar(QWidget *parent = 0, Qt::WFlags flags = 0);
  ~ToolBar(void);
public slots:
  void slot_set(void*);
protected: 
   virtual void resizeEvent ( QResizeEvent * event ) ;
private:
  void CreateWidget();
private:

  QList<ToolButton*> m_listMyBtnPoint;//自定义按钮
  QList<QString> m_listMyStr;//按钮对应的文本
  QLabel *m_pLabel;//label，显示logo
};
