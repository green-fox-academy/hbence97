#include "pch.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == cv::EVENT_LBUTTONDOWN) {
		std::cout << "Left button of the mouse is clicked - position (" << x << "," << y << ")" << std::endl;
	} else if (event == cv::EVENT_RBUTTONDOWN) {
		std::cout << "Right button of the mouse is clicked - position (" << x << "," << y << ")" << std::endl;
	} else if (event == cv::EVENT_MBUTTONDOWN) {
		std::cout << "Middle button of the mouse is clicked - position (" << x << "," << y << ")" << std::endl;
	}
	else if (event == cv::EVENT_MOUSEMOVE) {
		std::cout << "Mouse move over the window (" << x << "," << y << ")" << std::endl;
	}
}

int main(int argc, char** argv)
{
	// Reading the image from the file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\kutya.jpg");

	// Checking for failure
	if (image.empty()) {
		std::cout << "Cannot open the file" << std::endl;
		std::cin.get();
	}

	// Creating a window
	cv::namedWindow("My Window", cv::WINDOW_NORMAL);

	// Setting the callback function for any mouse event
	cv::setMouseCallback("My Window", CallBackFunc, NULL);

	// Showing the image
	cv::imshow("My Window", image);

	cv::waitKey(0);

	return 0;
}