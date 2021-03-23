QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    SimpleCell.cpp \
    boardcontroller.cpp \
    cell.cpp \
    cellgraphics.cpp \
    classicstrategy.cpp \
    classicwithwallstrategy.cpp \
    colorstrategy.cpp \
    customstrategy.cpp \
    enviroment.cpp \
    iclicklistener.cpp \
    main.cpp \
    mainwindow.cpp \
    poisonedcell.cpp \
    strategy.cpp \
    view.cpp \
    wallcell.cpp \
    wallstrategy.cpp

HEADERS += \
    Board.h \
    Color.h \
    SimpleCell.h \
    boardcontroller.h \
    cell.h \
    cellgraphics.h \
    classicstrategy.h \
    classicwithwallstrategy.h \
    colorstrategy.h \
    customstrategy.h \
    enviroment.h \
    iclicklistener.h \
    mainwindow.h \
    poisonedcell.h \
    strategy.h \
    view.h \
    wallcell.h \
    wallstrategy.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore
