#include "battle_panel.h"
#include "globalvar.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPalette>
#include <QObject>
#include <QWidget>
//#include<QSoundEffect>

battle_panel::battle_panel()
{

}

QMainWindow* battle_panel::initialize(QProgressBar* pb_w){
    use_skill=-1;fini_skill=-1;
    QMainWindow* panel=new QMainWindow;
    panel->resize(800,120);
    panel->setMenuBar(nullptr);panel->setStatusBar(nullptr);
    QPalette panel_bkg(panel->palette());
    QImage img = QImage(":/img/back.png");
    img = img.scaled(panel->size());
    QBrush *pic = new QBrush(img);
    panel_bkg.setBrush(QPalette::Window,*pic);
    panel->setPalette(panel_bkg);

    QWidget *widget = new QWidget(panel);
    panel->setCentralWidget(widget);

    QGridLayout* grid=new QGridLayout(panel);
    grid->setVerticalSpacing(0);
    grid->setRowMinimumHeight(0,0);
    grid->setRowMinimumHeight(1,30);
    grid->setRowMinimumHeight(2,50);
    grid->setRowMinimumHeight(3,80);
    //grid->setColumnStretch(6,2);

    const char * route[6];
    route[0]=":/img/color5.png";
    route[1]=":/img/color6.png";
    route[2]=":/img/color7.png";
    route[3]=":/img/color8.png";
    route[4]=":/img/color9.png";
    const char* transparent;transparent=":/img/trans.png";
    //QSoundEffect effect;
    //effect.setSource(QUrl::fromLocalFile(":\resources\audio\click.wav"));

    d[0]="hp+100";
    d[1]="rebound";
    d[2]="triple";
    d[3]="shield";
    d[4]="HOPE";


    for(int c=0;c<5;c++){
        //use_skill[c]=-1;
        if(colorStatus[c]!=0){
        panel_color[c]=new QPushButton;panel_label[c]=new QLabel;
        panel_color[c]->setFixedSize(50,50);panel_label[c]->setFixedSize(50,30);
        panel_label[c]->setText("");panel_label[c]->setAlignment(Qt::AlignHCenter);
        panel_label[c]->setStyleSheet("color: white;");

        QIcon myicon;
        myicon.addFile(route[c]);
        panel_color[c]->setIcon(myicon);
        panel_color[c]->setIconSize(QSize(45,45));
        panel_color[c]->setFlat(true);
        panel_color[c]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
        QPushButton:hover{\
        border: 3px solid red;\
         }\
        ");
        }
        else{
        panel_color[c]=new QPushButton;panel_label[c]=new QLabel;
        panel_color[c]->setFixedSize(50,50);panel_label[c]->setFixedSize(50,30);
        /*
        panel_label[c]->setText("0");panel_label[c]->setAlignment(Qt::AlignHCenter);

        QIcon myicon;
        myicon.addFile(route[c]);
        panel_color[c]->setIcon(myicon);
        panel_color[c]->setIconSize(QSize(45,45));*/
        panel_color[c]->setFlat(true);
        panel_color[c]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
        ");
        }
        grid->addWidget(panel_color[c],2,c);grid->addWidget(panel_label[c],1,c);
    }
    if(colorStatus[0]!=0)
    QObject::connect(panel_color[0],&QPushButton::clicked,widget,[=](void){
        panel_color[0]->setStyleSheet("QPushButton {\
        border: 3px solid red;\
         }\
        ");
        if(use_skill!=-1){
            panel_color[use_skill]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                                  QPushButton:hover{\
                                                          border: 3px solid red;\
                                                  }\
        ");
            panel_label[use_skill]->setText("");
        }
        use_skill=0;
        panel_label[0]->setText(d[0]);
        //effect.play();
    }
    );
    if(colorStatus[1]!=0)
    QObject::connect(panel_color[1],&QPushButton::clicked,widget,[=](void){
        panel_color[1]->setStyleSheet("QPushButton {\
        border: 3px solid red;\
         }\
        ");
        if(use_skill!=-1){
            panel_color[use_skill]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                                  QPushButton:hover{\
                                                          border: 3px solid red;\
                                                  }\
        ");
            panel_label[use_skill]->setText("");
        }
        panel_label[1]->setText(d[1]);
        use_skill=1;
        //effect.play();
    }
    );
    if(colorStatus[2]!=0)
    QObject::connect(panel_color[2],&QPushButton::clicked,widget,[=](void){
        panel_color[2]->setStyleSheet("QPushButton {\
        border: 3px solid red;\
         }\
        ");
        if(use_skill!=-1){
            panel_color[use_skill]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                                  QPushButton:hover{\
                                                          border: 3px solid red;\
                                                  }\
        ");
            panel_label[use_skill]->setText("");
        }
        use_skill=2;
        panel_label[2]->setText(d[2]);
        //effect.play();
    }
    );
    if(colorStatus[3]!=0)
    QObject::connect(panel_color[3],&QPushButton::clicked,widget,[=](void){
        panel_color[3]->setStyleSheet("QPushButton {\
        border: 3px solid red;\
         }\
        ");
        if(use_skill!=-1){
            panel_color[use_skill]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                                  QPushButton:hover{\
                                                          border: 3px solid red;\
                                                  }\
        ");
            panel_label[use_skill]->setText("");
        }
        use_skill=3;
        panel_label[3]->setText(d[3]);
        //effect.play();
    }
    );
    if(colorStatus[4]!=0)
    QObject::connect(panel_color[4],&QPushButton::clicked,widget,[=](void){
        panel_color[4]->setStyleSheet("QPushButton {\
        border: 3px solid red;\
         }\
        ");
        if(use_skill!=-1){
            panel_color[use_skill]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                                  QPushButton:hover{\
                                                          border: 3px solid red;\
                                                  }\
        ");
            panel_label[use_skill]->setText("");
        }
        use_skill=4;
        panel_label[4]->setText(d[4]);
        //effect.play();
    }
    );


    QPushButton* attack=new QPushButton;//replace with mybtn
    attack->setFixedSize(80,80);
    QIcon myicon;
    myicon.addFile(":/img/bb1.png");
    attack->setIconSize(QSize(75,75));
    attack->setIcon(myicon);
    grid->addWidget(attack,1,5,2,1);
    QObject::connect(attack,&QPushButton::clicked,widget,[=](void){
        fini_skill=use_skill;
        battle_action(pb_w);
    }
    );


    pbh=new QProgressBar;         //pbh: progress bar hero
    pbh->setMinimum(0);pbh->setMaximum(500);
    pbh->setValue(heroHP);
    pbh->setTextVisible(false);
    pbh->setFixedSize(400,20);
    pbh->setStyleSheet("QProgressBar {\
    border: 2.2px solid black;\
    color:rgb(255,255,0);\
    }\
    QProgressBar:chunk{\
    background-color:red;\
    }");
    grid->addWidget(pbh,3,0,1,6,Qt::AlignHCenter);

    widget->setLayout(grid);
    return panel;
}


