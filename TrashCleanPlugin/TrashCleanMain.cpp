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

//�������
QString TrashCleanMain::GetName()
{
  return tr("��������");
}

//�������
QString TrashCleanMain::GetDescribe()
{
  return tr("������̺�ע�������");
}

//���ͼƬ����
QString TrashCleanMain::GetPicture()
{
  return tr("1.png");
}

void  TrashCleanMain::DoAction()
{
  m_TrashCleanDlg.show();
}

Q_EXPORT_PLUGIN2(TrashCleanMain, TrashCleanMain);