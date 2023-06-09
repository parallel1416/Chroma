
#include "mybtn.h"

mybtn::mybtn(std::string s)
{
    // Set default button style
    normal=QColor(20,20,20);
    hover=QColor(40,40,40);
    press=QColor(90,90,90);
    setStyleSheet("QPushButton { background-color: #141414; color: white; border: none; padding: 10px; }"
                  "QPushButton:hover { background-color: #282828; }"
                  "QPushButton:pressed { background-color: #5A5A5A; }");

    // Load sound effect
    soundClicked.setSource(QUrl::fromLocalFile(":/resources/audio/click.wav"));
    soundHover.setSource(QUrl::fromLocalFile(":/resources/audio/hover.wav"));
    // Connect signals to slots
    connect(this, &QPushButton::clicked, this, &mybtn::playClickedSound);
    connect(this, &QPushButton::pressed, this, &mybtn::animateClick);
    connect(this, &QPushButton::released, this, &mybtn::animateRelease);
    setText(QString::fromStdString(s));
}
mybtn::mybtn(QPushButton* b)
{
    // Set default button style
    normal=QColor(20,20,20);
    hover=QColor(40,40,40);
    press=QColor(90,90,90);
    setStyleSheet("QPushButton { background-color: #141414; color: white; border: none; padding: 10px; }"
                  "QPushButton:hover { background-color: #282828; }"
                  "QPushButton:pressed { background-color: #5A5A5A; }");

    // Load sound effect
    soundClicked.setSource(QUrl::fromLocalFile(":/resources/audio/click.wav"));
    soundHover.setSource(QUrl::fromLocalFile(":/resources/audio/hover.wav"));
    // Connect signals to slots
    connect(this, &QPushButton::clicked, this, &mybtn::playClickedSound);
    connect(this, &QPushButton::pressed, this, &mybtn::animateClick);
    connect(this, &QPushButton::released, this, &mybtn::animateRelease);
    setText(b->text());
}
mybtn::mybtn(QString& s){
    pic=QPixmap(":/resources/image/"+s+".png");
    setPixmap(pic);
    soundClicked.setSource(QUrl::fromLocalFile(":/resources/audio/click.wav"));
    soundHover.setSource(QUrl::fromLocalFile(":/resources/audio/hover.wav"));
    // Connect signals to slots
    connect(this, &QPushButton::clicked, this, &mybtn::playClickedSound);
    connect(this, &QPushButton::pressed, this, &mybtn::animateClick);
    connect(this, &QPushButton::released, this, &mybtn::animateRelease);
}

QColor mybtn::background_color()const{
    return my_background_color;
}

void mybtn::setBackground_color(const QColor &color)
{
    my_background_color=color;
    setStyleSheet("background-color: my_background_color");
}

void mybtn::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    soundHover.play();
    // Animate button color change
    QPropertyAnimation *animation = new QPropertyAnimation(this, "background-color");
    animation->setDuration(200);
    animation->setStartValue(normal);
    animation->setEndValue(hover);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void mybtn::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // Animate button color change
    QPropertyAnimation *animation = new QPropertyAnimation(this, "background-color");
    animation->setDuration(200);
    animation->setStartValue(hover);
    animation->setEndValue(normal);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void mybtn::playClickedSound()
{
    soundClicked.play();
    emit btnClicked();
}

void mybtn::animateClick()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "background-color");
    animation->setDuration(100);
    animation->setStartValue(normal);
    animation->setEndValue(press);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void mybtn::animateRelease()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "background-color");
    animation->setDuration(100);
    animation->setStartValue(press);
    animation->setEndValue(normal);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

