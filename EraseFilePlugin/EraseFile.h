#pragma once
//#include <QFile>
#include <QDir>
#include <QStringList>
#include <windows.h>
#include "Define.h"
#define CLEANBUFSIZE 65536
#define	FILEMAPSIZE		(16384+2)
#define LINVALID -1
class CEraseFile :public QObject
{
   Q_OBJECT
public:
  CEraseFile(QObject* parent = NULL);
  ~CEraseFile(void);
public:
  bool StartEraseFile(QStringList EraseList);
  void CleanFreeSpace();
signals:
  void UpdataProgressValue(int value);
private:
  void MemmoryAlloc();
  QString PrintWin32Error( DWORD ErrorCode );
  //qFile文件对象 length写入数据长度(注意这里要用int64，应为文件长度可能大于4G)
  bool SafeWrite(HANDLE FileHandle, qint64 length);
  bool SafeDelete(QString FileName, quint64 length);
  bool SafeRename(QString FileName, QString& Lastname);
  bool SafeDeleteCompressed(QString FileName);
  bool SafeWriteCompressedFile(HANDLE VolumeHandle, 
    HANDLE hFile,
    DWORD clusterSize, 
    bool* realcompress, 
    bool* zap);
 
private:
  //获得目录下文件绝对路径
  void GetFiels(QString odir, QStringList& absolutePaths);
  bool GetNativeEntryPoints();
private:
  QStringList  m_EraseList; //删除列表保存要删除的文件和路径
  PBYTE	       m_cleanBuffer[3];
  PNtFsControlFile  m_NtFsControlFile;
  PRtlNtStatusToDosError m_RtlNtStatusToDosError;
  PGetDiskFreeSpaceEx    m_PGetDiskFreeSpaceEx;
  bool m_realcompress;
  bool m_zap;
};
