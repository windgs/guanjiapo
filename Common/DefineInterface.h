#ifndef _COMMON_INFACETER_H
#define _COMMON_INFACETER_H
#include <QtCore/QtPlugin>
#include <QString>
class ISafeCommon
{
public:
  virtual ~ISafeCommon() {};

  //ͨ�ýӿ�
  //�����ΨһID
  virtual QString GetGuid()  = 0;
  //�������
  virtual QString GetName() = 0;
  //�������
  virtual QString GetDescribe() = 0;
  //���ͼƬ����
  virtual QString GetPicture() = 0;
  //�򿪲��
  virtual void    DoAction() = 0;
};
Q_DECLARE_INTERFACE(ISafeCommon, "0895260D-9053-4e8a-B37C-9C05CCFE4A14");
#endif