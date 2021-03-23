#ifndef STRATEGY_H
#define STRATEGY_H
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Color.h"
#include <list>
#include "cell.h"
#include <QString>

class Cell;
using namespace std;
class Strategy
{
public:
    virtual ~Strategy();
    Strategy();
    virtual Color calculateNextState(vector<Cell*> neightbours, Cell* cell)=0;
    virtual Color changeStateOnClick(Cell* cell)=0;
    virtual Color drawState(Cell *cell)=0;
    virtual list<QString> getPossibleCellTypes()=0;
    virtual Cell* getCell(QString &cellType)=0;
};

#endif // STRATEGY_H
