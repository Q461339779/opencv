#include "common.h"

bool cannyImg() {
	//-----------------------------------【canny 边缘检测】--------------------------------------
	//【0】载入原始图  
	Mat srcImage = imread(fileName);  //工程目录下应该有一张名为1.jpg的素材图
	imshow("【原始图】Canny边缘检测", srcImage); 	//显示原始图 
	Mat dstImage, edge, grayImage;	//参数定义

	//【1】创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//【2】将原图像转换为灰度图像
	//此句代码的OpenCV2版为：
	//cvtColor( srcImage, grayImage, CV_BGR2GRAY );
	//此句代码的OpenCV3版为：
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//【3】先用使用 3x3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//【4】运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	//【5】显示效果图 
	imshow("【效果图】Canny边缘检测", edge);
	imwrite("writePic/输出Canny边缘检测后图片.jpg", edge);
	waitKey(0);

	return true;
}