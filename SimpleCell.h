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
    SimpleCell();
    SimpleCell(Color color);
    virtual bool isPoisoned();
    virtual bool isWall();

};
#endif
