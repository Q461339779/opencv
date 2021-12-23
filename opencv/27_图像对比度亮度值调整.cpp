#include "common.h"


static void ContrastAndBright(int,void *);


int g_nContrastValue, g_nBrightValue;
Mat g_srcImage, g_dstImage;

bool contrastControl() {
	system(" color 2F"); //改变控制台的前景和背景颜色

	g_srcImage = imread(fileName);
	if (!g_srcImage.data)
	{
		cout << "图片加载失败" << endl;
		return false;
	}
	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());
	//设置对比度和亮度初始值
	g_nContrastValue = 80;
	g_nBrightValue = 80;

	namedWindow("【效果图窗口】", 1);
	//创建轨迹条
	/**
	* 轨迹条的名字
	* 窗口的名字
	* 整型指针
	* 轨迹条的最大值
	* ContrastAndBright为回调函数的函数名（即指向函数地址的指针）
	*/
	createTrackbar("对比度", "【效果图窗口】", &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("亮   度：", "【效果图窗口】", &g_nBrightValue, 200, ContrastAndBright);

	//调用回调函数
	ContrastAndBright(g_nContrastValue, 0);
	ContrastAndBright(g_nBrightValue, 0);

	//输出一些帮助信息
	cout << endl << "\t运行成功，请调整滚动条观察图像效果\n\n"
		<< "\t按下“q”键时，程序退出\n";

	//按下“q”键时，程序退出
	while (char(waitKey(1)) != 'q') {}
	
	return true;
}

void ContrastAndBright(int, void*)
{
	// 创建窗口
	namedWindow("【原始图窗口】", 1);
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
	// 显示图像
	imshow("【原始图窗口】", g_srcImage);
	imshow("【效果图窗口】", g_dstImage);
}
