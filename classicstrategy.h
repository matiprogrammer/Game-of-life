#ifndef CLASSICSTRATEGY_H
#define CLASSICSTRATEGY_H

#include "strategy.h"
#include<vector>
class ClassicStrategy : public Strategy
{
public:
    ClassicStrategy();

    // Strategy interface
public:
    virtual Color calculateNextState(vector<SimpleCell> neightbours, Color currentState) override;
    virtual Color onCellClick(Color currentState) override;
};

#endif // CLASSICSTRATEGY_H
