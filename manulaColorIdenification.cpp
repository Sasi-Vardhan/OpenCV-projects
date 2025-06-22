//
//  project-Color Identification.cpp
//  OpenCV_Learn
//
//  Created by Sasi Vardhan Vemuri on 21/06/25.
//

#include "project-Color Identification.hpp"
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>
#include<string>


// to find colors first convert image into  hsv

/*
 Providing Explanation :
 
 HSV (Hue, Saturation, Value) is a color model that represents colors in a way that is more intuitive for humans than the traditional RGB model*
 
 */




using namespace std;
using namespace cv;

Mat hsvImg,mask;
Mat grayImg,blurImg,cannyImg,dilatedImg;
void findColors(const std::string &path)
{
   
    
    int hmin=0,smin=0,vmin=0;
    int hmax=179,smax=255,vmax=255;
    cv::Mat img=cv::imread(path);
    
    Scalar lower(hmin,smin,vmin);
    Scalar higher(hmax,smax,vmax);
    string winName="colorpad";
    namedWindow(winName);
    createTrackbar("hmin", winName, &hmin, 179);
    createTrackbar("smin", winName, &smin, 255);
    createTrackbar("vmin", winName, &vmin, 255);
    createTrackbar("hmax", winName, &hmax, 179);
    createTrackbar("smax", winName, &smax, 255);
    createTrackbar("vmax", winName, &vmax, 255);
    
    
    
    while(true){
        cvtColor(img, hsvImg, COLOR_BGR2HSV);
        Scalar lower(hmin,smin,vmin);
        Scalar higher(hmax,smax,vmax);
        inRange(hsvImg,lower,higher,mask);
        imshow("HSV image :: ",mask);
        imshow("Image :: ",img);
        waitKey(1);
    }
    
}
