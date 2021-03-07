#include "boardcontroller.h"

#include <QDebug>

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

            int neightbours= board->getAliveNeighbours(j,i).size();

            SimpleCell *cell= board->getCell(j,i);
            if((cell->getColor()==white && neightbours==3)||(cell->getColor()==black &&(neightbours==2 || neightbours==3)))
            {
                cell->setNextState(black);
            }
            else
            {
                cell->setNextState(white);
            }
            //cell=NULL;
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

void BoardController::onClick(SimpleCell *cell)
{
    cell->setState(black);
    QDebug _qDebug= qDebug();
    _qDebug<<"klik";
}
