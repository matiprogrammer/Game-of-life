#include "classicstrategy.h"

ClassicStrategy::ClassicStrategy()
{

}

Color ClassicStrategy::calculateNextState(vector<Cell*> neightbours, Color currentState)
{
    int neightboursAlive=0;
    for(unsigned long long i=0;i<neightbours.size();i++)
    {
        if(neightbours.at(i)->getState()!=white)
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

Color ClassicStrategy::changeStateOnClick(Color currentState)
{
    if(currentState==white)
        return black;
    else
        return white;
}

