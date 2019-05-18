#pragma once
#include "ui_LoadWaitDlg.h"
#include <QMovie>
#include <QLabel>
#include <QDialog>
class LoadWaitDialog :public QDialog
{
public:
	LoadWaitDialog(QWidget *parent = NULL, Qt::WindowFlags f = 0);
	~LoadWaitDialog(void);
private:
	Ui::Dialog_Run_Load_Wait  m_WaitDialog;
	QMovie       m_Movegif;
};
