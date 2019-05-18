#pragma once
#include <QDialog>
#include "ui_TrashCleanDlg.h"
//#include "..\Common\CommonModel\StandardItem.h"
//#include "..\Common\CommonModel\TreeModle.h"
#include "FindDirInfo.h"
#include <QVector>
#include "ScanClearThread.h"
#include <QMap>
#include <QMovie>
#define  GBSIZE (1024 * 1024)
#define  MBSIZE  1024.0
class TrashCleanerDlg :public QDialog
{
  Q_OBJECT
public:
  TrashCleanerDlg(QWidget *parent = NULL, Qt::WindowFlags f = 0);
  ~TrashCleanerDlg(void);
  void CreateTreeView();
  QTreeWidgetItem* GetItem(QTreeWidgetItem* curitem ,QString FirendName);
  QStringList GetClearItem(int id);
private:
  quint64 CacleSize(QString path,QStringList fiels);
  void InsertClearItem(int id, QStringList itemlist);
  void RemoveWidgetItem(QString FirendName);
  void InsertSizeMap(int id, quint64 ssize);
  void ClearSizeMap();
  quint64 GetSizeMap(int id);
  void StartGif();
  void StopGif();
  void CacleZeroItem();
public slots:
    void OnCloseForm();
    void OnMinimized();
    void itemClick(QTreeWidgetItem*, int);
    void OnScan();
    void OnRemve();
    void OnItemAdd(QStringList scanitem,QString path,QString FriendName);
    void OnTreeWidgetPress(QTreeWidgetItem * item, int column);
    void OnDeleteWidgetItem(QString filename);
    void OnCurrentFindDir(QString dir);
    void OnSacnFinished(); //扫描完成通知
    void OnitemDoubleClicked ( QTreeWidgetItem * item, int column );
    void OnHuiShouZhan(quint32 count, quint64 size);
private:
  ScanClearThread m_thread;
  Ui::Dialog  m_TrashDlgUI;
  QTreeWidgetItem*  m_invisibleRoot;
  QVector<FindDirInfo> m_FindDorInfos; 
  QMap<int,QStringList>  m_ClearMap; //保存清理文件路径，key为清理类型id
  QMap<int,quint64>  m_sizemap; //存储每个路径下垃圾文件大小
  quint64  m_SacnTotal; //本次扫描总大小
  QMovie   m_Runninggif;
};
