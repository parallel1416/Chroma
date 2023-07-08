#include "battle.h"
#include "battle_scene.h"
#include<QGraphicsProxyWidget>


/*
color 0-green
1-magneta//enemy suffer same damage
2-int cyan//triple damage at next attack
3-blue//change - shielded from next attack
4- yellow/
*/

battle::battle()
{

}

void battle::start(){
    bs=new battle_scene();
    bs->showscene();
}


