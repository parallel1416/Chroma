
#ifndef SCENE_H
#define SCENE_H
#include <QObject>
#include "dialogbox.h"
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
    Map* activeMap;
    Backpack* backpack;
    Setting* setting;

    mybtn* left; // 左移按钮
    mybtn* right; // 右移按钮
    Character* hero;
    DialogBox* dialog;
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
    void moveCharacter();
    void temp();
};

#endif // SCENE_H
