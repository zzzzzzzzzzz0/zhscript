
class img___ {
	Image i_;
public:
	img___() {}
	img___(const img___* i) : i_(i->i_) {}
	img___(size_t w2, size_t h2, const char* bgc) : i_(Geometry(w2, h2, 0, 0), Color(bgc)) {}
	void bgc__(const char* bgc) {
		i_.backgroundColor(Color(bgc));
	}
	
	void crop__(ssize_t x1s, ssize_t y1s, size_t x1e, size_t y1e, bool truee) {
		size_t w, h;
		if(truee) {
			w = w__() - (x1e + x1s);
			h = h__() - (y1e + y1s);
		} else {
			w = x1e;
			h = y1e;
		}
		i_.crop({w, h, x1s, y1s});
	}
	size_t w__() {return i_.columns();}
	size_t h__() {return i_.rows();}

	ColorRGB getPixel(size_t x, size_t y) {return (ColorRGB)i_.getPixels(x, y,1,1)[0];}
	PixelPacket *getPixels(size_t w1, size_t h1) {return i_.getPixels(0,0,(ssize_t)w1,(ssize_t)h1);}
	PixelPacket *getPixels(size_t x, size_t y, ssize_t w, ssize_t h) {return i_.getPixels(x,y,w,h);}

	size_t columns() {return i_.columns();}
	size_t rows() {return i_.rows();}
	void resize(const string& w_h) {i_.resize(w_h);}
	void read(const char* name) {i_.read(name);}
	void write(const char* name) {i_.write(name);}
	void syncPixels() {i_.syncPixels();}
	void rotate(double r) {i_.rotate(r);}
	void flop() {i_.flop();}
	void flip() {i_.flip();}

	bool hulasi__(char* buf, long siz, size_t x1, size_t y1, size_t w, size_t h, double pian, int xx, char fang);
	
	void composite(img___* ii2, size_t x2, size_t y2, int o);
	void alphaChannel() {
		i_.alphaChannel(/*AlphaChannelType::*/DeactivateAlphaChannel /*BackgroundAlphaChannel TransparentAlphaChannel ActivateAlphaChannel DeactivateAlphaChannel*/);
	}
	
	size_t o__(size_t x7, unsigned int l, bool w);

	static size_t w__(size_t w1, int w2, float f);

	static size_t x__(size_t x, size_t w1, bool fanzhuan) {
		if(fanzhuan)
			x = w1 - x - 1;
		return x;
	}
	
	ColorRGB getPixel(size_t x, size_t y, bool fanzhuan) {return getPixel(x__(x, columns(), fanzhuan), y);}
};

void img___::composite(img___* ii2, size_t x2, size_t y2, int o) {
	// /usr/include/ImageMagick-6/magick/composite.h:25:
	CompositeOperator co = CopyCompositeOp;
	switch(o) {
		case -2: co = CopyOpacityCompositeOp; break;
		case -1: co = AtopCompositeOp; break;
		case 1: co = BlendCompositeOp; break;
		case 2: co = BumpmapCompositeOp; break;
		case 3: co = CopyRedCompositeOp; break;
		case 4: co = CopyGreenCompositeOp; break;
		case 5: co = CopyBlueCompositeOp; break;
		case 6: co = ExclusionCompositeOp; break;
		case 7: co = SaturateCompositeOp; break;
		case 9: co = ThresholdCompositeOp; break;
	}
	i_.composite(ii2->i_, x2, y2, co);
}

size_t img___::w__(size_t w1, int w2, float f) {
	if(w2 < 0) {
		w2 = -w2;
		if(w2 > 100 && w2 < 10000) {
			return w1 * (w2 / 100) / (w2 % 100);
		}
		if(w2 > 10000 && w2 < 100000000) {
			return w1 * (w2 / 10000) / (w2 % 10000);
		}
		return 0;
	}
	if(w2 >= 1 && w2 <= 6) {
		w2 = w1 * f / w2;
	}
	return w2;
}

size_t img___::o__(size_t x7, unsigned int l, bool w) {
	size_t w1 = w ? w__() : h__();
	if(x7 >= w1) {
		size_t i = x7 / w1;
		x7 %= w1;
		if(i % 2 == l)
			x7 = w1 - 1 - x7;
	} else {
		if(!l)
			x7 = w1 - 1 - x7;
	}
	return x7;
}

ColorRGB g__(PixelPacket *pp, size_t x, size_t y, size_t w) {
	return (ColorRGB)*(pp + y * w + x);
}
void p__(PixelPacket *pp, size_t x, size_t y, size_t w, const ColorRGB& c) {
	*(pp + y * w + x) = c;
}
