
#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"
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

// 构造函数，初始化属性
Character::Character(int hp, int atk, int x, int y)
{
    this->hp = hp;
    this->atk = atk;
    this->speed = 10;
    this->interact = false;
    // 设置初始位置
    setPos(x, y);
}

// 重写绘图函数
void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // 绘制一个简单的圆形代表角色
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-10, -10, 20, 20);
}

// 重写边界函数
QRectF Character::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

// 重写碰撞检测函数
bool Character::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);

    // 简单地判断两个圆形的距离是否小于半径之和
    qreal dx = other->x() - x();
    qreal dy = other->y() - y();
    qreal distance = qSqrt(dx * dx + dy * dy);

    return distance < 20;
}

// 重写按键事件处理函数
void Character::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Left:
        // 向左移动，注意边界检查
        if (x() > -250) {
            moveBy(-speed, 0);
        }
        break;
    case Qt::Key_Right:
        // 向右移动，注意边界检查
        if (x() < 250) {
            moveBy(speed, 0);
        }
        break;
    case Qt::Key_Space:
        // 设置交互标志为真，表示可以进行交互操作，比如攻击或对话等
        interact = true;
        break;
    default:
        break;
    }
}

// 获取和设置生命值
int Character::getHp() const
{
    return hp;
}

void Character::setHp(int value)
{
    hp = value;
}

// 获取和设置攻击力
int Character::getAtk() const
{
    return atk;
}

void Character::setAtk(int value)
{
    atk = value;
}

#endif // CHARACTER_H
