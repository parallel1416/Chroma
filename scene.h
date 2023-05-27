
#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QWidget>

class scene : public QGraphicsScene
{
public:
    explicit scene(QObject *parent = nullptr);

    int sceneNum;
signals:
    void endofScene();
private:
    QGraphicsPixmapItem *background;
public slots:
    void updateBackground(scene *scene);
    void startDialog(gameobject* obj);
};

#endif // SCENE_H
