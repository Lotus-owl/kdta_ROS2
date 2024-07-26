#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "building.jpg", IMREAD_GRAYSCALE);
    Mat edge;

    Canny(src, edge, 50, 150);

    vector<Vec4i> lines;
    HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
    cvtColor(src, src, COLOR_GRAY2RGB);
    
    for(auto lineP : lines)
    {
        line(src, Point(lineP[0], lineP[1]), Point(lineP[2], lineP[3]), Scalar(0, 0, 255), 2);
    }
    
    imshow("src", src);
    imshow("dst", edge);
    waitKey(0);
    return 0;
}