#include "common.h"


static void ContrastAndBright(int,void *);


int g_nContrastValue, g_nBrightValue;
Mat g_srcImage, g_dstImage;

bool contrastControl() {
	system(" color 2F"); //�ı����̨��ǰ���ͱ�����ɫ

	g_srcImage = imread(fileName);
	if (!g_srcImage.data)
	{
		cout << "ͼƬ����ʧ��" << endl;
		return false;
	}
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());
	//���öԱȶȺ����ȳ�ʼֵ
	g_nContrastValue = 80;
	g_nBrightValue = 80;

	namedWindow("��Ч��ͼ���ڡ�", 1);
	//�����켣��
	/**
	* �켣��������
	* ���ڵ�����
	* ����ָ��
	* �켣�������ֵ
	* ContrastAndBrightΪ�ص������ĺ���������ָ������ַ��ָ�룩
	*/
	createTrackbar("�Աȶ�", "��Ч��ͼ���ڡ�", &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("��   �ȣ�", "��Ч��ͼ���ڡ�", &g_nBrightValue, 200, ContrastAndBright);

	//���ûص�����
	ContrastAndBright(g_nContrastValue, 0);
	ContrastAndBright(g_nBrightValue, 0);

	//���һЩ������Ϣ
	cout << endl << "\t���гɹ���������������۲�ͼ��Ч��\n\n"
		<< "\t���¡�q����ʱ�������˳�\n";

	//���¡�q����ʱ�������˳�
	while (char(waitKey(1)) != 'q') {}
	
	return true;
}

void ContrastAndBright(int, void*)
{
	// ��������
	namedWindow("��ԭʼͼ���ڡ�", 1);
	for (int y = 0; y < g_srcImage.rows; y++)	
	{
		for (int x = 0; x < g_srcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}

		}
	}
	// ��ʾͼ��
	imshow("��ԭʼͼ���ڡ�", g_srcImage);
	imshow("��Ч��ͼ���ڡ�", g_dstImage);
}
