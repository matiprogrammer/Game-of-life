#ifndef CELL_H
#define CELL_H
#include <vector>
#include <Color.h>
#include "strategy.h"
class Strategy;

using namespace std;
class Cell
{
    protected:
    Color currentColor, nextColor;
    Strategy* strategy;
public:
    virtual ~Cell();
    Cell(Color color, Strategy* strategy);
    virtual void calculateNextState(vector<Cell*> neightbours)=0;
    virtual void updateState();
    virtual bool isPoisoned()=0;
    virtual bool isWall()=0;
    virtual Color getState();
    virtual void changeStrategy(Strategy *strategy);
    virtual void changeStateOnClick()=0;
    virtual void drawState();
};

#endif // CELL_H
