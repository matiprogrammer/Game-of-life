#include "pattern.h"

#include <QPainter>

Pattern::Pattern(QRect rect)
{
    this->rect=rect;
    this->rows=9;
    this->columns=9;

    for (int i = 0; i < rows; i++)
    {
        this->pattern.emplace_back(vector<shared_ptr<Cell>>());
        vector<vector<std::shared_ptr<Cell>>>::iterator iter1 = --(pattern.end());

        (*iter1).emplace_back(new SimpleCell(white));
        (*iter1).emplace_back(new SimpleCell(black));
        (*iter1).emplace_back(new SimpleCell(white));
        (*iter1).emplace_back(new SimpleCell(black));
        (*iter1).emplace_back(new SimpleCell(white));
        (*iter1).emplace_back(new SimpleCell(black));
        (*iter1).emplace_back(new SimpleCell(white));
        (*iter1).emplace_back(new SimpleCell(black));
        (*iter1).emplace_back(new SimpleCell(white));
        iter1++;
    }
}

std::vector<std::vector<std::shared_ptr<Cell> > > Pattern::getPattern()
{
    return this->pattern;
}

QRectF Pattern::boundingRect() const
{
    return this->rect;
}

void Pattern::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int rectWidth= (this->rect.width()-columns-1)/columns;
    int rectHeight=(this->rect.height()-rows-1)/rows;

    painter->setPen(Qt::black);
    for(int i=0;i<this->columns*rectWidth+(1*this->columns);i+=rectWidth+1)
    {
        for(int j=0;j<this->rows*rectHeight+(1*this->rows);j+=rectHeight+1)
        {
            int yPos=j/(rectWidth+1);
            int xPos=i/(rectHeight+1);

            if(pattern.at(xPos).at(yPos).get()->getState()==white)
                painter->setBrush(Qt::white);
            else
                painter->setBrush(Qt::black);
            painter->drawRect(i,j,i+rectWidth,j+rectHeight);
        }
    }

}
