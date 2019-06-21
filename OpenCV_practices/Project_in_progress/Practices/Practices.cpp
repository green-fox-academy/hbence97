#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// The mouse callback
void mouseCallback(int event, int x, int y, int flags, void* userdata);

int main(int argc, char** argv)
{
	// Creating the image
	cv::Mat image(800, 800, CV_8UC1, cv::Scalar::all(255));
	// Creating the basic line
	cv::line(image, cv::Point(400, 400), cv::Point(800, 400), cv::Scalar(0), 2, 8, 0);
	// Showing the image
	imshow("Ablak", image);
	// Calling the function
	cv::setMouseCallback("Ablak", mouseCallback, &image);
	// Wait for a keystroke in the window
	cv::waitKey(0);
	return 0;
}

void mouseCallback(int event, int x, int y, int flags, void* userdata)
{
	cv::Mat &image = *(cv::Mat*)userdata;

	// If the left button on the mouse is down
	if (flags & cv::MouseEventTypes::EVENT_LBUTTONDOWN)
	{
		// Giving 0 value to the image
		image = cv::Mat::zeros(cv::Size(800, 800), CV_8UC1);
		// Redrawing the basic line
		cv::line(image, cv::Point(400,400), cv::Point(800,400), cv::Scalar(255), 2, 8, 0);
		// Drawing the line which follows the mouse if you left click
		cv::line(image, cv::Point(400,400), cv::Point(x, y), cv::Scalar(255), 2, 8, 0);
		cv::putText(image,"TEXT", /* The text you wanna display */cv::Point(400, 435),/* Coordinates */cv::FONT_HERSHEY_COMPLEX_SMALL, /* Font */
		2.0, /* Scale. 2.0 = 2x bigger */ cv::Scalar(255,255, 255), /* BGR Color */ 1); /* Line Thickness (Optional) */ /* cv::CV_AA); Anti-alias (Optional) */
		// Showing the image
		imshow("Ablak", image);
	}
}