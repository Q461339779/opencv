#include "common.h"

bool showImg() {

	//-----------------------------------����ȡһ��ͼƬ��--------------------------------------
	Mat img = imread(fileName);
	if (!img.data)
	{
		cout << "ͼƬ����ʧ�ܣ�" << endl;
		return -1;
	}
	else
	{
		cout << "ͼƬ���سɹ���" << endl;
	}
	// ������ʾͼƬ
	imshow("������ԭͼ��", img);
	waitKey(0);

	return true;
}