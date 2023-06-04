
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "scene.h"
#include "startmenu.h"


class mainwindow : public QWidget

{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    scene* activeScene;
    startmenu* menu;
};

#endif // MAINWINDOW_H
