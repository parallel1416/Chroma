
#include "scene.h"
#include "globalvar.h"
#include "startmenu.h"
scene::scene(QObject* parent){

}
scene::scene(int num){
    pause=new mybtn("P");
    pause->setFixedSize(boxSize);
    pause->move(700,50);
    bkpk=new mybtn("B");
    bkpk->setFixedSize(boxSize);
    bkpk->move(50,50);
    ensureVisible(pause);
    ensureVisible(bkpk);
    Character* H=new Character(100,100,100,100);
    Character* npc=new Character(100,100,100,100);
    switch (num) {
    case 1:
        map[0]=new Map(":/resources/image/world1.jpg",800,600);
        map[1]=new Map(":/resources/image/city1.jpg",800,600);
        map[2]=new Map(":/resources/image/mono1.jpg",800,600);
        map[0]->setCharacter(H,0);
        map[0]->addTeleportPoint(800, map[1]);
        map[0]->addInteractionPoint(750, "Enter");
        break;
    default:
        break;
    }
    for (int i = 0; i < 3; ++i) {
        map[i]->addWidget(pause);
        map[i]->addWidget(bkpk);
    }
    connect(pause, &mybtn::btnClicked, this, &scene::paused);
}

void scene::start(){
    setScene(map[0]);
}

void scene::paused(){
    startmenu* pauseMenu=new startmenu;
    pauseMenu->start->setText("CONTINUE");
    setScene(pauseMenu);
    QPixmap bkgrd(":/resources/image/pause.jpg");
    pauseMenu->addPixmap(bkgrd);
}
