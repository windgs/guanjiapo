#pragma once
#include <QThread>
#include <QVector>
#include "FindDirInfo.h"
class TrashCleanerDlg;
class ScanClearThread :public QThread
{
  Q_OBJECT
public:
  ScanClearThread(void);
  ~ScanClearThread(void);
   virtual void	run ();
   void RemoveAll () {m_WorkDir.clear();}
   void Append(const FindDirInfo& info);
   void setAction(ACTION action) {m_curaction = action;}
   int count() {return m_WorkDir.count();}
   void setDlg(TrashCleanerDlg* Dlg) { m_Dlg = Dlg; }
signals:
  void ItemAdd(QStringList,QString ,QString);
  void NotifyHuiShouZhan(quint32, quint64);
  void NotifyDeleteFile(QString);
  void NotifyFinished();
  void NotifyCurrentFindDir(QString); //֪ͨ��ǰ���ڲ��ҵ�Ŀ¼
private:
  void ActionSacn();
  void ActionClear();
  bool FindFileInDirectory(const FindDirInfo& info);
  bool FindFileWithExtInDirectory(QString path,
    QStringList strExtArray, 
    QStringList strFilt,
    int index,
    QString FriendName);
  QStringList GetSubDir(QString path);
private:
  ACTION m_curaction;
  FindDirInfo copyinfo;
  QVector<FindDirInfo> m_WorkDir; //��Ҫɨ���������ļ��� 
  TrashCleanerDlg*  m_Dlg;
};
