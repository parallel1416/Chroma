
#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include "map.h"
#include "mybtn.h"
#include "qgraphicsview.h"
#include "startmenu.h"
#include "backpack.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QWidget>

class scene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit scene(int num, QObject *parent = nullptr);
    Map* map[3];
    int sceneNum;
    mybtn* pause;
    mybtn* bkpk;
    QGraphicsScene* activeMap;
    Backpack* backpack;
signals:
    void endofScene();
    void to_menu();
private:
    QGraphicsPixmapItem *background;
    startmenu* pauseMenu;
public slots:
    void start();
    void paused();
    void cont();
    void to_bkpk();
};

#endif // SCENE_H
