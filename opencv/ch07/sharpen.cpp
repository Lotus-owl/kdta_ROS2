#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/yunsy616/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;
    
    for(int alpha = 5; alpha <= 19; alpha +=2){
        Mat blurred, dst;
        GaussianBlur(src, blurred, Size(0, 0), 3);
        dst = (1 + alpha) * src - alpha * blurred;
        dsts.push_back(dst);
    }

    imshow("src", src);

    int i = 3;
    for(auto dst : dsts){
        imshow("dst" + to_string(i), dst);
        i += 2;
    }
    waitKey(0);
    return 0;
}