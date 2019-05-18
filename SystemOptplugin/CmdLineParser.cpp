// CmdLineParser.cpp: implementation of the CCmdLineParser class.
//
//////////////////////////////////////////////////////////////////////
#include "CmdLineParser.h"
#include <assert.h>
#pragma warning( disable:4996)

//
//////////////////////////////////////////////////////////////////////////


// 是不是路径隔离字符（/ 或 \）
static inline bool is_path_separator_char(TCHAR c)
{
	return (c == _T('/')) || (c == _T('\\'));
}

// 是不是绝对路径
static inline bool is_absolute_path(LPCTSTR lpPath)
{
	if ( lpPath[1] == _T(':') )
	{
		return TRUE;
	}

	if ( lpPath[0] == _T('\\') && lpPath[1] == _T('\\') )
	{
		return TRUE;
	}

	if ( _tcsnicmp(lpPath, _T("file://"), 7) == 0 )
	{
		return TRUE;
	}

	return FALSE;
}

// 是不是相对路径
static inline bool is_relative_path(LPCTSTR lpPath) // 调用这个函数的 lpPath 必须fix过,没有多余的 '\'
{
	bool bResult = TRUE;
	TCHAR c;

	while ( (c = *lpPath) != 0 )
	{
		if ( c == _T('\\') )
		{
			if ( bResult )
			{
				break;
			}

			bResult = TRUE;
		}
		else if ( c != _T('.') )
		{
			bResult = FALSE;
		}

		lpPath++;
	}

	return bResult;
}	

// 是不是空白字符
static inline bool is_blank_char(TCHAR c)
{
	return (c == _T(' ')) || (c == _T('\t'));
}

// 字符串是否为空
static inline BOOL is_empty_str(LPCTSTR str)
{
	return (str == NULL) || (*str == _T('\0'));
}

// 跳过空白字符
static inline LPCTSTR skip_blank(LPCTSTR lpStr)
{
	TCHAR c;
	while ( (c = *lpStr) != 0 )
	{
		if ( !is_blank_char(c) )
		{
			return lpStr;
		}

		lpStr++;
	}

	return lpStr;
}

// 跳过非空白字符
static inline LPCTSTR skip_no_blank(LPCTSTR lpStr)
{
	TCHAR c;
	while ( (c = *lpStr) != 0 )
	{
		if ( is_blank_char(c) )
		{
			return lpStr;
		}
		
		lpStr++;
	}
	
	return lpStr;
}

// 跳过 '\"'
static inline LPCTSTR skip_quotation(LPCTSTR lpStr)
{
	TCHAR c;
	while ( (c = *lpStr) != 0 )
	{
		if ( c != _T('\"') )
		{
			return lpStr;
		}
		
		lpStr++;
	}
	
	return lpStr;
}

// 获得参数的长度
static size_t cmd_param_len(LPCTSTR lpParam)
{
	int nBacket = 0;
	TCHAR c;

	LPCTSTR lpStr = lpParam;
	while ( (c = *lpStr) != 0 )
	{
		// ""里面的空字符不会break
		if ( is_blank_char(c) && (nBacket == 0 || nBacket == 2) )
		{
			break;
		}

		lpStr++;

		// 统计"个数
		if ( c == _T('\"') )
		{
			nBacket++;
		}
		else if ( c == _T('\\') )
		{
			// 转义
			if ( lpStr[1] == 0 )
			{
				break;
			}

			lpStr++;
		}
	}

	return (lpStr - lpParam);
}

// 补全路径名
static BOOL fix_path_separator(LPTSTR lpDst, size_t nDstLen, LPCTSTR lpSrc, size_t nSrcLen = -1)
{
	bool seqarator = false;
	LPCTSTR lpDst_End = lpDst + nDstLen;

	if ( nDstLen < 3 )
	{
		return false;
	}

	if ( nSrcLen == -1 )
	{
		nSrcLen = _tcslen(lpSrc);
	}

	if ( nSrcLen >= 2 && _tcsncmp(lpSrc, _T("\\\\"), 2) == 0 )
	{
		*lpDst++ = _T('\\');
		*lpDst++ = _T('\\');
		*lpDst = 0;

		lpSrc += 2;
		nSrcLen -= 2;
	}
	else if ( nSrcLen >= 7 && _tcsnicmp(lpSrc, _T("file://"), 7) == 0 )
	{
		if ( lpSrc[8] != _T(':') )
		{
			*lpDst++ = _T('\\');
			*lpDst++ = _T('\\');
			*lpDst = 0;
		}

		lpSrc += 7;
		nSrcLen -= 7;
	}

	while ( nSrcLen-- != 0 )
	{
		if ( lpDst >= lpDst_End )
		{
			return FALSE;
		}

		TCHAR c = *lpSrc;
		if ( is_path_separator_char(c) )
		{
			if ( !seqarator )
			{
				seqarator = true;
				*lpDst++ = _T('\\');
			}
		}
		else
		{
			*lpDst++ = c;
			seqarator = false;
		}
	
		lpSrc++;
	}

	*lpDst = 0;
	return true;
}

