#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "milkdrop.bmp");
    Mat bin;
    threshold(img, bin, 120, 255, THRESH_BINARY);

    Mat dst1, dst2, dst3, dst4, dst5;
    morphologyEx(bin, dst1, MORPH_OPEN, Mat());
    morphologyEx(bin, dst2, MORPH_CLOSE, Mat());
    morphologyEx(bin, dst3, MORPH_GRADIENT, Mat());
    morphologyEx(bin, dst4, MORPH_TOPHAT, Mat());
    morphologyEx(bin, dst5, MORPH_BLACKHAT, Mat());   

    imshow("img", img);
    imshow("bin", bin);
    imshow("open", dst1);
    imshow("close", dst2);
    imshow("grad", dst3);
    imshow("toph", dst4);
    imshow("black", dst5);
    
    waitKey(0);

    return 0;
}