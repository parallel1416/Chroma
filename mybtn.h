
#ifndef MYBTN_H
#define MYBTN_H
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QWidget>
#include <QPropertyAnimation>
#include <QSoundEffect>

class mybtn : public QPushButton, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    mybtn();
    mybtn(std::string s);
    void mouseMoveEvent(QMouseEvent *event) override
    {
        soundHover.play();
        animateHoverIn();
    }

    void animateHoverIn();
    void animateHoverOut();
signals:
    void btnClicked();

private slots:
    void playClickedSound();
    void animateClick();
    void animateRelease();

private:
    QColor normal,hover,press;
    QSoundEffect soundClicked, soundHover;
};


#endif // MYBTN_H