void battle_panel::battle_action(QProgressBar* pb_w){
    if(use_skill!=-1){//hero attack
    int n=use_skill;
    if (n == 0&&colorStatus[0]) {
        heroHP += 100;
        colorStatus[0] = 0;
    }
    else if (n == 1&&colorStatus[1]) {
        last_act= 1;
        wizHP -= 100;
        colorStatus[1] = 0;
    }
    else if (n == 2&&colorStatus[2]) {
        wizHP -=300;
        colorStatus[2] = 0;
    }
    else if (n == 3&&colorStatus[3]) {
        last_act= 3;
        colorStatus[3] = 0;
    }
    else if (n == 4&&colorStatus[4]) {
        if (heroHP < 200) {
            heroHP = 500;
        }
        colorStatus[4] = 0;
    }
    else {
        wizHP -= 100;
    }
    }
    else{
    wizHP-=100;
    }

    update_hp(pb_w);
    //delete bs;

    //wiz attack
    if (last_act==1) {
    heroHP -= 100;
    wizHP -= 100;
    }
    else if (last_act == 3) {
    heroHP -= 50;
    }
    else {
    heroHP -= 100;
    }

    update_hp(pb_w);

    last_act=-1;

}

void battle_panel::update_hp(QProgressBar* pb_w){
    const char* transparent;transparent=":/img/trans.png";
    pb_w->setValue(wizHP);
    pbh->setValue(heroHP);
    for(int i=0;i<5;i++){
    if(colorStatus[i]==0){
        QIcon myicon;
        myicon.addFile(transparent);
        panel_color[i]->setIcon(myicon);
        panel_color[i]->setStyleSheet("QPushButton {\
        border: 3px solid black;\
         }\
                                      QPushButton:hover{\
                                              border: 3px solid black;\
                                      }\
                                      QPushButton:pressed{\
                                              border: 3px solid black;\
                                      }\
        ");
        d[i]="";
    }
    }
}
