#include "Board.h"
#include "classicstrategy.h"
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

        board.push_back(vector<SimpleCell>());
        vector<vector<SimpleCell>>::iterator iter1 = --(board.end());
        for (int j = 0; j < width; j++)
        {
            (*iter1).push_back(SimpleCell(white,new ClassicStrategy()));
        }
        iter1++;
    }
}

void Board::drawBoard()
{
    for (vector<vector<SimpleCell>>::iterator iter1 = board.begin(); iter1 != board.end(); iter1++)
    {
        QDebug _qDebug=qDebug();
        for (vector<SimpleCell>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++)
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

vector<SimpleCell> Board::getAliveNeighbours(int height, int width)
{
    vector<SimpleCell> neightbours;
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

    int aliveNeightbours = 0;
    vector<vector<SimpleCell>>::iterator rowIterator = board.begin() + height - heightOffset;
    for (int i = (height == 0 ? 1 : 0); i < (height >= this->height - 1 ? 2 : 3); i++, rowIterator++)
    {
        vector<SimpleCell>::iterator columnIterator = (*rowIterator).begin() + width - widthOffset;
        for (int j = (width == 0 ? 1 : 0); j < (width >= this->width - 1 ? 2 : 3); j++, columnIterator++)
        {
            SimpleCell current = (*columnIterator);

            if (i == 1 && j == 1)
            {
            }
            else if(current.getState()==black)
            {
                neightbours.push_back(current);
            }

        }
    }
    return neightbours;
}

SimpleCell* Board::getCell(int y, int x)
{
    SimpleCell* cell=&this->board.at(y).at(x);
    return cell;
}
