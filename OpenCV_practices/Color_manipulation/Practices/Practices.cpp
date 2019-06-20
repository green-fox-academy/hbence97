#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat image;

int main(int argc, char** argv)
{
	image = cv::imread("C:\\Users\\hegye\\Pictures\\Saved Pictures\\Guardian Angel Jahseh.jpg"); // Read the file

	cv::imshow("Ablak", image); // Show our image inside it.
	cv::Mat image2(image.rows, image.cols, CV_8UC3);

	image2 = image;

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			image2.at<cv::Vec3b>(i, j)[0] = image.at < cv::Vec3b>(i, j)[0];
			image2.at<cv::Vec3b>(i, j)[0] = image.at < cv::Vec3b>(i, j)[1];
			image2.at<cv::Vec3b>(i, j)[0] = image.at < cv::Vec3b>(i, j)[2];
		}
	}
	cv::imshow("greyScale", image2);


	cv::waitKey(0); // Wait for a keystroke in the window
	return 0;
}