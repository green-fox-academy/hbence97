#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	// Reading the image from the file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\xxxtentacion_and_lil_peep.jpg");

	// Checking for failure
	if (image.empty()) {
		std::cout << "Cannot open the image" << std::endl;
		std::cin.get();
	}

	// Bluring the imgae with 3x3 Gaussian kernel
	cv::Mat image_blurred_with_3x3_kernel;
	cv::GaussianBlur(image, image_blurred_with_3x3_kernel, cv::Size(3, 3), 0);

	// Bluring the imgae with 5x5 Gaussian kernel
	cv::Mat image_blurred_with_5x5_kernel;
	cv::GaussianBlur(image, image_blurred_with_5x5_kernel, cv::Size(5, 5), 0);

	// Defining names for the windows
	std::string window_name = "Original Image";
	std::string window_name_blurred_with_3x3_kernel = "Image Blurred with 3x3 Gaussian Kernel";
	std::string window_name_blurred_with_5x5_kernel = "Image blurred with 5x5 Gaussian Kernel";

	// Creating windows with the given names
	cv::namedWindow(window_name);
	cv::namedWindow(window_name_blurred_with_3x3_kernel);
	cv::namedWindow(window_name_blurred_with_5x5_kernel);

	// Showing the images in the created windows
	imshow(window_name, image);
	imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
	imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}