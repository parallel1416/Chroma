#include "dialogbox.h"
#include "mybtn.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QPushButton>

DialogBox::DialogBox(QWidget *parent) :
    QDialog(parent),
    messageBox(new QMessageBox(this)),
    leftCharacter(new QLabel(this)),
    rightCharacter(new QLabel(this)),
    signalMapper(new QSignalMapper(this)),
    timer(new QTimer(this)), // 新增一个QTimer对象
    textBuffer("") // 新增一个QString对象
{
    // 设置对话框的大小和标题
    resize(800, 600);
    setWindowTitle("Dialog");

    // 设置消息框的属性
    messageBox->setWindowTitle("Content");
    messageBox->setWindowModality(Qt::ApplicationModal);
    messageBox->setIcon(QMessageBox::NoIcon);

    // 设置角色标签的属性
    leftCharacter->setGeometry(50, 50, 200, 400);
    rightCharacter->setGeometry(550, 50, 200, 400);

    // 连接信号映射器到一个槽函数
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(updateScene(QString)));

    // 连接QTimer对象的timeout信号到一个新的槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(updateText()));
}

DialogBox::~DialogBox()
{
}

void DialogBox::loadJson(const QString &fileName)
{
    // 打开json文件并读取其内容
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Cannot open file: %s", qPrintable(file.errorString()));
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    // 解析json数据并将其存储在一个文档对象中
    QJsonParseError error;
    jsonDoc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning("Parse error: %s", qPrintable(error.errorString()));
        return;
    }

}

void DialogBox::showContent()
{
    // 从json文档中获取当前场景对象
    QJsonObject scene = jsonDoc.object();

    // 从场景对象中获取说话者和文本
    QString speaker = scene.value("speaker").toString();
    QString text = scene.value("text").toString();

    // 初始化QString对象为文本内容
    textBuffer = text;

    // 使用说话者设置消息框的文本，但不显示文本内容
    messageBox->setText(QString("<b>%1</b>: ").arg(speaker));

    // 设置QTimer对象的间隔为100毫秒，并启动它
    timer->setInterval(100);
    timer->start();

    // 从场景对象中获取选项数组
    QJsonArray options = scene.value("options").toArray();

    // 清除之前的按钮和映射
    messageBox->setStandardButtons(QMessageBox::NoButton);
    signalMapper->removeMappings(messageBox);
    backgroundMap.clear();
    backpackMap.clear();

    // 遍历每个选项对象并为其创建一个按钮
    for (int i = 0; i < options.size(); i++) {
        QJsonObject option = options.at(i).toObject();

        // 从选项对象中获取选项文本
        QString optionText = option.value("text").toString();

        // 使用选项文本创建一个按钮
        QPushButton *button = messageBox->addButton(optionText, QMessageBox::ActionRole);

        // 从选项对象中获取下一个场景文件名
        QString nextScene = option.value("nextScene").toString();

        // 使用信号映射器将按钮映射到下一个场景文件名
        signalMapper->setMapping(button, nextScene);

        // 连接按钮点击信号到信号映射器map槽函数
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));

        // 从选项对象中获取背景图像文件名
        QString backgroundImage = option.value("backgroundImage").toString();

        // 使用选项文本作为键将背景图像文件名存储在一个映射中
        backgroundMap.insert(optionText, backgroundImage);

        // 从选项对象中获取backpack内容
        QString backpackContent = option.value("backpackContent").toString();

        // 使用选项文本作为键将backpack内容存储在一个映射中
        backpackMap.insert(optionText, backpackContent);
    }

    // 显示消息框
    messageBox->show();
}
void DialogBox::setPixmap(const QPixmap& m){}
void DialogBox::updateScene(const QString &option)
{
    // 隐藏消息框
    messageBox->hide();

    // 停止QTimer对象
    timer->stop();

    // 使用选项作为键从映射中获取背景图像文件名
    QString backgroundImage = backgroundMap.value(option);

    // 使用QPixmap类加载和设置背景图像
    QPixmap backgroundPixmap(backgroundImage);
    setPixmap(backgroundPixmap);

    // 使用选项作为键从映射中获取backpack内容
    QString backpackContent = backpackMap.value(option);

    // 在这里对backpack内容做一些操作

    // 使用选项作为文件名加载和解析一个新的json文件
    loadJson(option);

    // 使用新的json数据显示一个新的内容
    showContent();
}

// 定义一个新的槽函数，用来更新消息框的文本
void DialogBox::updateText()
{
    // 如果QString对象不为空，说明还有文字没有显示完
    if (!textBuffer.isEmpty()) {
        // 从QString对象中取出第一个字符，并将其追加到消息框的文本中
        QChar ch = textBuffer.at(0);
        messageBox->setText(messageBox->text() + ch);

        // 从QString对象中移除第一个字符
        textBuffer.remove(0, 1);
    }
    else {
        // 如果QString对象为空，说明文字已经显示完，停止QTimer对象
        timer->stop();
    }
}
