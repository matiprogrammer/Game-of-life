#include "Board.h"
#include <iostream>
#include<QDebug>
#include <list>
using namespace std;

Board::Board(int height, int width)
{
    this->height = height;
    this->width = width;
    for (int i = 0; i < height; i++)
    {

        board.push_back(vector<Cell>());
        vector<vector<Cell>>::iterator iter1 = --(board.end());
        for (int j = 0; j < width; j++)
        {
            (*iter1).push_back(Cell(false));
        }
        iter1++;
    }
}

void Board::drawBoard()
{
    for (vector<vector<Cell>>::iterator iter1 = board.begin(); iter1 != board.end(); iter1++)
    {
        QDebug _qDebug=qDebug();
        for (vector<Cell>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++)
        {

            _qDebug<<qPrintable((*iter2).alive() ? "x" : "_");

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

int Board::getAliveNeighbours(int height, int width)
{
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
    vector<vector<Cell>>::iterator rowIterator = board.begin() + height - heightOffset;
    for (int i = (height == 0 ? 1 : 0); i < (height >= this->height - 1 ? 2 : 3); i++, rowIterator++)
    {
        vector<Cell>::iterator columnIterator = (*rowIterator).begin() + width - widthOffset;
        for (int j = (width == 0 ? 1 : 0); j < (width >= this->width - 1 ? 2 : 3); j++, columnIterator++)
        {
            Cell current = (*columnIterator);
            if (current.alive())
            {
                if (i == 1 && j == 1)
                {
                }
                else
                {
                    aliveNeightbours++;
                }
            }
        }
    }
    return aliveNeightbours;
}

Cell Board::getCell(int height, int width)
{
    return board[height][width];
}
