#pragma once
#include <QLabel>
#include "../Common/DefineCommon.h"
#include "../Common/CommonUI/CommonTitleBar.h"
class ErasePluginTitleBar : public CBaseTitleBar
{
public:
	ErasePluginTitleBar(QWidget  *parent = 0, Qt::WFlags flags = 0);
	virtual ~ErasePluginTitleBar(void);
protected: 
	//virtual void resizeEvent ( QResizeEvent * event ) ;
private:
	//QLabel* m_pLabel;
};
