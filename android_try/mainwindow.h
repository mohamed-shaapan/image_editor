#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
     void load_is_done(QString imagePath);
     void touchEvent(QTouchEvent *ev);

private slots:
    void on_save_button_clicked();

    void on_zoom_slider_sliderMoved(int position);

    void on_zoom_slider_sliderPressed();

    //void on_rotate_slider_sliderMoved(int position);

    void on_zoom_slider_valueChanged(int value);

    void on_zoom_slider_sliderReleased();

    void on_dial_valueChanged(int value);

    void on_dial_sliderReleased();

    void on_image_canvas_destroyed();

    void on_image_canvas_destroyed(QObject *arg1);

    void on_back_button_clicked();

    void on_crop_button_clicked();

private:
    Ui::MainWindow *ui;
    void edit_scene();
};

#endif // MAINWINDOW_H
