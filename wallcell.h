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
    virtual void calculateNextState(vector<Cell *> neightbours) override;
    virtual bool isPoisoned() override;
    virtual bool isWall() override;
    virtual void changeStateOnClick() override;
};

#endif // WALLCELL_H
