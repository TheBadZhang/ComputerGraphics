#include <cstdio>
#include <cmath>

struct OBJ {
	long long m;
	double s;
	double v;
}B1 {1, 10.0, 0.0}, B2 {100000000000000/*物体二的质量应是物体一的 100^n 倍，方能得出正确结果*/, 30.0, -10.0};

inline double calc (OBJ a, OBJ b) {
	return ((a.m - b.m) * a.v + 2 * b.m * b.v) / (a.m + b.m);
}

int main () {
	
	unsigned long long count = 0;
	double v;
	
	while (true) {
		
		B1.s += B1.v;
		B2.s += B2.v;
		
		if (B1.s <= 0.0) {
			B1.v = -B1.v;
			count ++;
		}
		if (B1.s >= B2.s) {
			v = calc (B1, B2);
			B2.v = calc (B2, B1);
			B1.v = v;
			count ++;
		}
		
		if (abs (B1.v) <= B2.v && B2.v > 0) break;
		
	}
	
	printf ("%ld\n", count);
		
	return 0;
} 
