#include <opencv2/opencv.hpp> //����ͷ�ļ� <> ��ʾ����ϵͳͷ�ļ�  "" ��ʾ�����Լ���ͷ�ļ�
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>



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

#endif