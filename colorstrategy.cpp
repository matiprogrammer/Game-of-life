#include "SimpleCell.h"
#include "colorstrategy.h"

Color ColorStrategy::getColorOneUnitLarger(Color color)
{
    switch (color) {
    case black:
        return yellow;
    case yellow:
        return green;
    case green:
        return blue;
    case blue:
        return red;
    case red:
        return yellow;
    default:
        return yellow;
    }
}

ColorStrategy::ColorStrategy()
{

}

Color ColorStrategy::calculateNextState(vector<Cell *> neightbours, Cell* cell)
{
    int neightboursCauseChange=0;
    Color colorWhichCasueChange=getColorOneUnitLarger(cell->getState());
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        if(neightbours.at(i)->getState()==colorWhichCasueChange)
        {
            neightboursCauseChange++;
        }
    }
    if(neightboursCauseChange>0)
    {
        return colorWhichCasueChange;
    }
    else
    {
        return cell->getState();
    }
}

Color ColorStrategy::changeStateOnClick(Cell* cell){
    return getColorOneUnitLarger(cell->getState());
}

Color ColorStrategy::drawState(Cell* cell)
{
    int random=rand()%5;
    switch (random) {
    case 0:
        return white;
        break;
    case 1:
        return red;
        break;
    case 2:
        return yellow;
        break;
    case 3:
        return green;
        break;
    case 4:
        return blue;
        break;

    }
    return white;
}

list<QString> ColorStrategy::getPossibleCellTypes()
{
    list<QString> possibleCellTypes;
    possibleCellTypes.push_back("kolorowa");
    return possibleCellTypes;
}

Cell *ColorStrategy::getCell(QString &cellType)
{
    return new SimpleCell(yellow);
}
