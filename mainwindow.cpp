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
    menu=new startmenu;
    view=new QGraphicsView(menu);
    view->setFixedSize(800,600);
    view->show();

    connect(menu->start, &mybtn::btnClicked, this, &mainwindow::newScene);
    //connect(menu->cont, &mybtn::btnClicked, this, &mainwindow::contScene);
    connect(menu->exit, &mybtn::btnClicked, a, &QApplication::quit);

}
void mainwindow::newScene(){
    curScene=1;
    initScene();
}
void mainwindow::initScene(){
    player = new QMediaPlayer(this);
    QGraphicsVideoItem *Vitem = new QGraphicsVideoItem;
    player->setVideoOutput(Vitem);
    view->scene()->addItem(Vitem);
    view->show();
    activeScene=new scene(curScene);
    connect(activeScene, &scene::endofScene, this, &mainwindow::nextScene);
    connect(this, &mainwindow::playScene, activeScene, &scene::start);
    std::string s=":/resources/animation/"+std::to_string(curScene)+std::string(".mp4");
    player->setSource(QUrl(QString::fromStdString(s)));
    player->play();
    view->hide();
    emit playScene();
    activeScene->show();
}
void mainwindow::nextScene(){
    if (curScene<5) curScene++;
    else view->setScene(menu);
    initScene();
}
void mainwindow::contScene(){

}
mainwindow::~mainwindow()
{
    delete ui;
}
