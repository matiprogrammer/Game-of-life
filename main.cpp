#include "mainwindow.h"
#include "Board.h"
#include "Cell.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QPainter>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsGridLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Board board(3,3);
       board.drawBoard();
//       QVBoxLayout *layout=new QVBoxLayout();

//       QTableWidget* qTableWidget=new QTableWidget(50,50);
//        QTableWidgetItem* item=new QTableWidgetItem("heheh");

//        qTableWidget->setItem(0,0,item);
//        layout->addWidget(qTableWidget);
//        w.centralWidget()->setLayout(layout);


        QGraphicsScene scene(0,0,900,600);
        QBrush brush(Qt::blue);
        QPen *pen=new QPen(Qt::black);
        for(int i=0;i<900;i+=12)
        {
            for(int j=0;j<600;j+=12)
            {
                scene.addRect(i,j,10,10,*pen,brush);
            }
        }

        QGraphicsView *view=new QGraphicsView(&scene);
           view->scale(3,3);
        QVBoxLayout *layout =new QVBoxLayout();
        layout->addWidget(view);
        w.centralWidget()->setLayout(layout);

    w.show();

    return a.exec();
}
