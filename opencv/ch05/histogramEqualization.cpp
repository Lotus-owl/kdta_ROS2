#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "hawkes.bmp", IMREAD_GRAYSCALE);
    Mat add, center, minmax, dst;
    double gmin, gmax;

    add = src + 50;
    center = src + (src - 125) * 1.0;
    minMaxLoc(src, &gmin, &gmax);
    minmax = (src - gmin) * 255 / (gmax - gmin);
    equalizeHist(src, dst);

    imshow("src", src);
    imshow("add", add);
    imshow("center", center);
    imshow("minmax", minmax);
    imshow("dst", dst);
    waitKey(0);
    return 0;
}