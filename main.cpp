#include "mainwindow.h"
#include "Board.h"
#include "SimpleCell.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QPainter>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
#include "gui.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board* board=new Board(50,50);
    BoardController* controller=new BoardController(board);
    Gui* gui=new Gui(controller,20,20);

    QGraphicsView *view=new QGraphicsView(gui->getScene());
    QPushButton* button=new QPushButton("button");
    gui->getScene()->addWidget(button);

    QObject::connect(button,&QPushButton::clicked,gui,&Gui::buttonClick);
    QVBoxLayout *layout =new QVBoxLayout();

    layout->addWidget(view);
    w.centralWidget()->setLayout(layout);

    w.show();

    return a.exec();
}
