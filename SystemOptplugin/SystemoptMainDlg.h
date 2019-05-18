#pragma once
#include "ui_SystemoptUI.h"
#include <QDialog>
#include <QButtonGroup>
#include <QShowEvent>
#include "..\Common\DefineCommon.h"
#include "ThreadStub.h"
#include <QColor>
#include <QMovie>
#define RUNOPTNAME "runopt.xml"
#define PAGE0 0
#define PAGE1 1
#define PAGE2 2
#define PAGE3 3
#define PAGE4 4
class SystemoptMainDlg :public QDialog
{
  Q_OBJECT
public:
  SystemoptMainDlg(QWidget *parent = NULL, Qt::WindowFlags f = 0);
  ~SystemoptMainDlg(void);
private:
  void CreateTableWidget();
  void CreateServiceWidget();
  void AddRunTableWidgetItem(SafeRunInfo* runinfo);
  //加载被禁止的项到UI
  void CreateDisenableItem();
  void SetSheetStyle();
  void SetTextColor(int pageindex,int index,QColor color);
  void SetTextColorColumn(int pageindex,int index,int column,QColor color);
  void CreateMovieWidget();
  void StartMovieWidget();
  void StopMovice();
  QTableWidget* GetCurrentPagTable(int index);
  QString ConverServiceType(int servicetype);
public slots:
  void OnbuttonClicked ( QAbstractButton * button );

public slots:
  void OnReadFindItem();
  void OnCloseForm();
  void OnMinimized();
protected:
  virtual void showEvent (QShowEvent * event);
private:
  Ui::Dialog  m_Dialog;
  QButtonGroup*  m_buttongroup;
  //QButtonGroup*  m_Servicebuttongroup;
//public:
  //QVector<RUN_DIR_INFO>  m_dir_run_array; //目录启动项目信息
  //QVector<RegRunInfo>    m_Reg_run_array; //注册表启动项信息
private: 
  ThreadStub   m_threadstub;
  QMovie       m_Movegif;
  bool         m_init;
};
