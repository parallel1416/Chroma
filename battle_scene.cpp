#include "battle_scene.h"
#include "qgraphicsitem.h"
#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QMainWindow>
#include<QProgressBar>
#include<QPushButton>
#include<QGraphicsProxyWidget>
#include "battle_panel.h"
#include "globalvar.h"
battle_scene::battle_scene()
{


}

void battle_scene::showscene(){
    battle=new QGraphicsScene;
    battle->setSceneRect(0,0,800,600);
    battle->setBackgroundBrush(QBrush(QPixmap(":/background color/grey pure.png")));
    pbw=new QProgressBar;         //pbw: progress bar wizard
    pbw->setMinimum(0);pbw->setMaximum(1000);
    pbw->setValue(wizHP);
    pbw->setTextVisible(false);
    pbw->setFixedSize(600,20);
    pbw->setStyleSheet("QProgressBar {\
    border: 2.2px solid black;\
    color:rgb(255,255,0);\
    }\
    QProgressBar:chunk{\
    background-color:red;\
    }");
    proxy_pbw=battle->addWidget(pbw);
    proxy_pbw->setPos(100,50);
    battle_view=new QGraphicsView(battle);
    battle_view->show();

    hero_p=new battle_panel;
    hero_panel=hero_p->initialize();
    proxy_panel=battle->addWidget(hero_panel);
    proxy_panel->setPos(0,400);


}
