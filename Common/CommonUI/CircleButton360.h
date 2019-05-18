#pragma once
#include <QGraphicsWidget>
#include <QPixmap>
#include <QPainterPath>
#include <QLinearGradient>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QGraphicsView>
class CircleBut360 : public QGraphicsView
{
  Q_OBJECT
public:
  CircleBut360(QString filename, QGraphicsView *parent = 0)
    : QGraphicsView(parent)
  {
   // setAcceptHoverEvents(true);
   // setCacheMode(DeviceCoordinateCache);
    _pix = QPixmap(filename);
  }

  QRectF boundingRect() const
  {
    return QRectF(-65, -65, 130, 130);
  }

  QPainterPath shape() const
  {
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
  }
  
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *);
  
signals:
  void pressed();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *)
  {
    emit pressed();
    update();
  }

  void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
  {
    update();
  }

private:
  QPixmap _pix;
};
