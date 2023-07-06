static string text2image_ = "imk4.t2i";
dlle___ void text2image__(int*err, char* buf, long siz, const char *text0, const char *name1, const char *name2) {
	try {
		InitializeMagick(NULL);

		Image ii1;
		ii1.read(name1);
		ssize_t w1 = ii1.columns(), h1 = ii1.rows();
		PixelPacket *pp1 = ii1.getPixels(0,0,w1,h1);
		Image io2(Geometry(w1, h1, 0, 0), Color(bgc_));
		io2.quality(100);
		PixelPacket *pp2 = io2.getPixels(0,0,w1,h1);
		size_t i = 0, i2 = 0;
		bool end = false;
		string text = text2image_ + text0;
		for(ssize_t y = 0; y < h1; y++) {
			for(ssize_t x = 0; x < w1; x++) {
				/*auto c2__ = [&](unsigned u2) {
				};*/
				auto c__ = [&](double d) {
					if(end)
						return d;
					unsigned u = (unsigned)(d * 255);
					unsigned char c = text[i];
					if((c << i2) & 0x80) {
						if(u % 2 == 0) {
							if(u < 255)
								u += 1;
						}
					} else {
						if(u % 2 == 1) {
							if(u > 0)
								u -= 1;
						}
					}
					if(++i2 >= 8) {
						i2 = 0;
						if(c)
							++i;
						else
							end = true;
					}
					return (double)u / 255.;
				};

				PixelPacket *p2 = pp2 + y * w1 + x;
				ColorRGB c1 = (ColorRGB)pp1[y * w1 + x];
				
				ColorRGB c2(c__(c1.red()), c__(c1.green()), c__(c1.blue()));
				*p2 = c2;
			}
		}
		if(!end) {
			cpy__(buf, "more big", siz);
			return;
		}
		if(name2 && name2[0]) {
			io2.syncPixels();
			io2.write(name2);
		}
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}
dlle___ void rust_text4image__(rust_add___ add, void* env, const char *name1) {
	try {
		InitializeMagick(NULL);

		Image ii1;
		ii1.read(name1);
		ssize_t w1 = ii1.columns(), h1 = ii1.rows();
		PixelPacket *pp1 = ii1.getPixels(0,0,w1,h1);
		size_t i2 = 0;
		unsigned char c2 = 0;
		string buf;
		bool end = false, good = false;
		auto c__ = [&](double d) {
			unsigned u = (unsigned)(d * 255);
			if(u % 2)
				c2 += 1 << (7 - i2);
			if(++i2 >= 8) {
				if(c2) {
					buf += c2;
					if(buf.length() == text2image_.length() && !good) {
						if(buf == text2image_) {
							good = true;
						} else {
							end = true;
						}
						buf.clear();
					}
				} else
					end = true;
				i2 = c2 = 0;
			}
		};
		for(ssize_t y = 0; !end && y < h1; y++) {
			for(ssize_t x = 0; !end && x < w1; x++) {
				ColorRGB c1 = (ColorRGB)pp1[y * w1 + x];
				c__(c1.blue());
				c__(c1.green());
				c__(c1.red());
			}
		}
		add(good ? "" : "is not", 0, env);
		add(buf.c_str(), 1, env);
	} catch (Exception &e) {
		add(e.what(), 0, env);
		add("", 1, env);
	}
}
