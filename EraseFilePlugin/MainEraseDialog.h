#pragma once

#include "ui_MainForm.h"
#include <QDialog>
#include <QStandardItemModel>
#include "EraseFile.h"
class CMainPlugin;
//class TitleBar;
class MainEraseDialog : public QDialog
{
	Q_OBJECT
public:
  MainEraseDialog(CMainPlugin*  plugin,QDialog* parent = NULL);
  ~MainEraseDialog(void);
  virtual void paintEvent ( QPaintEvent * event );
  //void SetPluginMgr(CMainPlugin*  parent_plugin) {m_parent_plugin = parent_plugin;}
  bool AdjustPurview();
protected:
	void closeEvent(QCloseEvent *event);
  void Connect();
  void OnDeleteItemAll();
public slots:
    void AddFile();
    void OnAddDir();
    void OnEraseStart();
    void OnDeleteItem();
    void OnFreeSpace();
    void OnCloseForm();
    void OnMinimized();
    void OnMaximized();
    void OnProgressValue(int iValue);
Q_SIGNALS:
    void SignalClose();
private:
  Ui::Dialog  m_MainDiglog;
  QStandardItemModel m_tableModel;
  CMainPlugin*   m_parent_plugin;
  //TitleBar*   m_TtitleBar;   
  CEraseFile  m_EraseFile;
};
