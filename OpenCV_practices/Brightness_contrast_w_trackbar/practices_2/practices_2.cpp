#include "pch.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

	// Creating a trackbar to change brightness
	int iSliderValue1 = 50;
	cv::createTrackbar("Brightness", "My Window", &iSliderValue1, 100);

	// Creating a trackbar to change contrast
	int iSliderValue2 = 50;
	cv::createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

	while (true) {
		// Changing the brightness and contrast of the images 
		cv::Mat adjustedImage;
		int iBrightness = iSliderValue1 - 50;
		double dContrast = iSliderValue2 / 50.0;
		image.convertTo(adjustedImage, -1, dContrast, iBrightness);

		// Showing the adjusted images
		cv::imshow("My window",adjustedImage);

		// Wait until the user presses some key for 50ms
		int iKey = cv::waitKey(50);

		//if user presses the 'ESC' key
		if (iKey == 27)
		{
			break;
		}
	}
	return 0;
}