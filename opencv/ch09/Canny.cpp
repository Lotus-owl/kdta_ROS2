#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "lenna.bmp");
    Mat dst1, dst2;

    Canny(src, dst1, 50, 100);
    Canny(src, dst2, 100, 150);

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    waitKey(0);

    return 0;
}