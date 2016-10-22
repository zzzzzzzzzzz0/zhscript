#include <png++/png.hpp>
#include <exception>
#include <cmath>
#include <string>
#include <iostream>
#include "def1.h"
#include "call_util.cpp"
using namespace std;

static string head_("txt2png");

dlle___ void txt2png__(char* buf, const char* txt, const char* pngname, char over, const char* outpngname) {
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
				r = p->red;
				g = p->green;
				b = p->blue;
				if(!end) {
					png::uint_32 u;
					if(i < txt2.size())
						u = txt2[i++];
					else {
						end = true;
						u = 0;
					}
					switch(over) {
					default:
						r = u;
						break;
					case 'g':
						g = u;
						break;
					case 'b':
						b = u;
						break;
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

dlle___ void png2txt__(char**addr_ret, const char* pngname, char over) {
	if(!pngname)
		return;
	string buf;
	try {
		png::image< png::rgb_pixel > img(pngname);
		png::uint_32 len = img.get_height() * img.get_width();
		if(len < head_.size())
			return;
		int step = 1;
		char* buf2 = NULL;
		png::uint_32 i = 0;
		for(png::uint_32 y = 0; y < img.get_height(); y++) {
			for(png::uint_32 x = 0; x < img.get_width(); x++) {
				png::rgb_pixel* p = &img[y][x];
				unsigned char u;
				switch(over) {
				default:
					u = p->red;
					break;
				case 'g':
					u = p->green;
					break;
				case 'b':
					u = p->blue;
					break;
				}
				if(step < 3) {
					if(!u)
						step = buf2 ? 3 : 4;
					else {
						switch(step) {
						case 1:
							if(i >= head_.size()) {
								step = 2;
								buf2 = new char[len];
								i = 0;
							} else {
								if(u != head_[i]) {
									return;
								}
							}
							break;
						}
					}
					switch(step) {
					case 2: case 3:
						buf2[i] = u;
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

