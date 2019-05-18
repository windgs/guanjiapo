#pragma once
#include <QString>
#include <QThread>
#include <QStringList>
#include "..\Common\DefineCommon.h"
class ThreadStub :public QThread
{  
  Q_OBJECT 
public:
  ThreadStub(void);
  ~ThreadStub(void);
signals:
  void NotifyFindItem();

 
protected:
  virtual void	run ();
};
