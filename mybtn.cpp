
#include "mybtn.h"
#include "qmediaplayer.h"
#include "globalvar.h"

mybtn::mybtn()
{
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(toolSound);

    void mybtn::mousePressEvent(QMouseEvent *event)
    {
        player->setSource(QUrl::fromLocalFile("/resources/audio/press"));
        player->play();
        emit clicked();
    }

}

