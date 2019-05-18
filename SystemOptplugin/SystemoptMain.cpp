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

//插件名称
QString SystemoptMain::GetName()
{
  return tr("系统优化");
}

//插件描述
QString SystemoptMain::GetDescribe()
{
  return tr("优化系统设置提升运行速度");
}

//插件图片名称
QString SystemoptMain::GetPicture()
{
  return tr("3.png");
}

void  SystemoptMain::DoAction()
{
  m_Systemoptdlg.show();
}

Q_EXPORT_PLUGIN2(SystemoptMain, SystemoptMain);