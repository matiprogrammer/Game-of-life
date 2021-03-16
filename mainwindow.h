#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardcontroller.h"

#include <QBoxLayout>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(BoardController* boardController, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
        QPushButton* startButton, *stopButton;
        QGraphicsView *view;
        QGraphicsScene *scene;

        QHBoxLayout *mainLayout, *boardLayout;
        QVBoxLayout *leftBarLayout;
        QSpacerItem * verticalSpacer;
        BoardController * boardController;

        QTimer *timer;

public slots:
       void onStartButtonClicked();
       void onStopButtonClicked();
       void timeout();
};
#endif // MAINWINDOW_H
