#include <iostream>
#include "SimpleCell.h"
using namespace std;

SimpleCell::~SimpleCell()
{

}

SimpleCell::SimpleCell(Color color, Strategy *strategy):Cell(color,strategy)
{
}

void SimpleCell::calculateNextState(vector<Cell*> neightbours)
{
    this->nextColor=strategy->calculateNextState(neightbours,this->currentColor);
}

bool SimpleCell::isPoisoned()
{
    return false;
}

bool SimpleCell::isWall()
{
    return false;
}

void SimpleCell::changeStateOnClick()
{
    this->currentColor=this->strategy->changeStateOnClick(this->currentColor);
}








