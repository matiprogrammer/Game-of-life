#include "cellgraphics.h"

#include <QDebug>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QGraphicsScene>

CellGraphics::CellGraphics(QRect rect,int xPos, int yPos,ICellInfo* cellInfo)
{
    this->rect=rect;
    this->xPos=xPos;
    this->yPos=yPos;
    this->cellInfo=cellInfo;
    this->setAcceptHoverEvents(true);
    this->setAcceptDrops(true);

    // setCacheMode(CacheMode::ItemCoordinateCache);
}

int CellGraphics::getYPos()
{
    return this->yPos;
}

int CellGraphics::getXPos()
{
    return this->xPos;
}

QRectF CellGraphics::boundingRect() const
{
    return this->rect;
}

void CellGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(cellInfo->getColor(this->xPos,this->yPos))
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
        painter->setBrush(Qt::darkGray);
        painter->drawEllipse(rect);
        break;
    case  poisoned:
        painter->setBrush(Qt::darkGreen);
        break;
    }


    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());
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
    this->cellInfo->onCellClick(this);
    update();
}

void CellGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void CellGraphics::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{

}
