#include "pch.h"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

cv::Mat src;
cv::Mat dst;

int display_caption(const char* caption);
int display_dst(int delay);
int main(int argc, char ** argv)
{
	cv::namedWindow("Smoothing Demo", cv::WINDOW_AUTOSIZE);
	src = cv::imread(("C:\\Users\\hegye\\Desktop\\kutya.jpg"), cv::IMREAD_COLOR);

	if (display_caption("Original Image") != 0)
	{
		return 0;
	}
	dst = src.clone();
	if (display_dst(1500) != 0)
	{
		return 0;
	}
	if (display_caption("Homogeneous Blur") != 0)
	{
		return 0;
	}
	for (int i = 1; i < 31; i = i + 2)
	{
		blur(src, dst, cv::Size(i, i), cv::Point(-1, -1));
		if (display_dst(100) != 0)
		{
			return 0;
		}
	}
	if (display_caption("Gaussian Blur") != 0)
	{
		return 0;
	}
	for (int i = 1; i < 31; i = i + 2)
	{
		GaussianBlur(src, dst, cv::Size(i, i), 0, 0);
		if (display_dst(100) != 0)
		{
			return 0;
		}
	}
	if (display_caption("Median Blur") != 0)
	{
		return 0;
	}
	for (int i = 1; i < 31; i = i + 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(100) != 0)
		{
			return 0;
		}
	}
	if (display_caption("Bilateral Blur") != 0)
	{
		return 0;
	}
	for (int i = 1; i < 31; i = i + 2)
	{
		bilateralFilter(src, dst, i, i * 2, i / 2);
		if (display_dst(100) != 0)
		{
			return 0;
		}
	}
	display_caption("Done!");
	return 0;
}
int display_caption(const char* caption)
{
	dst = cv::Mat::zeros(src.size(), src.type());
	putText(dst, caption,
		cv::Point(src.cols / 4, src.rows / 2),
		cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255));
	return display_dst(1500);
}
int display_dst(int delay)
{
	imshow("Smoothing demo", dst);
	int c = cv::waitKey(delay);
	if (c >= 0) { return -1; }
	return 0;
}