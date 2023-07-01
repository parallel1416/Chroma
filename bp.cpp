#include "bp.h"
#include "bp.ui"
#include "globalvar.h"
#include <QPalette>
#include <QPushButton>
#include <QSoundEffect>

/*
#TODO:
1.add USE & BACK
2.color pictures 大小调整
3.QSoundEffect
*/

int color_slots[6]={};

bp::bp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bp)
{
    ui->setupUi(this);
    this->resize(480,330);
    QPalette pa(this->palette());
    QImage img = QImage(":/background color/grey pure.png");
    img = img.scaled(this->size());
    QBrush *pic = new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    this->setPalette(pa);
    use_color=-1;

    const char * route[6];
    route[0]=":/color pictures/emoji1.png";
    route[1]=":/color pictures/emoji2.png";
    route[2]=":/color pictures/emoji3.png";
    route[3]=":/color pictures/emoji4.png";
    route[4]=":/color pictures/emoji5.png";
    route[5]=":/color pictures/emoji6.png";

    QPushButton* push[6];
    push[0]=new QPushButton("",this);
    push[1]=new QPushButton("",this);
    push[2]=new QPushButton("",this);
    push[3]=new QPushButton("",this);
    push[4]=new QPushButton("",this);
    push[5]=new QPushButton("",this);
    push[0]->setFlat(1);
    push[1]->setFlat(1);
    push[2]->setFlat(1);
    push[3]->setFlat(1);
    push[4]->setFlat(1);
    push[5]->setFlat(1);
    push[0]->move(0,0);push[0]->resize(81,81);
    push[1]->move(80,0);push[1]->resize(81,81);
    push[2]->move(160,0);push[2]->resize(81,81);
    push[3]->move(0,80);push[3]->resize(81,81);
    push[4]->move(80,80);push[4]->resize(81,81);
    push[5]->move(160,80);push[5]->resize(81,81);

    int cnt=0;
    QIcon myicon;
    myicon.addFile(tr(route[0]));
    ui->color_pic->setIcon(myicon);
    ui->color_pic->setIconSize(QSize(60,60));

    for(int i=0;i<6;i++){
        color_slots[i]=-1;
        if(colorStatus[i]){
            //QIcon myicon; //新建QIcon对象
            //myicon.addFile(tr(route[i])); //让QIcon对象指向想要的图标
            //push[cnt]->setIcon(myicon); //给按钮添加图标
            //push[cnt]->setIconSize(QSize(60,60));
            color_slots[cnt]=i;
            cnt++;
        }
    }
    items[0]=new Item("Red","The red of love");
    items[1]=new Item("Magneta","The 2 of love");
    items[2]=new Item("Cyan","The 3 of love");
    items[3]=new Item("Blue","The 4 of love");
    items[4]=new Item("Yellow","The 5 of love");

    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(":\resources\audio\click.wav"));

    if(color_slots[0]!=-1){
    connect(push[0],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[0]]->getName());
        ui->color_descrip->setText(items[color_slots[0]]->getDescription());
        use_color=0;
        QIcon myicon;
        myicon.addFile(tr(route[0]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[0]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji1.png);}"
                           "QPushButton:hover{border-image:url(:/color pictures/emoji2.png);}");

    };
    if(color_slots[1]!=-1){
    connect(push[1],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[1]]->getName());
        ui->color_descrip->setText(items[color_slots[1]]->getDescription());
        use_color=1;
        QIcon myicon;
        myicon.addFile(tr(route[1]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[1]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji2.png);}"
                               "QPushButton:hover{border-image:url(:/color pictures/emoji3.png);}");
    };
    if(color_slots[2]!=-1){
    connect(push[2],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[2]]->getName());
        ui->color_descrip->setText(items[color_slots[2]]->getDescription());
        use_color=2;
        QIcon myicon;
        myicon.addFile(tr(route[2]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[2]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji3.png);}"
                               "QPushButton:hover{border-image:url(:/color pictures/emoji4.png);}");
    };
    if(color_slots[3]!=-1){
    connect(push[3],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[3]]->getName());
        ui->color_descrip->setText(items[color_slots[3]]->getDescription());
        use_color=3;
        QIcon myicon;
        myicon.addFile(tr(route[3]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[3]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji4.png);}"
                               "QPushButton:hover{border-image:url(:/color pictures/emoji5.png);}");
    };
    if(color_slots[4]!=-1){
    connect(push[4],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[4]]->getName());
        ui->color_descrip->setText(items[color_slots[4]]->getDescription());
        use_color=4;
        QIcon myicon;
        myicon.addFile(tr(route[4]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[4]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji5.png);}"
                               "QPushButton:hover{border-image:url(:/color pictures/emoji6.png);}");
    };
    if(color_slots[5]!=-1){
    connect(push[5],&QPushButton::clicked,this,[=](void){
        ui->color_name->setText(items[color_slots[5]]->getName());
        ui->color_descrip->setText(items[color_slots[5]]->getDescription());
        use_color=5;
        QIcon myicon;
        myicon.addFile(tr(route[5]));
        ui->color_pic->setIcon(myicon);
        ui->color_pic->setIconSize(QSize(60,60));
        effect.play();
    });
        push[5]->setStyleSheet("QPushButton{border-image:url(:/color pictures/emoji6.png);}"
                               "QPushButton:hover{border-image:url(:/color pictures/emoji1.png);}");
    };





}

bp::~bp()
{
    delete ui;
}




