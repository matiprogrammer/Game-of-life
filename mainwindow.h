#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardcontroller.h"

#include <QBoxLayout>
#include <QComboBox>
#include <QGraphicsView>
#include <QGroupBox>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "view.h"
#include <QGridLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public View
{
    Q_OBJECT


public:
    MainWindow(BoardController* boardController, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton* startButton, *stopButton, *drawStatesButton, *resetButton, *customStrategyButton;
    QGraphicsView *view;
    QGraphicsScene *scene;

    QHBoxLayout *mainLayout, *boardLayout;
    QVBoxLayout *leftBarLayout;
    QGridLayout *customStrategyLayout;
    QWidget *customStrategyWidget;
    QSpacerItem * verticalSpacer;
    BoardController * boardController;
    QGroupBox* groupBox;
    QVBoxLayout *groupBoxLayout;
    QComboBox * strategyComboBox, *numberOfCellsStillLiveComboBox, *numberOfCellsThenDieComboBox, *numberOfCellsStillDeadComboBox, *numberOfCellsThenBornComboBox;
    QTimer *timer;

public slots:
    void onStartButtonClicked();
    void onStopButtonClicked();
    void nextIteration();
    void changeStrategyClicked(const QString &text);
    void onDrawStatesClicked();
    void onAddWallClicked();
    void radioButtonSelected(bool selected);
    void onResetButtonClicked();


    // View interface
public:
    virtual void update() override;
    virtual void setPossibleCellTypes(list<QString> possibleCellTypes) override;
};
#endif // MAINWINDOW_H
