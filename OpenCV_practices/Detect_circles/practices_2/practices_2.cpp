#include "pch.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    cv::Mat src = cv::imread("C:\\Users\\hegye\\Desktop\\circles.jpg");
	
    // Checking for failure
    if (src.empty()) {
        std::cout << "Cannot open the file" << std::endl;
        std::cin.get();
    }

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    
    cv::medianBlur(gray, gray, 5);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 16, 100, 30, 10, 500);

    for (size_t i = 0; i < circles.size(); i++) {
        cv::Vec3i c = circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        // Circle center
        cv::circle(src, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);
        // Circle outline
        int radius = c[2];
        cv::circle(src, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
    }
    cv::imshow("detected circles", src);
    cv::waitKey();

	return 0;
}
