#ifndef SETTING_H
#define SETTING_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QSlider>
#include "globalvar.h"
#include "mybtn.h"

class Setting : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Setting(QGraphicsScene *backScene, QObject *parent = nullptr);

signals:
    void backToMenu(); // 返回到主菜单
public slots:
    void to_menu();
private:
    QGraphicsTextItem *title; // 标题
    mybtn *backButton; // 返回按键
    QGraphicsScene *backScene; // 返回的场景
    QSlider *bgmSlider;
    QSlider *toolSlider;
    QSlider *storySlider;
};

#endif // SETTING_H
