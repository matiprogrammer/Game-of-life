#ifndef SIMPLECELL_H
#define SIMPLECELL_H
#include "Color.h"
#include <cell.h>
#include <QGraphicsItem>

using namespace std;
class SimpleCell
{
private:
    bool isAlive;
    Color currentColor, nextColor;

public:
    SimpleCell(Color color);
    void setNextState(Color color);
    void setState(Color color);
    void updateState();
    bool isPoisoned();
    bool isWall();
    Color getColor();
};
#endif
