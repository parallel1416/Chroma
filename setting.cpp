#include "setting.h"

Setting::Setting(QGraphicsScene *backScene, QObject *parent) : QGraphicsScene(parent)
{
    // 设置背景颜色
    setBackgroundBrush(QBrush(Qt::black));
    // 设置背景颜色
    setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(Qt::black);

    // 加载地图图片，并添加到场景中
    bkgrd = new QGraphicsPixmapItem(QPixmap(":/resources/image/startmenu_faded.jpg"));
    addItem(bkgrd);
    // 创建标题，参数按需修改
    title = new QGraphicsTextItem("Settings");
    title->setDefaultTextColor(Qt::white);
    title->setFont(QFont("Microsoft YaHei UI", 24));
    title->setPos(250, 50);
    addItem(title);
    bgmLabel = new QGraphicsTextItem("BGM");
    bgmLabel->setDefaultTextColor(Qt::white);
    bgmLabel->setFont(QFont("Microsoft YaHei UI", 12));
    bgmLabel->setPos(50, 200);
    addItem(bgmLabel);
    toolLabel = new QGraphicsTextItem("BUTTONS");
    toolLabel->setDefaultTextColor(Qt::white);
    toolLabel->setFont(QFont("Microsoft YaHei UI", 12));
    toolLabel->setPos(50, 250);
    addItem(toolLabel);
    storyLabel = new QGraphicsTextItem("STORY");
    storyLabel->setDefaultTextColor(Qt::white);
    storyLabel->setFont(QFont("Microsoft YaHei UI", 12));
    storyLabel->setPos(50, 300);
    addItem(storyLabel);

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
    bgmSlider->setValue(bgmSound); // 设置初始值为50
    bgmSlider->setGeometry(200, 200, 300, 20); // 设置位置和大小，根据需要修改参数
    addWidget(bgmSlider);

    // 创建工具音效音量滑动条
    toolSlider = new QSlider(Qt::Horizontal);
    toolSlider->setRange(0, 100); // 设置范围为0到100
    toolSlider->setSingleStep(1); // 设置步长为1
    toolSlider->setValue(toolSound); // 设置初始值为50
    toolSlider->setGeometry(200, 250, 300, 20); // 设置位置和大小，根据需要修改参数
    addWidget(toolSlider);

    // 创建故事音效音量滑动条
    storySlider = new QSlider(Qt::Horizontal);
    storySlider->setRange(0, 100); // 设置范围为0到100
    storySlider->setSingleStep(1); // 设置步长为1
    storySlider->setValue(storySound); // 设置初始值为50
    storySlider->setGeometry(200, 300, 300, 20); // 设置位置和大小，根据需要修改参数
    addWidget(storySlider);

    globalVar = new globalvar();

    // 在滑动条上连接槽函数，用来调用globalvar类里的修改函数
    connect(bgmSlider, &QSlider::valueChanged, this, [this](int value){globalVar->setBgmSound(value);});
    connect(toolSlider, &QSlider::valueChanged, this, [this](int value){globalVar->setToolSound(value);});
    connect(storySlider, &QSlider::valueChanged, this, [this](int value){globalVar->setStorySound(value);});
}

void Setting::to_menu(){
    emit backToMenu();
}
