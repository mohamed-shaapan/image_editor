#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFileDialog>

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
