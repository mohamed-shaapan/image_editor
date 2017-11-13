#include "image_processing.h"
#include <QWidget>
#include <QtWidgets>
#include <QRubberBand>
#include <QPoint>
#include <QPixmap>
#include <QScrollArea>

image_processing::image_processing(QWidget *parent): QLabel( parent)
{
    rubberBand = new QRubberBand(QRubberBand::Rectangle , this);
}

QPoint image_processing:: get_first_point()
{
    return first_point;
}

QPoint image_processing:: get_second_point()
{
    return second_point;
}

void image_processing:: hide_border()
{
    rubberBand->hide();
}

/***********************************************/
void image_processing::mousePressEvent(QMouseEvent *event)
{

    if(this->underMouse()){
        first_point = event->pos();
        rubberBand->setGeometry(QRect(first_point, QSize()));
        rubberBand->show();
    }
}

void image_processing::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(first_point, event->pos()).normalized());
    rubberBand->show();
}

void image_processing::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->underMouse()){
        second_point = event->pos();
        rubberBand->setGeometry(QRect(first_point, second_point));
        rubberBand->show();
    }
}
