#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "lena.bmp", IMREAD_GRAYSCALE);
    Mat histo;
    int channel[] = {0};
    int dims = 1;
    const int histSize[] = {256};
    float grayLevel[] = {0, 256};
    const float *ranges[] = {grayLevel};

    calcHist(&src, 1, channel, noArray(), histo, dims, histSize, ranges);
    imshow("src", src);

    Mat graph(100, 256, CV_8U, Scalar(255));
    normalize(histo, histo, 0, 100, NORM_MINMAX);
    for(int i = 0; i < 256; i++){
        line(graph, Point(i, 100), Point(i, 100-cvRound(histo.at<float>(i))), Scalar(0, 0, 255));
    }
    imshow("graph", graph);
    waitKey(0);
    return 0;
}