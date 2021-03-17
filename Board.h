#ifndef BOARD_H
#define BOARD_H
#include <cell.h>
#include <vector>
#include <stdlib.h>
#include "SimpleCell.h"
using namespace std;
class Board
{
private:
    vector<vector<Cell*>> board;
    int height, width;
    int cellHeight, cellWidth;
public:
    Board(int height, int width);
    int getHeight();
    int getWidth();
    void drawBoard();
    vector<Cell*> getAliveNeighbours(int height, int width);
    Cell* getCell(int y, int x);
    vector<vector<Cell*>>::iterator getHeightIterator();
    vector<Cell*>::iterator getWidthIterator();
    vector<vector<Cell*>> getBoard();
};
#endif
