#include "pch.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

cv::Mat OriginalImage;
int iAngle = 180;
int iScale = 50;
int iBorder = 0;
int imageCenterX = 0;
int imageCenterY = 0;
const char* pzRotatedImage = "Rotated Image";

void callbackForTrackbar(int, void*)
{
	cv::Mat matRotation = cv::getRotationMatrix2D(cv::Point(imageCenterX, imageCenterY), (iAngle - 180), iScale / 50.0);

	// Rotate the image
	cv::Mat imageRotated;
	cv::warpAffine(OriginalImage, imageRotated, matRotation, OriginalImage.size(), cv::INTER_LINEAR, iBorder, cv::Scalar());

	imshow(pzRotatedImage, imageRotated);
}

int main(int argc, char** argv)
{
	// Reading the image from the file
	OriginalImage = cv::imread("C:\\Users\\hegye\\Desktop\\kutya.jpg",1);
	
	imageCenterY = OriginalImage.rows / 2;
	imageCenterX = OriginalImage.cols / 2;

	//show the original image
	const char* pzOriginalImage = "Original Image";
	cv::namedWindow(pzOriginalImage, cv::WINDOW_AUTOSIZE);
	imshow(pzOriginalImage, OriginalImage);

	//create the "Rotated Image" window and 3 trackbars in it
	cv::namedWindow(pzRotatedImage, cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("Angle", pzRotatedImage, &iAngle, 360, callbackForTrackbar);
	cv::createTrackbar("Scale", pzRotatedImage, &iScale, 100, callbackForTrackbar);
	cv::createTrackbar("Border Mode", pzRotatedImage, &iBorder, 5, callbackForTrackbar);

	int iDummy = 0;

	callbackForTrackbar(iDummy, &iDummy);

	cv::waitKey(0);

	return 0;
}
