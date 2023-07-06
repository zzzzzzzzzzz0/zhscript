static float xuan__(size_t i1, size_t i2) {
	return (float)i1 / i2;
}

static void x2__(size_t& x2, size_t x, int xx, size_t w) {
	if(xx < 0 && -xx > x) {
		x2 = 0;
		return;
	}
	x2 = x + xx;
	if(x2 >= w)
		x2 = w - 1;
}

dlle___ bool xiefen__(char* buf, long siz, img___* ii, size_t x, size_t y, int xx, int yx) {
	try {
		if(xx == 0 || yx == 0)
			return true;
		size_t w = ii->columns(), h = ii->rows();
		if(x >= w || y >= h)
			return true;
		PixelPacket *pp3 = ii->getPixels(w, h);
		size_t x2, y2;
		x2__(x2, x, xx, w);
		x2__(y2, y, yx, h);
		size_t x3 = min(x, x2), x4 = max(x, x2), y3 = min(y, y2), y4 = max(y, y2);
		size_t w5 = abs(xx), h5 = abs(yx);
		float xuan = xuan__(w5, h5);
		if(xx > 0 && yx < 0) {
			for(y = y3; y < y4; ++y) {
				ColorRGB c1 = g__(pp3, x3, y, w);
				size_t y5 = y4 - y;
				for(x = x3; ++x <= x4;) {
					size_t x5 = x - x3;
					p__(pp3, x, y, w, xuan__(x5, y5)
					< xuan
					? c1 : g__(pp3, x, y4, w));
				}
			}
		}
		else
		if(xx > 0 && yx > 0) {
			for(y = y3; ++y <= y4;) {
				ColorRGB c1 = g__(pp3, x3, y, w);
				size_t y5 = y4 - y;
				for(x = x3; ++x <= x4;) {
					size_t x5 = x4 - x;
					p__(pp3, x, y, w, xuan__(x5, y5)
					< xuan
					? g__(pp3, x, y3, w) : c1);
				}
			}
		}
		else
		if(xx < 0 && yx > 0) {
			for(y = y3; ++y <= y4;) {
				ColorRGB c1 = g__(pp3, x4, y, w);
				size_t y5 = y4 - y;
				for(x = x3; x < x4; ++x) {
					size_t x5 = x - x3;
					p__(pp3, x, y, w, xuan__(x5, y5)
					< xuan
					? g__(pp3, x, y3, w) : c1);
				}
			}
		}
		else
		{
			for(y = y3; y < y4; ++y) {
				ColorRGB c1 = g__(pp3, x4, y, w);
				size_t y5 = y4 - y;
				for(x = x3; x < x4; ++x) {
					size_t x5 = x4 - x;
					p__(pp3, x, y, w, xuan__(x5, y5)
					< xuan
					? c1 : g__(pp3, x, y4, w));
				}
			}
		}
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
