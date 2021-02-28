#ifndef CELL_H
#define CELL_H
using namespace std;
class Cell
{
private:
    bool isAlive;

public:
    Cell();
    Cell(bool isAlive);
    void computeNextState(int neightboursAlive);
    bool alive();
};
#endif