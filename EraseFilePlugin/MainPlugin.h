#pragma once
//qt
#include <QObject>
#include <QString>

//safe
#include "../Common/DefineInterface.h"
#include "MainEraseDialog.h"

//������
class CMainPlugin : public QObject , ISafeCommon  
{
  Q_OBJECT
  Q_INTERFACES(ISafeCommon)
public:
  CMainPlugin(QObject* parent = NULL);
  virtual ~CMainPlugin(void);

public slots:
  void SlotCloseWindow();
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
  MainEraseDialog m_EraseDialog;

};
