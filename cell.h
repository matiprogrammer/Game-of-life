#ifndef CELL_H
#define CELL_H
#include <vector>
#include <Color.h>
#include "strategy.h"
class Strategy;

using namespace std;
class Cell
{
private:
    int width, height;
protected:
    Color currentColor, nextColor;
public:
    virtual ~Cell();
    Cell(Color color);
    void updateState();
    virtual bool isPoisoned()=0;
    virtual bool isWall()=0;
    Color getState();
    void setNextState(Color color);
};

#endif // CELL_H
