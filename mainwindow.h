#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "motorController.h"
#include "inspectionCamera.h"

using namespace std;
using namespace cv;

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

    void fiducialFound(float);

    void fiducialNotFound();

    void on_locateFiducialButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    void startSlave(int);
};

#endif // MAINWINDOW_H
