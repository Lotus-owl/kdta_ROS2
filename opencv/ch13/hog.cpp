#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    VideoCapture cap(folder + "vtest.avi");

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    Mat frame;
    while(true){
        cap >> frame;
        vector<Rect> detected;
        hog.detectMultiScale(frame, detected);
        for(auto re : detected){
            rectangle(frame, re, Scalar(0, 255, 255), 5);
        }
        imshow("frame", frame);
        if(waitKey(100) == 27)
            break;
    }
    return 0;
}