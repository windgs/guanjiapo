#include "MainPlugin.h"

CMainPlugin::CMainPlugin(QObject* parent)
:QObject(parent),m_EraseDialog(this)
{
  
}

CMainPlugin::~CMainPlugin(void)
{}

void CMainPlugin::SlotCloseWindow()
{

}

QString CMainPlugin::GetGuid()
 {
    return tr("7F1F6AF1-82C3-4224-8A37-496A7FC53AEA");
 }

//�������
 QString CMainPlugin::GetName()
 {
    return tr("�ļ�����");
 }

//�������
 QString CMainPlugin::GetDescribe()
 {
   return tr("���Գ��׷����޷�ɾ�����ļ�");
 }

//���ͼƬ����
 QString CMainPlugin::GetPicture()
 {
   return tr("5.png");
 }

void  CMainPlugin::DoAction()
{
  /*if (!m_EraseDialog)
  {
	  m_EraseDialog = new MainEraseDialog(this);
	  m_EraseDialog->show();
  }
  else
  {
	  m_EraseDialog->raise();
  }*/
  //m_EraseDialog.
  m_EraseDialog.show();
 
}

Q_EXPORT_PLUGIN2(CMainPlugin, CMainPlugin);