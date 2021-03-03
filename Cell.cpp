#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell()
{
    this->isAlive = false;
    this->color=white;
}

Cell::Cell(bool isAlive)
{
    this->isAlive = isAlive;
}

void Cell::computeNextState(int neightboursAlive)
{

}

bool Cell::alive()
{
    return this->isAlive;
}


