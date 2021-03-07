#ifndef STRATEGY_H
#define STRATEGY_H
#include <vector>
#include <SimpleCell.h>
class SimpleCell;
using namespace std;
class Strategy
{
public:
    virtual Color calculateNextState(vector<SimpleCell> neightbours, Color currentState)=0;
    virtual Color onCellClick(Color currentState)=0;
};

#endif // STRATEGY_H
