
#include "mainwindow.h"
#include <QGraphicsView>
#include <QApplication>

mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
{
    menu=new startmenu;
    QGraphicsView view(menu);
    view.show();
}

mainwindow::~mainwindow()
{

}


