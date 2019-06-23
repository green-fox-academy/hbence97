#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	// Reading the image from the file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\Peep_X.jpeg");

	// Checking for failure
	if (image.empty()) {
		std::cout << "Cannot open the file" << std::endl;
		std::cin.get();
	}

	// Eroding the image with 3x3 kernel
	cv::Mat image_eroded_with_3x3_kernel;
	erode(image, image_eroded_with_3x3_kernel, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));

	// Erogind the image with 5x5 kernel
	cv::Mat image_eroded_with_5x5_kernel;
	erode(image, image_eroded_with_5x5_kernel, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));

	// Defining the name for the windows
	std::string window_name = "Original Image";
	std::string window_name_eroded_with_3x3_kernel = "Image Eroded with 3x3 kernel";
	std::string window_name_eroded_with_5x5_kernel = "Image Eroded with 5x5 kernel";

	// Creating windows with the names given
	cv::namedWindow(window_name);
	cv::namedWindow(window_name_eroded_with_3x3_kernel);
	cv::namedWindow(window_name_eroded_with_5x5_kernel);

	// Showing our images
	imshow(window_name, image);
	imshow(window_name_eroded_with_3x3_kernel, image_eroded_with_3x3_kernel);
	imshow(window_name_eroded_with_5x5_kernel, image_eroded_with_5x5_kernel);

	cv::waitKey(0);
	
	cv::destroyAllWindows();

	return 0;
}