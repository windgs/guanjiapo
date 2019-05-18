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

  QList<ToolButton*> m_listMyBtnPoint;//�Զ��尴ť
  QList<QString> m_listMyStr;//��ť��Ӧ���ı�
  QLabel *m_pLabel;//label����ʾlogo
};
