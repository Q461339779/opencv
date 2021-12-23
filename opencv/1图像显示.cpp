#include "common.h"

bool showImg() {

	//-----------------------------------【读取一张图片】--------------------------------------
	Mat img = imread(fileName);
	if (!img.data)
	{
		cout << "图片加载失败！" << endl;
		return -1;
	}
	else
	{
		cout << "图片加载成功！" << endl;
	}
	// 窗口显示图片
	imshow("【载入原图】", img);
	waitKey(0);

	return true;
}