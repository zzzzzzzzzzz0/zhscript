#include <Magick++.h>
#include <iostream>
#include <sstream>
#include "def1.h"
#include "call_util.cpp"

using namespace std;
using namespace Magick;

//#include <magick/MagickCore.h>
#if MAGICKCORE_CHECK_VERSION(0,0,1)
#warning MAGICKCORE_CHECK_VERSION
#endif

#if MAGICKCORE_MAJOR_VERSION >= 7
#define ver_7_
#endif
#ifdef ver_7_
#define ver_image_
#define PixelPacket Quantum
#endif
#ifdef ver_6_9_7_4_
#define ver_image_
#endif

dlle___ void image_w_h__(char* buf, long siz, const char *name1,
		const char *name2, const char* bgc, size_t w2, size_t h2, const char *ctl) {
	char xc = '2', yc = '5';
	if(ctl) {
		for(int i = 0;; i++) {
			char c = ctl[i];
			if(!c)
				break;
			switch(c) {
			case '1': case '2': case '3':
				xc = c;
				continue;
			case '4': case '5': case '6':
				yc = c;
				continue;
			}
			cpy__(buf, ctl, siz);
			return;
		}
	}

	stringstream w_h2;
	w_h2 << w2 << "x" << h2;
	try {
		InitializeMagick(NULL);
		Image ii1, io2(
#ifdef ver_image_
		Geometry(w2, h2, 0, 0), Color(bgc)
#else
		w_h2.str(), bgc
#endif
		);
		ii1.read(name1);

		size_t w1 = ii1.columns(), h1 = ii1.rows();
		if(w2 < w1 || h2 < h1) {
			ii1.resize(w_h2.str());
			w1 = ii1.columns();
			h1 = ii1.rows();
		}
		size_t x3 = 0, y3 = 0, x4 = w1 - 1, y4 = h1 - 1;
		switch(xc) {
		case '2': x3 = (w2 - w1) / 2; break;
		case '3': x3 = w2 - w1; break;
		}
		switch(yc) {
		case '5': y3 = (h2 - h1) / 2; break;
		case '6': y3 = h2 - h1; break;
		}
		size_t x5 = w1 + x3, y5 = h1 + y3;
				
		PixelPacket *pp2 = io2.getPixels(0, 0, (ssize_t)w2, (ssize_t)h2);
		for(size_t y = 0; y < h2; y++) {
			for(size_t x = 0; x < w2; x++) {
				/*if(x < x3 && y < y3) continue;
				if(x >= x5 && y >= y5) continue;
				if(x < x3 && y >= y5) continue;
				if(x >= x5 && y < y3) continue;*/
				PixelPacket *p2 = pp2 + y * w2 + x;
				*p2 = ii1.getPixels(x >= x5 ? x4 : (x < x3 ? 0 : x - x3),
									y >= y5 ? y4 : (y < y3 ? 0 : y - y3), 1, 1)[0];
			}
		}
		io2.syncPixels();

		io2.write(name2);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}

dlle___ void image2to1__(char* buf, long siz, const char *name1, const char *name2, const char *name3,
const char* bgc, size_t w3, size_t h3, size_t h2, size_t h22, const char *ctl) {
	bool hula = false, shangla = false, shangzhongla = false;
	if(ctl) {
		for(int i = 0;; i++) {
			char c = ctl[i];
			if(!c)
				break;
			switch(c) {
			case '1':
				shangla = true;
				continue;
			case '2':
				hula = true;
				continue;
			case '3':
				shangzhongla = true;
				continue;
			}
			cpy__(buf, ctl, siz);
			return;
		}
	}
	try {
		InitializeMagick(NULL);

#ifndef ver_image_
		stringstream w_h3;
		w_h3 << w3 << "x" << h3;
#endif
		Image ii1, ii2, io3(
#ifdef ver_image_
		Geometry(w3, h3, 0,0), Color(bgc)
#else
		w_h3.str(), bgc
#endif
		);
		ii1.read(name1);
		ii2.read(name2);
		switch(h2) {
		case (size_t)-1:
			h2 = ii1.rows();
			break;
		case (size_t)-2:
			h2 = ii2.rows();
			break;
		case (size_t)-22:
			h2 = h22;
			break;
		}
		switch(h22) {
		case (size_t)-1:
			h22 = ii1.rows();
			break;
		case (size_t)-2:
			h22 = ii2.rows();
			break;
		case (size_t)-11:
			h22 = h2;
			break;
		}
		{
			stringstream w_h2;
			w_h2 << h2 << "x" << h2;
			//std::cout << w_h2.str() << std::endl;
			ii1.resize(w_h2.str());
		}
		{
			stringstream w_h2;
			w_h2 << h22 << "x" << h22;
			//std::cout << w_h2.str() << std::endl;
			ii2.resize(w_h2.str());
		}

		size_t w1 = ii1.columns();
		size_t w2 = ii2.columns();
		w3 = io3.columns(); h3 = io3.rows();
		PixelPacket *pp3 = io3.getPixels(0,0,(ssize_t)w3,(ssize_t)h3);
		size_t w4 = w3 - w1 - w2;
		size_t h4 = h3 - h2;
		size_t h42 = h3 - h22;
		for(size_t y = 0; y < h3; y++) {
			size_t y2 = y < h4 ? 0 : y - h4;
			size_t y22 = y < h42 ? 0 : y - h42;
			for(size_t x = 0; x < w3; x++) {
				size_t i = w3 - w2;
				if(x >= w1 && x < i) {
					if(y < h4 || y < h42) {
						if(!shangzhongla)
							continue;
					} else {
						if(!hula)
							continue;
					}
				} else {
					if(y < h42 && !shangla)
						continue;
				}
				PixelPacket *p3 = pp3 + y * w3 + x;
				if(x < w1) {
					*p3 = ii1.getPixels(x,y2,1,1)[0];
					continue;
				}
				if(x >= i) {
					*p3 = ii2.getPixels(x - i,y22,1,1)[0];
					continue;
				}
#ifdef ver_7_
				Quantum c1 = ii1.getPixels(w1 - 1,y2,1,1)[0];
				Quantum c2 = ii2.getPixels(0,y22,1,1)[0];
				//SetPixelRed(io3, GetPixelRed(ii1, c1) + (GetPixelRed(ii2, c2) - GetPixelRed(ii1, c1)) * x4 / w4, p3);
				//p3[io3.channel_map[RedPixelChannel].offset]=0;
#else
				ColorRGB c1 = (ColorRGB)ii1.getPixels(w1 - 1,y2,1,1)[0];
				ColorRGB c2 = (ColorRGB)ii2.getPixels(0,y22,1,1)[0];
				size_t x4 = x - w1;
				ColorRGB c3(c1.red() + (c2.red() - c1.red()) * x4 / w4,
						c1.green() + (c2.green() - c1.green()) * x4 / w4,
						c1.blue() + (c2.blue() - c1.blue()) * x4 / w4);
				*p3 = c3;
#endif
			}
		}
		io3.syncPixels();

		io3.write(name3);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}

static void get_p__(char* buf, long siz, Image *ii1, size_t x, size_t y, size_t w, size_t h) {
	PixelPacket *pp = ii1->getPixels(x,y,w,h);
	string s;
	size_t i = 0;
	for(y = 0; y < h; y++) {
		if(y > 0)
			s += '\n';
		for(x = 0; x < w; x++) {
			if(x > 0)
				s += ',';
			ColorRGB c1 = (ColorRGB)pp[i++];
			s += (string)c1;
		}
	}
	cpy__(buf, s.c_str(), siz);
}
static void set_p__(PixelPacket *pp2, size_t x, size_t y, const char *x11color, size_t w1) {
	PixelPacket *p2 = pp2 + y * w1 + x;
	ColorRGB c2(x11color);
	*p2 = c2;
}

dlle___ void pixel__(char* buf, long siz, const char *name1, size_t x, size_t y, size_t w, size_t h) {
	try {
		InitializeMagick(NULL);
		Image ii1;
		ii1.read(name1);
		get_p__(buf, siz, &ii1, x, y, w, h);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}

static void* jsq_;
static callback2_2___ cb_;
static stringstream get_p_fmt_, set_p_fmt_;
dlle___ void init__(void* jsq, callback2_2___ cb, int addr_fmt) {
	jsq_ = jsq;
	cb_ = cb;
	get_p_fmt_ << "/";
	set_p_fmt_ << "/";
	if(addr_fmt == 16) {
		get_p_fmt_ << hex << (long)get_p__ << "/";
		set_p_fmt_ << hex << (long)set_p__ << "/";
	} else {
		get_p_fmt_ << (unsigned long)get_p__ << "/-";
		set_p_fmt_ << (unsigned long)set_p__ << "/-";
	}
	get_p_fmt_ << "S-${l%ld}-iu-iu-${l1}-${l1}";
	set_p_fmt_ << "${l%ld}-iu-iu-c*-iu";
}

dlle___ void image__(int*err, char* buf, long siz, const char *name1, const char *name2,
		const char *code, void*ce, void* shangji) {
	try {
		InitializeMagick(NULL);

		Image ii1;
		ii1.read(name1);
		size_t w1 = ii1.columns(), h1 = ii1.rows();
		//                   1234567890123456
		//                   IMAGEMAGICK4
		const char* bgc = "#13A6E3A61C040000";
#ifdef ver_image_
		Image io2(Geometry(w1, h1, 0, 0), Color(bgc));
#else
		stringstream w_h1;
		w_h1 << w1 << "x" << h1;
		Image io2(w_h1.str(), bgc);
#endif
		PixelPacket *pp2 = io2.getPixels(0,0,(ssize_t)w1,(ssize_t)h1);
		char get_p[64], set_p[64];
		sprintf(get_p, get_p_fmt_.str().c_str(), (long)&ii1);
		sprintf(set_p, set_p_fmt_.str().c_str(), (long)pp2);
		for(size_t y = 0; y < h1; y++) {
			for(size_t x = 0; x < w1; x++) {
				/*ColorRGB c1 = (ColorRGB)ii1.getPixels(x,y,1,1)[0];
				PixelPacket *p2 = pp2 + y * w1 + x;
				ColorRGB c2 = c1;
				*p2 = c2;*/

				PixelPacket *p2 = pp2 + y * w1 + x;
				if((string)(ColorRGB)*p2 == bgc) {
					stringstream x_2, y_2, w_2;
					x_2 << (unsigned)x;
					y_2 << (unsigned)y;
					w_2 << (unsigned)w1;
					cb_(jsq_, shangji, err, ce, code, false, NULL, 5,
						x_2.str().c_str(),
						y_2.str().c_str(),
						w_2.str().c_str(), get_p, set_p);
					if(*err) {
						//cout << *err << endl;
						return;
					}
					//buf[0] = 0;
				}
			}
		}
		if(name2 && name2[0]) {
			io2.syncPixels();
			io2.write(name2);
		}
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}
