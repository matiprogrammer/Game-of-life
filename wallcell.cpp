#include "wallcell.h"

WallCell::WallCell():Cell(wall, new ClassicStrategy())
{
    nextColor=wall;
}

void WallCell::calculateNextState(vector<Cell *> neightbours)
{

}

bool WallCell::isPoisoned()
{
    return false;
}

bool WallCell::isWall()
{
    return true;
}

void WallCell::changeStateOnClick()
{

}
