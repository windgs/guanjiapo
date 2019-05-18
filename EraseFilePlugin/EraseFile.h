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
  //qFile�ļ����� lengthд�����ݳ���(ע������Ҫ��int64��ӦΪ�ļ����ȿ��ܴ���4G)
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
  //���Ŀ¼���ļ�����·��
  void GetFiels(QString odir, QStringList& absolutePaths);
  bool GetNativeEntryPoints();
private:
  QStringList  m_EraseList; //ɾ���б���Ҫɾ�����ļ���·��
  PBYTE	       m_cleanBuffer[3];
  PNtFsControlFile  m_NtFsControlFile;
  PRtlNtStatusToDosError m_RtlNtStatusToDosError;
  PGetDiskFreeSpaceEx    m_PGetDiskFreeSpaceEx;
  bool m_realcompress;
  bool m_zap;
};
