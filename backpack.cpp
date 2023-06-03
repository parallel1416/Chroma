
#include "backpack.h"

// 构造函数，初始化存储空间大小
Backpack::Backpack(int size)
{
    this->size = size;
}

// 放入一个道具，返回是否成功
bool Backpack::putItem(Item *item)
{

    if (item == nullptr) {
        return false;
    }

    // 如果背包已满，则返回失败
    if (items.size() == size) {
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

    if (items.isEmpty()) {
        qDebug() << "The backpack is empty.";
        return;
    }

    qDebug() << "The backpack contains:";

    // 遍历映射中的键值对，打印出每种道具的名称，数量和描述
    for (auto it = itemCounts.begin(); it != itemCounts.end(); ++it) {
        Item *item = it.key();
        int count = it.value();
        qDebug() << item->getName() << "(" << count << "):" << item->getDescription();
    }
}
