#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat lenna = imread(folder + "lenna.bmp");
    Mat smile = imread(folder + "mask_smile.bmp", IMREAD_GRAYSCALE);
    
    lenna.setTo(yellow, smile);

    imshow("img", lenna);
    waitKey(0);

    Mat airplane = imread(folder + "airplane.bmp");
    Mat mask = imread(folder + "mask_plane.bmp", IMREAD_GRAYSCALE);
    Mat sky = imread(folder + "field.bmp");

    airplane.copyTo(sky, mask);

    imshow("img", sky);
    waitKey(0);

    return 0;
}