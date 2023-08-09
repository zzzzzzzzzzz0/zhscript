
bool img___::hulasi__(char* buf, long siz, size_t x1, size_t y1, size_t w, size_t h, double pian1, int xx, char fang) {
	try {
		size_t w3 = i_.columns(), h3 = i_.rows();
		if(x1 >= w3 || y1 >= h3)
			return true;
		PixelPacket *pp3 = getPixels(w3, h3);
		size_t x2 = x1 + w, y2 = y1 + h;
		if(x2 >= w3)
			x2 = w3 - 1;
		if(y2 >= h3)
			y2 = h3 - 1;
		switch(fang) {
		case '|':
			y2 += xx;
			for(size_t y = y1; y <= y2; y++) {
				int pian2 = (y - y1) * pian1;
				for(size_t x = x1; x <= x2; x++) {
					size_t x3 = x + h * pian1, x32 = x + pian2;
					if(x3 >= w3 || x32 >= w3)
						continue;
					ColorRGB c1 = getPixel(x, y1);
					ColorRGB c2 = getPixel(x3, y2);
					size_t x4 = y - y1;
					ColorRGB c3(c1.red() + (c2.red() - c1.red()) * x4 / h,
							c1.green() + (c2.green() - c1.green()) * x4 / h,
							c1.blue() + (c2.blue() - c1.blue()) * x4 / h);
					PixelPacket *p3 = pp3 + y * w3 + x32;
					*p3 = c3;
				}
			}
			break;
		case '-':
			x2 += xx;
			for(size_t x = x1; x <= x2; x++) {
				int pian2 = (x - x1) * pian1;
				for(size_t y = y1; y <= y2; y++) {
					size_t y3 = y + w * pian1, y32 = y + pian2;
					if(y3 >= h3 || y32 >= h3)
						continue;
					ColorRGB c1 = getPixel(x1, y);
					ColorRGB c2 = getPixel(x2, y3);
					size_t x4 = x - x1;
					ColorRGB c3(c1.red() + (c2.red() - c1.red()) * x4 / w,
							c1.green() + (c2.green() - c1.green()) * x4 / w,
							c1.blue() + (c2.blue() - c1.blue()) * x4 / w);
					PixelPacket *p3 = pp3 + y32 * w3 + x;
					*p3 = c3;
				}
			}
			break;
		default:
			sprintf(buf, "%c?", fang);
			return false;
		}
		return true;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return false;
	}
}
