#include "def1.h"

static callback3_2___ cb_;
static void* jsq_;

dlle___ void init__(void* jsq, callback3_2___ cb) {
	jsq_ = jsq;
	cb_ = cb;
}

#include <stdio.h>

dlle___ void move__(int* err, void*ce, void* shangji,
int x1, int y1, int x2, int y2, int end, int i, char* code) {
	int x, y;
	if(i <= 0) {
		x = x1;
		y = y1;
	} else if(i >= end) {
		x = x2;
		y = y2;
	} else {
		if(x1 == x2) {
			x = x1;
			y = (int)((double)(y2 - y1) / end * i) + y1;
		} else {
			double d = x2 - x1;
			x = (int)(d / end * i) + x1;
			y = (int)((x - x1) * (y2 - y1) / d + y1);
		}
	}
	char sx[16], sy[16];
	sprintf(sx, "%d", x);
	sprintf(sy, "%d", y);
	const char *argv[] = {sx, sy};
	cb_(jsq_, shangji, err, ce, code, false, 0, 2, argv, 0);
}

#include <cmath>

dlle___ void jiajiao__(char* buf, int x1, int y1, int x2, int y2) {
	int x = x2 - x1, y = y2 - y1;
	float f = atan2(y, x) * 180 / M_PI;
	if(f > 0) f = f - 360;
	sprintf(buf, "%.0f", f);
}
