#include "wallcell.h"

WallCell::WallCell():Cell(wall)
{
    nextColor=wall;
}

bool WallCell::isPoisoned()
{
    return false;
}

bool WallCell::isWall()
{
    return true;
}

