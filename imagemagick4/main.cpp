#include <Magick++.h>
#include <iostream>
#include <sstream>
#include <cstdarg>
#include "def1.h"
#include "call_util.cpp"
#include "../gjke4/rust.h"

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

//                   1234567890123456
//                   IMAGEMAGICK4
const char* bgc_ = "#13A6E3A61C040000";

#include "img___.h"
#include "img-hulasi.h"

dlle___ img___* new__(char* buf, long siz, size_t w2, size_t h2, const char* bgc) {
	try {
		InitializeMagick(NULL);
		return new img___(w2, h2, bgc);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}
dlle___ img___* clone__(char* buf, long siz, img___* i) {
	try {
		InitializeMagick(NULL);
		return new img___(i);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}
dlle___ void rust_get_w_h__(rust_add___ add, void* env, img___* i) {
	add(to_string(i->columns()).c_str(), 0, env);
	add(to_string(i->rows()).c_str(), 1, env);
}
dlle___ bool bgc__(char* buf, long siz, img___* ii1, const char* bgc) {
	try {
		ii1->bgc__(bgc);
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ img___* read__(char* buf, long siz, const char *name1) {
	try {
		InitializeMagick(NULL);
		img___* ii1 = new img___();
		ii1->read(name1);
		return ii1;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}
dlle___ void write__(char* buf, long siz, img___* ii1, const char *name2) {
	try {
		ii1->write(name2);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}
dlle___ bool alpha_channel__(char* buf, long siz, img___* ii1) {
	try {
		ii1->alphaChannel();
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool crop__(char* buf, long siz, img___* ii1, ssize_t x1s, ssize_t y1s, size_t x1e, size_t y1e, bool truee = true) {
	try {
		ii1->crop__(x1s, y1s, x1e, y1e, truee);
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool rotate__(char* buf, long siz, img___* ii1, double r) {
	try {
		ii1->rotate(r);
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool flop__(char* buf, long siz, img___* ii1) {
	try {
		ii1->flop();
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool flip__(char* buf, long siz, img___* ii1) {
	try {
		ii1->flip();
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool composite__(char* buf, long siz, img___* ii1, img___* ii2, long x2, long y2, int o) {
	try {
		ii1->composite(ii2, x2, y2, o);
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool hulasi__(char* buf, long siz, img___* ii1, size_t x1, size_t y1, size_t w, size_t h, double pian, int xx, char fang) {
	return ii1->hulasi__(buf, siz, x1, y1, w, h, pian, xx, fang);
}
dlle___ bool resize__(char* buf, long siz, img___* ii1, char* s) {
	try {
		ii1->resize(s);
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ bool w_h_max__(char* buf, long siz, img___* ii1, int _w1_max, int _h1_max) {
	try {
		size_t w1 = ii1->columns(), h1 = ii1->rows();
		size_t w1_max = img___::w__(w1, _w1_max, 1);
		size_t h1_max = img___::w__(h1, _h1_max, 1);
		//std::cout << " " << w1 << " " << w1_max << " " << _w1_max << " " << h1 << " " << h1_max << " " << _h1_max << "\n";
		if(w1 > w1_max || h1 > h1_max) {
			stringstream w_h2;
			w_h2 << w1_max << "x" << h1_max;
			ii1->resize(w_h2.str());
		}
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
dlle___ void free__(img___* ii1) {
	delete ii1;
}

#include "main-image_w.h"
#include "main-2to1.h"

dlle___ void get_p__(char* buf, long siz, Image *ii1, size_t x, size_t y, size_t w, size_t h) {
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
dlle___ void set_p__(PixelPacket *pp2, size_t x, size_t y, const char *x11color, size_t w1) {
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

#include "main-imagehua.h"

static void* jsq_;
static callback2_2___ cb_;
static stringstream get_p_fmt_, set_p_fmt_;
dlle___ void init__(void* jsq, callback2_2___ cb, int addr_fmt) {
	jsq_ = jsq;
	cb_ = cb;
	if(jsq) {
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
	} else {
		get_p_fmt_ << "%lu";
		set_p_fmt_ << "%lu";
	}
}

static void image__(int*err, char* buf, long siz, const char *name1, const char *name2,
		const char *code, rust_cb___ rust_cb, rust_cb_free___ rust_cbf, void*ce, void* shangji) {
	try {
		InitializeMagick(NULL);

		Image ii1;
		ii1.read(name1);
		size_t w1 = ii1.columns(), h1 = ii1.rows();
#ifdef ver_image_
		Image io2(Geometry(w1, h1, 0, 0), Color(bgc_));
#else
		stringstream w_h1;
		w_h1 << w1 << "x" << h1;
		Image io2(w_h1.str(), bgc_);
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
				if((string)(ColorRGB)*p2 == bgc_) {
					stringstream x_2, y_2, w_2;
					x_2 << (unsigned)x;
					y_2 << (unsigned)y;
					w_2 << (unsigned)w1;
					if(rust_cb) {
						const char* argv[] = {x_2.str().c_str(),
							y_2.str().c_str(),
							w_2.str().c_str(), get_p, set_p};
						char *s = rust_cb(ce, shangji, err, '0', code, 5, argv);
						rust_cbf(s);
					} else {
						cb_(jsq_, shangji, err, ce, code, false, NULL, 5,
							x_2.str().c_str(),
							y_2.str().c_str(),
							w_2.str().c_str(), get_p, set_p);
					}
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
dlle___ void image__(int*err, char* buf, long siz, const char *name1, const char *name2,
		const char *code, void*ce, void* shangji) {
	image__(err, buf, siz, name1, name2, code, NULL, NULL, ce, shangji);
}
dlle___ void rust_image__(int*err, char* buf, long siz, const char *name1, const char *name2,
		const char *code, rust_cb___ cb, rust_cb_free___ f, void* env, void* ret) {
	image__(err, buf, siz, name1, name2, code, cb, f, env, ret);
}

#include "main-imagepin.h"
#include "main-text2image.h"
#include "main-xiefen.h"
