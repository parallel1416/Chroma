
#include "startmenu.h"
#include "qgraphicsitem.h"

startmenu::startmenu()
{
    QPixmap bkgrd(":/resources/image/startmenu.jpg");
    background=new QGraphicsPixmapItem(bkgrd);
    start=new mybtn("START");
}

