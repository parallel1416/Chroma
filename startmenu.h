
#ifndef STARTMENU_H
#define STARTMENU_H
#include <QGraphicsScene>
#include "mybtn.h"


class startmenu: public QGraphicsScene
{
public:
    startmenu(QString& imagePath);
    mybtn *start, *cont, *settings, *exit;
    void checkCont();
private:
    QGraphicsPixmapItem *background;
};

#endif // STARTMENU_H
