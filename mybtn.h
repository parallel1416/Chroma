
#ifndef MYBTN_H
#define MYBTN_H
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QMediaPlayer>
#include <QWidget>
#include <QAudioOutput>


class mybtn : public QPushButton
{
public:
    mybtn();
    mybtn(QString& s);
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void HoverEnterEvent(QMouseEvent *event);
signals:
    void clicked();
};

#endif // MYBTN_H
