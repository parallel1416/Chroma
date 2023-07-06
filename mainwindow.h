
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
    QGraphicsView* view, gameView, settingsView, pauseView, bkpkView;
    QMediaPlayer* player;
    void initScene();
    QAudioOutput* bgm;
    Setting* setting;

public slots:
    void newScene();
    void contScene();
    void nextScene();
    void to_menu();
    void to_setting();
signals:
    void playScene();
};

#endif // MAINWINDOW_H
