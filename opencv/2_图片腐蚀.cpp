#include "common.h"

bool etchImage() {
	//-----------------------------------��ͼƬ��ʴЧ����--------------------------------------
	Mat img = imread(fileName);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat etchImg;
	erode(img, etchImg, element);
	imshow("����ʴ��ͼƬ��", etchImg);
	imwrite("writePic/�����ʴ��ͼƬ.jpg", etchImg);
	waitKey(0);

	return true;
}