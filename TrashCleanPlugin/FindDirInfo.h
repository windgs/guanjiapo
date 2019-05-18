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
  QStringList strDirectory; //查找目录
  QString strFriendName;  //显示名称
  QStringList strExtArray;  //需要查找的文件扩展名
  QStringList strFilt;  //要被过滤的文件夹
  bool bRecursive;     // 是否查找子目录
  bool bDefaultSelect; //默认选项
  bool bRSelect;       //推荐选项
  QString  iconName;      //图标名称
  quint64 ulSize;   
  int id;              //执行id
  int parent;
  bool bIsLeaf;        //是否为叶子节点
  bool bselect;        //是否被选中 

};
