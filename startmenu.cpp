#include "globalvar.h"
#include "startmenu.h"
#include "qgraphicsitem.h"

startmenu::startmenu()
{
    QPixmap bkgrd(":/resources/image/startmenu.jpg");
    background=new QGraphicsPixmapItem(bkgrd);
    QString s="NEW GAME";
    start=new mybtn(s);
    start->setFixedSize(btnSize);
    start->move(50,300);
    s="SETTINGS";
    settings=new mybtn(s);
    settings->setFixedSize(btnSize);
    settings->move(50,400);
    s="EXIT";
    exit=new mybtn(s);
    exit->setFixedSize(btnSize);
    exit->move(50,500);
    if (prevScene){
    s="CONTINUE";
    cont=new mybtn(s);
    cont->setFixedSize(btnSize);
    cont->move(50,200);
    }
}

