
#include "globalvar.h"
int bgmSound=50, toolSound=50, storySound=50;
int curScene=0, prevScene=0;

QSize btnSize(120,60), boxSize(50,50), picSize(200,200);
int colorStatus[5]={0};

globalvar::globalvar()
{

}
void globalvar::setBgmSound(int value)
{
    // 修改bgmSound的值
    bgmSound = value;
}

void globalvar::setToolSound(int value)
{
    // 修改toolSound的值
    toolSound = value;
}

void globalvar::setStorySound(int value)
{
    // 修改storySound的值
    storySound = value;
}


