#include <opencv2/opencv.hpp> //引入头文件 <> 表示引入系统头文件  "" 表示引入自己的头文件
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
#include <iostream>
#include <stdio.h>
#include <cstdio>




using namespace std;
using namespace cv;
#ifndef CONSTANTS_H
#define CONSTANTS_H

const string fileName = "gril.png";

bool showImg();
bool etchImage();
bool blurImg();
bool cannyImg();
bool videoPlay();
bool MultiChannelBlending();
bool videoCapture();
bool contrastControl();
bool opticalflow();
#endif