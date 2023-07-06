#ifndef BATTLE_PANEL_H
#define BATTLE_PANEL_H
#include <QMainWindow>
#include <QProgressBar>

class battle_panel
{
public:
    battle_panel();
    QMainWindow* initialize();
    int use_skill;
    QProgressBar* pbh;
};

#endif // BATTLE_PANEL_H
