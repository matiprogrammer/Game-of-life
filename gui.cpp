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
    this->scene =new QGraphicsScene(0,0,this->width*cellWidth+(2*width),this->height*cellHeight+(2*height));
    initBoard();

}

void Gui::initBoard()
{
    for(int i=0;i<this->width*cellWidth+(separatorTick*width);i+=cellWidth+separatorTick)
    {
        for(int j=0;j<this->height*cellHeight+(separatorTick*height);j+=cellHeight+separatorTick)
        {
            SimpleCell* cell=controller->getCell(j/(cellHeight+separatorTick),i/(cellWidth+separatorTick));
            this->scene->addItem(new CellGraphics(QRect(i,j,cellWidth,cellHeight),cell,controller));
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

