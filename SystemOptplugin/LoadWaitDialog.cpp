#include "LoadWaitDialog.h"

LoadWaitDialog::LoadWaitDialog(QWidget *parent, Qt::WindowFlags f)
:QDialog(parent,f)
{  
   setWindowFlags(Qt::WindowMinimizeButtonHint| Qt::SplashScreen); 
   m_WaitDialog.setupUi(this);
   m_Movegif.setFileName("../SaftUI/Resources/gif/running.gif");
   m_WaitDialog.label_Gif->setMovie(&m_Movegif);
   m_Movegif.start();
}

LoadWaitDialog::~LoadWaitDialog(void)
{
}
