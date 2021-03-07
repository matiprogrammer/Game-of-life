#ifndef SIMPLECELL_H
#define SIMPLECELL_H
#include "Color.h"
#include "strategy.h"

#include <cell.h>
#include <QGraphicsItem>

class Strategy;

using namespace std;
class SimpleCell
{
private:
    bool isAlive;
    Color currentColor, nextColor;
    Strategy* strategy;

public:
    SimpleCell(Color color, Strategy* strategy);
    void calculateNextState(vector<SimpleCell> neightbours);
    void updateState();
    bool isPoisoned();
    bool isWall();
    Color getState();
    void changeStrategy(Strategy *strategy);
    void cellClick();
};
#endif
