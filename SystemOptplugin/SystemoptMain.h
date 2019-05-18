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
  //�����ΨһID
  virtual QString GetGuid();
  //�������
  virtual QString GetName();
  //�������
  virtual QString GetDescribe();
  //���ͼƬ����
  virtual QString GetPicture();

  virtual void    DoAction() ;
private:
  SystemoptMainDlg  m_Systemoptdlg;
};
