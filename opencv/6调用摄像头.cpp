#include "common.h"

bool videoCapture() {
	//��1��������ͷ������Ƶ
	VideoCapture capture(0);

	//��2��ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;  //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  //��ȡ��ǰ֡
		imshow("��ȡ��Ƶ", frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}
}