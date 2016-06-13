#include <Magick++.h>
#include <iostream>
#include <sstream>
#include "def1.h"
#include "call_util.cpp"

using namespace std;
using namespace Magick;

#if MAGICKCORE_MAJOR_VERSION >= 7
#define ver_7_
#endif

dlle___ void image2to1__(char* buf, long siz, const char *name1, const char *name2, const char *name3,
const char* bgc, size_t w3, size_t h3, size_t h2, const char *ctl) {
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

#ifndef ver_7_
		stringstream w_h3;
		w_h3 << w3 << "x" << h3;
#endif
		stringstream w_h2;
		w_h2 << h2 << "x" << h2;

		Image ii1, ii2, 
#ifdef ver_7_
		io3(Geometry(w3, h3, 0,0), Color(bgc))
#else
		io3(w_h3.str(), bgc)
#endif
;
		ii1.read(name1);
		ii2.read(name2);
		ii1.resize(w_h2.str());
		ii2.resize(w_h2.str());

		size_t w1 = ii1.columns();
		size_t w2 = ii2.columns();
		w3 = io3.columns(); h3 = io3.rows();
#ifdef ver_7_
		Quantum
#else
		PixelPacket
#endif
		*pp3 = io3.getPixels(0,0,(ssize_t)w3,(ssize_t)h3);
		size_t w4 = w3 - w1 - w2, h4 = h3 - h2;
		for(size_t y = 0; y < h3; y++) {
			size_t y2 = y < h4 ? 0 : y - h4;
			for(size_t x = 0; x < w3; x++) {
				size_t i = w3 - w2;
				if(x >= w1 && x < i) {
					if(y < h4) {
						if(!shangzhongla)
							continue;
					} else {
						if(!hula)
							continue;
					}
				} else {
					if(y < h4 && !shangla)
						continue;
				}
#ifdef ver_7_
				Quantum
#else
				PixelPacket
#endif
				*p3 = pp3 + y * w3 + x;
				if(x < w1) {
					*p3 = ii1.getPixels(x,y2,1,1)[0];
					continue;
				}
				if(x >= i) {
					*p3 = ii2.getPixels(x - i,y2,1,1)[0];
					continue;
				}
#ifdef ver_7_
				Quantum c1 = ii1.getPixels(w1 - 1,y2,1,1)[0];
				Quantum c2 = ii2.getPixels(0,y2,1,1)[0];
				//SetPixelRed(io3, GetPixelRed(ii1, c1) + (GetPixelRed(ii2, c2) - GetPixelRed(ii1, c1)) * x4 / w4, p3);
				//p3[io3.channel_map[RedPixelChannel].offset]=0;
#else
				ColorRGB c1 = (ColorRGB)ii1.getPixels(w1 - 1,y2,1,1)[0];
				ColorRGB c2 = (ColorRGB)ii2.getPixels(0,y2,1,1)[0];
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
