#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat image(800, 800, CV_8UC1, cv::Scalar::all(255));
void mouseCallback(int event, int x, int y, int flags, void* userdata);

int main(int argc, char** argv)
{

	cv::line(image, cv::Point(400, 400), cv::Point(800, 400), cv::Scalar(0), 2, 8, 0);

	imshow("Ablak", image);
	cv::setMouseCallback("Ablak", mouseCallback);

	cv::waitKey(0); // Wait for a keystroke in the window
	return 0;
}

void mouseCallback(int event, int x, int y, int flags, void* userdata)
{

	if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
		cv::circle(image, { x, y }, (x + y) % 10, 0);
	}
	cv::imshow("Ablak", image);
}