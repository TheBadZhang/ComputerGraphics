#include "graphics.h"
#include <thread>
#include <iostream>

mouse_msg gMouseMsg = { 0 };
key_msg gKeyMsg = { 0 };
PIMAGE pic;
// 加载函数，用于初始化资源
void load (void);
// 事件更新函数，主要用来接收事件，比如鼠标键盘事件
void eventUpdate (void);
// 输出更新函数，主要用于处理输入
void dataUpdate (void);
// 画面绘制函数，主要用于显示输出
void drawInterface (void);

int main (int argc, char *argv []) {
	std::thread test (
		[] () {
			int a = 0;
			while (a++ < 100) {
				std::cout << a << std::endl;
			}
			return ;
		}
	);
	// 手动刷新模式
	setinitmode (INIT_RENDERMANUAL);
	// 界面分辨率
	initgraph (800, 600);
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
//
	pic = newimage();
	getimage (pic, "pic.png");
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
//
}
void drawInterface (void) {
//
	putimage (gMouseMsg.x-getwidth(pic)/2, gMouseMsg.y-getheight(pic)/2, pic);
}
