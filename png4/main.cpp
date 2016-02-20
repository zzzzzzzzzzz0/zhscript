#include <png++/png.hpp>
#include <exception>
#include <cmath>
#include <string>
#include <iostream>
#include "def1.h"
#include "call_util.cpp"
using namespace std;

static string head_("txt2png");

dlle___ void txt2png__(char* buf, const char* txt, const char* pngname, const char* outpngname) {
	if(!txt || !pngname || !outpngname) {
		buf[0] = 'n';
		buf[1] = 0;
		return;
	}
	string txt2 = head_ + txt;
	if(txt2.size() == 0) {
		buf[0] = 's';
		buf[1] = 0;
		return;
	}
	unsigned int w = sqrt(txt2.size()), h = w;
	if(w * h < txt2.size() + 1) {
		w++;
		h++;
	}
	try {
		png::image< png::rgb_pixel > img(pngname);
		png::image< png::rgb_pixel > img2(w, h);
		unsigned int i = 0;
		bool end = false;
		for(png::uint_32 y = 0; y < img2.get_height(); y++) {
			for(png::uint_32 x = 0; x < img2.get_width(); x++) {
				png::uint_32 r, g, b;
				png::rgb_pixel* p = &img[y % img.get_height()][x % img.get_width()];
				g = p->green;
				b = p->blue;
				if(i < txt2.size())
					r = txt2[i++];
				else {
					if(!end) {
						end = true;
						r = 0;
					} else {
						r = p->red;
					}
				}
				img2[y][x] = png::rgb_pixel(r, g, b);
			}
		}
		img2.write(outpngname);
	} catch(exception& e) {
		const char* s = e.what();
		for(int i = 0; (buf[i] = s[i]); i++);
	}
}

dlle___ void png2txt__(char**addr_ret, const char* pngname) {
	if(!pngname)
		return;
	string buf;
	try {
		png::image< png::rgb_pixel > img(pngname);
		png::uint_32 len = img.get_height() * img.get_width();
		//cout << img.get_width() << " x " << img.get_height() << " = " << len << endl;
		if(len < head_.size())
			return;
		int step = 1;
		char* buf2 = NULL;
		png::uint_32 i = 0;
		for(png::uint_32 y = 0; y < img.get_height(); y++) {
			for(png::uint_32 x = 0; x < img.get_width(); x++) {
				unsigned char r = img[y][x].red;
				if(step < 3) {
					if(!r)
						step = buf2 ? 3 : 4;
					else {
						switch(step) {
						case 1:
							if(i >= head_.size()) {
								step = 2;
								buf2 = new char[len];
								i = 0;
							} else {
								if(r != head_[i]) {
									return;
								}
							}
							break;
						}
					}
					switch(step) {
					case 2: case 3:
						buf2[i] = r;
						break;
					}
					i++;
				}
			}
		}
		if(buf2) {
			buf = buf2;
			delete buf2;
		}
	} catch(...) {}
	*addr_ret = dup__(buf.c_str());
}

