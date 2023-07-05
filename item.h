
#ifndef ITEM_H
#define ITEM_H


#include <QObject>
#include <QWidget>
#include <QIcon>

#include <QList>
#include <QMap>
#include <QString>

// 道具类，包含名称和描述
class Item
{
public:
    // 构造函数，初始化名称和描述
    Item(int& i);
    int num;
    // 获取和设置名称
    QString getName() const;
    void setName(const QString &value);
    QIcon getIcon() const;
    // 获取和设置描述
    QString getDescription() const;
    void setDescription(const QString &value);

private:
    // 名称
    QString name;
    QIcon* icon;
    // 描述
    QString description;
};



#endif // ITEM_H
