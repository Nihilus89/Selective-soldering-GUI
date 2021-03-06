#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "motorController.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
    void on_startMotorsButton_clicked();

    void on_browseFilesButton_clicked();

    void on_loadFileButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    void startSlave(int);
};

#endif // MAINWINDOW_H
