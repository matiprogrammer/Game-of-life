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

SimpleCell *BoardController::getCell(int x, int y)
{
    return board->getCell(y,x);
}

void BoardController::computeNextGeneration()
{
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {
            vector<SimpleCell> neightbours= board->getAliveNeighbours(j,i);
            SimpleCell *cell= board->getCell(j,i);
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

void BoardController::onClick(SimpleCell *cell)
{
    cell->cellClick();

}
