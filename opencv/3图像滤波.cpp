#include "common.h"

bool blurImg() {
	//-----------------------------------【均值滤波>模糊】--------------------------------------
	Mat img = imread(fileName);
	Mat fliterImg;
	blur(img, fliterImg, Size(15, 15));
	imshow("【均值滤波效果图】", fliterImg);
	imwrite("writePic/输出滤波后图片.jpg", fliterImg);
	waitKey(0);

	return true;
}