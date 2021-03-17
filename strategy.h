#ifndef STRATEGY_H
#define STRATEGY_H
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Color.h"
#include "cell.h"
class Cell;
using namespace std;
class Strategy
{
public:
    Strategy();
    virtual Color calculateNextState(vector<Cell*> neightbours, Color currentState)=0;
    virtual Color changeStateOnClick(Color currentState)=0;
    virtual Color drawState()=0;
};

#endif // STRATEGY_H
