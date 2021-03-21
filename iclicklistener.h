#ifndef ICLICKLISTENER_H
#define ICLICKLISTENER_H

#include "SimpleCell.h"
#include "cellgraphics.h"

class CellGraphics;
class IClickListener
{
public:
    virtual void onCellClick(CellGraphics *cellGraphics)=0;
};

#endif // ICLICKLISTENER_H