// 逆向查找字符
static inline LPCTSTR re_strchr(LPCTSTR lpStrBegin, LPCTSTR lpStr, TCHAR c)
{
	assert(lpStr >= lpStrBegin);

	while ( lpStr != lpStrBegin )
	{
		if ( *lpStr == c )
		{
			return lpStr;
		}

		lpStr--;
	}

	return NULL;
}

// 是否包含禁止使用的符号
static inline BOOL is_vaild_file_name(LPCTSTR lpFileName)
{
	TCHAR c;
	while ( (c = *lpFileName) != 0 )
	{
		if ( _tcschr(_T("\\/:*?\"<>|"), c) != NULL )
		{
			return FALSE;
		}

		lpFileName++;
	}

	return TRUE;
}

// 连接路径和文件名
static BOOL append_file_name(LPTSTR lpPath, LPCTSTR lpFileName, size_t nFileNameLen = -1)
{
	if( lpPath[0] == _T('\0') )
	{
		return FALSE;
	}

	size_t nPathLen = _tcslen(lpPath);
	LPTSTR lpDstFileName = lpPath + nPathLen;
	
	// 判断前面路径有没有带 '\\'
	if ( lpDstFileName[-1] != _T('\\') )
	{
		*lpDstFileName++ = _T('\\');
		nPathLen++;
	}

	// 跳过文件名前面的隔离符
	while ( is_path_separator_char(*lpFileName) )
	{
		lpFileName++;
	}

	return fix_path_separator(lpDstFileName, MAX_PATH - nPathLen - 1, lpFileName, nFileNameLen);
}

// 获取文件名
static LPCTSTR get_file_name(LPCTSTR lpFilePath)
{
	// 逆序找 '\\'
	LPCTSTR lpFileName = _tcsrchr(lpFilePath, _T('\\'));
	if ( lpFileName == NULL )
	{
		// 没找到则找 '/'
		lpFileName = _tcsrchr(lpFilePath, _T('/'));
		if ( lpFileName == NULL )
		{
			lpFileName = lpFilePath;
		}
		else
		{
			lpFileName++;
		}
	}
	else
	{
		lpFileName++;
	}

	return lpFileName;
}

// 获取路径类型
static inline int get_path_type(LPCTSTR lpPath)
{
	DWORD dwErrMode = SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
	
	DWORD dwAttr = GetFileAttributes(lpPath);
	
	SetErrorMode(dwErrMode);
	
	// 是文件返回0
	if ( dwAttr == INVALID_FILE_ATTRIBUTES )
		return 0;
	
	// 是目录返回1，其它2
	return (dwAttr & FILE_ATTRIBUTE_DIRECTORY) ? 2 : 1;
}

// 获取完整的路径名
static DWORD MyGetLongPathName(LPCTSTR lpFilePath, LPTSTR lpBuff, DWORD dwBuffSize)
{
	DWORD dwResult = 0;

	if ( is_absolute_path(lpFilePath) &&
		_tcschr(lpFilePath, _T('~')) == NULL
		)
	{
		dwResult = _tcslen(lpFilePath);
		if ( lpBuff == NULL || dwResult > dwBuffSize )
		{
			dwResult++;
		}
		else
		{
			_tcsncpy(lpBuff, lpFilePath, dwBuffSize);
			lpBuff[dwBuffSize - 1] = 0;
		}
	}
	else
	{
	//	OutputDebugString(lpFilePath);
		dwResult = GetLongPathName(lpFilePath, lpBuff, dwBuffSize);
	}

	return dwResult;
}

