#include "FileDelete.h"

CFileDelete::CFileDelete(void)
{}

CFileDelete::~CFileDelete(void)
{}

CFileDelete* CFileDelete::Instance()
{
   static CFileDelete app;
   return &app;
}

int CFileDelete::TrashFileDelete(const QString pszFullName)
{
  int nResult = -1;
  DWORD dwNewAttributes = 0;

  if (pszFullName.isEmpty())
  {
    nResult = Delete_File_Failed;
    return nResult;
  }

  dwNewAttributes = ::GetFileAttributes(pszFullName.toStdWString().c_str());
  if (INVALID_FILE_ATTRIBUTES == dwNewAttributes)
  {
    nResult = Delete_File_Failed;
    return nResult;
  }
  
  //ȥ���ļ�ֻ������
  if (dwNewAttributes & FILE_ATTRIBUTE_READONLY)
  {
    dwNewAttributes &= ~FILE_ATTRIBUTE_READONLY;
  }

  ::SetFileAttributes(pszFullName.toStdWString().c_str(), dwNewAttributes);
  nResult = ::DeleteFile(pszFullName.toStdWString().c_str());

  if (nResult)
    nResult = Delete_File_Success;
  else
    nResult = Delete_File_Failed;

  if ( ERROR_FILE_NOT_FOUND == GetLastError() )
       nResult = Delete_File_Success;

  return nResult;
 
}

bool CFileDelete::MoveFile(QString lpExistingFileName,QString lpNewFileName, DWORD dwFlags)
{
  return ::MoveFileEx(lpExistingFileName.toStdWString().c_str(),lpNewFileName.toStdWString().c_str(),dwFlags);
}