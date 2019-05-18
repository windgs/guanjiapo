#pragma once
//qt
#include <QObject>
#include <QString>

//safe
#include "../Common/DefineInterface.h"
#include "TrashCleanerDlg.h"

class TrashCleanMain: public QObject , ISafeCommon  
{
  Q_OBJECT
  Q_INTERFACES(ISafeCommon)
public:
  TrashCleanMain(QObject* parent = NULL);
  ~TrashCleanMain(void);
public:
  //插件的唯一ID
  virtual QString GetGuid();
  //插件名称
  virtual QString GetName();
  //插件描述
  virtual QString GetDescribe();
  //插件图片名称
  virtual QString GetPicture();

  virtual void    DoAction() ;
private:
  TrashCleanerDlg  m_TrashCleanDlg;
};
