#include "pch.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


int main(int argc, char** argv)
{
	// open the video file for reading
	cv::VideoCapture cap("C:\\Users\\hegye\\Downloads\\2_monkeys.mp4");
	// if not succes, exit the program
	if (cap.isOpened() == false) {
		std::cout << "Cannot open the video file." << std::endl;
		// wait for any key press
		std::cin.get();
		return -1;
	}

	// getting the frame rates of the video
	double fps = cap.get(cv::CAP_PROP_FPS);
	std::cout << "Frames per seconds: " << fps << std::endl;

	std::string window_name = "My first video";
	
	//creating the window
	cv::namedWindow(window_name, cv::WINDOW_NORMAL);

	while (true)
	{
		cv::Mat frame;
		// read a new frame from video
		bool bsucess = cap.read(frame);
		if (bsucess == false)
		{
			std::cout << "Found the end of the video." << std::endl;
			break;
		}
		// showing the frame in the created window
		cv::imshow(window_name, frame);
		/*wait for for 10 ms until any key is pressed.  
		If the 'Esc' key is pressed, break the while loop.
		If the any other key is pressed, continue the loop 
		If any key is not pressed withing 10 ms, continue the loop */
		if (cv::waitKey(10) == 27) {
			std::cout << "The ESC key has been pressed by the user. Exiting the video." << std::endl;
			break;
		}
	}
	return 0;
}
