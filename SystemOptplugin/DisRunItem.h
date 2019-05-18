#pragma once
#include <QString>
#include <QObject>
#include <QVector>
#include "..\Common\DefineCommon.h"
class DisRunItem : public QObject
{
  Q_OBJECT
private:
  DisRunItem(void);
  ~DisRunItem(void);

public:
   static DisRunItem* Instance();
   //控制某个启动项
   bool ControlRun(bool nEnable, SafeRunInfo* ruinfo);
   //获得被禁止的lnk文件所放的目录
   bool GetDisDir(bool bCurrentUser, QString& strpath);
private:
  void ControlRunProcess(bool nEnable, int Regtype, SafeRunInfo* ruinfo);
  bool EnableRun(int Regtype,SafeRunInfo* ruinfo);
  bool DisEnableRun(int Regtype, SafeRunInfo* ruinfo);
  QString GetFilename(QString path);
 
private:
  QVector<SafeRunInfo> m_disRunItem;
};
