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
    virtual Color calculateNextState(vector<Cell*> neightbours, Color currentState) override;
    virtual Color changeStateOnClick(Color currentState) override;
};

#endif // CLASSICSTRATEGY_H
