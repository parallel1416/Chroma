
#include "scene.h"
#include "battle.h"
#include "dialogbox.h"
#include "globalvar.h"
#include "startmenu.h"

scene::scene(int num, QObject* parent){
    pause=new mybtn("");
    pause->setIcon(QIcon(QPixmap(":/resources/image/pause.png")));
    pause->setIconSize(QSize(35,35));
    pause->setFixedSize(boxSize);
    pause->move(700,50);
    bkpk=new mybtn("");
    bkpk->setIcon(QIcon(QPixmap(":/resources/image/packpack.png")));
    bkpk->setIconSize(QSize(40,40));
    bkpk->setFixedSize(boxSize);
    bkpk->move(50,50);
    ensureVisible(pause);
    ensureVisible(bkpk);
    backpack=new Backpack();
    connect(backpack, &Backpack::to_game, this, &scene::cont);
    QString s="hero_f";
    Character* H=new Character(10,s);
    H->QGraphicsItem::setFocus();
    s="BI";
    Character* BI=new Character(0,s);
    left=new mybtn("L");
    left->setFixedSize(boxSize);
    left->move(50,500);
    left->setStyleSheet("background-color: rgba(255, 255, 255, 100);"); // 半透明
    right=new mybtn("R");
    right->setFixedSize(boxSize);
    right->move(150,500);
    right->setStyleSheet("background-color: rgba(255, 255, 255, 100);"); // 半透明
    connect(left, &mybtn::pressed, H, &Character::moveLeft); // 按下按钮时移动
    connect(left, &mybtn::released, this, &scene::moveCharacter); // 松开按钮时停止移动
    connect(right, &mybtn::pressed, H, &Character::moveRight); // 按下按钮时移动
    connect(right, &mybtn::released, this, &scene::moveCharacter); // 松开按钮时停止移动
    connect(right, &mybtn::released, this, &scene::temp);
    switch (num) {
    case 1:
        map[0]=new Map(":/resources/image/world1.jpg",800,600);
        map[1]=new Map(":/resources/image/city1.jpg",800,600);
        map[2]=new Map(":/resources/image/mono1.jpg",800,600);
        map[0]->setCharacter(H,500);
        map[0]->addTeleportPoint(800, map[1]);

        map[0]->addInteractionPoint(750, "Enter");
        for (int i = 5; i < 10; ++i) {
            backpack->putItem(i);
        }
        map[1]->addInteractionPoint(600,"");
        map[1]->setCharacter(BI,610);
        break;
    default:
        break;
    }
    for (int i = 0; i < 3; ++i) {
        map[i]->addWidget(pause);
        map[i]->addWidget(bkpk);
        //map[i]->addWidget(left);
        map[i]->addWidget(right);
        //connect(left, &mybtn::pressed, map[i], &Map::moveLeft);
        //connect(right, &mybtn::pressed, map[i], &Map::moveRight);
    }
    connect(pause, &mybtn::btnClicked, this, &scene::paused);
    connect(bkpk, &mybtn::btnClicked, this, &scene::to_bkpk);
    s=QString(":/resources/image/pause.jpg");
    pauseMenu=new startmenu(s);
    pauseMenu->start->setText("CONTINUE");
    pauseMenu->exit->setText("EXIT");
    connect(pauseMenu->start, &mybtn::btnClicked, this, &scene::cont);
    connect(pauseMenu->exit, &mybtn::btnClicked, this, &scene::to_menu);
    setting=new Setting(pauseMenu);
    connect(setting, &Setting::backToMenu, this, &scene::paused);
    connect(pauseMenu->settings, &mybtn::btnClicked, this, &scene::to_setting);
    dialog=new DialogBox;
}

void scene::start(){
    setScene(map[0]);
    activeMap=map[0];
}
void scene::cont(){
    setScene(activeMap);
}

void scene::paused(){
    setScene(pauseMenu);
}

void scene::to_bkpk(){
    backpack->showItems();
    setScene(backpack);
}

void scene::to_setting(){
    setScene(setting);
}
void scene::moveCharacter(){ activeMap->character->stop(); // 停止角色移动
}
void scene::temp(){
    battle bat;
    for (int i = 0; i < 5; ++i) {
        colorStatus[i]=1;
    }
    bat.start();
    /*dialog->loadJson(":/resources/script/1.2.json");
    dialog->setPixmap(QPixmap(":/resources/image/city1.jpg"));
    //dialog->leftCharacter->setPixmap(QPixmap(":/resources/image/red_wolf.png"));
    dialog->rightCharacter->setPixmap(QPixmap(":/resources/image/blue_iceman.png"));
    // 显示内容
    dialog->showContent();

    // 显示对话框
    dialog->show();*/
}
