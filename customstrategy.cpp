#include "customstrategy.h"

CustomStrategy::CustomStrategy(int numberOfCellsWhenStillLive, int numberOfCellsWhenStillDead, int numberOfCellsThenBorn, int numberOfCellsThenDie)
{
    this->numberOfCellsWhenStillLive= numberOfCellsWhenStillLive;
    this->numberOfCellsWhenStillDead= numberOfCellsWhenStillDead;
    this->numberOfCellsThenBorn= numberOfCellsThenBorn;
    this->numberOfCellsThenDie= numberOfCellsThenDie;
}

Color CustomStrategy::calculateNextState(vector<Cell *> neightbours, Cell *cell)
{
    int neightboursAlive=0;
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        if(neightbours.at(i)->getState()!=white)
        {
            neightboursAlive++;
        }
    }
    if(cell->getState()==black && neightboursAlive==numberOfCellsWhenStillLive)
    {
        return black;
    }
    if(cell->getState()==black && neightboursAlive==numberOfCellsThenDie)
    {
        return white;
    }
    if(cell->getState()==white && neightboursAlive==numberOfCellsThenBorn)
    {
        return black;
    }
    if(cell->getState()==white && neightboursAlive==numberOfCellsWhenStillDead)
    {
        return white;
    }
    return cell->getState();
}
