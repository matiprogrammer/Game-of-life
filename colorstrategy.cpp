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
