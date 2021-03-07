#ifndef GUI_H
#define GUI_H
#include "Board.h"
#include "boardcontroller.h"
#include <QGraphicsScene>
#include <QObject>
class Gui : public QObject
{
Q_OBJECT
private:
    int separatorTick=1;
    BoardController* controller;
    QGraphicsScene *scene;
    int height, width, cellHeight, cellWidth;
public:
    Gui(BoardController* controller,int cellHeight, int cellWidth);
    void initBoard();
    QGraphicsScene* getScene();
   public slots:
    void buttonClick();
};

#endif // GUI_H
