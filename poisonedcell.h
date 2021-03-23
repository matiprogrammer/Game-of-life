#ifndef POISONEDCELL_H
#define POISONEDCELL_H

#include "cell.h"

class PoisonedCell : public Cell
{
public:
    PoisonedCell();

    // Cell interface
public:
    virtual bool isPoisoned() override;
    virtual bool isWall() override;
};

#endif // POISONEDCELL_H
