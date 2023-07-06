#include "setting.h"

Setting::Setting(QGraphicsScene *backScene, QObject *parent) : QGraphicsScene(parent)
{
    // 设置背景颜色
    setBackgroundBrush(QBrush(Qt::black));

    // 创建标题，参数按需修改
    title = new QGraphicsTextItem("Setting");
    title->setDefaultTextColor(Qt::white);
    title->setFont(QFont("Microsoft YaHei UI", 36));
    title->setPos(250, 50);
    addItem(title);

    // 创建返回按键
    backButton = new mybtn("BACK");
    backButton->setPos(350, 500);
    backButton->setFixedSize(btnSize);
    connect(backButton,&mybtn::btnClicked, this, &Setting::to_menu);
    addWidget(backButton);

    // 创建背景音乐音量滑动条
    bgmSlider = new QSlider(Qt::Horizontal);
    bgmSlider->setRange(0, 100); // 设置范围为0到100
    bgmSlider->setSingleStep(1); // 设置步长为1
    bgmSlider->setValue(50); // 设置初始值为50
    bgmSlider->setGeometry(200, 200, 200, 20); // 设置位置和大小，根据需要修改参数
    addWidget(bgmSlider);

    // 创建工具音效音量滑动条
    toolSlider = new QSlider(Qt::Horizontal);
    toolSlider->setRange(0, 100); // 设置范围为0到100
    toolSlider->setSingleStep(1); // 设置步长为1
    toolSlider->setValue(50); // 设置初始值为50
    toolSlider->setGeometry(200, 250, 200, 20); // 设置位置和大小，根据需要修改参数
    addWidget(toolSlider);

    // 创建故事音效音量滑动条
    storySlider = new QSlider(Qt::Horizontal);
    storySlider->setRange(0, 100); // 设置范围为0到100
    storySlider->setSingleStep(1); // 设置步长为1
    storySlider->setValue(50); // 设置初始值为50
    storySlider->setGeometry(200, 300, 200, 20); // 设置位置和大小，根据需要修改参数
    addWidget(storySlider);
}

void Setting::to_menu(){
    emit backToMenu();
}
