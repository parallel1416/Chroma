
#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QLabel>
#include <QGraphicsItem>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QJsonDocument>
#include <QObject>
#include <QWidget>


class dialogbox : public QLabel
{
public:
    dialogbox();
    void keyPressEvent(QKeyEvent *event);

private:
    QLabel *dialog;
    QMenu *choices;
};

#endif // DIALOGBOX_H
