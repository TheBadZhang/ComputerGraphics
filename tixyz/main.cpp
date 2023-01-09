#include "graphics.h"
#include <thread>
#include <iostream>
#include <functional>
#include <cmath>

mouse_msg gMouseMsg = { 0 };
key_msg gKeyMsg = { 0 };


double sine[16][16];
std::function<double(double t, double i, double x, double y, double z)> func = []
	(double t, double i, double x, double y, double z) {
		// return sin(i/3.14+t);
		return sin(t+i+x+y);
		// return double(int(2*(x-8)/y-9*t)&2^(int)(20/y)&2);
		// return 1-fmod((x*x-y+t*(1+x*fmod(x,5))*3),16)/16;
	};
double t = 0;
double t_div = 0.02;

// 加载函数，用于初始化资源
void load (void);
// 事件更新函数，主要用来接收事件，比如鼠标键盘事件
void eventUpdate (void);
// 输出更新函数，主要用于处理输入
void dataUpdate (void);
// 画面绘制函数，主要用于显示输出
void drawInterface (void);

int main (int argc, char *argv []) {
	// std::thread test (
	// 	[] () {
	// 		int a = 0;
	// 		while (a++ < 100) {
	// 			std::cout << a << std::endl;
	// 		}
	// 		return ;
	// 	}
	// );
	// 手动刷新模式
	setinitmode (INIT_RENDERMANUAL);
	// 界面分辨率
	initgraph (1600, 1600);
	// setbkmode (TRANSPARENT);
	load ();
	for (;is_run (); delay_fps (60), cleardevice ()) {

		eventUpdate ();
		dataUpdate ();
		drawInterface ();
	}

	closegraph ();
	return 0;
}

void load (void) {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			sine[x][y] = 0;
		}
	}
}
void eventUpdate (void) {
//
	while (mousemsg ()) {
		gMouseMsg = getmouse ();
	}
	while (kbmsg ()) {
		gKeyMsg = getkey ();
	}
}
void dataUpdate (void) {
	int i = 0;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			sine[x][y] = func(t, i, x, y, 0);
			i++;
		}
	}
	t += t_div;
}


void drawBox(int x, int y, double r) {
	// bar (x-r, y-r, x+r, y+r);
	fillellipsef(x, y, r, r);
}
void drawInterface (void) {
	int i = 0;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			if (sine[x][y] > 0) {
				setfillcolor (EGERGB(122, 147, 131));
				// setfillcolor (RED);
			} else {
				setfillcolor (EGERGB(84, 84, 84));
				// setfillcolor (BLUE);
			}
			drawBox(400+x*50+24, 400+y*50+24, 20*sine[x][y]);
			i++;
		}
		// bar(200+i*25+2, 400-200*sine[i], 200+i*25+23, 400+200*sine[i]);
	}
	xyprintf(0, 0, "t = %lf", t);
}
