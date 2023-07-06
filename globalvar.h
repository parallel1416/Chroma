
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
    void setBgmSound(int value); // 设置bgmSound的值
    void setToolSound(int value); // 设置toolSound的值
    void setStorySound(int value); // 设置storySound的值
};

#endif // GLOBALVAR_H
