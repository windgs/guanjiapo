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
   //����ĳ��������
   bool ControlRun(bool nEnable, SafeRunInfo* ruinfo);
   //��ñ���ֹ��lnk�ļ����ŵ�Ŀ¼
   bool GetDisDir(bool bCurrentUser, QString& strpath);
private:
  void ControlRunProcess(bool nEnable, int Regtype, SafeRunInfo* ruinfo);
  bool EnableRun(int Regtype,SafeRunInfo* ruinfo);
  bool DisEnableRun(int Regtype, SafeRunInfo* ruinfo);
  QString GetFilename(QString path);
 
private:
  QVector<SafeRunInfo> m_disRunItem;
};
