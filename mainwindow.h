
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "scene.h"
#include "startmenu.h"
#include <QStackedLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsVideoItem>
#include "./ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget

{
    Q_OBJECT

public:
    mainwindow(QApplication* a, QWidget *parent = nullptr);
    ~mainwindow();

    Ui::mainwindow *ui;
    scene* activeScene;
    startmenu* menu;
    QApplication* app;
    QGraphicsView* view;
    QMediaPlayer* player;
    void initScene();

public slots:

signals:
    void newScene();
    void contScene();
    void nextScene();
};

#endif // MAINWINDOW_H
