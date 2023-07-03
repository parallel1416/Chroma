
#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include <qsize.h>
#include "item.h"
extern int bgmSound, toolSound, storySound;
extern int curScene, prevScene;
extern int colorStatus[6];
extern Item* items[6];
extern int use_color;
extern QSize btnSize, boxSize;

class globalvar
{
public:
    globalvar();
};

#endif // GLOBALVAR_H
