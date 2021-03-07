#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "Board.h"
#include "iclicklistener.h"
class BoardController : public IClickListener
{
private:
    Board *board;
public:
    BoardController(Board* board);
    int getBoardHeight();
    int getBoardWidth();
    SimpleCell *getCell(int x, int y);
    void computeNextGeneration();

    // IClickListener interface
public:
    virtual void onClick(SimpleCell *cell) override;
};

#endif // BOARDCONTROLLER_H
