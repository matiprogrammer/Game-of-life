#ifndef STRATEGY_H
#define STRATEGY_H
#include <vector>
#include <SimpleCell.h>
class Cell;
using namespace std;
class Strategy
{
public:
    virtual Color calculateNextState(vector<Cell*> neightbours, Color currentState)=0;
    virtual Color changeStateOnClick(Color currentState)=0;
};

#endif // STRATEGY_H
