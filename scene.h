
#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include "map.h"
#include "mybtn.h"
#include "qgraphicsview.h"
#include "setting.h"
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
    Setting* setting;
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
    void to_setting();
};

#endif // SCENE_H
