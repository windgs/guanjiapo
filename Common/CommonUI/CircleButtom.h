#pragma once
#include <QPushButton>
#include <QString>
class CircleButton : public QPushButton
{
   Q_OBJECT
public:
   CircleButton(QString text,QString backgroup, QWidget * parent = 0);
   virtual ~CircleButton();
   virtual void paintEvent ( QPaintEvent * event );
   void SetBackGroup(QString backgroup);
private:
   QString m_backgroup;
};