
#include "map.h"
#include "dialogbox.h"

// 构造函数，初始化地图
Map::Map(const QString &imagePath, int width, int height)
{
    // 设置场景的大小和背景颜色
    setSceneRect(0, 0, width, height);
    setBackgroundBrush(Qt::black);

    // 加载地图图片，并添加到场景中
    mapImage = new QGraphicsPixmapItem(QPixmap(imagePath));
    addItem(mapImage);

    // 初始化角色为空指针
    character = nullptr;

    // 创建定时器，并连接到检查函数
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Map::checkInteractionOrTeleport);
}

// 添加一个交互点，指定位置和对话内容
void Map::addInteractionPoint(int x, const QString &dialog)
{
    interactionPoints[x] = dialog;
}

// 添加一个传送点，指定位置和目标地图
void Map::addTeleportPoint(int x, Map *target)
{
    teleportPoints[x] = target;
}

// 设置角色，指定初始位置
void Map::setCharacter(Character *character, int x)
{
    this->character = character;

    // 将角色添加到场景中，并设置位置
    addItem(character);
    character->setPos(x, height() / 2);
    // 启动定时器，每隔100毫秒检查一次交互或传送
    timer->start(100);
}

// 检查是否有交互或传送发生
void Map::checkInteractionOrTeleport()
{

    if (character == nullptr) {
        return;
    }

    // 获取角色的x坐标
    int x = character->QWidget::x();

    // 如果有交互点与角色重合，并且角色按下了空格键，则弹出对话框显示对话内容，并停止角色的移动和交互
    if (interactionPoints.contains(x) && character->getInteract()) {
        QMessageBox::information(nullptr, "Interaction", interactionPoints[x]);
        character->setInteract(false);
        character->setSpeed(0);
        // 创建一个dialogbox对象
        DialogBox dialog;

        // 加载exp.json文件
        dialog.loadJson(":/resources/script/exp.json");

        // 显示内容
        dialog.showContent();

        // 显示对话框
        dialog.show();
    }

    // 如果有传送点与角色重合，则将角色从当前地图移除，并添加到目标地图中，并停止当前地图的定时器
    if (teleportPoints.contains(x)) {
        removeItem(character);
        teleportPoints[x]->setCharacter(character, 100);
        timer->stop();
    }
}
