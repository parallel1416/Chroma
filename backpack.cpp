
#include "backpack.h"

// 构造函数，初始化存储空间大小
Backpack::Backpack()
{
    setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(Qt::gray);
    for (int i = 0; i < 6; ++i) {
        push[i]=new mybtn("");
        push[i]->setFlat(1);
        push[i]->setFixedSize(picSize);
        addWidget(push[i]);
    }
    push[0]->move(2,2);
    push[1]->move(204,2);
    push[2]->move(2,204);
    push[3]->move(204,204);
    push[4]->move(2,406);
    push[5]->move(204,406);
    back=new mybtn("X");
    back->setFixedSize(boxSize);
    back->move(700,50);
    addWidget(back);
    connect(back, &mybtn::btnClicked, this, &Backpack::to_game);
    use=new mybtn("USE");
    use->setFixedSize(btnSize);
    use->move(550,450);
    addWidget(use);
    connect(use,&mybtn::btnClicked, this, &Backpack::consumeItem);
    name=new QLabel();
    name->move(450,100);
    name->setFrameStyle(QFrame::Panel);
    name->setFixedSize(QSize(300,50));
    name->setWordWrap(true);
    name->setAlignment(Qt::AlignCenter);
    name->setFont(QFont("Baskerville Old Face",14,QFont::Bold));
    description=new QLabel();
    description->move(450,200);
    description->setFrameStyle(QFrame::Panel);
    description->setFixedSize(QSize(300,200));
    description->setWordWrap(true);
    description->setAlignment(Qt::AlignTop);
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

    return true;
}

// 消耗一个道具，返回是否成功
bool Backpack::consumeItem()
{
    Item* item=colorSlots[selectNum];
    if (item == nullptr) {
        return false;
    }
    // 如果背包中没有该道具，则返回失败
    if (!items.contains(item)) {
        return false;
    }
    name->setText("");
    description->setText("");
    // 从列表中移除该道具
    items.removeOne(item);
    showItems();
    return true;
}

// 显示背包中的道具信息和描述
void Backpack::showItems()
{
    // 遍历打印出每种道具的名称和描述
    int i=0;
    colorSlots.clear();
    for (auto it = items.begin(); it != items.end(); ++it) {
        Item *item = *it;
        push[i]->setIcon(item->getIcon());
        push[i]->setIconSize(QSize(120,120));
        colorSlots[i]=item;
        i++;
        connect(push[i],&mybtn::btnClicked,this,[this, i]{showDes(i);});
    }
    for(;i<6;i++){
        push[i]->setIcon(QIcon());
    }

}

void Backpack::showDes(int i){
    selectNum=i;
    Item* it=colorSlots[i];
    name->setText(it->getName());
    description->setText(it->getDescription());
}
