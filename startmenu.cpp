#include "globalvar.h"
#include "startmenu.h"
#include "qgraphicsitem.h"

startmenu::startmenu(QString& imagePath)
{
    setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(Qt::black);
    background = new QGraphicsPixmapItem(QPixmap(imagePath));
    addItem(background);
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
}

void startmenu::checkCont(){
    if (prevScene){
        cont=new mybtn("CONTINUE");
        cont->setFixedSize(btnSize);
        cont->move(350,200);
        addWidget(cont);
    }
}
