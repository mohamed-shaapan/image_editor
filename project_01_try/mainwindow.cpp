#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>


// some global variables
// ************************************************
int slider_initial_value=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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


}

void MainWindow::on_save_button_clicked(){

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Address Book"), "", tr("Address Book (*.abk);;All Files (*)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    ui->image_canvas->pixmap()->save(&file, "PNG");



}

void MainWindow::on_apply_button_clicked(){

    //QWidget::scroll(int dx, int dy);
    //ui->image_container->setWidget(ui->image_canvas);

    qInfo( "C Style Info Message" );

    //ui->image_canvas->scroll(500,100);
    //ui->image_canvas->hide();


    //ui->image_container->setBackgroundRole(QPalette::Dark);
    //ui->image_container->setWidget(ui->image_canvas);
    //setCentralWidget(ui->image_container);





}


void MainWindow::on_zoom_slider_sliderPressed(){

    int value=ui->zoom_slider->value();
    qInfo( "\nSlider Value %d\n", value );
    slider_initial_value=value;
}

void MainWindow::on_zoom_slider_sliderMoved(int position){

    QPixmap pixmap_new;
    // get image from canvas
    QPixmap pixmap = *(ui->image_canvas->pixmap());
    //
    int change = position-slider_initial_value ;
    // width of pixmap
    int width = pixmap.width() , maxWidth = ui->image_canvas->maximumWidth();
    int height = pixmap.height() , maxHeight = ui->image_canvas->maximumHeight();
    // create scaled pixmap
    if((change>0 && width+change<maxWidth && height+change<maxHeight)
            || (change<0 && width+change>0 && height+change>0)){
        pixmap_new = pixmap.scaled(width+change,height+change,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    }
    // set ui image to new pixmap
    if(!pixmap_new.isNull())ui->image_canvas->setPixmap(pixmap_new);
    //slider_initial_value=position;


}



void MainWindow::on_rotate_ninty_clicked()
{

    QPixmap pixmap = *(ui->image_canvas->pixmap());
    QMatrix rm;

    rm.rotate(90);
    pixmap = pixmap.transformed(rm);
    ui->image_canvas->setPixmap(pixmap);

}

void MainWindow::on_rotate_negative_ninty_clicked()
{
    QPixmap pixmap = *(ui->image_canvas->pixmap());
    QMatrix rm;

    rm.rotate(-90);
    pixmap = pixmap.transformed(rm);
    ui->image_canvas->setPixmap(pixmap);
}
