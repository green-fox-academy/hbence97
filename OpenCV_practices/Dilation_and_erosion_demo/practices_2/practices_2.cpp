#include "pch.h"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

cv::Mat src;
cv::Mat erosionDst;
cv::Mat dilationDst;

int erosionElem = 0;
int erosionSize = 0;
int dilationElem = 0;
int dilationSize = 0;
int const maxElem = 2;
int const maxKernelSize = 21;

void erosion(int, void*);
void dilation(int, void*);

int main(int argc, char ** argv)
{
	src = cv::imread("C:\\Users\\hegye\\Desktop\\kutya.jpg", cv::IMREAD_COLOR);
	
	// Creating 3 windows with the given names
	cv::namedWindow("Erosion Demo", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Dilation Demo", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Dilation Demo", cv::WINDOW_AUTOSIZE);

	// Creating 4 trackbars with the given names
	cv::createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo", &erosionElem, maxElem, erosion);
	cv::createTrackbar("Kernel size : \n 2n + 1", "Erosion Demo", &erosionSize, maxKernelSize, erosion);
	cv::createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo", &dilationElem, maxElem, dilation);
	cv::createTrackbar("Kernel size:\n 2n +1", "Dilation Demo", &dilationSize, maxKernelSize, dilation);

	// Initializing the values to 0
	erosion(0, 0);
	dilation(0, 0);
	
	cv::waitKey(0);

	return 0;
}

void erosion (int, void*) {
	
	int erosionType = 0;
	
	if (erosionElem == 0) {
		erosionType = cv::MORPH_RECT;
	} else if (erosionElem == 1) {
		erosionType = cv::MORPH_CROSS;
	} else if (erosionElem == 2) {
		erosionType = cv::MORPH_ELLIPSE;
	}
	
	cv::Mat element = cv::getStructuringElement(erosionType, cv::Size(2 * erosionSize + 1, 2 * erosionSize + 1), cv::Point(erosionSize, erosionSize));
	cv::erode(src, erosionDst, element);
	cv::imshow("Erosion Demo", erosionDst);

}

void dilation(int, void*) {

	int dilationType = 0;

	if (dilationElem == 0) {
		dilationType = cv::MORPH_RECT;
	} else if (dilationElem == 1) {
		dilationType = cv::MORPH_CROSS;
	} else if (dilationElem == 2) {
		dilationType = cv::MORPH_ELLIPSE;
	}

	cv::Mat element = cv::getStructuringElement(dilationType, cv::Size(2 * dilationSize + 1, 2 + dilationSize + 1), cv::Point(dilationSize, dilationSize));
	cv::dilate(src, dilationDst, element);
	cv::imshow("Dilation Demo", dilationDst);
}
