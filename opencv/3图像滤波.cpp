#include "common.h"

bool blurImg() {
	//-----------------------------------����ֵ�˲�>ģ����--------------------------------------
	Mat img = imread(fileName);
	Mat fliterImg;
	blur(img, fliterImg, Size(15, 15));
	imshow("����ֵ�˲�Ч��ͼ��", fliterImg);
	imwrite("writePic/����˲���ͼƬ.jpg", fliterImg);
	waitKey(0);

	return true;
}