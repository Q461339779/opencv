#include "common.h"
bool videoPlay() {
	VideoCapture capture("1.avi");
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("��ȡ��Ƶ", frame);
		waitKey(30);
	}
}