#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Character(int speed, int dir, int x, QString& name);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
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

private:
    int hp=100; // 生命值
    int atk=100; // 攻击力
    int speed=0; // 移动速度
    int dir=0;
    bool interact; // 交互标志

    QPixmap pic;
    QSoundEffect *sound; // 用于存储音效对象
    QGraphicsItemAnimation *animation; // 用于存储动画对象
    QTimeLine *timeline; // 用于存储时间线对象
};


#endif // CHARACTER_H
