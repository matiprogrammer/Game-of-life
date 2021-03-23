#ifndef CUSTOMSTRATEGY_H
#define CUSTOMSTRATEGY_H

#include "classicstrategy.h"

class CustomStrategy : public ClassicStrategy
{
private:
    int numberOfCellsWhenStillLive,numberOfCellsWhenStillDead,numberOfCellsThenBorn,numberOfCellsThenDie;
public:
    CustomStrategy(int numberOfCellsWhenStillLive, int numberOfCellsWhenStillDead, int numberOfCellsThenBorn, int numberOfCellsThenDie);

    // Strategy interface
public:
    virtual Color calculateNextState(vector<Cell *> neightbours, Cell *cell) override;
};

#endif // CUSTOMSTRATEGY_H
