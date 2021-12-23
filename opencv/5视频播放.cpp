#include "common.h"
bool videoPlay() {
	VideoCapture capture("1.avi");
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("∂¡»° ”∆µ", frame);
		waitKey(30);
	}
}