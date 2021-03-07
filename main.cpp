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
#include <QTimer>
#include "gui.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board* board=new Board(40,40);
    BoardController* controller=new BoardController(board);
    Gui* gui=new Gui(controller,20,20);

    QGraphicsView *view=new QGraphicsView(gui->getScene());
    QPushButton* button=new QPushButton("START");
    QPushButton* button2=new QPushButton("STOP");
    button2->setGeometry(100,10,100,20);
    gui->getScene()->addWidget(button);
    gui->getScene()->addWidget(button2);
    QObject::connect(button,&QPushButton::clicked,gui,&Gui::buttonClick);

    QTimer *timer = new QTimer(&a);
    timer->setInterval(100);

    QObject::connect(button,SIGNAL(clicked()),timer,SLOT(start()));
    QObject::connect(button2,SIGNAL(clicked()),timer,SLOT(stop()));
    QObject::connect(timer, &QTimer::timeout,gui,&Gui::buttonClick);

    QVBoxLayout *layout =new QVBoxLayout();

    layout->addWidget(view);
    w.centralWidget()->setLayout(layout);

    w.show();

    return a.exec();
}
