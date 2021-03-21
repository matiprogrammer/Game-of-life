#ifndef CELLGRAPHICS_H
#define CELLGRAPHICS_H
#include <QRect>
#include <cell.h>
#include <iclicklistener.h>
#include <QGraphicsItem>



class IClickListener;
class CellGraphics:public QGraphicsItem
{
private:
    QRectF rect;
    Cell *cell;
    IClickListener* clickListener;
public:
    CellGraphics(int xPos, int yPos, int height, int width, Cell* cell);
    CellGraphics(QRect rect, Cell* cell, IClickListener* clickListener);
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Cell *getCell();
    void setCell(Cell *cell);
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
