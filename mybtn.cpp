
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
    soundClicked.setSource(QUrl::fromLocalFile(":/audio/click.wav"));
    soundHover.setSource(QUrl::fromLocalFile(":/audio/hover.wav"));
    // Connect signals to slots
    connect(this, &QPushButton::clicked, this, &mybtn::playClickedSound);
    connect(this, &QPushButton::pressed, this, &mybtn::animateClick);
    connect(this, &QPushButton::released, this, &mybtn::animateRelease);
    setText(QString::fromStdString(s));
}

void mybtn::animateHoverIn()
{
    // Animate button color change
    QPropertyAnimation *animation = new QPropertyAnimation(this, "background-color");
    animation->setDuration(200);
    animation->setStartValue(normal);
    animation->setEndValue(hover);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void mybtn::animateHoverOut()
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

