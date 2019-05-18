#pragma once
#include <QListWidgetItem>
#include <QPainter>
class SaftUI;
class ListWidthItem :public QListWidgetItem
{
public:
	ListWidthItem(const QIcon &icon, const QString &text,
		QListWidget *view = 0, int type = Type);
	~ListWidthItem(void);
	void SetPress(bool bEnable);
	void SetOver(bool bEnable);
    void painter();
	void SetMainFrom(SaftUI* MainFrom) {m_MainFrom = MainFrom;}
	void SetPicture(QString picture) {m_sPicture = picture;}
	QString GetPicture() {return m_sPicture;};

private:
	bool m_bOver;
	bool m_bPress;
	SaftUI* m_MainFrom;
	QString m_sPicture;
};
