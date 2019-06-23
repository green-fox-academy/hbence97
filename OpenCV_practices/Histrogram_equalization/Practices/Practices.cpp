#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	// Reading the image from a file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\xxxtentacion_and_lil_peep.jpg");

	// Checking for failure
	if (image.empty()) {
		std::cout << "Cannot open the file" << std::endl; // Waiting for any key press
		std::cin.get();
	}

	// Changing the color image to grayscale image
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

	// Equalize the histogram
	cv::Mat hist_equalized_image;
	cv::equalizeHist(image, hist_equalized_image);

	// Defining names for 2 windows
	std::string windowNameOfOriginalImage = "Original Image";
	std::string windowNameOfHistogramEqualized = "Histrogram Eqalized Image";

	// Creating windows for each image
	cv::namedWindow(windowNameOfOriginalImage, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameOfHistogramEqualized, cv::WINDOW_NORMAL);

	// Showing images inside the created windows
	imshow(windowNameOfOriginalImage, image);
	imshow(windowNameOfHistogramEqualized, hist_equalized_image);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}