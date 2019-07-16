#include "pch.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    cv::Mat sourceImage = cv::imread("C:\\Users\\hegye\\Desktop\\kutya.jpg", cv::IMREAD_GRAYSCALE);
    
    // Detecting the keypoints using SURF detector
    int minHessian = 400;
    cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);
    std::vector<cv::KeyPoint> keypoints1; //keypoints2; // --- For the second picture

    detector->detect(sourceImage, keypoints1);
    //detector->detect(sourceImage, keypoints2); --- For the second picture

    // Drawing keypoints
    cv::Mat imageKeypoints1;
    //cv::Mat imageKeypoints2;
    cv::drawKeypoints(sourceImage, keypoints1, imageKeypoints1, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

    // Showing the detected (drawn) keypoints
    cv::imshow("Surf keypoints", imageKeypoints1);
    
    cv::waitKey(0);

    return 0;
}

/** @function readme */
void readme()
{
    std::cout << " Usage: ./SURF_detector <img1> <img2>" << std::endl;
}
