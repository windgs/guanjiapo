#pragma once
#include <QObject>
#include <QString>
//safe
#include "../Common/DefineInterface.h"
#include "SystemoptMainDlg.h"
class SystemoptMain: public QObject , ISafeCommon   
{
  Q_OBJECT
  Q_INTERFACES(ISafeCommon)
public:
  SystemoptMain(QObject* parent = NULL);
  ~SystemoptMain(void);
public:
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
  SystemoptMainDlg  m_Systemoptdlg;
};
