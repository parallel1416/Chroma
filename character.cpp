#include "character.h"
#include "globalvar.h"

// 构造函数，初始化属性
Character::Character(int speed, QString& name)

{
    this->speed = speed;
    this->interact = false;
    pic=QPixmap(":/resources/image/"+name+".png");
    setPixmap(pic);
    // QSoundEffect对象，设置要播放的音频文件的源和音量
    sound = new QSoundEffect();
    sound->setSource(QUrl(":/resources/audio/walk.wav"));
    sound->setVolume(storySound);
    setFocusPolicy(Qt::StrongFocus);
    // QGraphicsItemAnimation对象，指定要动画的对象和时间线，设置时间线的持续时间为0.5秒
    animation = new QGraphicsItemAnimation();
    timeline = new QTimeLine(500);
    animation->setItem(this);
    animation->setTimeLine(timeline);
}

// 边界函数
QRectF Character::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

// 碰撞检测函数
bool Character::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);

    // 判断两个圆形的距离是否小于半径之和
    qreal dx = other->QGraphicsItem::x() - QGraphicsItem::x();
    qreal dy = other->QGraphicsItem::y() - QGraphicsItem::y();
    qreal distance = qSqrt(dx * dx + dy * dy);

    return distance < 20;
}

// 按键事件处理函数
// 按键事件处理函数
void Character::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Left:
        // 向左移动，注意边界检查
        if (QGraphicsItem::x() > 0) {
            setPos(QGraphicsItem::x()-speed,QGraphicsItem::y());
            sound->play();
            setPixmap(QPixmap(":/resources/image/hero_l.png"));
        }
        break;
    case Qt::Key_Right:
        // 向右移动，注意边界检查
        if (QGraphicsItem::x() < 800) {
            setPos(QGraphicsItem::x()+speed,QGraphicsItem::y());
            sound->play();
            setPixmap(QPixmap(":/resources/image/hero_r.png"));
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
bool Character::getInteract(){return interact;}
void Character::setInteract(bool b){interact=b;}
void Character::setSpeed(int s){speed=s;}
