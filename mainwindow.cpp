#include "cellgraphics.h"
#include "classicstrategy.h"
#include "colorstrategy.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QPushButton>
#include <QTime>

MainWindow::MainWindow(BoardController* boardController,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    int cellWidth=10;
    int cellHeight=10;
    int width=boardController->getBoardWidth();
    int height=boardController->getBoardHeight();
    int separatorTick=1;
    this->boardController=boardController;
    this->scene=new QGraphicsScene(0,0,width*cellWidth+(separatorTick*width),height*cellHeight+(separatorTick*height));
    this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    this->view=new QGraphicsView(scene);

    this->boardLayout=new QHBoxLayout();
    boardLayout->addWidget(view);
    this->leftBarLayout=new QVBoxLayout();

    //buttons
    this->startButton=new QPushButton("Start");
    this->stopButton=new QPushButton("Stop");
    this->colorStrategyButton=new QPushButton("tryb kolorów");
    this->classicStrategyButton=new QPushButton("Tryb klasyczny");
    this->drawStatesButton=new QPushButton("Losuj stany");

    this->leftBarLayout->addWidget(startButton);
    this->leftBarLayout->addWidget(stopButton);
    this->leftBarLayout->addWidget(colorStrategyButton);
    this->leftBarLayout->addWidget(classicStrategyButton);
    this->leftBarLayout->addWidget(drawStatesButton);
    this->mainLayout=new QHBoxLayout();
    this->mainLayout->addLayout(leftBarLayout);
    this->mainLayout->addLayout(boardLayout);

    this->centralWidget()->setLayout(mainLayout);

    for(int i=0;i<width*cellWidth+(separatorTick*width);i+=cellWidth+separatorTick)
    {
        for(int j=0;j<height*cellHeight+(separatorTick*height);j+=cellHeight+separatorTick)
        {
            Cell* cell=boardController->getCell(i/(cellWidth+separatorTick),j/(cellHeight+separatorTick));
            this->scene->addItem(new CellGraphics(QRect(i,j,cellWidth,cellHeight),cell,boardController));
        }
    }

    this->timer = new QTimer(this);
    this->timer->setInterval(10);

    QObject::connect(startButton,SIGNAL(clicked()),timer,SLOT(start()));
    QObject::connect(stopButton,SIGNAL(clicked()),timer,SLOT(stop()));
    QObject::connect(timer, &QTimer::timeout,this,&MainWindow::nextIteration);
    QObject::connect(drawStatesButton, &QPushButton::released,this,&MainWindow::onDrawStatesClicked);
    QObject::connect(colorStrategyButton, &QPushButton::released,this,&MainWindow::onColorStrategyClicked);
    QObject::connect(classicStrategyButton, &QPushButton::released,this,&MainWindow::onClassicStrategyClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartButtonClicked()
{
     view->setInteractive(false);
}

void MainWindow::onStopButtonClicked()
{
 view->setInteractive(true);
}

void MainWindow::nextIteration()
{
    QElapsedTimer timer=QElapsedTimer();
    timer.start();
    this->boardController->computeNextGeneration();
    qDebug()<<"obliczanie komórek"<<timer.elapsed();
    timer.restart();
   this->scene->update();
    qDebug()<<"aktualizacja widoku"<<timer.elapsed();
}

void MainWindow::onColorStrategyClicked()
{
    this->boardController->changeGlobalStrategy(new ColorStrategy());
}

void MainWindow::onClassicStrategyClicked()
{
    this->boardController->changeGlobalStrategy(new ClassicStrategy());
}

void MainWindow::onDrawStatesClicked()
{
    this->boardController->drawStates();
    this->scene->update();
}


