#ifndef CLASSICWITHWALLSTRATEGY_H
#define CLASSICWITHWALLSTRATEGY_H

#include "strategy.h"

class ClassicWithWallStrategy : public Strategy
{
public:
    ClassicWithWallStrategy();

    // Strategy interface
public:
    virtual Color calculateNextState(vector<Cell *> neightbours, Color currentState) override;
    virtual Color changeStateOnClick(Color currentState) override;
    virtual Color drawState() override;
};

#endif // CLASSICWITHWALLSTRATEGY_H
