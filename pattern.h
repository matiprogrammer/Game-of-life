#ifndef PATTERN_H
#define PATTERN_H

#include <QGraphicsItem>
#include <vector>
#include <stdlib.h>
#include <cell.h>
#include <SimpleCell.h>

class Pattern : public QGraphicsItem
{
private:
    QRect rect;
    int rows,columns;
    std::vector<std::vector<std::shared_ptr<Cell>>> pattern;
public:
    Pattern(QRect rect);
    std::vector<std::vector<std::shared_ptr<Cell>>> getPattern();

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PATTERN_H
