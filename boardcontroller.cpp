#include "boardcontroller.h"
#include "cellgraphics.h"
#include "classicstrategy.h"
#include "classicwithwallstrategy.h"
#include "colorstrategy.h"
#include "customstrategy.h"

#include <QDebug>
#include <thread>

BoardController::BoardController(Board* board, Strategy* strategy)
{
    this->board=board;
    this->globalStrategy=strategy;
    this->nextCellType="brak";
}

int BoardController::getBoardHeight()
{
    return board->getHeight();
}

int BoardController::getBoardWidth()
{
    return board->getWidth();
}

void BoardController::setView(View *view)
{
    this->view=view;
    view->setPossibleCellTypes( globalStrategy->getPossibleCellTypes());
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
            cell->setNextState(globalStrategy->calculateNextState(neightbours,cell));
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

void BoardController::setNextCellType(const QString &cellType)
{
    this->nextCellType=cellType;
}

QString BoardController::getNextCellType()
{
    return this->nextCellType;
}

void BoardController::startGame()
{

}

void BoardController::resetBoard()
{
    this->board->reset();
    view->update();
}


void BoardController::drawStates()
{
    for(int j=0;j<board->getHeight();j++)
    {
        for(int i=0;i<board->getWidth();i++)
        {
            Cell* cell=board->getCell(j,i);
            cell->setNextState( this->globalStrategy->drawState(cell));
            cell->updateState();
        }

    }
}


void BoardController::onCellClick(CellGraphics* cellGraphics)
{
    if(nextCellType!="brak")
    {
        Cell* cell=globalStrategy->getCell(nextCellType);
        board->setCell(cellGraphics->getYPos(),cellGraphics->getXPos(),cell);
    }
    else{
        Cell* cell= board->getCell(cellGraphics->getYPos(),cellGraphics->getXPos());
        cell->setNextState(globalStrategy->changeStateOnClick(cell));
        cell->updateState();
    }
    cellGraphics->update();
}

void BoardController::changeGlobalStrategy(const QString &textStrategy)
{
    delete this->globalStrategy;
    if(textStrategy=="Kolorowa")
    {
        this->globalStrategy=new ColorStrategy();
    }
    else if(textStrategy=="Klasyczna")
    {
        this->globalStrategy=new ClassicStrategy();
    }
    else if(textStrategy=="Zatrute ściany")
    {
        this->globalStrategy=new ClassicWithWallStrategy();
    }
    this->nextCellType="brak";
    view->setPossibleCellTypes( globalStrategy->getPossibleCellTypes());
    board->reset();
    view->update();
}
void BoardController::changeCustomStrategy(int numberOfCellsWhenStillLive, int numberOfCellsWhenStillDead, int numberOfCellsThenBorn, int numberOfCellsThenDie )
{
    delete this->globalStrategy;
    this->globalStrategy=new CustomStrategy(numberOfCellsWhenStillLive,numberOfCellsWhenStillDead,numberOfCellsThenBorn,numberOfCellsThenDie);
    this->nextCellType="brak";
    view->setPossibleCellTypes( globalStrategy->getPossibleCellTypes());
    view->update();
}

Color BoardController::getColor(int xPos, int yPos)
{
    return board->getCell(yPos,xPos)->getState();
}
