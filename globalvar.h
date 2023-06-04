
#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include <qsize.h>
extern int bgmSound, toolSound, storySound;
extern int curScene, prevScene;
extern int colorStatus[5];
extern QSize btnSize, boxSize;

class globalvar
{
public:
    globalvar();
};

#endif // GLOBALVAR_H
