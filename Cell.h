#ifndef CELL_H
#define CELL_H
#include "Color.h"
#include <QGraphicsItem>
using namespace std;
class Cell
{
private:
    bool isAlive;
    Color color;

public:
    Cell();
    Cell(bool isAlive);
    void computeNextState(int neightboursAlive);
    bool alive();
};
#endif
