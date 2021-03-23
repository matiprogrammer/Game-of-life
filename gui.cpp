#include "cellgraphics.h"
#include "gui.h"
#include <QDebug>

Gui::Gui(BoardController* controller,int cellHeight, int cellWidth)
{
    this->controller=controller;
    this->height=controller->getBoardHeight();
    this->width=controller->getBoardWidth();
    this->cellHeight=cellHeight;
    this->cellWidth=cellWidth;
    this->scene =new QGraphicsScene(0,0,this->width*cellWidth+(separatorTick*width),this->height*cellHeight+(separatorTick*height));
    initBoard();

}

void Gui::initBoard()
{
    for(int i=0;i<this->width*cellWidth+(separatorTick*width);i+=cellWidth+separatorTick)
    {
        for(int j=0;j<this->height*cellHeight+(separatorTick*height);j+=cellHeight+separatorTick)
        {
            int yPos=j/(cellHeight+separatorTick);
            int xPos=i/(cellWidth+separatorTick);
            Cell* cell=controller->getCell(yPos,xPos);
           // this->scene->addItem(new CellGraphics(QRect(i,j,cellWidth,cellHeight),controller));
        }
    }
}

QGraphicsScene* Gui::getScene()
{
    return this->scene;
}

void Gui::buttonClick()
{
        controller->computeNextGeneration();
        scene->update();
}

