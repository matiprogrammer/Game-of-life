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
    vector<vector<std::shared_ptr<Cell>>> board;
    int height, width;
    int cellHeight, cellWidth;
    void init();
public:
    Board(int height, int width);
    int getHeight();
    int getWidth();
    void drawBoard();
    vector<Cell*> getAliveNeighbours(int height, int width);
    Cell* getCell(int y, int x);
    void setCell(int y,int x, Cell* cell);
    void reset();
    vector<vector<std::shared_ptr<Cell>>> getBoard();
};
#endif
