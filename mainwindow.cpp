#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileParser.h"
#include <QFileDialog>
#include <iostream>

#define MB_BITRATE 38400
#define MB_DATABITS 8
#define MB_STOPBITS 1
#define MB_PARITY 'N'

motorController topTable("/dev/tty.usbmodem1411", MB_BITRATE, MB_PARITY, MB_DATABITS, MB_STOPBITS,1);
inspectionCamera webcam(0);

char* filename;
int componentAmount, fiducialAmount;
float coordinates[100][2], fiducial[100][2];

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


void MainWindow::on_startMotorsButton_clicked()
{
    ui->startMotorsButton->setEnabled(false);
        topTable.initController();
        topTable.motorsOn(false);
}

void MainWindow::on_browseFilesButton_clicked()
{
    // Get the path of the selected file and store it
    QString qFilename;
    qFilename = QFileDialog::getOpenFileName(this, tr("Open .csv file"), "/home", tr("CSV Files (*.csv)"));
    ui->filePathTextField->setText(qFilename); // display the path to the selected file on the text field

}

void MainWindow::on_loadFileButton_clicked()
{
    QString qFilename;
    qFilename = ui->filePathTextField->toPlainText();
    // QString to char*
    QByteArray array = qFilename.toLocal8Bit();
    filename = array.data();
    if(getCoordinatesfromFile(filename,&componentAmount,&fiducialAmount,coordinates,fiducial))
        ui->fileAttributesLabel->setText("Error loading file. Try again");
    else{
        QString scannedFileString = QString("FOUND:\n%1 components\n%2 fiducial markers").arg(QString::number(componentAmount),QString::number(fiducialAmount));
        ui->fileAttributesLabel->setText(scannedFileString);
    }


}
