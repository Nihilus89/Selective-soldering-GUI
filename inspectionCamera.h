//
// Created by vassilis on 09.03.16.
//

#ifndef SELECTIVE_SOLDERING_INSPECTIONCAMERA_H
#define SELECTIVE_SOLDERING_INSPECTIONCAMERA_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

#include <QObject>

#define X_ROI 20
#define Y_ROI 20
#define WIDTH 40
#define HEIGHT 40

using namespace cv;
using namespace std;

const long double PI = 3.141592653589793238L;

class inspectionCamera : public QObject {
    Q_OBJECT
public:
    float fiducial_x, fiducial_y, fiducial_r;
    float degrees, offset_x, offset_y;
    int numCircles, fiducialIndex;

    inspectionCamera(int); // constructor
    Mat captureImage(int focus);
    int locateFiducial(Mat, float, float, int, int);
    void coordinatesTranslation(float correctFiducial[][2], float currentFiducial[][2], float coordinates[][2], int numFiducial, int numComp);

signals:
    void found(float x);
    void notFound();

private:
    int devNum;
    Mat R, t;

    void rigidTransform(Mat, Mat, Mat& R, Mat& t);
};


#endif //SELECTIVE_SOLDERING_INSPECTIONCAMERA_H
