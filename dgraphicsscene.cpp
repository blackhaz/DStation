#include "dgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>

DGraphicsScene::DGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void DGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event); // Passing event to parent
    QPointF mousePosition = event->scenePos();
    mousePressedX = (int)mousePosition.x();
    mousePressedY = (int)mousePosition.y();
    emit mousePressed();
}



