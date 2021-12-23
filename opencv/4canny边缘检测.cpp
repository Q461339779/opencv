#include "common.h"

bool cannyImg() {
	//-----------------------------------��canny ��Ե��⡿--------------------------------------
	//��0������ԭʼͼ  
	Mat srcImage = imread(fileName);  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ
	imshow("��ԭʼͼ��Canny��Ե���", srcImage); 	//��ʾԭʼͼ 
	Mat dstImage, edge, grayImage;	//��������

	//��1��������srcͬ���ͺʹ�С�ľ���(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//��2����ԭͼ��ת��Ϊ�Ҷ�ͼ��
	//�˾�����OpenCV2��Ϊ��
	//cvtColor( srcImage, grayImage, CV_BGR2GRAY );
	//�˾�����OpenCV3��Ϊ��
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//��3������ʹ�� 3x3�ں�������
	blur(grayImage, edge, Size(3, 3));

	//��4������Canny����
	Canny(edge, edge, 3, 9, 3);

	//��5����ʾЧ��ͼ 
	imshow("��Ч��ͼ��Canny��Ե���", edge);
	imwrite("writePic/���Canny��Ե����ͼƬ.jpg", edge);
	waitKey(0);

	return true;
}