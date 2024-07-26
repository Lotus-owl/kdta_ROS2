#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "kids.png");
    CascadeClassifier classfier(folder + "haarcascade_frontalface_default.xml");
    vector<Rect> face;
    classfier.detectMultiScale(img, face);

    for(auto rect : face)
    {
        rectangle(img, rect, Scalar(0, 255, 255), 5);
    }

    imshow("img", img);
    waitKey(0);
    return 0;
}