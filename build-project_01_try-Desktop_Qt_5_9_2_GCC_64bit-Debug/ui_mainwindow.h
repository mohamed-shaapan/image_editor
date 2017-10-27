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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *image_canvas;
    QGroupBox *file_handling_section;
    QPushButton *save_button;
    QPushButton *load_button;
    QGroupBox *action_history_section;
    QPushButton *undo_button;
    QPushButton *redo_button;
    QGroupBox *resize_image_section;
    QSlider *resize_slider;
    QGroupBox *rotate_image_section;
    QSlider *rotate_slider;
    QPushButton *apply_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(950, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        image_canvas = new QLabel(centralWidget);
        image_canvas->setObjectName(QStringLiteral("image_canvas"));
        image_canvas->setGeometry(QRect(230, 10, 711, 581));
        image_canvas->setFrameShape(QFrame::Box);
        file_handling_section = new QGroupBox(centralWidget);
        file_handling_section->setObjectName(QStringLiteral("file_handling_section"));
        file_handling_section->setGeometry(QRect(20, 10, 181, 71));
        save_button = new QPushButton(file_handling_section);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(10, 30, 71, 31));
        load_button = new QPushButton(file_handling_section);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(100, 30, 71, 31));
        action_history_section = new QGroupBox(centralWidget);
        action_history_section->setObjectName(QStringLiteral("action_history_section"));
        action_history_section->setGeometry(QRect(20, 90, 181, 71));
        undo_button = new QPushButton(action_history_section);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        undo_button->setGeometry(QRect(10, 30, 71, 31));
        redo_button = new QPushButton(action_history_section);
        redo_button->setObjectName(QStringLiteral("redo_button"));
        redo_button->setGeometry(QRect(100, 30, 71, 31));
        resize_image_section = new QGroupBox(centralWidget);
        resize_image_section->setObjectName(QStringLiteral("resize_image_section"));
        resize_image_section->setGeometry(QRect(20, 180, 181, 71));
        resize_slider = new QSlider(resize_image_section);
        resize_slider->setObjectName(QStringLiteral("resize_slider"));
        resize_slider->setGeometry(QRect(10, 40, 160, 16));
        resize_slider->setMinimum(-100);
        resize_slider->setMaximum(100);
        resize_slider->setValue(0);
        resize_slider->setOrientation(Qt::Horizontal);
        rotate_image_section = new QGroupBox(centralWidget);
        rotate_image_section->setObjectName(QStringLiteral("rotate_image_section"));
        rotate_image_section->setGeometry(QRect(20, 270, 181, 71));
        rotate_slider = new QSlider(rotate_image_section);
        rotate_slider->setObjectName(QStringLiteral("rotate_slider"));
        rotate_slider->setGeometry(QRect(10, 40, 160, 16));
        rotate_slider->setMinimum(-100);
        rotate_slider->setMaximum(100);
        rotate_slider->setOrientation(Qt::Horizontal);
        apply_button = new QPushButton(centralWidget);
        apply_button->setObjectName(QStringLiteral("apply_button"));
        apply_button->setGeometry(QRect(20, 360, 89, 25));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        image_canvas->setText(QString());
        file_handling_section->setTitle(QApplication::translate("MainWindow", "Image File", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        load_button->setText(QApplication::translate("MainWindow", "load", Q_NULLPTR));
        action_history_section->setTitle(QApplication::translate("MainWindow", "Action History", Q_NULLPTR));
        undo_button->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        redo_button->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        resize_image_section->setTitle(QApplication::translate("MainWindow", "Resize Image", Q_NULLPTR));
        rotate_image_section->setTitle(QApplication::translate("MainWindow", "Rotate Image", Q_NULLPTR));
        apply_button->setText(QApplication::translate("MainWindow", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
