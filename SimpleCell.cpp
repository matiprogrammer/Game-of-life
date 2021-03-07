#include <iostream>
#include "SimpleCell.h"
using namespace std;

SimpleCell::SimpleCell(Color color)
{
    this->currentColor=color;
}

void SimpleCell::setNextState(Color color)
{
    this->nextColor=color;
}

void SimpleCell::setState(Color color)
{
    this->currentColor=color;
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

Color SimpleCell::getColor()
{
    return this->currentColor;
}








