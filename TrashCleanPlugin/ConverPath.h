#pragma once
#include <QString>
#include <QMap>
#include "FindDirInfo.h"
class ConverPath
{
private:
  ConverPath(void);
  ~ConverPath(void);
public:
  static ConverPath* Instance();
  QString ConverFindPath(QString dir);
private:
   QString GetEnvVariable(QString pszName);
   QString GetFolderPath(QString strEnvName);
   void InitCsidlNameEntry();
   void GetPrePos(QString path, int& first,int& second);
   QString GetEnvironmentPath(QString ss);
private:
   QMap<QString, int> m_CsidlEntryMap;
};
