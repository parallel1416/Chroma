#ifndef BP_H
#define BP_H

#include <QMainWindow>
#include "item.h"
extern int color_slots[6];

namespace Ui {
class bp;
}

class bp : public QMainWindow
{
    Q_OBJECT

public:
    explicit bp(QWidget *parent = nullptr);
    ~bp();




private:
    Ui::bp *ui;
};

#endif // BP_H
