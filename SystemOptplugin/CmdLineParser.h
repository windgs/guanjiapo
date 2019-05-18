#ifndef _CMDLINE_PARSER_INC_
#define _CMDLINE_PARSER_INC_

#include <list>
#include <atlcoll.h>
#include <ShlObj.h>
#include <ShellAPI.h>
#include <QVector>
#include <QString>
// 命令行解析类
class CCmdLineParser  
{
public:
	enum {
		DEF_CUR_DIR		= 0x0001, // 在当前目录查找
		DEF_ENV_VAR		= 0x0002, // 在默认的环境变量查找
		DEF_EXT_NAME	= 0x0004, // 使用默认可执行的扩展名
		NEED_PARAM		= 0x0008,  // 解析参数
		DEF_FLAG		= DEF_CUR_DIR | DEF_ENV_VAR | DEF_EXT_NAME | NEED_PARAM
	};

public:
	CCmdLineParser(DWORD dwFlag = DEF_FLAG);
	CCmdLineParser(LPCTSTR lpCmdLine /*dwFlag = DEF_CUR_DIR | DEF_ENV_VAR | DEF_EXT_NAME | NEED_PARAM*/);
	virtual ~CCmdLineParser();
	
	// 解析命令行，分解成命令行的各部分
	BOOL	DoParser(LPCTSTR lpCmdLine, 
		LPCTSTR lpCurDir = NULL, 
		LPCTSTR lpEnvVars = NULL, 
		LPCTSTR lpExtNames = NULL,
		LPCTSTR lpParentPath = NULL
		);

	// 设置解析的方法
	void	SetFlag(DWORD dwFlag) {
		m_dwFlag = dwFlag;
	}

	// 得到命令
	LPCTSTR GetCmd() const {
		return (m_szCmd[0] != 0) ? m_szCmd : NULL;
	}

	// 得到参数
	LPCTSTR GetParam() const {
		return m_lpParam;
	}

private:
	// 下列函数的注释见cpp
	BOOL	ExpandExtNames(LPTSTR lpFilePath, LPCTSTR lpExtNames);
	BOOL	ExpandEnvVars(LPTSTR lpFilePath, LPCTSTR lpEnvVars, LPCTSTR lpExtNames);

	LPTSTR	ExpandMacro(LPCTSTR lpCmdBegin);
	LPTSTR	ExpandMacro2(LPCTSTR lpCmdBegin);
	LPTSTR	ExpandRelative(LPCTSTR lpCmdBegin, LPCTSTR lpCurDir, BOOL bQuotation);
	BOOL	ExpandAbsolute(LPCTSTR lpCmdBegin, LPCTSTR lpExtNames, BOOL bQuotation);

	void	ExpandParam(LPCTSTR lpCmdEnd);

private:
	TCHAR	m_szCmd[MAX_PATH + 10]; // 多几个字节防止溢出

	LPTSTR	m_lpParam;
	DWORD	m_dwFlag;
};

//DWORD GetFileListFromCmd(CCmdLineParser& cmdParser, CAtlArray<CString>& fileArray, LPCTSTR lpCurDir);
DWORD GetFileListFromCmd(CCmdLineParser& cmdParser, QVector<QString>& fileArray, LPCTSTR lpCurDir);
// runopt的命令行解析
class CRunoptCmdLineParser
{
public:
	CRunoptCmdLineParser(LPCTSTR lpCmdLine) :m_Parser(lpCmdLine)
	, m_lpCmdLine(lpCmdLine)
	, m_bFileExist(TRUE)
	{

	}
	virtual ~CRunoptCmdLineParser(){}

	// 获得命令
	LPCTSTR	GetCmd()
	{
		// 如果可执行文件不存在
		if (m_Parser.GetCmd() == NULL )
		{
			m_bFileExist = FALSE;
			int nArgCount = 0;
			// 取命令行的第一个参数
			LPWSTR* lpParsedCmdLine = ::CommandLineToArgvW(m_lpCmdLine,&nArgCount); 
			if ( lpParsedCmdLine != NULL )
				return lpParsedCmdLine[0];
			else
				return NULL;
		}
		else
			return m_Parser.GetCmd();
	}

	// 判断可执行文件是否存在
	BOOL IsPEFileExist()
	{
		return m_bFileExist;
	}

protected:
	CCmdLineParser	m_Parser;
	BOOL			m_bFileExist;
	LPCTSTR			m_lpCmdLine;
};

#endif /* _CMDLINE_PARSER_INC_ */