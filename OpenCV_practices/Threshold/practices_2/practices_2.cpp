#include "pch.h"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

cv::Mat src;
cv::Mat src_gray;
cv::Mat dst;

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;

const char* window_name = "Threshold Demo";
const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";


static void thresholdDemo(int, void*)
{
	/*
	0: Binary
	1 : Binary Inverted
	2 : Threshold Truncated
	3 : Threshold to Zero
	4 : Threshold to Zero Inverted
	*/
	
	cv::threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
	imshow(window_name, dst);
}

int main(int argc, char ** argv)
{
	src = cv::imread("C:\\Users\\hegye\\Desktop\\kutya.jpg", cv::IMREAD_COLOR);
	
	// Converting the image into gray
	cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY); 

	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	
	// Creating the trackbar with the given values
	cv::createTrackbar(trackbar_type, window_name, &threshold_type, max_type, thresholdDemo);

	// And another one
	cv::createTrackbar(trackbar_value, window_name, &threshold_value, max_value, thresholdDemo);

	// Initializing the function
	thresholdDemo(0, 0);

	cv::waitKey(0);

	return 0;
}
