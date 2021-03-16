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

Color Cell::getState()
{
    return this->currentColor;
}

void Cell::updateState()
{
    this->currentColor=this->nextColor;
}

