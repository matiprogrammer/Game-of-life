#ifndef CELLGRAPHICS_H
#define CELLGRAPHICS_H
#include <QRect>
#include <cell.h>
#include <iclicklistener.h>
#include <QGraphicsItem>



class ICellInfo;
class CellGraphics:public QGraphicsItem
{
private:
    QRectF rect;
    int xPos, yPos;
    ICellInfo* cellInfo;
public:

    CellGraphics(QRect rect, int xPos, int yPos, ICellInfo* cellInfo);
    int getYPos();
    int getXPos();
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
     virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
};

#endif // CELLGRAPHICS_H
