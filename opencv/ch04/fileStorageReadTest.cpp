#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";
void on_level_change(int pos, void *data);

int main()
{
    FileStorage fs;
    String name;
    int age;
    Mat img;


    fs.open(folder + "mydata.json", FileStorage::READ);
    if(!fs.isOpened())
    {
        cerr<<"file open failed"<<endl;
        return 1;
    }
    fs["name"]>>name;
    fs["age"]>>age;
    fs["mat1"]>>img;
    
    fs.release();

    cout<<name<<endl;
    cout<<age<<endl;
    imshow("img", img);
    waitKey(0);
    return 0;
}
