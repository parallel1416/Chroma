
#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QLabel>
#include <QGraphicsItem>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include "mybtn.h"
#include <QDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QLabel>
#include <QPixmap>
#include <QSignalMapper>
#include <QMap>

class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QWidget *parent = nullptr);
    ~DialogBox();

    void loadJson(const QString &fileName); // 加载并解析json文件
    void showContent(); // 显示当前场景的内容
    void updateScene(const QString &option); // 根据选择的选项更新场景

private:
    QMessageBox *messageBox; // 用于显示内容和选项的消息框
    QLabel *leftCharacter; // 用于显示左边角色立绘的标签
    QLabel *rightCharacter; // 用于显示右边角色立绘的标签
    QJsonDocument jsonDoc; // 用于存储解析后的数据的json文档
    QSignalMapper *signalMapper; // 用于将按钮的信号映射到不同的槽函数的信号映射器
    QMap<QString, QString> backgroundMap; // 用于存储每个选项对应的背景图像文件名的映射
    QMap<QString, QString> backpackMap; // 用于存储每个选项对应的backpack内容的映射
};

#endif // DIALOGBOX_H
