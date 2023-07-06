dlle___ img___* imagehua2__(char* buf, long siz, img___* ii1, int _w2, int _h2, size_t w2_max, size_t h2_max, int ctl0, int ctl1, int ctl10, int ctl11) {
	try {
		size_t w1 = ii1->columns(), h1 = ii1->rows();
		float f1 = (float)w1 / h1;

		size_t w2 = img___::w__(w1, _w2, 2);
		size_t h2 = img___::w__(h1, _h2, 2);
		if(w2 == 0 && h2 == 0) {
			w2 = w1 * 2;
			h2 = h1 * 2;
		} else if(w2 == 0) {
			w2 = h2 * f1;
		} else if(h2 == 0) {
			h2 = w2 / f1;
		}
		
		//cout << w2_max << "x" << h2_max << endl;
		for(;;) {
			//cout << w2 << "x" << h2 << endl;
			if(w2 > w2_max) {
				w2 = w2_max;
				h2 = w2 / f1;
				continue;
			}
			if(h2 > h2_max) {
				h2 = h2_max;
				w2 = h2 * f1;
				continue;
			}
			break;
		}

		{
			stringstream w_h;
			w_h << w2 / 2 << "x" << h2 / 2 << "!";
			ii1->resize(w_h.str());
		}
		w1 = ii1->columns();
		h1 = ii1->rows();

		img___* io2 = new img___(w2, h2, bgc_);

		PixelPacket *pp1 = ii1->getPixels(w1,h1);
		PixelPacket *pp2 = io2->getPixels(w2,h2);
		for(size_t y = 0; y < h2; y++) {
			for(size_t x = 0; x < w2; x++) {
				PixelPacket *p2 = pp2 + y * w2 + x;
				size_t x1 = x % w1;
				size_t y1 = y % h1;
				size_t i1 = x / w1 + (y / h1) * 10; //cout << i1 << endl;
				switch(i1) {
				case 0:
					x1 = img___::x__(x1, w1, ctl0 & 1);
					y1 = img___::x__(y1, h1, ctl0 & 2);
					break;
				case 1:
					x1 = img___::x__(x1, w1, ctl1 & 1);
					y1 = img___::x__(y1, h1, ctl1 & 2);
					break;
				case 10:
					x1 = img___::x__(x1, w1, ctl10 & 1);
					y1 = img___::x__(y1, h1, ctl10 & 2);
					break;
				case 11:
					x1 = img___::x__(x1, w1, ctl11 & 1);
					y1 = img___::x__(y1, h1, ctl11 & 2);
					break;
				}
				*p2 = *(pp1 + y1 * w1 + x1);
			}
		}

		io2->syncPixels();
		return io2;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}
dlle___ void imagehuax__(char* buf, long siz, const char *name1, const char *name2, int w2, int h2, size_t w2_max, size_t h2_max, int ctl0, int ctl1, int ctl10, int ctl11, size_t x1s, size_t y1s, size_t x1e, size_t y1e) {
	img___* ii1 = read__(buf, siz, name1);
	if(!ii1)
		return;
	if(!crop__(buf, siz, ii1, x1s, y1s, x1e, y1e))
		return;
	img___* io2 = imagehua2__(buf, siz, ii1, w2, h2, w2_max, h2_max, ctl0, ctl1, ctl10, ctl11);
	if(io2) {
		write__(buf, siz, io2, name2);
		free__(io2);
	}
	free__(ii1);
}
dlle___ void imagehua__(char* buf, long siz, const char *name1, const char *name2, int w2, int h2, size_t w2_max, size_t h2_max, int ctl0, int ctl1, int ctl10, int ctl11) {
	imagehuax__(buf, siz, name1, name2, w2, h2, w2_max, h2_max, ctl0, ctl1, ctl10, ctl11, 0, 0, 0, 0);
}
