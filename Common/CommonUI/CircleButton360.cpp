#include "CircleButton360.h"
#include <QStyle>
void CircleBut360::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
  bool down = option->state & QStyle::State_Sunken;
  QRectF r = boundingRect();
  QLinearGradient grad(r.topLeft(), r.bottomRight());
  grad.setColorAt(down ? 1 : 0, option->state & QStyle::State_MouseOver ? Qt::white : Qt::lightGray);
  grad.setColorAt(down ? 0 : 1, Qt::darkGray);
  painter->setPen(Qt::darkGray);
  painter->setBrush(grad);
  painter->drawEllipse(r);
  QLinearGradient grad2(r.topLeft(), r.bottomRight());
  grad.setColorAt(down ? 1 : 0, Qt::darkGray);
  grad.setColorAt(down ? 0 : 1, Qt::lightGray);
  painter->setPen(Qt::NoPen);
  painter->setBrush(grad);
  if (down)
    painter->translate(2, 2);
  painter->drawEllipse(r.adjusted(5, 5, -5, -5));
  painter->drawPixmap(-_pix.width()/2, -_pix.height()/2, _pix);
}
