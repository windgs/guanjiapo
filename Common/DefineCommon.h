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

// ��ֹ���е�Ŀ¼���������ļ���
#define KSAFE_DISABLE_USER_RUN_DIR		L"disuserrun"
#define KSAFE_DISABLE_COMM_RUN_DIR		L"discommrun"
// �����������ע����·��
#define STR_RUN_REG_KEY		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

#define KEY_SYS_SERVICE L"SYSTEM\\CurrentControlSet\\Services\\%1\\Parameters"
// ������������Ϣ�Ľṹ
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

//ע���������
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
  QString		strPath;		//�������ȫ·��
  QString		strExePath;		//������lnkָ���ļ���ȫ·��
  QString		strValue;		//run���ע���ֵ
  QString		strParam;		
  QString		strDisplay;		//��ʾ������
  QString		strWarning;		//��ֹ�ľ���
  QIcon     hIcon;
};


//������ͨ�ýṹ
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
    strPath = other.strPath;		//�������ȫ·��
    strExePath = other.strExePath;		//������lnkָ���ļ���ȫ·��
    strValue = other.strValue;		//run���ע���ֵ
    strParam = other.strParam;		
    strDisplay = other.strDisplay;		//��ʾ������
    strWarning = other.strWarning;		//��ֹ�ľ���
    strDisPath = other.strDisPath;   // ����ֹ��·��
    nRegType = other.nRegType;
  }
public:
  unsigned long		nID;
  unsigned long		nType;   //���������� ��Ŀ¼����ע��� �� windows���� ,�ƻ����� ������֮һ			
  unsigned long		nAdvice; //������	
  bool		bEnable;         //�Ƿ񱻽�ֹ
  bool		bNoDealyShow;	 //��ʱ��ʾ 
  bool		bUnknown;        
  bool		bSystem;         //�Ƿ�Ϊϵͳ����
  bool		bDisabledBy3xx;  //�Ƿ�360��ֹ
  unsigned long		nRegType; //��Ŀ¼��������ע�������
  QString		strName;	 //�������� 		
  QString		strDesc;	 //��������	
  QString		strPath;		//�������ȫ·��
  QString		strExePath;		//������lnkָ���ļ���ȫ·��
  QString		strValue;		//run���ע���ֵ
  QString		strParam;		//��������
  QString		strDisplay;		//��ʾ������
  QString		strWarning;		//��ֹ�ľ���
  QString   strDisPath;         // ����ֹ��·��
  QIcon     hIcon;
};

//һ���Ż�ѡ��(��ȡxml�ļ�)
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

// ���������Ϣ�Ľṹ����
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