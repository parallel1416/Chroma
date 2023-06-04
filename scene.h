
#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include "gameobject.h"
#include "map.h"
#include "character.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QWidget>

class scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit scene(QObject *parent = nullptr);

    int sceneNum;
signals:
    void endofScene();
private:
    QGraphicsPixmapItem *background;
public slots:
    //void updateBackground(scene *scene);
    //void initDialog(gameobject* obj);
};

#endif // SCENE_H
