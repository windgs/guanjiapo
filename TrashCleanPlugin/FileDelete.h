#pragma once
#include "FindDirInfo.h"
class CFileDelete
{
private:
  CFileDelete(void);
  ~CFileDelete(void);
public:
   static CFileDelete* Instance();
   int TrashFileDelete(const QString pszFullName);
   bool MoveFile(QString lpExistingFileName,QString lpNewFileName, DWORD dwFlags);

};
