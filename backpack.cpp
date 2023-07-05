
#include "backpack.h"

// 构造函数，初始化存储空间大小
Backpack::Backpack()
{
    setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(Qt::white);
    for (int i = 0; i < 6; ++i) {
        push[i]=new mybtn("");
        push[i]->setFlat(1);
        push[i]->setFixedSize(picSize);
        addWidget(push[i]);
    }
    push[0]->move(0,0);
    push[1]->move(200,0);
    push[2]->move(0,200);
    push[3]->move(200,200);
    push[4]->move(0,400);
    push[5]->move(200,400);
    back=new mybtn("X");
    back->setFixedSize(boxSize);
    back->move(700,50);
    addWidget(back);
    connect(back, &mybtn::btnClicked, this, &Backpack::to_game);
    use=new mybtn("USE");
    use->setFixedSize(btnSize);
    use->move(500,450);
    addWidget(use);
    name=new QLabel();
    name->move(400,0);
    description=new QLabel();
    description->move(400,200);
    addWidget(name);
    addWidget(description);
}

// 放入一个道具，返回是否成功
bool Backpack::putItem(int i)
{
    Item* item=new Item(i);
    if (item == nullptr) {
        return false;
    }

    // 将道具添加到列表中，并更新映射中的数量
    items.append(item);
    itemCounts[item]++;

    return true;
}

// 消耗一个道具，返回是否成功
bool Backpack::consumeItem(Item *item)
{

    if (item == nullptr) {
        return false;
    }

    // 如果背包中没有该道具，则返回失败
    if (!itemCounts.contains(item) || itemCounts[item] == 0) {
        return false;
    }

    // 从列表中移除该道具，并更新映射中的数量
    items.removeOne(item);
    itemCounts[item]--;

    return true;
}

// 显示背包中的道具信息，包括数量和描述
void Backpack::showItems()
{
    // 遍历打印出每种道具的名称和描述
    int i=0;
    for (auto it = items.begin(); it != items.end(); ++it) {
        Item *item = *it;
        push[i]->setIcon(item->getIcon());
        push[i]->setIconSize(QSize(120,120));
        i++;
    }
    connect(push[0],&mybtn::btnClicked,this,&Backpack::showDes0);
}

void Backpack::showDes0(){
    Item* it=items.front();
    name->setText(it->getName());
    description->setText(it->getDescription());
}
