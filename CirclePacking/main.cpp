#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
// #include <conio.h>

// #define Pic
// #define Bin
// Pic 用于是否根据图片输出 circlepacking
// Bin 用于是否使用背景色限定 circlepacking
// Pic 没定义，使用 Bin 也没啥效果（大概


struct Circle{
	int x, y, r;
};


int main () {
	
	const int R = 255, G = 255, B = 255;
	// 背景色
	////////////////////////////// 最小半径？这注释是啥？
	const int radius = 50;
	// 最大半径
	const int WW = 800, WH = 600, times = 3000;
	// 窗口宽度，窗口高度，圈数
	// 在这个程序里，窗口的大小决定了生成图片的大小
	std::vector <Circle> CircleList;
	int count = 0;
	// 圆圈计数器

	srand (time (nullptr));
	initgraph (WW, WH);
	
#ifdef Pic
	// 用于生成彩色的 circlepacking
	PIMAGE pic = newimage ();
	getimage (pic, "./1.jpg");
	putimage (0, 0, pic);
	// 打印图片，否则背景默认纯黑色，圆圈的空隙处会显得有些难看
	
	// 下面的操作现在看起来觉得很奇怪……因为像素颜色最多读取3000次（默认）
	// 照理直接用 getpixel 就好了
	int **map = new int *[WW];
	for (int a = 0; a < WW; a += 1)
		map [a] = new int [WH];
	for (int a = 0; a < WW; a += 1) {
		for (int b = 0; b < WH; b += 1) {
			map [a][b] = getpixel (a, b, pic);
		}
	}
	// 把图片颜色数据读取到 map 数组里
	
	cleardevice ();
#endif

	do {
		int x = rand () % WW;
		int y = rand () % WH;
		int r = rand () % radius;
		// 取模 防止圆 get 不到 pixel，限定园大小为 50 px
		for (auto a : CircleList) {
			int l = sqrt (pow (abs (x - a.x), 2) +
			              pow (abs (y - a.y), 2)
						 ) - a.r;
			// 当前坐标点下的最大半径
			// 需遍历每一个圆（照理这里应该有优化，但是我没有做，导致到了后面速度就非常慢了
			r = r > l ? l : r;
			// 选择半径较小的那一个
			if (r <= 0) break;
			// 如果不合法跳过这次循环(外面 while 的那个)
			// 也就是圆要是出现在了别的圆里就跳过这个数据
		}
#ifdef Pic
#ifdef Bin
		if (map [x][y] != EGERGB (R, G, B)) {
			continue;
		}
		// 可用于对某一特定形状进行输出，例如2018的例图
		// 用于判断是否和背景色相同
#endif
		// 没有定义 Bin就是那个不管什么颜色都会上那个点的色，
		// 定义了遇到背景色就会跳过
		setcolor (map [x][y]);
		setfillcolor (map [x][y]);
#endif
		circle (x, y, r);
		fillellipse (x, y, r, r);
		// 画出图形
		CircleList.push_back ({x,y,r});
		count += 1;
		// 计数值加一
		
	} while (count <= times);
#ifdef Pic
	delimage (pic);
#endif
	closegraph ();

	return 0;
}
