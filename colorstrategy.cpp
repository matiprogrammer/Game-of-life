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

Color ColorStrategy::calculateNextState(vector<Cell *> neightbours, Color currentState)
{
    int neightboursCauseChange=0;
    Color colorWhichCasueChange=getColorOneUnitLarger(currentState);
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
        return currentState;
    }
}

Color ColorStrategy::changeStateOnClick(Color currentState){
    return getColorOneUnitLarger(currentState);
}

Color ColorStrategy::drawState()
{
    int random=rand()%6;
    switch (random) {
    case 0:
        return white;
        break;
    case 1:
        return black;
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
    case 5:
        return red;
        break;
    }
    return white;
}
