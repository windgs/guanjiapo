#pragma once
//���ָ��Ŀ¼
#include <QString>
#include <QIcon>
class CSpecialFolderPath
{
public:
  CSpecialFolderPath(void);
  ~CSpecialFolderPath(void);

  static QString GetDirStartUserPath();
  static QString GetDirStartCommonPath();

  static QIcon GetExeIcon(QString);
};
