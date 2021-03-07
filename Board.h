#ifndef BOARD_H
#define BOARD_H
#include <SimpleCell.h>
#include <vector>

using namespace std;
class Board
{
private:
    vector<vector<SimpleCell>> board;
    int height, width;
    int cellHeight, cellWidth;
public:
    Board(int height, int width);
    int getHeight();
    int getWidth();
    void drawBoard();
    vector<SimpleCell> getAliveNeighbours(int height, int width);
    SimpleCell* getCell(int y, int x);
};
#endif
