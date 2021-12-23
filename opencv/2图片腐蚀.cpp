#include "common.h"

bool etchImage() {
	//-----------------------------------¡¾Í¼Æ¬¸¯Ê´Ð§¹û¡¿--------------------------------------
	Mat img = imread(fileName);
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat etchImg;
	erode(img, etchImg, element);
	imshow("¡¾¸¯Ê´ºóÍ¼Æ¬¡¿", etchImg);
	imwrite("writePic/Êä³ö¸¯Ê´ºóÍ¼Æ¬.jpg", etchImg);
	waitKey(0);

	return true;
}