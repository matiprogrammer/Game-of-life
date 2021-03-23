#include "Board.h"
#include "classicstrategy.h"
#include "colorstrategy.h"
#include <iostream>
#include <QDebug>
#include <Color.h>


Board::Board(int height, int width)
{
    this->height = height;
    this->width = width;
    init();
}
void Board::init()
{
    for (int i = 0; i < height; i++)
    {
        board.emplace_back(vector<std::shared_ptr<Cell>>());
        vector<vector<std::shared_ptr<Cell>>>::iterator iter1 = --(board.end());
        for (int j = 0; j < width; j++)
        {
            (*iter1).emplace_back(new SimpleCell(white));
        }
        iter1++;
    }
}
void Board::drawBoard()
{
    for (vector<vector<std::shared_ptr<Cell>>>::iterator iter1 = board.begin(); iter1 != board.end(); iter1++)
    {
        QDebug _qDebug=qDebug();
        for (vector<std::shared_ptr<Cell>>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++)
        {
            _qDebug<< "_";

        }
        qDebug() << "\n";
    }
}

int Board::getHeight()
{
    return this->height;
}
int Board::getWidth()
{
    return this->width;
}

vector<Cell*> Board::getAliveNeighbours(int height, int width)
{
    vector<Cell*> neightbours;
    int heightOffset = 1, widthOffset = 1;

    if (height <= 0)
    {
        heightOffset = 0;
        height = 0;
    }
    if (width <= 0)
    {
        widthOffset = 0;
        width = 0;
    }

    vector<vector<std::shared_ptr<Cell>>>::iterator rowIterator = board.begin() + height - heightOffset;
    for (int i = (height == 0 ? 1 : 0); i < (height >= this->height - 1 ? 2 : 3); i++, rowIterator++)
    {
        vector<std::shared_ptr<Cell>>::iterator columnIterator = (*rowIterator).begin() + width - widthOffset;
        for (int j = (width == 0 ? 1 : 0); j < (width >= this->width - 1 ? 2 : 3); j++, columnIterator++)
        {
            Cell* current = (*columnIterator).get();

            if (i == 1 && j == 1)
            {
            }
            else{
                neightbours.push_back(current);
            }

        }
    }
    return neightbours;
}


Cell* Board::getCell(int y, int x)
{
    Cell* cell=this->board.at(y).at(x).get();
    return cell;
}

void Board::setCell(int y, int x, Cell *cell)
{
    board.at(y).at(x).reset(cell);
}

void Board::reset()
{
    board.clear();
    init();
}

vector<vector<std::shared_ptr<Cell>> > Board::getBoard()
{
    return this->board;
}
