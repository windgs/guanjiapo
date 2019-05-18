#include "TrashCleanMain.h"

TrashCleanMain::TrashCleanMain(QObject* parent)
:QObject(parent)
{
}

TrashCleanMain::~TrashCleanMain(void)
{
}

QString TrashCleanMain::GetGuid()
{
  return tr("7B63E412-F758-4d4a-82B9-BAC8BC8CE286");
}

//插件名称
QString TrashCleanMain::GetName()
{
  return tr("垃圾清理");
}

//插件描述
QString TrashCleanMain::GetDescribe()
{
  return tr("清理磁盘和注册表垃圾");
}

//插件图片名称
QString TrashCleanMain::GetPicture()
{
  return tr("1.png");
}

void  TrashCleanMain::DoAction()
{
  m_TrashCleanDlg.show();
}

Q_EXPORT_PLUGIN2(TrashCleanMain, TrashCleanMain);