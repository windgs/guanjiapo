#pragma once
//qt
#include <QObject>
#include <QString>

//safe
#include "../Common/DefineInterface.h"
#include "MainEraseDialog.h"

//插件入口
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
  MainEraseDialog m_EraseDialog;

};
