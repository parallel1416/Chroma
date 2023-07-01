#include "globalvar.h"
#include "mainwindow.h"
#include <QGraphicsView>
#include <QApplication>

mainwindow::mainwindow(QApplication *a, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow), app(a)
{
    ui->setupUi(this);
    menu=new startmenu;
    view=new QGraphicsView(menu);
    view->setFixedSize(800,600);
    view->show();
    connect(activeScene, &scene::endofScene, this, &mainwindow::nextScene);
    connect(menu->start, &mybtn::btnClicked, this, &mainwindow::newScene);
    connect(menu->cont, &mybtn::btnClicked, this, &mainwindow::contScene);
    connect(menu->exit, &mybtn::btnClicked, a, &QApplication::quit);

}
void mainwindow::newScene(){
    curScene=1;
    initScene();
}
void mainwindow::initScene(){
    player = new QMediaPlayer(this);
    QGraphicsVideoItem *item = new QGraphicsVideoItem;
    player->setVideoOutput(item);
    view->scene()->addItem(item);
    view->show();
    switch (curScene) {
    case 1:
        player->setSource(QUrl(":/resources/animation/1.mp4"));
        player->play();
        break;
    default:
        break;
    }
}
void mainwindow::nextScene(){
    if (curScene<5) curScene++;
    initScene();
}
mainwindow::~mainwindow()
{
    delete ui;
}
