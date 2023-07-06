#include "globalvar.h"
#include "mainwindow.h"
#include <QGraphicsView>
#include <QApplication>
#include <string>
#include <QString>

mainwindow::mainwindow(QApplication *a, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow), app(a)
{
    ui->setupUi(this);
    QString s=QString(":/resources/image/startmenu.jpg");
    menu=new startmenu(s);
    view=new QGraphicsView(menu);
    view->setFixedSize(800,600);
    view->show();
    player = new QMediaPlayer(this);
    connect(menu->start, &mybtn::btnClicked, this, &mainwindow::newScene);
    connect(menu->exit, &mybtn::btnClicked, a, &QApplication::quit);
    bgm=new QAudioOutput;
    player->setAudioOutput(bgm);
    player->setSource(QUrl(":/resources/audio/menu.mp3"));
    bgm->setVolume(bgmSound);
    player->setLoops(INFINITY);
    player->play();
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void mainwindow::newScene(){
    curScene=1;
    initScene();
}
void mainwindow::initScene(){

    QGraphicsVideoItem *Vitem = new QGraphicsVideoItem;
    player->setVideoOutput(Vitem);
    view->scene()->addItem(Vitem);
    view->show();
    activeScene=new scene(curScene,this);
    connect(activeScene, &scene::endofScene, this, &mainwindow::nextScene);
    connect(this, &mainwindow::playScene, activeScene, &scene::start);
    connect(activeScene, &scene::to_menu, this, &mainwindow::to_menu);
    std::string s=":/resources/animation/"+std::to_string(curScene)+std::string(".mp4");
    player->setSource(QUrl(QString::fromStdString(s)));
    player->play();
    view->hide();
    emit playScene();
    activeScene->show();
}
void mainwindow::nextScene(){
    if (curScene<5) {
        curScene++;
        initScene();
    }
    else {
        activeScene->hide();
        view->show();
        view->setScene(menu);
    }

}
void mainwindow::contScene(){
    curScene=prevScene;
    initScene();
}
void mainwindow::to_menu(){
    prevScene=curScene;
    menu->checkCont();
    if (menu->cont) connect(menu->cont, &mybtn::btnClicked, this, &mainwindow::contScene);
    view->setScene(menu);
    activeScene->hide();
    view->show();
}
mainwindow::~mainwindow()
{
    delete ui;
}
