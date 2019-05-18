#ifndef _COMMON_INFACETER_H
#define _COMMON_INFACETER_H
#include <QtCore/QtPlugin>
#include <QString>
class ISafeCommon
{
public:
  virtual ~ISafeCommon() {};

  //通用接口
  //插件的唯一ID
  virtual QString GetGuid()  = 0;
  //插件名称
  virtual QString GetName() = 0;
  //插件描述
  virtual QString GetDescribe() = 0;
  //插件图片名称
  virtual QString GetPicture() = 0;
  //打开插件
  virtual void    DoAction() = 0;
};
Q_DECLARE_INTERFACE(ISafeCommon, "0895260D-9053-4e8a-B37C-9C05CCFE4A14");
#endif