#include "poisonedcell.h"

PoisonedCell::PoisonedCell():Cell(poisoned)
{

}

bool PoisonedCell::isPoisoned()
{
    return true;
}

bool PoisonedCell::isWall()
{
    return false;
}
