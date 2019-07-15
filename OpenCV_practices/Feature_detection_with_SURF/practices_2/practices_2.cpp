#include "pch.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <iostream>
#ifdef HAVE_OPENCV_XFEATURES2D
using namespace cv;
using namespace cv::xfeatures2d;
int main(int argc, char ** argv)
{
    Mat src = imread("C:\\Users\\hegye\\Desktop\\kutya.jpg");

    //-- Step 1: Detect the keypoints using SURF Detector
    int minHessian = 400;
    Ptr<SURF> detector = SURF::create(minHessian);
    std::vector<KeyPoint> keypoints;
    detector->detect(src, keypoints);


    //-- Draw keypoints
    Mat img_keypoints;
    drawKeypoints(src, keypoints, img_keypoints);

    //-- Show detected (drawn) keypoints
    imshow("SURF Keypoints", img_keypoints);

    waitKey();

	return 0;
}
#else
int main()
{
    std::cout << "This tutorial code needs the xfeatures2d contrib module to be run." << std::endl;
    return 0;
}
#endif