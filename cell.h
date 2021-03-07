#ifndef CELL_H
#define CELL_H

#include <Color.h>



class Cell
{
public:
    // Cell();
    virtual void computeNextState(int neightboursAlive)=0;
    virtual void updateState()=0;
    virtual Color getColor();
};

#endif // CELL_H
