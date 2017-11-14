#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_load_button_clicked();

    void on_save_button_clicked();

    void on_apply_button_clicked();

    //void on_zoom_slider_sliderMoved(int position);

    void on_zoom_slider_sliderPressed();

    //void on_rotate_slider_sliderMoved(int position);

    void on_zoom_slider_valueChanged(int value);

    void on_zoom_slider_sliderReleased();

    void on_dial_valueChanged(int value);

    void on_dial_sliderReleased();

    void on_undo_button_released();

    void on_redo_button_released();

private:
    Ui::MainWindow *ui;
    void regainState();
};

#endif // MAINWINDOW_H
