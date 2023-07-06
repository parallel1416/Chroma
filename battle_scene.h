#ifndef BATTLE_SCENE_H
#define BATTLE_SCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <qgraphicsview>
#include "battle_panel.h"

class battle_scene
{
public:
    battle_scene();
    void showscene();
    QGraphicsScene* battle;//add
    QGraphicsView* battle_view;
    QGraphicsProxyWidget *proxy_pbw;
    QGraphicsProxyWidget *proxy_panel;
    QMainWindow* hero_panel;
    battle_panel* hero_p;
    QProgressBar* pbw;


};

#endif // BATTLE_SCENE_H
