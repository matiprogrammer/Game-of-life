#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H

#include "Board.h"
#include "iclicklistener.h"
#include "view.h"
#include <thread>
#include <QObject>
class BoardController : public ICellInfo,public QObject
{
private:
    Board *board;
    Strategy* globalStrategy;
    QString nextCellType;
    View* view;
public:
    BoardController(Board* board, Strategy* strategy);
    int getBoardHeight();
    int getBoardWidth();
    void setView(View* view);
    Cell *getCell(int x, int y);
    void computeNextGeneration();
    void setNextCellType(const QString &cellType);
    QString getNextCellType();
    void startGame();
    void resetBoard();
    public slots:
    void drawStates();
    void changeCustomStrategy(int numberOfCellsWhenStillLive, int numberOfCellsWhenStillDead, int numberOfCellsThenBorn, int numberOfCellsThenDie );



    // IClickListener interface
public:
    virtual void onCellClick(CellGraphics* cellGraphics) override;
    virtual void changeGlobalStrategy(const QString &textStrategy);

    // ICellInfo interface
public:
    virtual Color getColor(int xPos, int yPos) override;
};

#endif // BOARDCONTROLLER_H
