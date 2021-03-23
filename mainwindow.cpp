#include "cellgraphics.h"
#include "classicstrategy.h"
#include "colorstrategy.h"
#include "classicwithwallstrategy.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QDebug>
#include <QElapsedTimer>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
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
    view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->boardLayout=new QHBoxLayout();
    boardLayout->addWidget(view);
    this->leftBarLayout=new QVBoxLayout();

    //buttons
    this->startButton=new QPushButton("Start");
    this->stopButton=new QPushButton("Stop");
    this->drawStatesButton=new QPushButton("Losuj stany");
    this->resetButton=new QPushButton("Reset");
    this-> groupBox=new QGroupBox("Komórki");
    this->groupBoxLayout = new QVBoxLayout();
    this->groupBox->setLayout(groupBoxLayout);

    this->strategyComboBox=new QComboBox(this);
    strategyComboBox->addItem("Klasyczna");
    strategyComboBox->addItem("Kolorowa");
    strategyComboBox->addItem("Zatrute ściany");
    this->customStrategyLayout=new QGridLayout();

    //custom strategy
    QStringList listOfNumbers;
    listOfNumbers.append("0");listOfNumbers.append("1");listOfNumbers.append("2");listOfNumbers.append("3");listOfNumbers.append("4");listOfNumbers.append("5");listOfNumbers.append("6");listOfNumbers.append("7");listOfNumbers.append("8");
    this->numberOfCellsStillLiveComboBox=new QComboBox();
    this->numberOfCellsThenDieComboBox=new QComboBox();
    this->numberOfCellsStillDeadComboBox=new QComboBox();
    this->numberOfCellsThenBornComboBox=new QComboBox();
    this->numberOfCellsStillLiveComboBox->addItems(listOfNumbers);
    this->numberOfCellsThenDieComboBox->addItems (listOfNumbers);
    this->numberOfCellsStillDeadComboBox->addItems (listOfNumbers);
    this->numberOfCellsThenBornComboBox->addItems(listOfNumbers);
    this->customStrategyLayout->addWidget(new QLabel("Narodzi się:"),0,0,Qt::AlignLeft);
    this->customStrategyLayout->addWidget(numberOfCellsThenBornComboBox,0,1);
    this->customStrategyLayout->addWidget(new QLabel("Umrze:"),1,0,Qt::AlignLeft);
    this->customStrategyLayout->addWidget(numberOfCellsThenDieComboBox,1,1);
    this->customStrategyLayout->addWidget(new QLabel("Przetrwa:"),2,0,Qt::AlignLeft);
    this->customStrategyLayout->addWidget(numberOfCellsStillLiveComboBox,2,1);
    this->customStrategyLayout->addWidget(new QLabel("Pozostanie umarła:"),3,0,Qt::AlignLeft);
    this->customStrategyLayout->addWidget(numberOfCellsStillDeadComboBox,3,1);
    this->customStrategyWidget=new QWidget();
    this->customStrategyWidget->setLayout(customStrategyLayout);
    this->customStrategyButton=new QPushButton("Zmień zasady");
    this->customStrategyLayout->addWidget(customStrategyButton);
    // this->customStrategyWidget->setVisible(false);


    this->leftBarLayout->addWidget(startButton);
    this->leftBarLayout->addWidget(stopButton);
    this->leftBarLayout->addWidget(groupBox);
    this->leftBarLayout->addWidget(drawStatesButton);
    this->leftBarLayout->addWidget(resetButton);
    this->leftBarLayout->addWidget(strategyComboBox);
    this->leftBarLayout->addWidget(customStrategyWidget);

    leftBarLayout->setAlignment(Qt::AlignTop);

    this->mainLayout=new QHBoxLayout();
    this->mainLayout->addLayout(leftBarLayout);
    this->mainLayout->addLayout(boardLayout);

    this->centralWidget()->setLayout(mainLayout);

    for(int i=0;i<width*cellWidth+(separatorTick*width);i+=cellWidth+separatorTick)
    {
        for(int j=0;j<height*cellHeight+(separatorTick*height);j+=cellHeight+separatorTick)
        {
            int yPos=j/(cellHeight+separatorTick);
            int xPos=i/(cellWidth+separatorTick);
            this->scene->addItem(new CellGraphics(QRect(i,j,cellWidth,cellHeight),xPos,yPos,boardController));
        }
    }

    this->timer = new QTimer(this);
    this->timer->setInterval(100);

    QObject::connect(startButton,SIGNAL(clicked()),timer,SLOT(start()));
    QObject::connect(stopButton,SIGNAL(clicked()),timer,SLOT(stop()));
    QObject::connect(timer, &QTimer::timeout,this,&MainWindow::nextIteration);
    QObject::connect(drawStatesButton, &QPushButton::released,this,&MainWindow::onDrawStatesClicked);
    QObject::connect(resetButton, &QPushButton::released,this,&MainWindow::onResetButtonClicked);
    QObject::connect(customStrategyButton, &QPushButton::released,this,&MainWindow::onCustomStrategyChanged);
    QObject::connect(strategyComboBox,&QComboBox::currentTextChanged,this, &MainWindow::changeStrategyClicked);
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

void MainWindow::changeStrategyClicked(const QString &text)
{
    boardController->changeGlobalStrategy(text);
}

void MainWindow::onDrawStatesClicked()
{
    this->boardController->drawStates();
    this->scene->update();
}


void MainWindow::radioButtonSelected(bool selected)
{
    QButtonGroup group;
    QList<QRadioButton *> allButtons = groupBox->findChildren<QRadioButton *>();
    qDebug() <<allButtons.size();
    for(int i = 0; i < allButtons.size(); ++i)
    {
        group.addButton(allButtons[i],i);
    }
    if(group.checkedButton()==NULL){
        this->boardController->setNextCellType("brak");
    }
    else if(group.checkedButton()->text()==this->boardController->getNextCellType())
    {
        this->boardController->setNextCellType("brak");
        group.setExclusive(false);
        group.checkedButton()->setChecked(false);
        group.setExclusive(true);
    }
    else{
        this->boardController->setNextCellType(group.checkedButton()->text());
    }
}

void MainWindow::onResetButtonClicked()
{
    boardController->resetBoard();
}

void MainWindow::onCustomStrategyChanged()
{
    int dead= numberOfCellsStillDeadComboBox->currentText().toInt();
    int live=numberOfCellsStillLiveComboBox->currentText().toInt();
    int die=numberOfCellsThenDieComboBox->currentText().toInt();
    int born=numberOfCellsThenBornComboBox->currentText().toInt();
    boardController->changeCustomStrategy(live,dead,born,die);
}

void MainWindow::update()
{
    this->scene->update();
}

void MainWindow::setPossibleCellTypes(list<QString> possibleCellTypes)
{
    // this->groupBoxLayout=new QVBoxLayout();
    QLayoutItem* item;
    while ( ( item = groupBoxLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }

    for(QString cellType:possibleCellTypes)
    {
        QRadioButton* radioButton=  new QRadioButton(cellType);
        QObject::connect(radioButton,&QRadioButton::clicked,this, &MainWindow::radioButtonSelected);
        groupBoxLayout->addWidget(radioButton);
    }
    //this->groupBox->setLayout(groupBoxLayout);
    groupBox->update();
}




