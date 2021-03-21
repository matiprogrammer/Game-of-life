#include "cellgraphics.h"

#include <QDebug>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QGraphicsScene>
CellGraphics::CellGraphics(int xPos, int yPos,int height, int width,  Cell* cell)
{
    this->rect=QRect(xPos,yPos,width,height);
    this->cell=cell;

}

CellGraphics::CellGraphics(QRect rect, Cell *cell,IClickListener* clickListener)
{
    this->rect=rect;
    this->cell=cell;
    this->clickListener=clickListener;
    this->setAcceptHoverEvents(true);
    this->setAcceptDrops(true);

    // setCacheMode(CacheMode::ItemCoordinateCache);
}

QRectF CellGraphics::boundingRect() const
{
    return this->rect;
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
    case yellow:
        painter->setBrush(Qt::yellow);
        break;
    case  green:
        painter->setBrush(Qt::green);
        break;
    case  blue:
        painter->setBrush(Qt::blue);
        break;
    case  red:
        painter->setBrush(Qt::red);
        break;
    case wall:
        painter->setBrush(Qt::black);
        painter->drawEllipse(rect);
        break;
    }


    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());
}

Cell *CellGraphics::getCell()
{
    return this->cell;
}

void CellGraphics::setCell(Cell* cell)
{
    this->cell=cell;
}



void CellGraphics::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{


}

void CellGraphics::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{

}

void CellGraphics::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}

void CellGraphics:: mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->clickListener->onCellClick(this);
    update();
}

void CellGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void CellGraphics::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{

}
