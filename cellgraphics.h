#ifndef CELLGRAPHICS_H
#define CELLGRAPHICS_H
#include <QRect>
#include <SimpleCell.h>
#include <QGraphicsItem>
#include <iclicklistener.h>



class CellGraphics:public QGraphicsItem
{
private:
    QRect rect;
    SimpleCell *cell;
    IClickListener* clickListener;
public:
    CellGraphics(int xPos, int yPos, int height, int width, SimpleCell* cell);
    CellGraphics(QRect rect, SimpleCell* cell, IClickListener* clickListener);
    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CELLGRAPHICS_H
