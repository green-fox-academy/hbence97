#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	// Reading the image file
	cv::Mat image = cv::imread("C:\\Users\\hegye\\Desktop\\xxxtentacion_and_lil_peep.jpg");

	// Checking for failure
	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get(); //wait for any key press
		return -1;
	}
	// Creating a new image
	cv::Mat imageContrastHigh2;
	// Converting the original image with the given values, and then saving it into the new image created above
	image.convertTo(imageContrastHigh2, -1, 2, 0); // Increasing the contrast by 2

	cv::Mat imageContrastHigh4;
	image.convertTo(imageContrastHigh4, -1, 4, 0); // Increasing the contrast by 4

	cv::Mat imageContrastLow0_5;
	image.convertTo(imageContrastLow0_5, -1, 0.5, 0); // Decreasing the contrast by 0.5

	cv::Mat imageContrastLow0_25;
	image.convertTo(imageContrastLow0_25, -1, 0.25, 0); // Decreasing the contrast by 0.25


	// Defining the name for each window
	std::string windowNameOriginalImage = "Original Image";
	std::string windowNameContrastHigh2 = "Contrast Increased by 2";
	std::string windowNameContrastHigh4 = "Contrast Increased by 4";
	std::string windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
	std::string windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

	// Creating and opening windows for the images
	cv::namedWindow(windowNameOriginalImage, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastHigh2, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastHigh4, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastLow0_5, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastLow0_25, cv::WINDOW_NORMAL);

	// Showing the images in the created windows
	imshow(windowNameOriginalImage, image);
	imshow(windowNameContrastHigh2, imageContrastHigh2);
	imshow(windowNameContrastHigh4, imageContrastHigh4);
	imshow(windowNameContrastLow0_5, imageContrastLow0_5);
	imshow(windowNameContrastLow0_25, imageContrastLow0_25);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}