
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
    activeScene=new scene;
    connect(activeScene, &scene::endofScene, this, &mainwindow::nextScene);
    connect(menu->start, &mybtn::btnClicked, this, &mainwindow::initScene);
    connect(menu->exit, &mybtn::btnClicked, a, &QApplication::quit);
}

mainwindow::~mainwindow()
{
    delete ui;
}
