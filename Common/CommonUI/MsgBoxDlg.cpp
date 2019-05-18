#include "MsgBoxDlg.h"

MsgBoxDlg::MsgBoxDlg(QString title_text, QString msg ,QWidget* From, QWidget* parent)
:QDialog(parent)

{  
   InitTitleBar(title_text);
   m_msgDiglog.setupUi(this);
   m_msgDiglog.label_Msg->setText(msg);
   setWindowFlags(Qt::FramelessWindowHint);

   connect(m_msgDiglog.pushButton_OK, SIGNAL(clicked()), this, SLOT(OnOk()));
   connect(m_msgDiglog.pushButton_Cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
   connect(m_msgDiglog.toolButton_Close, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

void  MsgBoxDlg::closeEvent(QCloseEvent *event)
{
   event->accept();
}

void MsgBoxDlg::OnOk()
{
  //emit accepted () ;
  //close();
  done(QDialog::Accepted);
}

void MsgBoxDlg::OnCancel()
{
  close();
}

void MsgBoxDlg::InitTitleBar(QString title_text)
{
  m_TitleBar = new CBaseTitleBar(this);
  m_TitleBar->setObjectName(QString::fromUtf8("MsgBoxwidget"));
  m_TitleBar->setGeometry(QRect(0, 0, 751, 21));
  m_TitleBar->setAutoFillBackground(true);
  m_TitleBar->setStyleSheet(QString::fromUtf8(""));
  m_TitleBar->SetTitleString(title_text);
  m_TitleBar->SetBackGroup("./Resources/min_button/title.png");
}

MsgBoxDlg::~MsgBoxDlg(void)
{
}

void MsgBoxDlg::moveEvent ( QMoveEvent * event )
{
   m_TitleBar->move(5 ,0);
}
