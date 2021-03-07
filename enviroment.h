#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include "strategy.h"



class Environment
{
private:
    Strategy* strategy;
public:
    Environment(Strategy* strategy);
    void changeStrategy(Strategy* strategy);
};

#endif // ENVIROMENT_H
