#pragma once

#include <atlconv.h>
#include <QString>
#include <QVector>
class CCmdLineParser2 
{
public:
	CCmdLineParser2(LPCTSTR lpCmdLine )
	{
		//USES_CONVERSION;

		int	iCount = 0;

#ifdef _UNICODE
		LPWSTR* lpArray = CommandLineToArgvW(lpCmdLine,&iCount);
#else
		LPWSTR* lpArray = CommandLineToArgvW( A2W(lpCmdLine) ,&iCount);
#endif

		if (lpArray != NULL && iCount>0)
		{
#ifdef _UNICODE
			m_strAppPath = QString::fromStdWString(lpArray[0]);
#else
			m_strAppPath = W2A(lpArray[0]);
#endif
			for ( int i=1; i < iCount; i++)
			{
#ifdef _UNICODE
				m_listArgv.append(QString::fromStdWString(lpArray[i]));
#else
				m_listArgv.Add(QString::fromStdString(W2A(lpArray[i]));
#endif
			
			}
		
			::GlobalFree(lpArray);
		}
	}

	virtual ~CCmdLineParser2()
	{

	}

	QString& GetAppPath()
	{
		return m_strAppPath;
	}

	QString GetAppPathStr()
	{
		return m_strAppPath;
	}

	int GetArgvCount()
	{
		return m_listArgv.count();
	}

	QString GetArgv(int i)
	{
		return m_listArgv[i];
	}

protected:
	
	QVector<QString>        m_listArgv;
	QString					m_strAppPath;
};
