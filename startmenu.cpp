#include "globalvar.h"
#include "startmenu.h"
#include "qgraphicsitem.h"

startmenu::startmenu()
{
    QPixmap bkgrd(":/resources/image/startmenu.jpg");
    //background=new QGraphicsPixmapItem(bkgrd);
    //background->setPos(50,100);
    //addItem(background);
    addPixmap(bkgrd);
    start=new mybtn("NEW GAME");
    start->setFixedSize(btnSize);
    start->move(50,300);
    addWidget(start);
    settings=new mybtn("SETTINGS");
    settings->setFixedSize(btnSize);
    settings->move(50,400);
    addWidget(settings);
    exit=new mybtn("EXIT");
    exit->setFixedSize(btnSize);
    exit->move(50,500);
    addWidget(exit);
    if (prevScene){
        cont=new mybtn("CONTINUE");
        cont->setFixedSize(btnSize);
        cont->move(50,200);
        addWidget(cont);
    }
}

