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
    virtual Color calculateNextState(vector<Cell *> neightbours, Color currentState) override;
    virtual Color changeStateOnClick(Color currentState) override;
    virtual Color drawState() override;
};

#endif // COLORSTRATEGY_H
