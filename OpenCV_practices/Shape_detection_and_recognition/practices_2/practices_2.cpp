#include "pch.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
#include <cmath>

static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
void setLabel(cv::Mat& image, const std::string label, std::vector<cv::Point>& contour);

int main()
{
    cv::Mat src;
    cv::VideoCapture capture(0);
    int q;
    cv::Mat gray;
    cv::Mat bw;
    cv::Mat dst;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Point> approx;

    while (cv::waitKey(30) != 'q')
    {
        capture >> src;
        if (true)
        {
            // Convert to grayscale
            cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

            // Use Canny instead of threshold to catch squares with gradient shading
            cv::blur(gray, bw, cv::Size(3, 3));
            cv::Canny(gray, bw, 80, 240, 3);
            cv::imshow("bw", bw);

            // Find contours
            cv::findContours(bw.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

            src.copyTo(dst);

            for (int i = 0; i < contours.size(); i++) {
                // Approximate contour with accuracy proportional to the contour perimeter
                cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

                // Skip small or non-convex objects
                if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx)) {
                    continue;
                }
                if (approx.size() == 3)
                {
                    setLabel(dst, "TRIANGLE", contours[i]);    // Triangles
                }
                else if (approx.size() >= 4 && approx.size() <= 6)
                {
                    // Number of vertices of polygonal curve
                    int vtc = approx.size();

                    // Get the cosines of all corners
                    std::vector<double> cos;
                    for (int j = 2; j < vtc + 1; j++)
                        cos.push_back(angle(approx[j%vtc], approx[j - 2], approx[j - 1]));

                    // Sort ascending the cosine values
                    std::sort(cos.begin(), cos.end());

                    // Get the lowest and the highest cosine
                    double mincos = cos.front();
                    double maxcos = cos.back();

                    // Use the degrees obtained above and the number of vertices
                    // to determine the shape of the contour
                    if (vtc == 4)
                        setLabel(dst, "RECTANGLE", contours[i]);
                    else if (vtc == 5)
                        setLabel(dst, "PENTAGON", contours[i]);
                    else if (vtc == 6)
                        setLabel(dst, "HEXAGON", contours[i]);
                }
                else {
                    // Detect and label circles
                    double area = cv::contourArea(contours[i]);
                    cv::Rect r = cv::boundingRect(contours[i]);
                    int radius = r.width / 2;

                    if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                        std::abs(1 - (area / (CV_PI * (radius * radius)))) <= 0.2)
                        setLabel(dst, "CIRCLE", contours[i]);
                }
            }
            cv::imshow("src", src);
            cv::imshow("dst", dst);
        }
    }
    cv::waitKey(0);
    return 0;
}

// Function to find the cosine of the angle between vectors

double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0) {
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;

    return (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
}

// Function to display the text in the center of the contour

void setLabel(cv::Mat & image, const std::string label, std::vector<cv::Point>& contour) {
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.4;
    int thickness = 1;
    int baseline = 0;

    cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
    cv::Rect r = cv::boundingRect(contour);

    cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
    cv::rectangle(image, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), cv::FILLED);
    cv::putText(image, label, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
}
