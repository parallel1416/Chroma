
#ifndef STARTMENU_H
#define STARTMENU_H
#include <QGraphicsScene>
#include "mybtn.h"


class startmenu: public QGraphicsScene
{
public:
    startmenu();
    mybtn *start, *cont, *settings, *exit;
private:
    QGraphicsPixmapItem *background;
};

#endif // STARTMENU_H
