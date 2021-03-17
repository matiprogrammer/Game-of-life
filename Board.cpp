#include "Board.h"
#include "classicstrategy.h"
#include "colorstrategy.h"
#include <iostream>
#include <QDebug>
#include <Color.h>
using namespace std;

Board::Board(int height, int width)
{
    this->height = height;
    this->width = width;
    for (int i = 0; i < height; i++)
    {
        board.push_back(vector<Cell*>());
        vector<vector<Cell*>>::iterator iter1 = --(board.end());
        for (int j = 0; j < width; j++)
        {
            (*iter1).push_back(new SimpleCell(white,new ClassicStrategy()));
        }
        iter1++;
    }
}

void Board::drawBoard()
{
    for (vector<vector<Cell*>>::iterator iter1 = board.begin(); iter1 != board.end(); iter1++)
    {
        QDebug _qDebug=qDebug();
        for (vector<Cell*>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++)
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

    vector<vector<Cell*>>::iterator rowIterator = board.begin() + height - heightOffset;
    for (int i = (height == 0 ? 1 : 0); i < (height >= this->height - 1 ? 2 : 3); i++, rowIterator++)
    {
        vector<Cell*>::iterator columnIterator = (*rowIterator).begin() + width - widthOffset;
        for (int j = (width == 0 ? 1 : 0); j < (width >= this->width - 1 ? 2 : 3); j++, columnIterator++)
        {
            Cell* current = (*columnIterator);

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
    Cell* cell=this->board.at(y).at(x);
    return cell;
}

vector<vector<Cell*>>::iterator Board::getHeightIterator()
{
    return board.begin();
}


vector<Cell*>::iterator Board::getWidthIterator()
{
    return board.begin()->begin();
}

vector<vector<Cell*> > Board::getBoard()
{
    return this->board;
}
