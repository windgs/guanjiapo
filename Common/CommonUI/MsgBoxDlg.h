#pragma once
#include <QDialog>
#include "ui_MsgBox.h"
#include "CommonTitleBar.h"
class MsgBoxDlg :public QDialog
{  
   Q_OBJECT
public:
  MsgBoxDlg(QString title_text, QString msg,QWidget* From = NULL,QWidget *parent  = NULL);
  ~MsgBoxDlg(void);

protected:
  void closeEvent(QCloseEvent *event);

public slots:
  void OnOk();
  void OnCancel();
 
protected:
  void moveEvent ( QMoveEvent * event );

private:
  void InitTitleBar(QString title_text);
private:
 CBaseTitleBar*  m_TitleBar; 
 Ui::MsgBoxDialog m_msgDiglog;
};
