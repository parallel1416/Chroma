
#ifndef BACKPACK_H
#define BACKPACK_H
#include "item.h"

#include <QObject>
#include <QWidget>


// 背包类，包含一维存储空间，可以实现道具的放入和消耗，可以显示道具信息
class Backpack
{
public:
    // 构造函数，初始化存储空间大小
    Backpack(int size);

    // 放入一个道具，返回是否成功
    bool putItem(Item *item);

    // 消耗一个道具，返回是否成功
    bool consumeItem(Item *item);

    // 显示背包中的道具信息，包括数量和描述
    void showItems();

private:
    // 存储空间大小
    int size;

    // 存储道具的列表，按照放入顺序排列
    QList<Item *> items;

    // 存储道具的映射，用于快速查找道具的数量
    QMap<Item *, int> itemCounts;
};



#endif // BACKPACK_H
