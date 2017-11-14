/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <image_processing.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *file_handling_section;
    QPushButton *save_button;
    QPushButton *load_button;
    QGroupBox *action_history_section;
    QPushButton *undo_button;
    QPushButton *redo_button;
    QGroupBox *zoom_section;
    QSlider *zoom_slider;
    QGroupBox *rotate_image_section;
    QDial *dial;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    image_processing *image_canvas;
    image_processing *original_image;
    QGroupBox *crop_image_section;
    QPushButton *apply_button;
    image_processing *backup_image;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 600);
        MainWindow->setMinimumSize(QSize(950, 600));
        MainWindow->setMaximumSize(QSize(950, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        file_handling_section = new QGroupBox(centralWidget);
        file_handling_section->setObjectName(QStringLiteral("file_handling_section"));
        file_handling_section->setGeometry(QRect(20, 30, 181, 71));
        save_button = new QPushButton(file_handling_section);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(10, 30, 71, 31));
        load_button = new QPushButton(file_handling_section);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(100, 30, 71, 31));
        action_history_section = new QGroupBox(centralWidget);
        action_history_section->setObjectName(QStringLiteral("action_history_section"));
        action_history_section->setGeometry(QRect(20, 110, 181, 71));
        undo_button = new QPushButton(action_history_section);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        undo_button->setGeometry(QRect(10, 30, 71, 31));
        redo_button = new QPushButton(action_history_section);
        redo_button->setObjectName(QStringLiteral("redo_button"));
        redo_button->setGeometry(QRect(100, 30, 71, 31));
        zoom_section = new QGroupBox(centralWidget);
        zoom_section->setObjectName(QStringLiteral("zoom_section"));
        zoom_section->setGeometry(QRect(20, 200, 181, 71));
        zoom_slider = new QSlider(zoom_section);
        zoom_slider->setObjectName(QStringLiteral("zoom_slider"));
        zoom_slider->setGeometry(QRect(10, 40, 160, 16));
        zoom_slider->setMinimum(20);
        zoom_slider->setMaximum(200);
        zoom_slider->setPageStep(30);
        zoom_slider->setValue(100);
        zoom_slider->setOrientation(Qt::Horizontal);
        rotate_image_section = new QGroupBox(centralWidget);
        rotate_image_section->setObjectName(QStringLiteral("rotate_image_section"));
        rotate_image_section->setGeometry(QRect(20, 290, 181, 71));
        dial = new QDial(rotate_image_section);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(60, 10, 50, 64));
        dial->setMaximum(360);
        dial->setSingleStep(10);
        dial->setPageStep(20);
        dial->setOrientation(Qt::Vertical);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(220, 30, 701, 531));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 689, 519));
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        image_canvas = new image_processing(centralWidget);
        image_canvas->setObjectName(QStringLiteral("image_canvas"));
        image_canvas->setGeometry(QRect(120, 540, 51, 41));
        image_canvas->setFrameShape(QFrame::Box);
        original_image = new image_processing(centralWidget);
        original_image->setObjectName(QStringLiteral("original_image"));
        original_image->setEnabled(true);
        original_image->setGeometry(QRect(40, 540, 51, 41));
        original_image->setFrameShape(QFrame::Box);
        crop_image_section = new QGroupBox(centralWidget);
        crop_image_section->setObjectName(QStringLiteral("crop_image_section"));
        crop_image_section->setGeometry(QRect(20, 380, 181, 91));
        apply_button = new QPushButton(crop_image_section);
        apply_button->setObjectName(QStringLiteral("apply_button"));
        apply_button->setGeometry(QRect(10, 40, 101, 31));
        backup_image = new image_processing(centralWidget);
        backup_image->setObjectName(QStringLiteral("backup_image"));
        backup_image->setGeometry(QRect(80, 480, 51, 41));
        backup_image->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        file_handling_section->setTitle(QApplication::translate("MainWindow", "Image File", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        load_button->setText(QApplication::translate("MainWindow", "load", Q_NULLPTR));
        action_history_section->setTitle(QApplication::translate("MainWindow", "Action History", Q_NULLPTR));
        undo_button->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        redo_button->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        zoom_section->setTitle(QApplication::translate("MainWindow", "Zoom", Q_NULLPTR));
        rotate_image_section->setTitle(QApplication::translate("MainWindow", "Rotate Image", Q_NULLPTR));
        image_canvas->setText(QString());
        original_image->setText(QString());
        crop_image_section->setTitle(QApplication::translate("MainWindow", "Crop Image", Q_NULLPTR));
        apply_button->setText(QApplication::translate("MainWindow", "Crop Canvas", Q_NULLPTR));
        backup_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
