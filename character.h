#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

class Character :public QWidget,  public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Character(int speed, QString& name);
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    virtual void keyPressEvent(QKeyEvent *event) override;

    int getHp() const;
    void setHp(int value);

    int getAtk() const;
    void setAtk(int value);
    bool getInteract();
    void setInteract(bool b);
    void setSpeed(int s);
    void moveLeft();
    void moveRight();
    void stop();
    int speed=0; // 移动速度
private:
    int hp=100; // 生命值
    int atk=100; // 攻击力

    bool interact; // 交互标志

    QPixmap pic;
    QSoundEffect *sound; // 用于存储音效对象
    QGraphicsItemAnimation *animation; // 用于存储动画对象
    QTimeLine *timeline; // 用于存储时间线对象
};


#endif // CHARACTER_H
