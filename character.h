
#ifndef CHARACTER_H
#define CHARACTER_H

#include <QPainter>


#include <QGraphicsItem>
#include <QKeyEvent>

class Character : public QGraphicsItem
{
public:
    // 构造函数，初始化属性
    Character(int hp, int atk, int x, int y);

    // 重写绘图函数
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // 重写边界函数
    QRectF boundingRect() const override;

    // 重写碰撞检测函数
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

    // 重写按键事件处理函数
    void keyPressEvent(QKeyEvent *event) override;

    // 获取和设置生命值
    int getHp() const;
    void setHp(int value);

    // 获取和设置攻击力
    int getAtk() const;
    void setAtk(int value);
    bool getInteract();
    void setInteract(bool b);
    void setSpeed(int s);
private:
    // 生命值
    int hp;

    // 攻击力
    int atk;

    // 移动速度
    int speed;

    // 交互标志
    bool interact;
};



#endif // CHARACTER_H
