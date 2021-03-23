#include "cell.h"



Cell::~Cell()
{

}

Cell::Cell(Color color)
{
    this->currentColor=color;
    this->width=width;
    this->height=height;
}


Color Cell::getState()
{
    return this->currentColor;
}

void Cell::setNextState(Color color)
{
    this->nextColor=color;
}

void Cell::updateState()
{
    this->currentColor=this->nextColor;
}

