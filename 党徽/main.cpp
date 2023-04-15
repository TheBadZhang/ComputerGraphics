#include "graphics.h"

#define SIZE 40

#define _line(a,b,c,d) line(a*SIZE,b*SIZE,c*SIZE,d*SIZE)
#define _circle(x,y,r) circle(x*SIZE,y*SIZE,r*SIZE)
#define _arc(x,y,sa,ea,r) arc(x*SIZE,y*SIZE,sa,ea,r*SIZE)

int main (int argc, char *argv []) {

	setinitmode (INIT_RENDERMANUAL, 1000, 500);

	initgraph (32*SIZE+1, 32*SIZE+1);
	setcaption ("建党百年");

	for (int i = 0; i <= 32;i++) {
		_line(i,0,i,32);
		_line(0,i,32,i);
	}
	_line (0, 0, 32, 32);  // 对角线
	_line (0, 32, 32, 0);

	setbkcolor (RED);
	setcolor (YELLOW);
	setfillcolor(YELLOW);

	// 锤头
	_line (28,32,32,28);         // 手柄底部（ef
	_line (10.5,14.5,21.1,25.1); // 中间段锤柄(re,vf（中间两条
	_line (14.5,10.5,25.1,21.1);
	_line (25,29,28,32);         // 底部段锤柄(re,vf（右下角两条
	_line (29,25,32,28);
	_line (10.6,5.4,3,13);       // 锤头顶部（il
	_line (7.5,17.5,10.5,14.5);  // 锤头底部（gr
	_line (14.5,10.5,18.5,6.5);  // 锤头底部（vh
	_line (3,13,7.5,17.5);       // 锤头敲击位（lg
	_line (18.5,6.5,16,4);       // 锤头（jh
	_arc  (12,0,-106,-44,5.7);   // 圆弧（ij
	// 镰刀
	_arc  (16,16,-36,90,16);            // 镰刀右侧外侧圆弧
	_arc  (16,16,-90,-55,16);
	_arc  (16,14,213,227,18);           // 镰刀下侧，外侧圆弧（分段
	_arc  (16,14,234,-90,18);
	_arc  (10, 15.5, 0, 70, 16.62);     // 内侧右上角圆弧
	_arc  (15.5, 15.5, -31, 0,11.1);    // 内侧右下角圆弧
	_arc  (15.5, 15.5, -90, -59,11.1);
	_arc  (15.5, 10, -137, -90, 16.6);  // 内侧左下角圆弧
	_arc  (2.5, 29.5, 77, 10, 2.5);     // 镰刀手柄（弧zy
	_line (4.8,29.2,5.5,28.5);          // 柄与刀的连线
	_line (2.9,27.1,3.3,26.7);
	_line (1,24,3.6,21.4);              // 镰刀（qw

	floodfill (16*SIZE, 16*SIZE, YELLOW);

	getch();
	closegraph ();

	return 0;
}
