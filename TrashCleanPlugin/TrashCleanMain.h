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
  TrashCleanerDlg  m_TrashCleanDlg;
};
