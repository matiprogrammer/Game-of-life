#include "boardcontroller.h"

#include <QDebug>
#include <thread>

BoardController::BoardController(Board* board)
{
    this->board=board;
}

int BoardController::getBoardHeight()
{
    return board->getHeight();
}

int BoardController::getBoardWidth()
{
    return board->getWidth();
}

Cell *BoardController::getCell(int x, int y)
{
    return board->getCell(y,x);
}

void BoardController::computeNextGeneration()
{
    vector<Cell*> neightbours;
    Cell *cell;
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {
            neightbours= board->getAliveNeighbours(j,i);
            cell= board->getCell(j,i);
            cell->calculateNextState(neightbours);
        }
    }
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {

            board->getCell(j,i)->updateState();
        }
    }
}

void BoardController::startGame()
{

}

void BoardController::drawStates()
{
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {
            board->getCell(j,i)->drawState();
        }

    }
}

void BoardController::onCellClick(Cell *cell)
{
    cell->changeStateOnClick();
}

void BoardController::changeGlobalStrategy(Strategy *strategy)
{
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {
            board->getCell(j,i)->changeStrategy(strategy);
        }
    }
}
