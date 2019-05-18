#pragma once
//获得指定目录
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
