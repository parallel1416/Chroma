
#ifndef MAP_H
#define MAP_H


#include <QObject>
#include <QWidget>
#include "character.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QTimer>

class Map : public QGraphicsScene
{
public:
    // 构造函数，初始化地图
    Map(const QString &imagePath, int width, int height);

    // 添加一个交互点，指定位置和对话内容
    void addInteractionPoint(int x, const QString &dialog);

    // 添加一个传送点，指定位置和目标地图
    void addTeleportPoint(int x, Map *target);

    // 设置角色，指定初始位置
    void setCharacter(Character *character, int x);

private slots:
    // 检查是否有交互或传送发生
    void checkInteractionOrTeleport();

private:
    // 地图图片
    QGraphicsPixmapItem *mapImage;

    // 交互点的位置和对话内容
    QMap<int, QString> interactionPoints;

    // 传送点的位置和目标地图
    QMap<int, Map *> teleportPoints;

    // 角色
    Character *character;

    // 定时器，用于周期性检查交互或传送
    QTimer *timer;
};



#endif // MAP_H
