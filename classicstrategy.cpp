#include "SimpleCell.h"
#include "classicstrategy.h"

ClassicStrategy::ClassicStrategy()
{
}

Color ClassicStrategy::calculateNextState(vector<Cell*> neightbours, Cell* cell)
{
    int neightboursAlive=0;
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        if(neightbours.at(i)->getState()!=white)
        {
            neightboursAlive++;
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

Color ClassicStrategy::changeStateOnClick(Cell* cell)
{
    if(cell->getState()==white)
        return black;
    else
        return white;
}

Color ClassicStrategy::drawState(Cell* cell)
{
    int random=rand()%2;
    switch (random) {
    case 0:
        return white;
    case 1:
        return black;

    }
    return white;
}

list<QString> ClassicStrategy::getPossibleCellTypes()
{
    list<QString> possibleCellTypes;
    possibleCellTypes.push_back("zwykła");
    return possibleCellTypes;
}

Cell *ClassicStrategy::getCell(QString &cellType)
{
        return new SimpleCell();
}



