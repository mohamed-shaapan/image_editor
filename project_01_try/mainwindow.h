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

    void on_zoom_slider_sliderMoved(int position);

    void on_zoom_slider_sliderPressed();

    void on_rotate_slider_sliderMoved(int position);

    void on_rotate_ninty_clicked();

    void on_rotate_negative_ninty_clicked();

    void on_zoom_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
