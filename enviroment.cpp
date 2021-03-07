#include "enviroment.h"

Environment::Environment(Strategy *strategy)
{
    this->strategy=strategy;
}

void Environment::changeStrategy(Strategy *strategy)
{
    this->strategy=strategy;
}
