#include <graphics.h>
#include <cmath>
#include <ctime>

const double pi = 3.14159265;
void drawPloy (int x = ege::getwidth () / 2, int y = ege::getheight () / 2,
      int n = 3, int r = 100, double R = 0.0) {
	int x1 = x + r * sin (R);
	int y1 = y + r * cos (R);
	// 第一条边的起点
	int x2, y2;


	for (int i = 0; i <= n; i ++) {
		double deviation = R + i*(2*pi/n);
		// 偏差角度
		x2 = x + r * sin (deviation);
		y2 = y + r * cos (deviation);
		// 计算新的坐标
		line (x1, y1, x2, y2);
		// 画线
		x1 = x2; y1 = y2;
	}
}


int main () {

	ege::setinitmode (INIT_RENDERMANUAL);
	// 设定更新方式为手动更新
	ege::initgraph (800, 800);

	double x = 400, y = 400, n = 3, r = 100, R = 0;
	// 原始坐标（初始化用）
	double nx, ny, nn, nr, nR;
	// 新的坐标

	int timer = 0;				// 计时器
	const int second = 2;		// 一次动画持续的时间
	const int fps = 60;			// 帧率
	srand (time (NULL));

	for (;ege::is_run (); delay_fps (fps)) {

		ege::cleardevice ();

		if (timer % (fps * second) == 0) {
			nx = rand () % 800;				// x 坐标
			ny = rand () % 800;				// y 坐标
			nn = rand () % 20;				// 边数
			nr = rand () % 400;				// 半径
			nR = rand () / 1000;			// 旋转角度
		}

		timer = timer + 1;

		x += (nx - x) / (fps * second);
		y += (ny - y) / (fps * second);
		n += (nn - n) / (fps * second);
		r += (nr - r) / (fps * second);
		R += (nR - R) / (fps * second);
		// 进行渐变

		
		// ege::floodfillsurface (x, y, EGERGB (0, 0, 0));
		// 内部填充，以线条颜色为依据
		drawPloy (x, y, n, r, R);
		// ege::imagefilter_blurring(NULL, 0x60, 0xff);
		// 去掉 cleardevice 运行这句
	}

	ege::getch ();

	ege::closegraph ();

	return 0;
}
