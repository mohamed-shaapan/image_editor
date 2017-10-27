#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>


// some global variables
// ************************************************
int slider_initial_value=0;
int image_original_width=0;
int image_original_height=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->image_canvas);
    ui->original_image->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_button_clicked(){

    QString file_name=QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.bmp *.jpeg)"));


    QPixmap pixmap;
    pixmap.load(file_name);
    ui->image_canvas->setPixmap(pixmap);
    ui->original_image->setPixmap(pixmap);

    image_original_width=pixmap.width();
    image_original_height=pixmap.height();
    ui->zoom_slider->setValue(100);



}

void MainWindow::on_save_button_clicked(){

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Address Book"), "", tr("Address Book (*.abk);;All Files (*)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    ui->image_canvas->pixmap()->save(&file, "jpg");



}

void MainWindow::on_apply_button_clicked(){


    qInfo( "C Style Info Message" );



}


void MainWindow::on_zoom_slider_sliderPressed(){

    int value=ui->zoom_slider->value();
    qInfo( "\nSlider Value %d\n", value );
    slider_initial_value=value;
}

void MainWindow::on_zoom_slider_sliderMoved(int position){


}



void MainWindow::on_rotate_ninty_clicked()
{

    QPixmap pixmap = *(ui->image_canvas->pixmap());
    QMatrix rm;

    rm.rotate(90);
    pixmap = pixmap.transformed(rm);
    ui->image_canvas->setPixmap(pixmap);

    pixmap = *(ui->original_image->pixmap());
    pixmap = pixmap.transformed(rm);
    ui->original_image->setPixmap(pixmap);

}

void MainWindow::on_rotate_negative_ninty_clicked()
{
    QPixmap pixmap = *(ui->image_canvas->pixmap());
    QMatrix rm;

    rm.rotate(-90);
    pixmap = pixmap.transformed(rm);
    ui->image_canvas->setPixmap(pixmap);

    pixmap = *(ui->original_image->pixmap());
    pixmap = pixmap.transformed(rm);
    ui->original_image->setPixmap(pixmap);
}

void MainWindow::on_zoom_slider_valueChanged(int value)
{

    QPixmap pixmap_new;
    QPixmap pixmap = *(ui->image_canvas->pixmap());

    int change = value;

    int new_width=change*image_original_width/100;
    int new_height=change*image_original_height/100;

    pixmap_new = pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // set ui image to new pixmap
    if(!pixmap_new.isNull())ui->image_canvas->setPixmap(pixmap_new);
    //slider_initial_value=value;

}

void MainWindow::on_zoom_slider_sliderReleased()
{
    int width=ui->image_canvas->pixmap()->width();
    int height=ui->image_canvas->pixmap()->height();

    QPixmap pixmap = *(ui->original_image->pixmap());

    QPixmap pixmap_new=pixmap.scaled(width,height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    ui->image_canvas->setPixmap(pixmap_new);




}
