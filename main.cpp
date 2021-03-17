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
#include "gui.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Board* board=new Board(100,200);
    BoardController* controller=new BoardController(board);
    MainWindow w(controller);

    w.showMaximized();

    return a.exec();
}
