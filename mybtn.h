
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
    Q_PROPERTY(QColor background_color READ background_color WRITE setBackground_color NOTIFY background_colorChanged)

public:
    mybtn(std::string s);
    mybtn(QPushButton* b);
    mybtn(QString& s);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    QColor background_color() const;
    void setBackground_color(const QColor& color);
signals:
    void btnClicked();
    void background_colorChanged();

private slots:
    void playClickedSound();
    void animateClick();
    void animateRelease();

private:
    QColor normal,hover,press;
    QColor my_background_color;
    QSoundEffect soundClicked, soundHover;
    QPixmap pic;
};


#endif // MYBTN_H
