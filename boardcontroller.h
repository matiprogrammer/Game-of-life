#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "Board.h"
#include "iclicklistener.h"
#include <thread>
#include <QObject>
class BoardController : public IClickListener,public QObject
{
private:
    Board *board;
    Strategy* strategyForNextCells;
public:
    BoardController(Board* board);
    int getBoardHeight();
    int getBoardWidth();
    Cell *getCell(int x, int y);
    void computeNextGeneration();
    void startGame();
    void changeStrategForNextCells(Strategy* strategy);
    public slots:
    void drawStates();

    // IClickListener interface
public:
    virtual void onCellClick(CellGraphics *cellGraphics) override;
    virtual void changeGlobalStrategy(Strategy* strategy);
};

#endif // BOARDCONTROLLER_H
