#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "state.h"
#include "commandcontroller.h"
#include "zoom.h"
#include "create.h"
#include "rotate.h"
#include <QFileDialog>


// some global variables
// ************************************************
int slider_initial_value=0;
int image_original_width=0;
int image_original_height=0;
int old_angel = 0 , overall_angel = 0  ;
State* state;
// *************************************************

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->image_canvas);
    ui->original_image->hide();
    ui->backup_image->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_button_clicked(){
    // use file chooser to get image
    QString file_name=QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.bmp *.jpeg)"));

    // user press cancel
    if(file_name.isNull())return ;

    // image loaded by user
    QPixmap pixmap;
    pixmap.load(file_name);

    // set image of canvas
    ui->image_canvas->setPixmap(pixmap);
    // store original image to be used later
    ui->original_image->setPixmap(pixmap);
    // store backup image to be used later
    ui->backup_image->setPixmap(pixmap);

    // save width and height of original image
    image_original_width=pixmap.width();
    image_original_height=pixmap.height();

    // set value of slider to max
    ui->zoom_slider->setValue(100);

    // begin a new state
    state = new State(old_angel,overall_angel,ui->zoom_slider->value());

    // make create command
    Create* com = new Create(state,CREATE,ui);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);

}

void MainWindow::on_save_button_clicked(){
    // use file chooser to get save directory
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Address Book"), "", tr("Address Book (*.abk);;All Files (*)"));

    // user press cancel
    if(fileName.isNull())return ;

    // make a file to image
    QFile file(fileName);


    file.open(QIODevice::WriteOnly);
    // write image in file
    ui->image_canvas->pixmap()->save(&file, "jpg");
}



void MainWindow::on_zoom_slider_sliderPressed(){
    int value=ui->zoom_slider->value();
    slider_initial_value=value;
}

void MainWindow::on_zoom_slider_valueChanged(int value)
{

    // image not loaded yet
    if(ui->image_canvas->pixmap() == NULL)return ;

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

    // image not loaded yet
    if(ui->image_canvas->pixmap() == NULL)return ;


    int width=ui->image_canvas->pixmap()->width();
    int height=ui->image_canvas->pixmap()->height();

    QPixmap pixmap = *(ui->original_image->pixmap());

    // zoom original image by new percentage
    QPixmap pixmap_new=pixmap.scaled(width,height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));

    // update state
    state = new State(old_angel,overall_angel,ui->zoom_slider->value());

    // make rotate command
    Zoom* com = new Zoom(state,ZOOM,ui,width,height);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);
}


void MainWindow::on_apply_button_clicked(){
    QPoint first = ui->image_canvas->get_first_point();
    QPoint second = ui->image_canvas->get_second_point();
    if(first != second)
    {
        QRect rect(first,second);
        ui->image_canvas->hide_border();
        ui->original_image->hide_border();
        QPixmap cropped=ui->scrollArea->grab(rect);
        ui->image_canvas->setPixmap(cropped);
        ui->original_image->setPixmap(cropped);
    }
}



void MainWindow::on_dial_valueChanged(int value)
{
    int change = value-old_angel ;
    overall_angel+=change ;

    // branching now please
    QPixmap pixmap = *(ui->original_image->pixmap());

    int slider_val = ui->zoom_slider->value();

    // new zoom dimensions
    int new_width=slider_val*image_original_width/100;
    int new_height=slider_val*image_original_height/100;

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QTransform trans  ;
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));
    old_angel = value ;

}

void MainWindow::on_dial_sliderReleased()
{
    // get original image no pexilation
    QPixmap pixmap = *(ui->original_image->pixmap());

    int slider_val = ui->zoom_slider->value();

    // new zoom dimensions
    int new_width=slider_val*image_original_width/100;
    int new_height=slider_val*image_original_height/100;

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;

    // update image of canvas
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));

    // update state
    state = new State(old_angel,overall_angel,ui->zoom_slider->value());

    // make rotate command
    Rotate* com = new Rotate(state,ROTATE,ui,new_width,new_height,overall_angel);

    // add command to undo/redo
    CommandController::getInst().addCommand(com);
}

void MainWindow::on_undo_button_released()
{
    CommandController::getInst().undo(state);
}

void MainWindow::on_redo_button_released()
{
    CommandController::getInst().redo(state);
}
