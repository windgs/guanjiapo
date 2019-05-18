#ifndef _COMMON_DEFINE_H
#define _COMMON_DEFINE_H
#include <QString>
#include <QIcon>
#include <Windows.h>
#define VALUE_DIS 5

#define RUN_TYPE_STARTUP	1
#define RUN_TYPE_SERVICE	2
#define RUN_TYPE_TASK		3
#define RUN_TYPE_ALL		-1

#define REG_RUN_TYPE_WINDOW_HKLM		1
#define REG_RUN_TYPE_WINDOW_HKCU		2
#define REG_RUN_TYPE_KSAFE_HKLM			3
#define REG_RUN_TYPE_KSAFE_HKCU			4
#define REG_RUN_TYPE_3XX_HKLM			5
#define REG_RUN_TYPE_3XX_HKCU			6

#define DIR_RUN_TYPE_BEGIN				100
#define DIR_RUN_TYPE_WINDOW_COMM		101
#define DIR_RUN_TYPE_WINDOW_USER		102
#define DIR_RUN_TYPE_KSAFE_COMM			103
#define DIR_RUN_TYPE_KSAFE_USER			104
#define DIR_RUN_TYPE_3XX_COMM			105
#define DIR_RUN_TYPE_3XX_USER			106

// 禁止运行的目录启动项保存的文件夹
#define KSAFE_DISABLE_USER_RUN_DIR		L"disuserrun"
#define KSAFE_DISABLE_COMM_RUN_DIR		L"discommrun"
// 保存启动项的注册表键路径
#define STR_RUN_REG_KEY		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

#define KEY_SYS_SERVICE L"SYSTEM\\CurrentControlSet\\Services\\%1\\Parameters"
// 保存启动项信息的结构
struct RUN_DIR_INFO
{ 
  unsigned long		nID;
  QString	strName;
  QString	strPath;
  QString	strDesc;
  QString strParam;
  QString strogripath;
  int	  nDirType;
  QIcon hIcon;
};

//注册表启动项
struct RegRunInfo
{
public:
  RegRunInfo()
  {	
    nID		= 0;
    bEnable = FALSE;
    nType	= 0;
    nAdvice	= 4;
    bSystem = FALSE;
    bNoDealyShow = FALSE;
    nRegType= 0;
    bUnknown= TRUE;
    bDisabledBy3xx = FALSE;
  
  }
  ~RegRunInfo(){}
public:
  unsigned long		nID;
  unsigned long		nType;			
  unsigned long		nAdvice;	
  bool		bEnable;
  bool		bNoDealyShow;	
  bool		bUnknown;
  bool		bSystem;
  bool		bDisabledBy3xx;
  unsigned long		nRegType;
  QString		strName;			
  QString		strDesc;		
  QString		strPath;		//启动项的全路径
  QString		strExePath;		//启动项lnk指向文件的全路径
  QString		strValue;		//run项的注册表值
  QString		strParam;		
  QString		strDisplay;		//显示的名字
  QString		strWarning;		//禁止的警告
  QIcon     hIcon;
};


//启动项通用结构
struct SafeRunInfo
{
public:
  SafeRunInfo()
  {	
    nID		= 0;
    bEnable = FALSE;
    nType	= 0;
    nAdvice	= 4;
    bSystem = FALSE;
    bNoDealyShow = FALSE;
    nRegType= 0;
    bUnknown= TRUE;
    bDisabledBy3xx = FALSE;

  }
  ~SafeRunInfo(){}

  SafeRunInfo(const SafeRunInfo& other)
  {
    nID = other.nID;
    nType = other.nType;
    bSystem = other.bSystem;
    strName = other.strName;			
    strDesc = other.strDesc;		
    strPath = other.strPath;		//启动项的全路径
    strExePath = other.strExePath;		//启动项lnk指向文件的全路径
    strValue = other.strValue;		//run项的注册表值
    strParam = other.strParam;		
    strDisplay = other.strDisplay;		//显示的名字
    strWarning = other.strWarning;		//禁止的警告
    strDisPath = other.strDisPath;   // 被禁止的路径
    nRegType = other.nRegType;
  }
public:
  unsigned long		nID;
  unsigned long		nType;   //启动项类型 是目录或者注册表 ， windows服务 ,计划任务 启动项之一			
  unsigned long		nAdvice; //处理建议	
  bool		bEnable;         //是否被禁止
  bool		bNoDealyShow;	 //延时显示 
  bool		bUnknown;        
  bool		bSystem;         //是否为系统进程
  bool		bDisabledBy3xx;  //是否被360禁止
  unsigned long		nRegType; //是目录启动还是注册表启动
  QString		strName;	 //进程名称 		
  QString		strDesc;	 //进程描述	
  QString		strPath;		//启动项的全路径
  QString		strExePath;		//启动项lnk指向文件的全路径
  QString		strValue;		//run项的注册表值
  QString		strParam;		//启动参数
  QString		strDisplay;		//显示的名字
  QString		strWarning;		//禁止的警告
  QString   strDisPath;         // 被禁止的路径
  QIcon     hIcon;
};

//一键优化选项(读取xml文件)
typedef struct tagRunOptItem  
{
  int id;
  int type;
  QString name;
  QString dispayname;
  QString appname;
  QString decs;
  int advice;
}RunOptItem;

// 保存服务信息的结构定义
struct ServiceConfig
{   
    ServiceConfig()
	{
	   Enable = false;
	   lpqscfg = NULL;
	}
	QString					strName;
	QString					strServDLL;
	QString					strDesc;
	QIcon                   hIcon;
	bool                    Enable;
	LPQUERY_SERVICE_CONFIG	lpqscfg;
};

#endif