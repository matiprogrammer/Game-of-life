#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell()
{
    this->isAlive = false;
}

Cell::Cell(bool isAlive)
{
    this->isAlive = isAlive;
}

void Cell::computeNextState(int neightboursAlive)
{
    cout << "obliczam stan komórki";
}

bool Cell::alive()
{
    return this->isAlive;
}