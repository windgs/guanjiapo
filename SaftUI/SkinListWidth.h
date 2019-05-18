#pragma once
#include <QListWidget>
class SaftUI;
class SkinListWidth : public QListWidget
{
	Q_OBJECT
public:
	SkinListWidth(QWidget *parent = 0);
	~SkinListWidth(void);
	void SetFrom(SaftUI* From) { m_MainFrom = From;}
public slots:
 void OnClickItem(QListWidgetItem* item);

protected:
	//virtual void    paintEvent (QPaintEvent *event);
	virtual void	enterEvent ( QEvent * event );
	virtual void	leaveEvent ( QEvent * event );
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void moveEvent ( QMoveEvent * event );
private:
	SaftUI*  m_MainFrom;
};
