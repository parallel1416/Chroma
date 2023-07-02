
#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include "map.h"
#include "mybtn.h"
#include "qgraphicsview.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QWidget>

class scene : public QGraphicsView
{
    Q_OBJECT
public:
    scene(int num);
    explicit scene(QObject *parent = nullptr);
    Map* map[3];
    int sceneNum;
    mybtn* pause;
    mybtn* bkpk;
signals:
    void endofScene();
private:
    QGraphicsPixmapItem *background;
public slots:
    void start();
    void paused();
    //void updateMap(scene *scene);
    //void initDialog(gameobject* obj);
};

#endif // SCENE_H
