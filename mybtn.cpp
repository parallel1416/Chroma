
#include "mybtn.h"
#include "qmediaplayer.h"
#include "globalvar.h"

mybtn::mybtn(QString& s)
{
    setText(s);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(toolSound);
}

void mybtn::mousePressEvent(QMouseEvent *event)
{
    player->setSource(QUrl::fromLocalFile("/resources/audio/press.WAV"));
    player->play();
    emit clicked();
}

void mybtn::HoverEnterEvent(QMouseEvent *ev)
{
    player->setSource(QUrl::fromLocalFile("/resources/audio/hover.WAV"));
    player->play();
}
