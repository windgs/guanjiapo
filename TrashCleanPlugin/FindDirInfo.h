#pragma once
#include <QString>
#include <QVector>
#include <QStringList>
#include <QList>
#include <Windows.h>

enum
{
  Delete_File_Success = 0,
  Delete_File_Success_Delay_Reboot = 1,
  Delete_File_Failed = 2
};

enum{
  NONE = -1,
  WIN_TRASH=0,
  BROWER_TRASH,
  VIDEO_TRASH,
  SYS_TRASH,
  
  WIN_TEMP,
  // 	WIN_LNK,
  // 	WIN_DESKTOPLNK,
  WIN_DUMP,
  WIN_HUISHOUZHAN,
  WIN_UPDATE,
  WIN_PREFETCH,
  WIN_USERTEMP,
  WIN_DOWNLOAD,
  WIN_SUOLIETU,
  WIN_ERRPORT,
  WIN_LOG,
  WIN_OFFICE,
  BROWER_IE,
  BROWER_FIREFOX,
  BROWER_MATHRON,
  BROWER_SOGO,
  BROWER_OPERA,
  BROWER_CHROME,
  VIDEO_TUDOU,
  VIDEO_XUNLEI,
  VIDEO_YOUKU,
  VIDEO_KU6,
  VIDEO_PPTV,
  VIDEO_FENGXING,
  VIDEO_QQLIVE
};

enum ACTION
{  
   ACTIONNONE,
   ACTIONSCAN,
   ACTIONRESCAN,
   ACTIONCLEAR
};
class FindDirInfo
{
public: 
  FindDirInfo();
  ~FindDirInfo(void);
  FindDirInfo(const FindDirInfo& cpy);
  FindDirInfo& operator= (const FindDirInfo& cpy);
  void clear();
public:
  QStringList strDirectory; //����Ŀ¼
  QString strFriendName;  //��ʾ����
  QStringList strExtArray;  //��Ҫ���ҵ��ļ���չ��
  QStringList strFilt;  //Ҫ�����˵��ļ���
  bool bRecursive;     // �Ƿ������Ŀ¼
  bool bDefaultSelect; //Ĭ��ѡ��
  bool bRSelect;       //�Ƽ�ѡ��
  QString  iconName;      //ͼ������
  quint64 ulSize;   
  int id;              //ִ��id
  int parent;
  bool bIsLeaf;        //�Ƿ�ΪҶ�ӽڵ�
  bool bselect;        //�Ƿ�ѡ�� 

};
