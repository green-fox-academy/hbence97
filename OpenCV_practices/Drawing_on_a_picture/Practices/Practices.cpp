#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat image;


void mouseCallback(int event, int x, int y, int flags, void* userdata)
{
	if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
		cv::circle(image, { x, y }, (x + y) % 10, 0);
	}
	cv::imshow("Ablak", image);
}

int main(int argc, char** argv)
{
	image = cv::imread("C:\\Users\\hegye\\Pictures\\Saved Pictures\\Guardian Angel Jahseh.jpg"); // Read the file

	cv::imshow("Ablak", image); // Show our image inside it.
	cv::setMouseCallback("Ablak", mouseCallback);

	cv::waitKey(0); // Wait for a keystroke in the window
	return 0;
}