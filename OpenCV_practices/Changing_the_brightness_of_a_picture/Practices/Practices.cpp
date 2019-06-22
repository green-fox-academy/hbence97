#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


int main(int argc, char** argv)
{
	// Reading the image from the file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\xxxtentacion and lil peep.jpg");

	// Increase the brightness by 50
	cv::Mat imageBrightnessHigh50;
	image.convertTo(imageBrightnessHigh50, -1, 1, 50);

	// Increase the brightness by 100
	cv::Mat imageBrightnessHigh100;
	image.convertTo(imageBrightnessHigh100, -1, 1, 100);

	// Decrease the brightness by 50
	cv::Mat imageBrightnessLow50;
	image.convertTo(imageBrightnessLow50, -1, 1, -50);

	// Decrease the brightness by 100
	cv::Mat imageBrightnessLow100;
	image.convertTo(imageBrightnessLow100, -1, 1, -100);

	// Defining the name of the window for each image
	std::string windowNameOriginalImage = "Original Image";
	std::string windowNameBrightnessHigh50 = "Brightness Increased by 50";
	std::string windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
	std::string windowNameBrightnessLow50 = "Brightness Decreased by 50";
	std::string windowNameBrightnessLow100 = "Brightness Decreased by 100";

	// Creating and opening windows for each images
	cv::namedWindow(windowNameOriginalImage, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessHigh50, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameWithBrightnessHigh100, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessLow50, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessLow100, cv::WINDOW_NORMAL);

	// Showing the images in the created windows
	imshow(windowNameOriginalImage, image);
	imshow(windowNameBrightnessHigh50, imageBrightnessHigh50);
	imshow(windowNameWithBrightnessHigh100, imageBrightnessHigh100);
	imshow(windowNameBrightnessLow50, imageBrightnessLow50);
	imshow(windowNameBrightnessLow100, imageBrightnessLow100);

	// Wait for any key stroke
	cv::waitKey(0);

	// Destroying every single windows
	cv::destroyAllWindows();

	return 0;
}