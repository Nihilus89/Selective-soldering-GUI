// Check alignment: ./Desktop/dispROI /Users/Vassilis/Documents/PnP.csv

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mat2qimage.h"
#include "fileParser.h"
#include <QFileDialog>
#include <iostream>

#define MB_BITRATE 38400
#define MB_DATABITS 8
#define MB_STOPBITS 1
#define MB_PARITY 'N'

motorController topTable("/dev/tty.usbmodem1D1131", MB_BITRATE, MB_PARITY, MB_DATABITS, MB_STOPBITS,1);
inspectionCamera webcam(0);

char* filename;
int componentAmount, fiducialAmount;
float coordinates[100][2], fiducial[100][2], currentFiducial[100][2], translatedCoordinates[100][2];
Mat src;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect signals
    connect(&webcam, SIGNAL(found(float)),
            this, SLOT(fiducialFound(float)));
    connect(&webcam, SIGNAL(notFound()),
            this, SLOT(fiducialNotFound()));
    connect(this, SIGNAL(translateCoordinatesSignal()),
            this, SLOT(translateCoordinates()));

    //imwrite("/Users/Vassilis/Documents/te.png",);

    // Initialise the widgets
    ui->filePathTextField->setText("/Users/Vassilis/Documents/PnP.csv"); // a default path (optional)
    ui->locateFiducialButton->setEnabled(false); // Not clickable until a .csv file has been parsed
    ui->startButton->setEnabled(false); // Not clickable until everything's ready

    // Display a snapshot from the camera on the window
    src = webcam.captureImage(30);
    QImage qImage = Mat2QImage(src);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->cameraImage->clear();
    ui->cameraImage->setPixmap(pixmap.scaled(QSize(500,281)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startMotorsButton_clicked()
{
    ui->startMotorsButton->setEnabled(false);
        topTable.initController();
        topTable.motorsOn(1);
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
    //webcam.locateFiducial(webcam.captureImage(30),200,200,3,5);
    qFilename = ui->filePathTextField->toPlainText();
    // QString to char*
    QByteArray array = qFilename.toLocal8Bit();
    filename = array.data();
    if(getCoordinatesfromFile(filename,&componentAmount,&fiducialAmount,coordinates,fiducial))
        ui->fileAttributesLabel->setText("Error loading file. Try again");
    else{
        QString scannedFileString = QString("FOUND:\n%1 components\n%2 fiducial markers").arg(QString::number(componentAmount),QString::number(fiducialAmount));
        ui->fileAttributesLabel->setText(scannedFileString);
        webcam.fiducialIndex = 0;
        ui->locateFiducialButton->setEnabled(true);
    }


}

void MainWindow::fiducialFound(float signalVal)
{
    // Print the fiducial's coordinates
    cout << signalVal <<endl;
    circle(src, Point(webcam.fiducial_x, webcam.fiducial_y), webcam.fiducial_r, Scalar(0, 0, 255), 3, LINE_AA); // +x_roi and +y_roi for displaying using the whole's frame
    circle(src, Point(webcam.fiducial_x, webcam.fiducial_y), 2, Scalar(0, 255, 0), 3, LINE_AA);   // coordinates rather than the ROI's ones (local)
    currentFiducial[webcam.fiducialIndex][0] = webcam.fiducial_x;
    currentFiducial[webcam.fiducialIndex][1] = webcam.fiducial_y;
    // Display the located fiducial
    QImage qImage = Mat2QImage(src);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->cameraImage->clear();
    ui->cameraImage->setPixmap(pixmap.scaled(QSize(500,281)));

    // Display the fiducial coordinates on the window
    QString fiducialLabelText = ui->fiducialLabel->text();
    fiducialLabelText.append(QString("Fiducial #%1:\tx:%2\ty:%3\tr:%4\n").arg(webcam.fiducialIndex+1).arg(webcam.fiducial_x).arg(webcam.fiducial_y).arg(webcam.fiducial_r));
    ui->fiducialLabel->setText(fiducialLabelText);

    // Increase the fiducial index
    webcam.fiducialIndex++;
    if(webcam.fiducialIndex<fiducialAmount)
        webcam.locateFiducial(webcam.captureImage(30),fiducial[webcam.fiducialIndex][0], fiducial[webcam.fiducialIndex][1], 6, 8);
    else{
        ui->startButton->setEnabled(true); // Ready to start
        emit translateCoordinatesSignal();
    }
}


void MainWindow::fiducialNotFound()
{
    cout << "Not found" <<endl;
        webcam.locateFiducial(webcam.captureImage(30),fiducial[webcam.fiducialIndex][0],fiducial[webcam.fiducialIndex][1],3,8);
}

void MainWindow::on_locateFiducialButton_clicked()
{
    ui->locateFiducialButton->setEnabled(false);
    webcam.locateFiducial(webcam.captureImage(30),fiducial[0][0],fiducial[0][1],3,8);
}

void MainWindow::translateCoordinates()
{
  webcam.coordinatesTranslation(fiducial, currentFiducial, coordinates, fiducialAmount, componentAmount);
  int i;
  for(i=0; i<componentAmount; i++)
    cout << "[" << i << "]: " << coordinates[i][0] << " " << coordinates[i][1] << endl;

  // Display the rotation and offset on the window
  QString fiducialLabelText = ui->fiducialLabel->text();
  fiducialLabelText.append(QString("\nx-offset: \t%1\ny-offset: \t%2\nrotation: \t%3°").arg(webcam.offset_x).arg(webcam.offset_y).arg(webcam.degrees));
  ui->fiducialLabel->setText(fiducialLabelText);

}
