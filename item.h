
#ifndef ITEM_H
#define ITEM_H


#include <QObject>
#include <QWidget>


#include <QList>
#include <QMap>
#include <QString>

// 道具类，包含名称和描述
class Item
{
public:
    // 构造函数，初始化名称和描述
    Item(const QString &name, const QString &description);

    // 获取和设置名称
    QString getName() const;
    void setName(const QString &value);

    // 获取和设置描述
    QString getDescription() const;
    void setDescription(const QString &value);

private:
    // 名称
    QString name;

    // 描述
    QString description;
};

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


#endif // ITEM_H
