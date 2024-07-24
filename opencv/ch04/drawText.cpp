#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/freetype.hpp"

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
    Mat img(400, 600, CV_8UC3, white);

    Ptr<freetype::FreeType2> ft2 = freetype::createFreeType2(); //smart pointer
    ft2->loadFontData("/home/yunsy616/Freesentation-v1.003/Freesentation-1Thin.ttf", 0);
    String text = u8"hello text utf-8";
    int fontHeight = 60;
    Size textSize = ft2->getTextSize(text, fontHeight, -1, 0);

    putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, green);
    putText(img, "FONT_HERSHEY_plain", Point(20, 150), FONT_HERSHEY_PLAIN, 1, red);

    ft2->putText(img, text, Point(20, 150), fontHeight, red, -1, LINE_AA, true);

    imshow("img", img);
    
    waitKey(0);
    return 0;
}