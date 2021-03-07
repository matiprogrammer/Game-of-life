#include "cellgraphics.h"

#include <QDebug>
#include <QPainter>

CellGraphics::CellGraphics(int xPos, int yPos,int height, int width,  SimpleCell* cell)
{
    this->rect=QRect(xPos,yPos,width,height);
    this->cell=cell;

}

CellGraphics::CellGraphics(QRect rect, SimpleCell *cell,IClickListener* clickListener)
{
    this->rect=rect;
    this->cell=cell;
    this->clickListener=clickListener;
}

QRectF CellGraphics::boundingRect() const
{
    return QRectF(this->rect);
}

void CellGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(cell->getState())
    {
    case black:
        painter->setBrush(Qt::black);
        break;
    case white:
        painter->setBrush(Qt::white);
        break;
    }


    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());
}

void CellGraphics:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->clickListener->onClick(this->cell);

    update();
}
