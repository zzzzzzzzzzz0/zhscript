dlle___ img___* image2to1___(char* buf, long siz, img___* ii1, img___* ii2, const char* bgc, int _w3, int _h3, int _h2, int _h22, const char *ctl) {
	bool hula = false, shangla = false, shangzhongla = false, fanzhuan1 = false, fanzhuan2 = false, daozhuan1 = false, daozhuan2 = false;
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
			case 'f': fanzhuan1 = !fanzhuan1; continue;
			case 'F': fanzhuan2 = !fanzhuan2; continue;
			case 'd': daozhuan1 = !daozhuan1; continue;
			case 'D': daozhuan2 = !daozhuan2; continue;
			}
			cpy__(buf, ctl, siz);
			return NULL;
		}
	}
	size_t w3 = img___::w__(ii1->w__(), _w3, 2);
	size_t h3 = img___::w__(ii1->h__(), _h3, 1);
	try {
		img___* io3 = new img___(w3, h3, bgc);

		size_t h2 = img___::w__(ii1->h__(), _h2, 1);
		size_t h22 = img___::w__(ii2->h__(), _h22, 1);
		switch(_h2) {
		case -1:
			h2 = ii1->rows();
			break;
		case -2:
			h2 = ii2->rows();
			break;
		case -22:
			h2 = h22;
			break;
		}
		switch(_h22) {
		case -1:
			h22 = ii1->rows();
			break;
		case -2:
			h22 = ii2->rows();
			break;
		case -11:
			h22 = h2;
			break;
		}
		{
			stringstream w_h2;
			w_h2 /*<< h2*/ << "x" << h2;
			//std::cout << w_h2.str() << std::endl;
			ii1->resize(w_h2.str());
		}
		{
			stringstream w_h2;
			w_h2 /*<< h22*/ << "x" << h22;
			//std::cout << w_h2.str() << std::endl;
			ii2->resize(w_h2.str());
		}

		size_t w1 = ii1->columns(); //std::cout << w1 << std::endl;
		size_t w2 = ii2->columns(); //std::cout << w2 << std::endl;
		w3 = io3->columns(); h3 = io3->rows();
		PixelPacket *pp3 = io3->getPixels(w3,h3);
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
				size_t y5  = img___::x__(y2 , h2 , daozhuan1);
				size_t y52 = img___::x__(y22, h22, daozhuan2);
				if(x < w1) {
					*p3 = ii1->getPixel(x, y5, fanzhuan1);
					continue;
				}
				if(x >= i) {
					*p3 = ii2->getPixel(x - i, y52, fanzhuan2);
					continue;
				}
				size_t x5  = img___::x__(w1 - 1, w1, fanzhuan1);
				size_t x52 = img___::x__(0     , w2, fanzhuan2);
#ifdef ver_7_
				Quantum c1 = ii1.getPixels(x5 , y5 ,1,1)[0];
				Quantum c2 = ii2.getPixels(x52, y52,1,1)[0];
				//SetPixelRed(io3, GetPixelRed(ii1, c1) + (GetPixelRed(ii2, c2) - GetPixelRed(ii1, c1)) * x4 / w4, p3);
				//p3[io3.channel_map[RedPixelChannel].offset]=0;
#else
				ColorRGB c1 = ii1->getPixel(x5 , y5);
				ColorRGB c2 = ii2->getPixel(x52, y52);
				size_t x4 = x - w1;
				ColorRGB c3(c1.red() + (c2.red() - c1.red()) * x4 / w4,
						c1.green() + (c2.green() - c1.green()) * x4 / w4,
						c1.blue() + (c2.blue() - c1.blue()) * x4 / w4);
				*p3 = c3;
#endif
			}
		}
		io3->syncPixels();
		return io3;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}

dlle___ void image2to1x__(char* buf, long siz, const char *name1, const char *name2, const char *name3,
const char* bgc, int w3, int h3, int h2, int h22, const char *ctl,
size_t x1s, size_t y1s, size_t x1e, size_t y1e,
size_t x2s, size_t y2s, size_t x2e, size_t y2e) {
	img___* ii1 = read__(buf, siz, name1);
	if(!ii1)
		return;
	img___* ii2 = read__(buf, siz, name2);
	if(!ii2)
		return;
	if(!crop__(buf, siz, ii1, x1s, y1s, x1e, y1e))
		return;
	if(!crop__(buf, siz, ii2, x2s, y2s, x2e, y2e))
		return;
	img___* io3 = image2to1___(buf, siz, ii1, ii2, bgc, w3, h3, h2, h22, ctl);
	if(io3) {
		write__(buf, siz, io3, name3);
		free__(io3);
	}
	free__(ii1);
	free__(ii2);
}
dlle___ void image2to1__(char* buf, long siz, const char *name1, const char *name2, const char *name3, const char* bgc, int w3, int h3, int h2, int h22, const char *ctl) {
	image2to1x__(buf, siz, name1, name2, name3, bgc, w3, h3, h2, h22, ctl, 0, 0, 0, 0, 0, 0, 0, 0);
}
