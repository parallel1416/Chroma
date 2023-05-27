
#ifndef MYBTN_H
#define MYBTN_H

#include <QPushButton>
#include <QMediaPlayer>
#include <QWidget>
#include <QAudioOutput>


class mybtn : public QPushButton
{
public:
    mybtn();
    void press();
    void select();
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void clicked();
};

#endif // MYBTN_H
