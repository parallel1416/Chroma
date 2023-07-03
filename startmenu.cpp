#include "globalvar.h"
#include "startmenu.h"
#include "qgraphicsitem.h"

startmenu::startmenu()
{
    QPixmap bkgrd(":/resources/image/startmenu.jpg");
    addPixmap(bkgrd);
    start=new mybtn("NEW GAME");
    start->setFixedSize(btnSize);
    start->move(350,200);
    addWidget(start);
    settings=new mybtn("SETTINGS");
    settings->setFixedSize(btnSize);
    settings->move(350,300);
    addWidget(settings);
    exit=new mybtn("EXIT");
    exit->setFixedSize(btnSize);
    exit->move(350,400);
    addWidget(exit);
    if (prevScene){
        cont=new mybtn("CONTINUE");
        cont->setFixedSize(btnSize);
        cont->move(350,200);
        addWidget(cont);
    }
}

