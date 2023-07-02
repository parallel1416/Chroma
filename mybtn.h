
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
    mybtn(std::string s);
    mybtn(QPushButton* b);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
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
