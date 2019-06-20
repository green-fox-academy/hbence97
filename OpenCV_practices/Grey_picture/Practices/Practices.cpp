#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


cv::Mat image;
int main(int argc, char** argv)
{
	image = cv::imread("C:\\Users\\hegye\\Pictures\\Saved Pictures\\Guardian Angel Jahseh.jpg"); // Read the file

	cv::imshow("Ablak", image); // Show our image inside it.
	
	cv::Mat greyScale(image.rows, image.cols, CV_8UC1);
	for (int i = 0; i < greyScale.rows; i++) {
		for (int j = 0; j < greyScale.cols; j++){
			cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
			greyScale.at<uint8_t>(i, j) = (pixel[0] + pixel[1] + pixel[2]) / 3;
		}
	}
	cv::imshow("greyScale", greyScale);

	cv::waitKey(0); // Wait for a keystroke in the window

	return 0;
}