#ifndef DGRAPHICSSCENE_H
#define DGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

/* DGraphicsScene is a sub-class of QGraphicsScene that provides necessary functions to work with mouse.
   It is designed to emit signals whenever mouse button is pressed. These signals
   are later connected to main application functions that process these events.
   This class also has public attributes that hold mouse events coordinates. */

class DGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DGraphicsScene(QObject *parent = 0);
    int mousePressedX;
    int mousePressedY;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePressed();

public slots:

};

#endif // DGRAPHICSSCENE_H
