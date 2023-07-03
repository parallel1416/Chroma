#ifndef CHARACTER_H
#define CHARACTER_H


#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QPropertyAnimation>

class Character : public QGraphicsItem
{
public:
    Character(int hp, int atk, int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void keyPressEvent(QKeyEvent *event) override;

    int getHp() const;
    void setHp(int value);

    int getAtk() const;
    void setAtk(int value);
    bool getInteract();
    void setInteract(bool b);
    void setSpeed(int s);
private:
    // 生命值
    int hp;

    void setSpeed(int s);

private:
    int hp; // 生命值
    int atk; // 攻击力
    int speed; // 移动速度
    bool interact; // 交互标志

    QSoundEffect *sound; // 用于存储音效对象
    QPropertyAnimation *animation; // 用于存储动画对象
};


#endif // CHARACTER_H