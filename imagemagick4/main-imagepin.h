dlle___ void rust_imagepin__(int*err, char* buf, long siz, rust_cb___ rust_cb, rust_cb_free___ rust_cbf, void*ce, void* shangji,
		const char *name2, size_t w2, size_t h2, const char* bgc, const char *code, int argc, ...) {
	try {
		InitializeMagick(NULL);

		vector<img___*> imgs;
		vector<string> get_p;
		{
			va_list argv;
			va_start(argv, argc);
			char get_p1[64];
			for(int i = 0; i < argc; i ++) {
				img___* ii1 = new img___();
				ii1->read(va_arg(argv, char*));
				imgs.push_back(ii1);
				sprintf(get_p1, get_p_fmt_.str().c_str(), (long)ii1);
				get_p.push_back(get_p1);
			}
			va_end(argv);
		}

		Image io2(Geometry(w2, h2, 0, 0), Color(bgc));
		PixelPacket *pp2 = io2.getPixels(0,0,(ssize_t)w2,(ssize_t)h2);
		char set_p[64];
		sprintf(set_p, set_p_fmt_.str().c_str(), (long)pp2);

		size_t argc2 = 3 + imgs.size();
		const char** argv2 = new const char* [argc2];
		argv2[2] = set_p;

		for(size_t i = 0; i < imgs.size(); i++)
			argv2[3 + i] = get_p[i].c_str();
		/*char x_2[16], y_2[16];
		argv2[0] = x_2;
		argv2[1] = y_2;*/

		for(size_t y = 0; y < h2; y++) {
			for(size_t x = 0; x < w2; x++) {
				stringstream x_2, y_2;
				x_2 << (unsigned)x;
				y_2 << (unsigned)y;
				argv2[0] = x_2.str().c_str();
				argv2[1] = y_2.str().c_str();
				/*sprintf(x_2, "%lu", x);
				sprintf(y_2, "%lu", y);*/
				rust_cbf(rust_cb(ce, shangji, err, '0', code, argc2, argv2));
			}
		}

		delete argv2;
		for(size_t i = 0; i < imgs.size(); i++)
			delete imgs[i];

		io2.syncPixels();
		io2.write(name2);
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
	}
}
