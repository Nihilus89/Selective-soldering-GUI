#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MB_BITRATE 38400
#define MB_DATABITS 8
#define MB_STOPBITS 1
#define MB_PARITY 'N'

motorController topTable("/dev/ttyUSB0", MB_BITRATE, MB_PARITY, MB_DATABITS, MB_STOPBITS,1);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&topTable, SIGNAL(request(QString)),this, SLOT(showRequest(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startMotorsButton_clicked()
{
    ui->startMotorsButton->setEnabled(false);
        topTable.initController();
        topTable.motorsOn(true);
}
