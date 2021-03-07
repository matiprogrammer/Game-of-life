#include <iostream>
#include "SimpleCell.h"
using namespace std;

SimpleCell::SimpleCell(Color color, Strategy *strategy)
{
    this->currentColor=color;
    this->strategy=strategy;
}

void SimpleCell::calculateNextState(vector<SimpleCell> neightbours)
{
    this->nextColor=strategy->calculateNextState(neightbours,currentColor);
}

void SimpleCell::updateState()
{
    this->currentColor=this->nextColor;
}

bool SimpleCell::isPoisoned()
{
    return false;
}

bool SimpleCell::isWall()
{
    return false;
}

Color SimpleCell::getState()
{
    return this->currentColor;
}

void SimpleCell::changeStrategy(Strategy *strategy)
{
    this->strategy=strategy;
}

void SimpleCell::cellClick()
{
    this->currentColor=this->strategy->onCellClick(this->currentColor);
}








