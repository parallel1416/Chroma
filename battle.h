#ifndef BATTLE_H
#define BATTLE_H
#include "battle_scene.h"
#include "battle_panel.h"
#include "globalvar.h"
#include<QGraphicsProxyWidget>

class battle
{
public:
    battle();
    void start();
    battle_scene* bs;
    void update_hp(battle_scene* bb);

};

#endif // BATTLE_H
