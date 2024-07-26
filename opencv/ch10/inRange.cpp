#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "candies.png");
    int lowerhue = 40;
    int upperhue = 80;
    int lowerSaturation = 50;

    Mat src, dst;
    cvtColor(img, src, COLOR_BGR2HSV);

    namedWindow("dst");
    createTrackbar("lower_hue", "dst", &lowerhue, 179);
    createTrackbar("upper_hue", "dst", &upperhue, 179);
    createTrackbar("lower_saturation", "dst", &lowerSaturation, 179);
    
    imshow("img", img);

    while(true)
    {
        inRange(src, Scalar(lowerhue, lowerSaturation, 0), Scalar(upperhue, 255, 255), dst);
        imshow("dst", dst);
        if(waitKey(33) == 27)
            break;
    }

    waitKey(0);

    return 0;
}