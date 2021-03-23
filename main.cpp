#include "mainwindow.h"
#include "Board.h"
#include "SimpleCell.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
#include <QTimer>
#include "classicstrategy.h"
#include "gui.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Board* board=new Board(100,100);
    BoardController* controller=new BoardController(board, new ClassicStrategy());
    MainWindow w(controller);
    controller->setView(&w);
    w.showMaximized();

    return a.exec();
}
