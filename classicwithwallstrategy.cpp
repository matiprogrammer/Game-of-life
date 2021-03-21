#include "classicwithwallstrategy.h"

ClassicWithWallStrategy::ClassicWithWallStrategy()
{

}

Color ClassicWithWallStrategy::calculateNextState(vector<Cell *> neightbours, Color currentState)
{
    int neightboursAlive=0;
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        if(neightbours.at(i)->getState()!=white && neightbours.at(i)->getState()!=wall )
        {
            neightboursAlive++;
        }
    }
    if((currentState==white && neightboursAlive==3)||(currentState!=white && (neightboursAlive==2|| neightboursAlive==3)))
    {
        return black;
    }
    else
    {
        return white;
    }
}

Color ClassicWithWallStrategy::changeStateOnClick(Color currentState)
{
    if(currentState==white)
        return black;
    else if(currentState==wall)
        return wall;
    else
        return white;
}

Color ClassicWithWallStrategy::drawState()
{
    return wall;
}
