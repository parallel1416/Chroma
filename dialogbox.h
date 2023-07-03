#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QSignalMapper>
#include <QTimer>
#include <QJsonDocument>

class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QWidget *parent = nullptr);
    ~DialogBox();

    // 加载和解析一个json文件
    void loadJson(const QString &fileName);

    // 显示一个内容
    void showContent();

    // 设置背景图像
    void setPixmap(const QPixmap& m);

private slots:
    // 更新场景
    void updateScene(const QString &option);

    // 更新文本
    void updateText();

private:
    QMessageBox *messageBox; // 消息框对象
    QLabel *leftCharacter; // 左边角色标签对象
    QLabel *rightCharacter; // 右边角色标签对象
    QSignalMapper *signalMapper; // 信号映射器对象
    QTimer *timer; // 定时器对象
    QString textBuffer; // 文本缓冲区对象
    QJsonDocument jsonDoc; // json文档对象
    QMap<QString, QString> backgroundMap; // 背景图像映射对象
    QMap<QString, QString> backpackMap; // backpack内容映射对象
};

#endif // DIALOGBOX_H
