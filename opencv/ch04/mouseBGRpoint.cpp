#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void *data);
struct MyData
{
    Point ptOld;
    Point ptNew;
    Mat img;
    Mat background;
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    vector<Vec3b> mouseBGR;
    bool flag = false;
};

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    MyData mydata;
    FileStorage fs;
    mydata.img = imread(folder + "lena.bmp");
    mydata.background = mydata.img.clone();
    
    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&mydata);

    imshow("img", mydata.img);
    int keycode = waitKey(0);
    if(keycode == 27){
        fs.open(folder + "mouseBGRvector.json", FileStorage::WRITE);
        fs<<"mouseBGR"<<mydata.mouseBGR;
        fs.release();
    }
    destroyAllWindows();
    return 0;
}

void onMouse(int event, int x, int y, int flags, void *data)
{
    MyData *ptr = (MyData *)data;
    switch(event)
    {
        case EVENT_LBUTTONDOWN:
            ptr->ptOld = Point(x, y);
            ptr->mouseBGR.push_back(ptr->background.at<Vec3b>(y, x));
            ptr->flag = true;
            break;

        case EVENT_LBUTTONUP:
            ptr->flag = false;
            break;

        case EVENT_MOUSEMOVE:
            
            if(EVENT_FLAG_LBUTTON){
                ptr->background.copyTo(ptr->img);
                rectangle(ptr->img, Point(x-25, y-25), Point(x+25, y+25), ptr->blue, 2);
                imshow("img", ptr->img);
                ptr->ptOld = Point(x, y);
            }
    }
}