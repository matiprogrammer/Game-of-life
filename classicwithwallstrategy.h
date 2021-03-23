#ifndef CLASSICWITHWALLSTRATEGY_H
#define CLASSICWITHWALLSTRATEGY_H

#include "strategy.h"

class ClassicWithWallStrategy : public Strategy
{
public:
    ClassicWithWallStrategy();

    // Strategy interface
public:
    virtual Color calculateNextState(vector<Cell *> neightbours,Cell* cell) override;
    virtual Color changeStateOnClick(Cell* cell) override;
    virtual Color drawState(Cell* cell) override;

    // Strategy interface
public:
    virtual list<QString> getPossibleCellTypes() override;

    // Strategy interface
public:
    virtual Cell *getCell(QString &cellType) override;
};

#endif // CLASSICWITHWALLSTRATEGY_H