// 获取环境变量中的 path
LPCTSTR GetDefaultPathVar()
{
	//static CString strPathVar;
	QString strPathVar;
	static BOOL bInitPathVar = FALSE;

	if ( !bInitPathVar )
	{
		DWORD dwPathVars = GetEnvironmentVariable(_T("path"), NULL, 0);
		if ( dwPathVars != 0 )
		{   
			TCHAR lpDefEnvs[MAX_PATH] = {0};
			//LPTSTR lpDefEnvs = strPathVar.GetBuffer(dwPathVars + 1);
			GetEnvironmentVariable(_T("path"), lpDefEnvs, dwPathVars);
			//strPathVar.ReleaseBuffer(dwPathVars);
			strPathVar = QString::fromStdWString(lpDefEnvs);
		}
	}

	return strPathVar.toStdWString().c_str();
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCmdLineParser::CCmdLineParser(DWORD dwFlag)
{
	ZeroMemory(m_szCmd, sizeof(m_szCmd));
	m_dwFlag = dwFlag;
	m_lpParam = NULL;
}

CCmdLineParser::CCmdLineParser(LPCTSTR lpCmdLine /*dwFlag = DEF_CUR_DIR | DEF_ENV_VAR | DEF_EXT_NAME | NEED_PARAM*/)
{
	ZeroMemory(m_szCmd, sizeof(m_szCmd));
	m_dwFlag = DEF_CUR_DIR | DEF_ENV_VAR | DEF_EXT_NAME | NEED_PARAM;
	m_lpParam = NULL;

	DoParser(lpCmdLine);
}

CCmdLineParser::~CCmdLineParser()
{
	if (NULL != m_lpParam)
	{
        delete[] m_lpParam;
        m_lpParam = NULL;
	}
}

// 展开扩展名
BOOL CCmdLineParser::ExpandExtNames(LPTSTR lpFilePath, LPCTSTR lpExtNames)
{
	BOOL bResult = FALSE;
	
	// ！！！ 应该是 get_path_type(lpFilePath) == 2 ！！！  
	if ( get_path_type(lpFilePath) != 1 )
	{
		// 取得文件名
		LPCTSTR lpFileName = get_file_name(lpFilePath);
		// 找最后的 .
 		LPTSTR lpExtName = (TCHAR*)_tcsrchr(lpFileName, _T('.'));
 		if ( lpExtName == NULL )
 		{
			lpExtName = lpFilePath + _tcslen(lpFilePath);
			*lpExtName++ = _T('.');
			*lpExtName = _T('\0');
			
			LPCTSTR lpFixExtName = lpExtNames;
			// 枚举传进来的扩展名列表
			while ( !is_empty_str(lpFixExtName) )
			{
				size_t nFixExtNameLen = 0;
				
				// 列表用 ; 分隔
				LPTSTR lpNextFixExtName = (LPTSTR)_tcschr(lpFixExtName, _T(';'));
				if ( lpNextFixExtName != NULL )
				{
					nFixExtNameLen = lpNextFixExtName - lpFixExtName;
					lpNextFixExtName++;
				}
				else
				{
					nFixExtNameLen = _tcslen(lpFixExtName);
				}
				
				if ( lpExtName + nFixExtNameLen < lpFilePath + MAX_PATH )
				{
					_tcsncpy(lpExtName, lpFixExtName, nFixExtNameLen);
					lpExtName[nFixExtNameLen] = 0;

					// 判断加上扩展名后是不是有效文件
					if ( get_path_type(lpFilePath) == 1 )
					{
						bResult = TRUE;
						break;
					}
				}

				lpFixExtName = lpNextFixExtName;
			}
			
			if ( !bResult )
			{
				lpExtName[-1] = _T('\0');
			}
		}
	}
	else
	{
		bResult = TRUE;
	}

	return bResult;
}

// 展开环境变量
BOOL CCmdLineParser::ExpandEnvVars(LPTSTR lpFilePath, LPCTSTR lpEnvVars, LPCTSTR lpExtNames)
{
	TCHAR szTempBuff[MAX_PATH + 10];

	// 取得系统目录
	GetSystemDirectory(szTempBuff, MAX_PATH);
	// 连接系统目录和文件名
	append_file_name(szTempBuff, lpFilePath);
	if ( ExpandExtNames(szTempBuff, lpExtNames) )
	{
		// 补充扩展名后如果存在，则取得完整路径名，并返回成功
		MyGetLongPathName(szTempBuff, lpFilePath, MAX_PATH);
		return TRUE;
	}

	// 取得windows目录，操作同上
	GetSystemWindowsDirectory(szTempBuff, MAX_PATH);
	append_file_name(szTempBuff, lpFilePath);
	if ( ExpandExtNames(szTempBuff, lpExtNames) )
	{
		MyGetLongPathName(szTempBuff, lpFilePath, MAX_PATH);
		return TRUE;
	}

	// 如果标志有需要查看环境变量
	if ( (m_dwFlag & DEF_ENV_VAR) && lpEnvVars == NULL )
	{
		// 取得环境变量 path
		lpEnvVars = GetDefaultPathVar();
	}

	if ( lpEnvVars != NULL )
	{
		//
		// 展开环境变量
		//
		LPCTSTR lpVar = lpEnvVars;
		while ( !is_empty_str(lpVar)  )
		{
			size_t nVarLen;
			TCHAR c;

			while ( (c = *lpVar) != 0 )
			{
				if ( c != _T(';') && c != _T(' ') && c != _T('\t') )
				{
					break;
				}

				lpVar++;
			}

			if ( c == 0 )
			{
				break;
			}

			LPCTSTR lpNextVar = _tcschr(lpVar, _T(';'));
			if ( lpNextVar != NULL )
			{
				nVarLen = lpNextVar - lpVar;
				lpNextVar++;
			}
			else
			{
				nVarLen = _tcslen(lpVar);
			}

			// 将文件名连接到环境变量指定目录，再补上扩展名，再查找
			if ( fix_path_separator(szTempBuff, MAX_PATH, lpVar, nVarLen) &&
				append_file_name(szTempBuff, lpFilePath) &&
				ExpandExtNames(szTempBuff, lpExtNames) )
			{
				MyGetLongPathName(szTempBuff, lpFilePath, MAX_PATH);
				return TRUE;
			}

			lpVar = lpNextVar;
		}
	}

	return FALSE;
}

// 展开参数
void CCmdLineParser::ExpandParam(LPCTSTR lpCmdEnd)
{
	// 如果标志需要解析参数
	if ( m_dwFlag & NEED_PARAM )
	{
		LPCTSTR lpParamBegin;

		lpParamBegin = lpCmdEnd;

		// 跳过空白
		lpParamBegin = skip_blank(lpParamBegin);

		// 有参数则保存到成员变量
		if ( !is_empty_str(lpParamBegin) )
		{
			size_t nParamLen = _tcslen(lpParamBegin);

			m_lpParam = new TCHAR[nParamLen + 2];
			_tcscpy(m_lpParam, lpParamBegin);
		}
	}
}

// 展开宏路径
LPTSTR CCmdLineParser::ExpandMacro(LPCTSTR lpCmdBegin)
{
	size_t nMacroLen, nExpandMacroLen;
	LPTSTR lpCmdBuff = NULL;

	if ( _tcsnicmp(lpCmdBegin, _T("%SystemRoot%"), nMacroLen = sizeof ("%SystemRoot%") - 1) == 0 ||
		_tcsnicmp(lpCmdBegin, _T("%windir%"), nMacroLen = sizeof ("%windir%") - 1) == 0
		)
	{
		nExpandMacroLen = GetSystemWindowsDirectory(m_szCmd, MAX_PATH);
	}
	else if ( _tcsnicmp(lpCmdBegin, _T("%ProgramFiles%"), nMacroLen = sizeof ("%ProgramFiles%") - 1) == 0 )
	{
		if ( SHGetSpecialFolderPath(NULL, m_szCmd, CSIDL_PROGRAM_FILES, FALSE) )
		{
			nExpandMacroLen = _tcslen(m_szCmd);
		}
	}
	else if ( _tcsnicmp(lpCmdBegin, _T("%CommonProgramFiles%"), nMacroLen = sizeof ("%CommonProgramFiles%") - 1) == 0 )
	{
		if ( SHGetSpecialFolderPath(NULL, m_szCmd, CSIDL_PROGRAM_FILES_COMMON, FALSE) )
		{
			nExpandMacroLen = _tcslen(m_szCmd);
		}
	}
	else if ( _tcsnicmp(lpCmdBegin, _T("%Temp%"), nMacroLen = sizeof ("%Temp%") - 1) == 0 ||
		_tcsnicmp(lpCmdBegin, _T("%Tmp%"), nMacroLen = sizeof ("%Tmp%") - 1) == 0
		)
	{
		nExpandMacroLen = GetTempPath(MAX_PATH, m_szCmd);
	}
	else 
	{
		// 不支持的宏路径
		goto _Failed_Exit;
	}

	if ( nExpandMacroLen != 0 )
	{
		size_t dwBuffLen = nExpandMacroLen + _tcslen(lpCmdBegin + nMacroLen) + 2;

		lpCmdBuff = new TCHAR[dwBuffLen];
		if ( lpCmdBuff != NULL )
		{
			_tcscpy(lpCmdBuff, m_szCmd);
			if ( lpCmdBuff[nExpandMacroLen - 1] == _T('\\') )
			{
				nExpandMacroLen--;
			}

			_tcscpy(lpCmdBuff + nExpandMacroLen, lpCmdBegin + nMacroLen);
		}
	}

_Failed_Exit:
	return lpCmdBuff;
}

// 展开另一种宏路径
LPTSTR CCmdLineParser::ExpandMacro2(LPCTSTR lpCmdBegin)
{
	size_t nMacroLen, nExpandMacroLen;
	LPTSTR lpCmdBuff = NULL;

	if ( _tcsnicmp(lpCmdBegin, _T("SystemRoot"), nMacroLen = sizeof ("SystemRoot") - 1) == 0 )
	{
		nExpandMacroLen = GetSystemWindowsDirectory(m_szCmd, MAX_PATH);
	}
	else if ( _tcsnicmp(lpCmdBegin, _T("system32"), nMacroLen = sizeof ("system32") - 1) == 0 )
	{
		nExpandMacroLen = GetSystemDirectory(m_szCmd, MAX_PATH);
	}
	else
	{
		goto _Failed_Exit;
	}

	if ( nExpandMacroLen != 0 )
	{
		size_t dwBuffLen = nExpandMacroLen + _tcslen(lpCmdBegin + nMacroLen) + 2;

		lpCmdBuff = new TCHAR[dwBuffLen];
		if ( lpCmdBuff != NULL )
		{
			_tcscpy(lpCmdBuff, m_szCmd);
			if ( lpCmdBuff[nExpandMacroLen - 1] == _T('\\') )
			{
				nExpandMacroLen--;
			}

			_tcscpy(lpCmdBuff + nExpandMacroLen, lpCmdBegin + nMacroLen);
		}
	}

_Failed_Exit:
	return lpCmdBuff;
}


// 展开绝对路径
BOOL CCmdLineParser::ExpandAbsolute(LPCTSTR lpCmdBegin, LPCTSTR lpExtNames, BOOL bQuotation)
{
	BOOL bResult = FALSE;

	// 如果是绝对路径
	if ( is_absolute_path(lpCmdBegin) )
	{
		//
		// 绝对路径
		// 支持不加引号的命令行如 C:\Program Files\ASUS\Power4 Gear\BatteryLife.exe 1
		//
		TCHAR szCmdBuff[MAX_PATH + 10];
		LPCTSTR lpCmdEnd = NULL, lpCmdEnd_Last = NULL;

		m_szCmd[0] = 0;

		if ( bQuotation )
		{
			lpCmdEnd = _tcschr(lpCmdBegin, _T('\"'));
			if ( fix_path_separator(szCmdBuff, MAX_PATH, lpCmdBegin, lpCmdEnd - lpCmdBegin) &&
				ExpandExtNames(szCmdBuff, lpExtNames)
				)
			{
				MyGetLongPathName(szCmdBuff, m_szCmd, MAX_PATH);

				lpCmdEnd = skip_quotation(lpCmdEnd);
				lpCmdEnd = skip_blank(lpCmdEnd);
			}
		}
		else
		{
			lpCmdEnd = skip_no_blank(lpCmdBegin);
			lpCmdEnd_Last = lpCmdEnd;

			while ( TRUE )
			{
				if ( !fix_path_separator(szCmdBuff, MAX_PATH, lpCmdBegin, lpCmdEnd - lpCmdBegin) )
				{
					break;
				}

				if ( ExpandExtNames(szCmdBuff, lpExtNames) )
				{
					lpCmdEnd_Last = lpCmdEnd;
					MyGetLongPathName(szCmdBuff, m_szCmd, MAX_PATH);
				}

				lpCmdEnd = skip_blank(lpCmdEnd);
				if ( *lpCmdEnd == 0 ) 
				{
					break;
				}

				lpCmdEnd = skip_no_blank(lpCmdEnd);
			}

			lpCmdEnd = lpCmdEnd_Last;
		}

		if ( m_szCmd[0] != 0 )
		{
			ExpandParam(lpCmdEnd);
			bResult = TRUE;
		}
	}

	return bResult;
}

// 展开相对路径
LPTSTR CCmdLineParser::ExpandRelative(LPCTSTR lpCmdBegin, LPCTSTR lpCurDir, BOOL bQuotation)
{
	LPTSTR	lpFileNameOffset, lpFileNameOffsetEnd;
	LPTSTR	lpDirOffset;
	BOOL	bJmpDir;
	TCHAR	szTempBuff[MAX_PATH + 10];
	LPCTSTR lpCmdEnd = NULL, lpCmdEnd_Last = NULL;
	LPTSTR	lpCmdBuff = NULL;

	if ( lpCurDir == NULL )
	{
		// 取得当前路径
		GetCurrentDirectory(MAX_PATH, m_szCmd);
	}
	else
	{
		fix_path_separator(m_szCmd, MAX_PATH, lpCurDir);
	}

	lpFileNameOffset = m_szCmd + _tcslen(m_szCmd);
	lpFileNameOffsetEnd = m_szCmd + MAX_PATH;
	if ( lpFileNameOffset[-1] == _T('\\') )
	{
		*--lpFileNameOffset = 0;
	}

	if ( bQuotation )
	{
		lpCmdEnd = _tcschr(lpCmdBegin, _T('\"'));
		if ( lpCmdEnd == NULL )
		{
			goto _Failed_Exit;
		}
	}
	else
	{
		lpCmdEnd = skip_no_blank(lpCmdBegin);
	}

	if ( !fix_path_separator(szTempBuff, MAX_PATH, lpCmdBegin, lpCmdEnd - lpCmdBegin) )
	{
		goto _Failed_Exit;
	}

	// ../../a.exe
	// ./a.exe
	// ./../a.exe
	// a/../a.exe
	// ../a/2.exe
	bJmpDir = TRUE;
	lpDirOffset = szTempBuff;
	
	// 搜索几种相对路径
	while ( *lpDirOffset != 0 )
	{
		if ( lpFileNameOffset >= lpFileNameOffsetEnd )
		{
			// 缓冲区不够
			goto _Failed_Exit;
		}

		if ( lpDirOffset[0] == _T('.') )
		{
			if ( lpDirOffset[1] == _T('.') && lpDirOffset[2] == _T('\\') )
			{
				lpFileNameOffset = (LPTSTR)re_strchr(m_szCmd, lpFileNameOffset, _T('\\'));
				if ( lpFileNameOffset == NULL )
				{
					// Bad Command Line
					goto _Failed_Exit;
				}

				*lpFileNameOffset = 0;
				lpDirOffset += 3;

				bJmpDir = TRUE;
				continue;
			}
			else if ( is_path_separator_char(lpDirOffset[1]) )
			{
				lpDirOffset += 2;

				bJmpDir = TRUE;
				continue;
			}
		}
		else if ( lpDirOffset[0] == _T('\\') )
		{
			lpDirOffset++;

			bJmpDir = TRUE;
			continue;
		}

		if ( bJmpDir )
		{
			bJmpDir = FALSE;
			*lpFileNameOffset++ = _T('\\');
		}

		*lpFileNameOffset++ = *lpDirOffset++;
		*lpFileNameOffset = 0;
	}

	if ( !bJmpDir )
	{
		size_t dwLen1 = _tcslen(m_szCmd);

		lpCmdBuff = new TCHAR[dwLen1 +  _tcslen(lpCmdEnd) + 2];
		if ( lpCmdBuff != NULL )
		{
			_tcscpy(lpCmdBuff, m_szCmd);
			if ( lpCmdBuff[dwLen1 - 1] == _T('\\') )
			{
				dwLen1--;
			}

			_tcscpy(lpCmdBuff + dwLen1, lpCmdEnd);
		}
	}

_Failed_Exit:
	return lpCmdBuff;
}

// 命令行解析
BOOL CCmdLineParser::DoParser(LPCTSTR lpCmdLine,
							  LPCTSTR lpCurDir, 
							  LPCTSTR lpEnvVars, 
							  LPCTSTR lpExtNames,
							  LPCTSTR lpParentPath
							  )
{
	BOOL	bResult = FALSE;
	LPCTSTR	lpCmdBegin = NULL;
	BOOL	bQuotation = FALSE;
	
	m_szCmd[0] = 0;

    if (m_lpParam != NULL)
    {
        delete[] m_lpParam;
        m_lpParam = NULL;
    }

	if ( is_empty_str(lpCmdLine) ) return FALSE;
	if ( is_empty_str(lpParentPath) ) lpParentPath = NULL;
	if ( is_empty_str(lpCurDir) ) lpCurDir = NULL;
	if ( is_empty_str(lpEnvVars) ) lpEnvVars = NULL;
	if ( is_empty_str(lpExtNames) ) lpExtNames = NULL;

	/*
	1、The directory from which the application loaded. 
	2、The current directory for the parent process. 
	3、The 32-bit Windows system directory. Use the GetSystemDirectory function to get the path of this directory.
	Windows Me/98/95:  The Windows system directory. Use the GetSystemDirectory function to get the path of this directory.
	4、The 16-bit Windows system directory. There is no function that obtains the path of this directory, but it is searched. The name of this directory is System. 
	5、The Windows directory. Use the GetWindowsDirectory function to get the path of this directory. 
	6、The directories that are listed in the PATH environment variable. Note that this function does not search the per-application path specified by the App Paths registry key. To include this per-application path in the search sequence, use the ShellExecute function. 
	*/
	lpCmdBegin = skip_blank(lpCmdLine);
	if ( *lpCmdBegin == _T('\"') )
	{
		lpCmdBegin = skip_quotation(lpCmdBegin);
		bQuotation = TRUE;
	}

	if ( (m_dwFlag & DEF_EXT_NAME) && lpExtNames == NULL )
	{
		// 默认扩展名
		lpExtNames = _T("bat;cmd;exe;pif");
	}

	if ( _tcsnicmp(lpCmdBegin, _T("\\??\\"), 4) == 0 )
	{
		lpCmdBegin += 4;
	}

	if ( _tcsnicmp(lpCmdBegin, _T("file://"), 7) == 0 )
	{
		if ( lpCmdBegin[8] == _T(':') )
		{
			lpCmdBegin += 7;
		}
	}

	/*
		宏展开
	*/
	if ( *lpCmdBegin == _T('%') )
	{
		LPTSTR lpCmdBuff = ExpandMacro(lpCmdBegin);
		if ( lpCmdBuff != NULL )
		{
			bResult = ExpandAbsolute(lpCmdBuff, lpExtNames, bQuotation);

			delete lpCmdBuff;
			lpCmdBuff = NULL;
		}
		
		goto _Exit;
	}
	
	/*
		绝对路径展开
	*/
	if ( is_absolute_path(lpCmdBegin) )
	{
		bResult = ExpandAbsolute(lpCmdBegin, lpExtNames, bQuotation);
		goto _Exit;
	}

	/*
		相对路径转换
	*/
	if ( (lpCurDir != NULL) || (m_dwFlag & DEF_CUR_DIR) )
	{
		LPTSTR lpCmdBuff = ExpandRelative(lpCmdBegin, lpCurDir, bQuotation);
		if ( lpCmdBuff != NULL )
		{
			bResult = ExpandAbsolute(lpCmdBuff, lpExtNames, bQuotation);

			delete lpCmdBuff;
			lpCmdBuff = NULL;

			if ( bResult )
			{
				goto _Exit;
			}
		}
	}
	
	/*
		二次宏展开
	*/
	if ( m_dwFlag & DEF_ENV_VAR )
	{
		LPTSTR lpCmdBuff = ExpandMacro2(lpCmdBegin);
		if ( lpCmdBuff != NULL )
		{
			bResult = ExpandAbsolute(lpCmdBuff, lpExtNames, bQuotation);
			
			delete lpCmdBuff;
			lpCmdBuff = NULL;

			if ( bResult )
			{
				goto _Exit;
			}
		}
	}

	/*
		在父程序目录下查找
	*/
	if ( lpParentPath != NULL )
	{
		if ( MyGetLongPathName(lpParentPath, m_szCmd, MAX_PATH) != 0 )
		{
			LPTSTR lpFileName = (LPTSTR)get_file_name(m_szCmd);
			*lpFileName = 0;
			DWORD dwLen2 = (DWORD)_tcslen(m_szCmd);

			LPTSTR lpCmdBuff = new TCHAR[dwLen2 + _tcslen(lpCmdBegin) + 2];
			if ( lpCmdBuff != NULL )
			{
				_tcscpy(lpCmdBuff, m_szCmd);
				if ( lpCmdBuff[dwLen2 - 1] != _T('\\') )
				{
					lpCmdBuff[dwLen2++] = _T('\\');
				}
				_tcscpy(lpCmdBuff + dwLen2, lpCmdBegin);
				//MessageBox(0, lpCmdBuff, NULL, 0);

				bResult = ExpandAbsolute(lpCmdBuff, lpExtNames, bQuotation);
				
				delete lpCmdBuff;
				lpCmdBuff = NULL;

				if ( bResult )
				{
					goto _Exit;
				}
			}
		}
	}

	/*
	环境变量中查找
	*/
	if ( lpEnvVars != NULL || (m_dwFlag & DEF_ENV_VAR) )
	{
		LPCTSTR lpCmdEnd = NULL;

		if ( bQuotation )
		{
			lpCmdEnd = _tcschr(lpCmdBegin, _T('\"'));
			if ( lpCmdEnd == NULL )
			{
				goto _Exit;
			}
		}
		else
		{
			lpCmdEnd = skip_no_blank(lpCmdBegin);
		}

		if ( !fix_path_separator(m_szCmd, MAX_PATH, lpCmdBegin, lpCmdEnd - lpCmdBegin) )
		{
			goto _Exit;
		}

		if ( !is_relative_path(m_szCmd) )
		{
			bResult = ExpandEnvVars(m_szCmd, lpEnvVars, lpExtNames);
			if ( bResult )
			{
				ExpandParam(lpCmdEnd);
			}
		}
	}

_Exit:
	if ( !bResult )
	{
		m_szCmd[0] = 0;
	}

	return bResult;
}


// 从命令行获得文件列表
// 针对几种可能有列表的命令行
// 如rundll32.exe wscript.exe等
//DWORD GetFileListFromCmd(CCmdLineParser& cmdParser, CAtlArray<CString>& fileArray, LPCTSTR lpCurDir)
DWORD GetFileListFromCmd(CCmdLineParser& cmdParser, QVector<QString>& fileArray, LPCTSTR lpCurDir)
{
	LPCTSTR lpCmd, lpParam;
	if ( (lpCmd = cmdParser.GetCmd()) != NULL && (lpParam = cmdParser.GetParam()) != NULL )
	{
		LPCTSTR lpFileName = _tcsrchr(lpCmd, _T('\\'));
		if ( lpFileName != NULL )
		{
			lpFileName++;
			if ( _tcsicmp(lpFileName, _T("rundll32.exe")) == 0 )
			{
				CCmdLineParser a((DWORD)0);
				if ( a.DoParser(lpParam, lpCurDir, NULL, _T("dll")) )
				{
					//fileArray.Add(a.GetCmd());
					fileArray.append(QString::fromStdWString(a.GetCmd()));
				}//
			}
			else if ( _tcsicmp(lpFileName, _T("wscript.exe")) == 0 ||
				_tcsicmp(lpFileName, _T("cscript.exe")) == 0
				)
			{
				LPCTSTR lpStr = lpParam;
				while ( *lpStr != 0 )
				{
					lpStr = skip_blank(lpStr);
					if ( *lpStr == _T('/') || *lpStr == _T('-') )
					{
						lpStr = skip_no_blank(lpStr);
					}
					else//
					{
						CCmdLineParser a((DWORD)0);
						if ( a.DoParser(lpStr, lpCurDir, NULL, _T("wsh;vbs;vbe;")) )
						{
							//fileArray.Add(a.GetCmd());
							fileArray.append(QString::fromStdWString(a.GetCmd()));
						}
						break;
					}//
				}
			}
			else if ( _tcsicmp(lpFileName, _T("cmd.exe")) == 0 )
			{
				LPCTSTR lpStr = lpParam;
				while ( *lpStr != 0 )
				{
					lpStr = skip_blank(lpStr);
					if ( *lpStr == _T('/') || *lpStr == _T('-') )
					{
						lpStr = skip_no_blank(lpStr);
					}
					else
					{
						CCmdLineParser a((DWORD)0);
						if ( a.DoParser(lpStr, lpCurDir, NULL, _T("bat;cmd;exe;")) )
						{
							//fileArray.Add(a.GetCmd());
							fileArray.append(QString::fromStdWString(a.GetCmd()));
							GetFileListFromCmd(a, fileArray, lpCurDir);
						}
						break;
					}
				}
			}
			else if ( _tcsicmp(lpFileName, _T("regsvr32.exe")) == 0 )
			{
				LPCTSTR lpStr = lpParam;
				while ( *lpStr != 0 )
				{
					lpStr = skip_blank(lpStr);
					if ( *lpStr == _T('/') || *lpStr == _T('-') )
					{
						lpStr = skip_no_blank(lpStr);
					}
					else
					{
						CCmdLineParser a((DWORD)0);
						if ( a.DoParser(lpStr, lpCurDir) )
						{
							//fileArray.Add(a.GetCmd());
							fileArray.append(QString::fromStdWString(a.GetCmd()));
						}
						break;
					}
				}
			}
		}
	}

	// 返回总数
	//return (DWORD)fileArray.GetCount();
	return (DWORD) fileArray.count();

}