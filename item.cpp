
#include "item.h"

// 构造函数，初始化名称和描述
Item::Item(int& i)
{
    num=i;
    QString name[10]={"Primordial Green","Primordial Magenta","Primordial Cyan","Primordial Blue","Primordial Yellow",
                        "The Green of Life","The Magenta of Love","The Cyan of Wisdom","The Blue of Unity","The Yellow of Hope"};
    QString description[10]={"The green color you seem to have brought to this world.",
                               "The magenta color you seem to have brought to this world.",
                               "The cyan color you seem to have brought to this world.",
                               "The blue color you seem to have brought to this world.",
                               "The yellow color you seem to have brought to this world.",
                               "Gifted to you by a wanderer. It reminds you of grass, trees, and flower fields.",
                               "Gifted to you by a someone who searches for love. Its hues are like red wine swaying in a tall glass.",
                               "Gifted to you by a piece of ice. It won't last forever.",
                               "Gifted to you by two dragons. You now walk with the Dragon's Blessing.",
                               "Gifted to you by a lion. Hope doesn't do anything. It's just hope."};
    this->name = name[i];
    this->description = description[i];
    QPixmap pic=QPixmap(":/resources/image/color"+QString::fromStdString(std::to_string(num))+".png");
    icon=new QIcon(pic);
}

// 获取和设置名称
QString Item::getName() const
{
    return name;
}
QIcon Item::getIcon() const
{
    return *icon;
}
void Item::setName(const QString &value)
{
    name = value;
}

// 获取和设置描述
QString Item::getDescription() const
{
    return description;
}

void Item::setDescription(const QString &value)
{
    description = value;
}

