#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;

cv::Mat image;
int main(int argc, char** argv)
{	
	image = cv::imread("C:\\Users\\hegye\\Pictures\\Saved Pictures\\Guardian Angel Jahseh.jpg"); // Read the file
	
	cv::imshow("Ablak", image); // Show our image inside it.
	cv::waitKey(0); // Wait for a keystroke in the window
	return 0;
}