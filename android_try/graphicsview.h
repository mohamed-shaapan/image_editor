#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>
#include <QWidget>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene *scene = 0, QWidget *parent = 0);
    GraphicsView(QWidget *parent = Q_NULLPTR);
    bool viewportEvent(QEvent *event);

private:
    qreal totalScaleFactor;
};

#endif // GRAPHICSVIEW_H
