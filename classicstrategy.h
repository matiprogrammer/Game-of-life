#ifndef CLASSICSTRATEGY_H
#define CLASSICSTRATEGY_H

#include "strategy.h"

class ClassicStrategy : public Strategy
{
public:
    ClassicStrategy();

    // Strategy interface
public:
    virtual Color calculateNextState(vector<Cell*> neightbours, Cell* cell) override;
    virtual Color changeStateOnClick(Cell* cell) override;
    virtual Color drawState(Cell* cell) override;


    // Strategy interface
public:
    virtual list<QString> getPossibleCellTypes() override;

    // Strategy interface
public:
    virtual Cell *getCell(QString &cellType) override;
};

#endif // CLASSICSTRATEGY_H
