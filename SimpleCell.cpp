#include <iostream>
#include "SimpleCell.h"
using namespace std;

SimpleCell::~SimpleCell()
{

}

SimpleCell::SimpleCell():Cell(white)
{
}

SimpleCell::SimpleCell(Color color):Cell(color)
{

}

bool SimpleCell::isPoisoned()
{
    return false;
}

bool SimpleCell::isWall()
{
    return false;
}








