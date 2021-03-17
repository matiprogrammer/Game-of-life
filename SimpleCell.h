#ifndef SIMPLECELL_H
#define SIMPLECELL_H
#include <cell.h>
#include "Color.h"
#include "strategy.h"


#include <QGraphicsItem>


using namespace std;
class SimpleCell :public Cell
{

public:
    ~SimpleCell();
    SimpleCell(Color color, Strategy* strategy);
    virtual void calculateNextState(vector<Cell*> neightbours);
    virtual bool isPoisoned();
    virtual bool isWall();
    virtual void changeStateOnClick();
    virtual void drawState() override;
};
#endif
