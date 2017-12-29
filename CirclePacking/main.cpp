#include <graphics.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <conio.h>

// #define Pic
// #define Bin
struct Circle{
	int x, y, r;
};


int main () {

	const int R = 255, G = 255, B = 255;
	// 最小半径
	const int radius = 50;
	// 最大半径
	const int WW = 800, WH = 600, times = 3000;
	// 宽度，高度，圈数
	std::vector <Circle> CircleList;
	int count = 0;

	srand (time (nullptr));
	initgraph (WW, WH);
	
#ifdef Pic
	PIMAGE pic = newimage ();
	getimage (pic, "./1.jpg");
	putimage (0, 0, pic);
	int **map = new int *[WW];
	for (int a = 0; a < WW; a += 1)
		map [a] = new int [WH];
	for (int a = 0; a < WW; a += 1) {
		for (int b = 0; b < WH; b += 1) {
			map [a][b] = getpixel (a, b, pic);
		}
	}
	cleardevice ();
#endif

	do {
 con:	
		int x = rand () % WW;
		int y = rand () % WH;
		int r = rand () % radius;
		for (auto a : CircleList) {
			int l = sqrt (pow (abs (x - a.x), 2) +
			              pow (abs (y - a.y), 2)
						 ) - a.r;
			// 最大半径
			r = r > l ? l : r;
			// 选择较小的那一个
			if (r <= 0) goto con;
			// 如果不合法跳过这次循环
		}
#ifdef Pic
#ifdef Bin
		if (map [x][y] != EGERGB (R, G, B)) {
			continue;
		}
		// 可用于对某一特定形状进行输出，例如2018的例图
#endif
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