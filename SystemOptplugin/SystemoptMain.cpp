#include "SystemoptMain.h"

SystemoptMain::SystemoptMain(QObject* parent)
:QObject(parent)
{
}

SystemoptMain::~SystemoptMain(void)
{
}

QString SystemoptMain::GetGuid()
{
  return tr("A7E2D166-AE9B-4775-B97C-AE5C0A1970BE");
}

//�������
QString SystemoptMain::GetName()
{
  return tr("ϵͳ�Ż�");
}

//�������
QString SystemoptMain::GetDescribe()
{
  return tr("�Ż�ϵͳ�������������ٶ�");
}

//���ͼƬ����
QString SystemoptMain::GetPicture()
{
  return tr("3.png");
}

void  SystemoptMain::DoAction()
{
  m_Systemoptdlg.show();
}

Q_EXPORT_PLUGIN2(SystemoptMain, SystemoptMain);