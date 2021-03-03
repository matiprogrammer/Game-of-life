#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Cell.h"
using namespace std;
class Board
{
private:
    vector<vector<Cell>> board;
    int height, width;

public:
    Board(int height, int width);
    int getHeight();
    int getWidth();
    void drawBoard();
    int getAliveNeighbours(int height, int width);
    Cell getCell(int height, int width);
};
#endif
