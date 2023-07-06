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

QMainWindow* battle_panel::initialize(){
    use_skill=-1;
    QMainWindow* panel=new QMainWindow;
    panel->resize(800,200);
    panel->setMenuBar(nullptr);panel->setStatusBar(nullptr);
    QPalette panel_bkg(panel->palette());
    QImage img = QImage(":/background color/grey change.jpg");
    img = img.scaled(panel->size());
    QBrush *pic = new QBrush(img);
    panel_bkg.setBrush(QPalette::Window,*pic);
    panel->setPalette(panel_bkg);

    QWidget *widget = new QWidget(panel);
    panel->setCentralWidget(widget);

    QGridLayout* grid=new QGridLayout(panel);
    grid->setVerticalSpacing(0);
    grid->setRowMinimumHeight(0,20);
    grid->setRowMinimumHeight(1,30);
    grid->setRowMinimumHeight(2,50);
    grid->setRowMinimumHeight(3,90);
    grid->setColumnStretch(6,2);

    const char * route[6];
    route[0]=":/color pictures/emoji1.png";
    route[1]=":/color pictures/emoji2.png";
    route[2]=":/color pictures/emoji3.png";
    route[3]=":/color pictures/emoji4.png";
    route[4]=":/color pictures/emoji5.png";
    route[5]=":/color pictures/emoji6.png";
    //QSoundEffect effect;
    //effect.setSource(QUrl::fromLocalFile(":\resources\audio\click.wav"));

    QPushButton* panel_color[6];
    QLabel* panel_label[6];
    for(int c=0;c<6;c++){
        //use_skill[c]=-1;
        if(colorStatus[c]!=0){
        panel_color[c]=new QPushButton;panel_label[c]=new QLabel;
        panel_color[c]->setFixedSize(50,50);panel_label[c]->setFixedSize(50,30);
        panel_label[c]->setText("");panel_label[c]->setAlignment(Qt::AlignHCenter);

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
        panel_label[0]->setText("0");
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
        panel_label[1]->setText("0");
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
        panel_label[2]->setText("0");
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
        panel_label[3]->setText("0");
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
        panel_label[4]->setText("0");
        //effect.play();
    }
    );
    if(colorStatus[5]!=0)
    QObject::connect(panel_color[5],&QPushButton::clicked,widget,[=](void){
        panel_color[5]->setStyleSheet("QPushButton {\
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
        use_skill=5;
        panel_label[5]->setText("0");
        //effect.play();
    }
    );


    QPushButton* attack=new QPushButton;//replace with mybtn
    attack->setFixedSize(80,80);
    grid->addWidget(attack,1,6,2,1);
    QObject::connect(panel_color[5],&QPushButton::clicked,widget,[=](void){
        return nullptr;
        //effect.play();
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
    grid->addWidget(pbh,3,0,1,7,Qt::AlignHCenter);

    widget->setLayout(grid);
    return panel;
}
