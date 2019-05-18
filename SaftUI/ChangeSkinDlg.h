#pragma once
#include "ui_ChangeSkin.h"
#include <QDialog>
class SaftUI;
class ChangeSkinDlg :public QDialog
{
  Q_OBJECT
public:
	ChangeSkinDlg(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~ChangeSkinDlg(void);
  void SetFrom(SaftUI* From) { m_Parent = From;}
  void CreatePictureListItem();
public slots:
    void OnCloseForm();
    void OnMinimized();
    
protected:
	void closeEvent(QCloseEvent *event);
private:
  void CreateTitle();
private:
	Ui::Dialog  m_Dlg;
	SaftUI* m_Parent;
};
