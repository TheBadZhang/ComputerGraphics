#include "graphics.h"
#include <thread>
#include <iostream>

mouse_msg gMouseMsg = { 0 };
key_msg gKeyMsg = { 0 };
PIMAGE pic;
// ���غ��������ڳ�ʼ����Դ
void load (void);
// �¼����º�������Ҫ���������¼��������������¼�
void eventUpdate (void);
// ������º�������Ҫ���ڴ�������
void dataUpdate (void);
// ������ƺ�������Ҫ������ʾ���
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
	// �ֶ�ˢ��ģʽ
	setinitmode (INIT_RENDERMANUAL);
	// ����ֱ���
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
