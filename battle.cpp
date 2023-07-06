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
    while(true){
        bs->hero_p->initialize();
        if(bs->hero_p->use_skill!=-1){//hero attack
            int n=bs->hero_p->use_skill;
            if (n == 0) {
                heroHP += 100;
                colorStatus[0] = 0;
            }
            else if (n == 1) {
                last_act= 1;
                wizHP -= 100;
                colorStatus[1] = 0;
            }
            else if (n == 2) {
                wizHP -=300;
                colorStatus[2] = 0;
            }
            else if (n == 3) {
                last_act= 3;
                colorStatus[3] = 0;
            }
            else if (n == 4) {
                if (heroHP < 200) {
                    heroHP = 500;
                }
                colorStatus[4] = 0;
            }
            else {
                wizHP -= 100;
            }
        }
        update_hp(bs);
        //delete bs;

        //wiz attack
        if (last_act==1) {
            heroHP -= 100;
            wizHP -= 100;
        }
        else if (last_act == 3) {
            heroHP -= 50;
        }
        else {
            heroHP -= 100;
        }

        update_hp(bs);



        last_act=-1;

    }
}

void battle::update_hp(battle_scene* bb){
    bb->pbw->setValue(wizHP);
    bb->hero_p->pbh->setValue(heroHP);
}
