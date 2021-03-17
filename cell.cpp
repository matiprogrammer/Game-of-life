#include "cell.h"



Cell::~Cell()
{

}

Cell::Cell(Color color, Strategy* strategy)
{
    this->currentColor=color;
    this->strategy=strategy;
}
void Cell::changeStrategy(Strategy *strategy)
{
    this->strategy=strategy;
}

void Cell::drawState()
{
    currentColor=this->strategy->drawState();
}

Color Cell::getState()
{
    return this->currentColor;
}

void Cell::updateState()
{
    this->currentColor=this->nextColor;
}

