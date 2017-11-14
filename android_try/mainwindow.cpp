#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStandardPaths>
#include "androidimagepicker.h"
#include <QScreen>
#include <QInputDialog>

// some global variables
// ************************************************
int slider_initial_value=0;
int image_original_width=0;
int image_original_height=0;
int pading = 10;
QString curr_imagePath;
QScreen *screen;
AndroidImagePicker *android_image_picker;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit_scene();
    /*opening a connection between image picker and this class.*/
    android_image_picker = new AndroidImagePicker();
    connect(android_image_picker,SIGNAL(imagePathRetrieved(QString)),this,SLOT(load_is_done(QString)));
    /*starting program by selecting the image.*/
    android_image_picker->openPicker();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::edit_scene(){
    screen = QApplication::screens().at(0);
    int button_width=161;
    int button_height=(screen->availableSize().height()*1)/8;
    /*editing Scroll Area Postion and properties.*/
    ui->scrollArea->setGeometry(pading,pading,screen->availableSize().width()-pading,(screen->availableSize().height()*3)/4);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->image_canvas);
    //ui->scrollArea->setAttribute(Qt::MouseEventFlags);//enable touch events on scrollArea
    /*making all button relative to the screen boundries.*/
    ui->save_button->setGeometry(screen->availableSize().width()-button_width-pading,pading,button_width,button_height);
    ui->save_button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->back_button->setGeometry(pading,pading,button_width,button_height);
    ui->back_button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->zoom_slider->setGeometry(pading,(screen->availableSize().height()*3)/4+2*pading,screen->availableSize().width(),button_height/2);
    ui->undo_button->setGeometry(pading,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->redo_button->setGeometry(pading+button_width,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->crop_button->setGeometry(pading+2*button_width,(screen->availableSize().height()*7)/8,button_width,button_height);
    ui->dial->setGeometry(pading+3*button_width,(screen->availableSize().height()*7)/8,button_width,button_height);

    ui->original_image->hide();
}
void MainWindow::load_is_done(QString imagePath){
    curr_imagePath = imagePath;
    QPixmap pixmap;
    pixmap.load( imagePath.remove(0,7) );
    ui->image_canvas->setPixmap(pixmap);
    ui->original_image->setPixmap(pixmap);

    image_original_width=pixmap.width();
    image_original_height=pixmap.height();
    ui->zoom_slider->setValue(100);
}
QString *path,*name;
void getImageName(QString image){
    int i;
    path = new QString("");
    name = new QString("");
    for(i = image.length()-1;i >= 0 ;i--){
        if(image[i] == '/')
            break;
        name->push_front(image[i]);
    }
    for(int j = 0; j < i;j++){
        path->append(image[j]);
    }
}
void MainWindow::on_save_button_clicked(){
//    bool dialogResult;
//    getImageName(curr_imagePath);
//    QInputDialog *renameDialog = new QInputDialog();
//    QString result = renameDialog->getText(0, "Save Image", "New name:", QLineEdit::Normal,
//                                           *name, &dialogResult);

//    if(result.length() > 0 && dialogResult){
//        path->append('/');
//        path->append(result);
//        qDebug() << *path <<" OOOOOOO " << curr_imagePath << endl;
//        ui->image_canvas->pixmap()->save(*path,0,-1);
//    }
//    else
        ui->image_canvas->pixmap()->save(curr_imagePath,0,-1);
//        QBuffer buffer;
//        buffer.open(QIODevice::WriteOnly);
//        ui->image_canvas->pixmap()->save(&buffer, 0 ,-1);
//        buffer.close();

//        QFile file( curr_imagePath  );
//        if( file.open( QIODevice::WriteOnly ) )
//        {
//            qDebug() << file.isOpen() << endl;
//            file.write( buffer.buffer() );
//            qDebug() << " Done  " << endl;
//            file.close();
//        }

}


void MainWindow::on_zoom_slider_sliderPressed(){

    int value=ui->zoom_slider->value();
    qInfo( "\nSlider Value %d\n", value );
    slider_initial_value=value;
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

int old_angel = 0 , overall_angel = 0  ;

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
    // branching now please
    QPixmap pixmap = *(ui->original_image->pixmap());

    int slider_val = ui->zoom_slider->value();

    // new zoom dimensions
    int new_width=slider_val*image_original_width/100;
    int new_height=slider_val*image_original_height/100;

    // scale original image
    QPixmap pixmap_new=pixmap.scaled(new_width,new_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // rotate zoomed version
    QTransform trans  ;
    ui->image_canvas->setPixmap(pixmap_new.transformed(trans.rotate(overall_angel)));
}

void MainWindow::on_back_button_clicked()
{
    android_image_picker->openPicker();
}

void MainWindow::on_crop_button_clicked()
{
    // 01 - obtain coordinates
    QRect rect(pading,pading,screen->availableSize().width()-100,
               (screen->availableSize().height()*3)/4 -90);
    QPixmap cropped=ui->scrollArea->grab(rect);
    ui->image_canvas->setPixmap(cropped);
    ui->original_image->setPixmap(cropped);
}
