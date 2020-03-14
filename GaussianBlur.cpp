#include <graphics.h>
#include <cmath>
#include <cstdio>
#include <ctime>

class PicBlur {
	
	PIMAGE Pic;
	double *vector;
	color_t *GMap;
	int W, H, W21, H21, picH, picW;
	double GaussianWeight (int x, int y, double sigama = 1.5) {
		double sigama22 = 2 * sigama * sigama;
		return 1.0/(3.141592653 * sigama22) * pow(2.718281828, -(x*x + y*y) / sigama22);
	}
public:
	PicBlur (PIMAGE pic, int w, int h = 0) {
		Pic = pic;
		picH = getheight (pic);
		picW = getwidth (pic);
		GMap = new color_t [picW * picH];
		for (int i = 0; i < picH; i ++) {
			for (int j = 0; j < picW; j ++) {
				GMap [i * picW + j] = getpixel (j, i, pic);
			}
		}

		if (h == 0) { H = w; }
		else        { H = h; }
		W = w;
		W21 = W * 2 + 1;
		H21 = H * 2 + 1;
		vector = new double [W21 * H21];

		for (int i = -H; i <= H; i ++) {
			for (int j = -W; j <= W; j ++) {
				vector [(i+H) * W21 + j + W] = GaussianWeight (i, j); 
			}
		}

	}
	double GetNum (int i, int j) {
		if (i < 0 || i > H21 || j < 0 || j > W21) {
			return -1.0;
		} else {
			return vector [i*W21 + j];
		}
	}
	color_t GetMapNum (int i, int j) {
		if (i < 0 || i > picH || j < 0 || j > picW) {
			return EGERGB (128, 128, 128);
		} else {
			return GMap [i * picW + j];
		}
	}
	color_t GetBlurColor (int x, int y) {
		double R = 0, G = 0, B = 0;
		color_t color;
		double num;
		for (int i = 0; i < H21; i ++) {
			for (int j = 0; j < W21; j ++) {
				color = GetMapNum (x - H + i, y - W + j);
				num = GetNum (i, j);
				R += EGEGET_R(color) * num;
				G += EGEGET_G(color) * num;
				B += EGEGET_B(color) * num;
			}
		}
		return EGERGB ((int)R, (int)G, (int)B);
	}
	void Blur (void) {
		for (int i = 0; i < picH; i ++) {
			for (int j = 0; j < picW; j ++) {
				putpixel (j, i, GetBlurColor (i, j), Pic);
			}
		}
	}
};


int main () {

	initgraph (400, 400, 0);
	PIMAGE pic = newimage ();
	// getimage (pic, "pic.jpg");
	putimage (0, 0, pic);
	PicBlur g(pic, 3);
	
	g.Blur();
	putimage (0, 0, pic);
	
	getch ();
	closegraph ();

}
