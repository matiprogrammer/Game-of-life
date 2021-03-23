#include "SimpleCell.h"
#include "classicwithwallstrategy.h"
#include "poisonedcell.h"
#include "wallcell.h"

ClassicWithWallStrategy::ClassicWithWallStrategy()
{

}

Color ClassicWithWallStrategy::calculateNextState(vector<Cell *> neightbours, Cell* cell)
{
    if(cell->isWall())
    {
        return wall;
    }

    if(cell->isPoisoned())
    {
        return poisoned;
    }

    int neightboursAlive=0;
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        Cell* neightbour=neightbours.at(i);
        if(neightbour->getState()!=white && neightbour->getState()!=wall && neightbour->getState()!=poisoned)
        {
            neightboursAlive++;
        }
        else if(neightbour->getState()==poisoned)
        {
            return white;
        }
    }

    if((cell->getState()==white && neightboursAlive==3)||(cell->getState()!=white && (neightboursAlive==2|| neightboursAlive==3)))
    {
        return black;
    }
    else
    {
        return white;
    }
}

Color ClassicWithWallStrategy::changeStateOnClick(Cell* cell)
{
    if(cell->getState()==wall)
        return wall;
    else if(cell->getState()==poisoned)
        return poisoned;
    else if(cell->getState()==white)
        return black;
    else
        return white;
}

Color ClassicWithWallStrategy::drawState(Cell* cell)
{
    if(cell->isWall())
        return wall;
    else if(cell->isPoisoned())
        return poisoned;

    int random=rand()%2;
    switch (random) {
    case 0:
        return white;
        break;
    default:return black;
    }

    return wall;
}

list<QString> ClassicWithWallStrategy::getPossibleCellTypes()
{
    list<QString> possibleCellTypes;
    possibleCellTypes.push_back("ściana");
    possibleCellTypes.push_back("zatruta");
    possibleCellTypes.push_back("zwykła");
    return possibleCellTypes;
}

Cell *ClassicWithWallStrategy::getCell(QString &cellType)
{
    if(cellType=="ściana")
        return new WallCell();
    else if(cellType=="zatruta")
        return new PoisonedCell();
    else
        return new SimpleCell();
}
