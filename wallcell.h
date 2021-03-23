#ifndef WALLCELL_H
#define WALLCELL_H
#include "Color.h"
#include "classicstrategy.h"
#include "cell.h"

class WallCell : public Cell
{
public:
    WallCell();

    // Cell interface
public:
    virtual bool isPoisoned() override;
    virtual bool isWall() override;

};

#endif // WALLCELL_H
