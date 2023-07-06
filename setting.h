#ifndef SETTING_H
#define SETTING_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QSlider>
#include "globalvar.h"

class Setting : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void backToMenu(QGraphicsScene *scene); // 返回到主菜单

private:
    QGraphicsTextItem *title; // 标题
    QGraphicsPixmapItem *backButton; // 返回按键
    QGraphicsScene *backScene; // 返回的场景
    QSlider *bgmSlider;
    QSlider *toolSlider;
    QSlider *storySlider;
};

#endif // SETTING_H
