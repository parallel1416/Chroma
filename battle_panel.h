#ifndef BATTLE_PANEL_H
#define BATTLE_PANEL_H
#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class battle_panel
{
public:
    battle_panel();
    QMainWindow* initialize(QProgressBar* pb_w);
    void battle_action(QProgressBar* pb_w);
    int use_skill;
    int fini_skill=-1;
    QProgressBar* pbh;
    void update_hp(QProgressBar* pb_w);
    QPushButton* panel_color[6];
    QLabel* panel_label[6];
        QString d[6];
};

#endif // BATTLE_PANEL_H
