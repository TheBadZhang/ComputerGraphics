#include <ege.h>
#include <cmath>
#include <cstdio>

// #define SHOW_CONSOLE

// �˷ݴ���������鵽�︺���������֮����������������� 

double timeSpeed = 0.001;
// ʱ�������ٶȣ���λ�� s���룩 ���˴�Ϊ 1 ms�����룩 

struct OBJ {
	long long m;
	// ���� 
	double s;
	// λ�� 
	double v;
	// �ٶ�
}B1 {1, 10.0, 0.0}, B2 {1000000, 20.0, -10.0};

double border1, border2;
// ����ͼ�εĴ�С 

double calc (OBJ a, OBJ b) {
	return ((a.m - b.m) * a.v + 2 * b.m * b.v) / (a.m + b.m);
	// ������ײ����ٶ� 
}


int main () {
	
	
	// printf ("Start!"); 
	unsigned long long count = 0;
	double v;
	border1 = pow (B1.m, 1.0 / 3.0);
	border2 = pow (B2.m, 1.0 / 3.0);
	// ����ͼ�εı߳���������Ū�������ˡ����� 
	ege::setinitmode (ege::INIT_RENDERMANUAL);
	ege::initgraph (1900, 100);
	ege::setfillcolor (EGERGB (255, 255, 255));
	
	
	for (; ege::is_run (); ege::delay_ms(0)) {
		
		ege::cleardevice ();
		
		ege::bar (B1.s*20, 0, (B1.s + border1)*20, 100);
		ege::bar (B2.s*20, 0, (B2.s + border2)*20, 100);
		ege::xyprintf (1700, 0, "%lf", B1.v);
		ege::xyprintf (1700, 20, "%lf", B2.v);
		ege::xyprintf (1700, 40, "%d", count);
		// ���ݳ��� 
		
		B1.s += B1.v * timeSpeed;
		B2.s += B2.v * timeSpeed;
		// ����״̬���� 
		
		// ege::getch ();
		
		if (B1.s <= 0.0) {
			B1.v = -B1.v;
			// B1.s = 0.0;
			// printf ("ײǽ");
			count ++;
		}
		if (B1.s + border1 >= B2.s) {
			v = calc (B1, B2);
			B2.v = calc (B2, B1);
			B1.v = v;
			// printf ("��ײ");
			count ++;
		}
		
		// printf ("%d\n", count);
		
	}
		
	return 0;
} 
