#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";
void on_level_change(int pos, void *data);

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));
    FileStorage fs;

    fs.open(folder + "mydata.json", FileStorage::WRITE);
    if(!fs.isOpened())
    {
        cerr<<"file open failed"<<endl;
        return 1;
    }
    String name = "yunsoyeon";
    int age = 25;
    Point pt1(30, 40);
    vector<float> v ={1.2, 4.5, 3.14};
    Mat mat1 = imread(folder + "lenna.bmp");

    fs << "name" << name;
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "vector" << v;
    fs << "mat1" << mat1;
    
    fs.release();
    return 0;
}
