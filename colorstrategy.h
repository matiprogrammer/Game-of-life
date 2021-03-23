#ifndef COLORSTRATEGY_H
#define COLORSTRATEGY_H

#include "strategy.h"

class ColorStrategy : public Strategy
{
private:
    Color getColorOneUnitLarger(Color color);
public:
    ColorStrategy();

    // Strategy interface
public:
    virtual Color calculateNextState(vector<Cell *> neightbours, Cell* cell) override;
    virtual Color changeStateOnClick(Cell* cell) override;
    virtual Color drawState(Cell* cell) override;

    // Strategy interface
public:
    virtual list<QString> getPossibleCellTypes() override;

    // Strategy interface
public:
    virtual Cell *getCell(QString &cellType) override;
};

#endif // COLORSTRATEGY_H
