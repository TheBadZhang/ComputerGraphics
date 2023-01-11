#include "graphics.h"
#include <thread>
#include <iostream>
#include <vector>

PIMAGE pic;
std::vector<PIMAGE> pattern;
std::vector<std::string> pattern_list = {
	"./pattern/res.png",
	"./pattern/res2.png",
	"./pattern/res3.png"
};

int main (int argc, char *argv []) {
	// 手动刷新模式
	setinitmode (INIT_RENDERMANUAL);
	// 界面分辨率
	initgraph (1024, 768);
	// setbkmode (TRANSPARENT);
	setbkcolor(EGERGB(255,255,255));
	cleardevice();
	for (auto& s:pattern_list) {
		pattern.push_back(newimage());
		getimage(pattern.back(), s.c_str());
	}
	pic = newimage();
	getimage(pic, "./2023.png");
	for (int i = 0; i < 1000;) {
		int x, y;
		x = rand() % getwidth(pic);
		y = rand() % getheight(pic);
		if (getpixel(x, y, pic) == EGERGBA(0,0,0,0)) {
			i ++;
			putimage_rotate(nullptr, pattern[rand()%pattern.size()], x, y, 0.5, 0.5, (double)(rand() % 360)/(180.0)*(3.14), true);
		}
	}
	getch();
	closegraph ();
	return 0;
}
