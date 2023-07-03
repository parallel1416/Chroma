
#include "item.h"

// 构造函数，初始化名称和描述
Item::Item(const QString &name, const QString &description)
{
    this->name = name;
    this->description = description;
}

// 获取和设置名称
QString Item::getName() const
{
    return name;
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

