#ifndef ICLICKLISTENER_H
#define ICLICKLISTENER_H

#include "SimpleCell.h"
#include "cellgraphics.h"

class CellGraphics;
class ICellInfo
{
public:
    virtual void onCellClick(CellGraphics* cellGraphics)=0;
    virtual Color getColor(int xPos, int yPos)=0;
};

#endif // ICLICKLISTENER_H
