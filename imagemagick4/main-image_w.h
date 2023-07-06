static void get_c_use__(const char* s, ColorRGB& c, int& use) {
	if(!s || !s[0]) {
		use = 0;
		return;
	}
	string s1 = s;
	if(s1 == "+") {
		use = '+';
		return;
	}
	if(s1 == "j") {
		use = 'j';
		return;
	}
	use = 1;
	c = s;
	//string(c) != "none"
}

dlle___ img___* image_w_h_4__(char* buf, long siz, img___* ii1, const char* bgc,
		const char* bc_t, const char* bc_b, const char* bc_l, const char* bc_r,
		int _w2, int _h2, const char *ctl) {
	size_t w2 = img___::w__(ii1->w__(), _w2, 1);
	size_t h2 = img___::w__(ii1->h__(), _h2, 1);
	ColorRGB c2_l, c2_r, c2_t, c2_b;
	int use_c2_t, use_c2_b, use_c2_l, use_c2_r;
	get_c_use__(bc_t, c2_t, use_c2_t);
	get_c_use__(bc_b, c2_b, use_c2_b);
	get_c_use__(bc_l, c2_l, use_c2_l);
	get_c_use__(bc_r, c2_r, use_c2_r);
	char xk = '2', yk = '5';
	string bk;
	bool jiao4xie = false, fanzhuan = false, hua1 = false, hua1_heng_zs = false, hua1_heng_ys = false, hua1_heng_zx = false, hua1_heng_yx = false;
	if(ctl) {
		for(int i = 0;; i++) {
			char c = ctl[i];
			if(!c)
				break;
			switch(c) {
			case '1': case '2': case '3':
				xk = c;
				continue;
			case '4': case '5': case '6':
				yk = c;
				continue;
			case '7': case '8': case '9': case '0':
				bk += c;
				continue;
			case '/':
				jiao4xie = !jiao4xie;
				continue;
			case 'f':
				fanzhuan = !fanzhuan;
				continue;
			case 'j':
				hua1 = !hua1;
				continue;
			case '-': {
				bool ok = true;
				switch(ctl[i + 1]) {
				case '7': hua1_heng_zs = !hua1_heng_zs; break;
				case '8': hua1_heng_ys = !hua1_heng_ys; break;
				case '9': hua1_heng_zx = !hua1_heng_zx; break;
				case '0': hua1_heng_yx = !hua1_heng_yx; break;
				default:
					ok = false;
					hua1_heng_zs = hua1_heng_ys = hua1_heng_zx = hua1_heng_yx = true;
					break;
				}
				if(ok)
					i++;
				continue; }
			}
			cpy__(buf, ctl, siz);
			return NULL;
		}
	}

	try {
		img___* io2 = new img___(w2, h2, bgc);

		size_t w1 = ii1->columns(), h1 = ii1->rows();
		size_t x3 = 0, y3 = 0, x4 = w1 - 1, y4 = h1 - 1;
		switch(xk) {
		case '2': x3 = (w2 - w1) / 2; break;
		case '3': x3 = w2 - w1; break;
		}
		switch(yk) {
		case '5': y3 = (h2 - h1) / 2; break;
		case '6': y3 = h2 - h1; break;
		}
		size_t x5 = w1 + x3, y5 = h1 + y3,
			w_l = x3, w_r = w2 - (w1 + w_l),
			h_t = y3, h_b = h2 - (h1 + h_t);
				
		PixelPacket *pp2 = io2->getPixels(w2, h2);
		for(size_t y = 0; y < h2; y++) {
			for(size_t x = 0; x < w2; x++) {
				PixelPacket *p2 = pp2 + y * w2 + x;
				bool
					x_o_r = x >= x5, x_o_l = x < x3,
					y_o_b = y >= y5, y_o_t = y < y3;
				size_t
					x6 = x_o_r ? x4 : (x_o_l ? 0 : x - x3),
					y6 = y_o_b ? y4 : (y_o_t ? 0 : y - y3);

				ColorRGB c1;
				for(;;) {
					bool bxl = false, bxr = false, byt = false, byb = false;
					auto fxl = [&] {
						if(bxl)
							return false;
						else
							bxl = true;
						if(use_c2_l == 'j' && x_o_l) {
							c1 = ii1->getPixel(ii1->o__(x3 - x, 1, true), y6);
							return true;
						}
						return false;
					};
					auto fxr = [&] {
						if(bxr)
							return false;
						else
							bxr = true;
						if(use_c2_r == 'j' && x_o_r) {
							c1 = ii1->getPixel(ii1->o__(x - x5, 0, true), y6);
							return true;
						}
						return false;
					};
					auto fyt = [&] {
						if(byt)
							return false;
						else
							byt = true;
						if(use_c2_t == 'j' && y_o_t) {
							c1 = ii1->getPixel(x6, ii1->o__(y3 - y, 1, false));
							return true;
						}
						return false;
					};
					auto fyb = [&] {
						if(byb)
							return false;
						else
							byb = true;
						if(use_c2_b == 'j' && y_o_b) {
							c1 = ii1->getPixel(x6, ii1->o__(y - y5, 0, false));
							return true;
						}
						return false;
					};
					if(hua1_heng_zs || hua1_heng_ys) {
						if(fyt()) break;
					}
					if(hua1_heng_zx || hua1_heng_yx) {
						if(fyb()) break;
					}
					if(fxl()) break;
					if(fxr()) break;
					if(fyt()) break;
					if(fyb()) break;
					c1 = ii1->getPixel(x6, y6, fanzhuan);
					break;
				}
				if(y_o_b || y_o_t) {
					if(x_o_l) {
						if(y_o_t && bk.find('7') != string::npos) continue;
						if(y_o_b && bk.find('9') != string::npos) continue;
						if(!jiao4xie) {
							*p2 = c1;
							continue;
						}
					}
					if(x_o_r) {
						if(y_o_t && bk.find('8') != string::npos) continue;
						if(y_o_b && bk.find('0') != string::npos) continue;
						if(!jiao4xie) {
							*p2 = c1;
							continue;
						}
					}
				}

				double r_y = -1, g_y = 0, b_y = 0;
				if((use_c2_b && y_o_b) || (use_c2_t && y_o_t)) {
					//去掉的是一种递减遮罩
					if(use_c2_t == 'j' || use_c2_b == 'j') {
						if(jiao4xie) {
							bool repl = false;
							size_t y62 = y_o_t ? ii1->o__(y3 - y, 1, false) : ii1->o__(y - y5, 0, false);
							if(x_o_l) {
								if(y_o_t) {
									if(w_l > 0) {
										repl = (y < x * h_t / w_l);
									}
								}
								else if(y_o_b) {
									if(w_l > 0) {
										size_t y7 = h_b - x * h_b / w_l;
										repl = y > h_t + h1 + y7;
									}
								}
							}
							else if(x_o_r) {
								if(y_o_t) {
									if(h_t > 0) {
										repl = (x < w_l + w1 + (h_t - y) * w_r / h_t);
									}
								}
								else if(y_o_b) {
									if(h_b > 0) {
										repl = (x < w_l + w1 + (y - h_t - h1) * w_r / h_b);
									}
								}
							}
							if(repl) {
								ColorRGB c4 = ii1->getPixel(x6, y62, fanzhuan);
								*p2 = c4;
								continue;
							}
						}
					} else {
						size_t i = y_o_b ? y - (h1 + y3) : y, n = y_o_b ? h_b : h_t;
						if(use_c2_t == '+' || use_c2_b == '+') {
							i = y_o_b ? i : i + h_b;
							n = h_b + h_t;
						}
						ColorRGB
							c4 = y_o_b ? c1 : (use_c2_t == '+' ? ii1->getPixel(x6, y4, fanzhuan) : c2_t),
							c5 = y_o_b ? (use_c2_b == '+' ? ii1->getPixel(x6, 0, fanzhuan) : c2_b) : c1;
						r_y = c4.red() + (c5.red() - c4.red()) * i / n;
						g_y = c4.green() + (c5.green() - c4.green()) * i / n;
						b_y = c4.blue() + (c5.blue() - c4.blue()) * i / n;
					}
				}
				double r_x = -1, g_x = 0, b_x = 0;
				if((use_c2_r && x_o_r) || (use_c2_l && x_o_l)) {
					//同上
					if(use_c2_l == 'j' || use_c2_r == 'j') {
					} else {
						size_t i = x_o_r ? x - (w1 + x3) : x, n = x_o_r ? w_r : w_l;
						if(use_c2_l == '+' || use_c2_r == '+') {
							i = x_o_r ? i : i + w_r;
							n = w_l + w_r;
							//std::cout << x_o_l << x_o_r << " " << i << "/" << n << "(" << w_l << "," << w_r << ")\n";
						}
						ColorRGB c4 = x_o_r ? c1 : (use_c2_l == '+' ? ii1->getPixel(x4, y6, fanzhuan) : c2_l);
						ColorRGB c5 = x_o_r ? (use_c2_r == '+' ? ii1->getPixel(0, y6, fanzhuan) : c2_r) : c1;
						r_x = c4.red() + (c5.red() - c4.red()) * i / n;
						g_x = c4.green() + (c5.green() - c4.green()) * i / n;
						b_x = c4.blue() + (c5.blue() - c4.blue()) * i / n;
					}
				}
				if(r_y >= 0 && r_x >= 0) {
					if(y3 == 0) {
						r_y = -1;
					} else {
						if(x_o_l) {
							if(y_o_t) {
								size_t x7 = y * x3 / y3;
								if(x <= x7) {
									r_y = -1;
								}
							}
							else if(y_o_b) {
								size_t x7 = x3 - (y - y5) * x3 / y3;
								if(x <= x7) {
									r_y = -1;
								}
							}
						} else if(x_o_r) {
							if(y_o_t) {
								size_t x7 = x5 + x3 - y * x3 / y3;
								if(x > x7) {
									r_y = -1;
								}
							}
							else if(y_o_b) {
								size_t x7 = x5 + (y - y5) * x3 / y3;
								if(x > x7) {
									r_y = -1;
								}
							}
						}
					}
				}
				if(r_y >= 0) {
					ColorRGB c3(r_y, g_y, b_y);
					*p2 = c3;
					continue;
				}
				if(r_x >= 0) {
					ColorRGB c3(r_x, g_x, b_x);
					*p2 = c3;
					continue;
				}
				*p2 = c1;
			}
		}
		io2->syncPixels();
		return io2;
	} catch (Exception &e) {
		cpy__(buf, e.what(), siz);
		return NULL;
	}
}
dlle___ void image_w_h_3__(char* buf, long siz, const char *name1, const char *name2, const char* bgc,
		const char* bc_t, const char* bc_b, const char* bc_l, const char* bc_r,
		int w2, int h2, int w1_max, int h1_max, const char *ctl) {
	img___* ii1 = read__(buf, siz, name1);
	if(!ii1)
		return;
	if(!w_h_max__(buf, siz, ii1, w1_max, h1_max))
		return;
	img___* io2 = image_w_h_4__(buf, siz, ii1, bgc, bc_t, bc_b, bc_l, bc_r, w2, h2, ctl);
	if(io2) {
		write__(buf, siz, io2, name2);
		free__(io2);
	}
	free__(ii1);
}
dlle___ void image_w_h_2__(char* buf, long siz, const char *name1,
		const char *name2, const char* bgc, const char* bc_t, const char* bc_b, const char* bc_l, const char* bc_r,
		int w2, int h2, const char *ctl) {
	image_w_h_3__(buf, siz, name1, name2, bgc, bc_t, bc_b, bc_l, bc_r, w2, h2, w2, h2, ctl);
}
dlle___ void image_w_h__(char* buf, long siz, const char *name1, const char *name2, const char* bgc, int w2, int h2, const char *ctl) {
	image_w_h_2__(buf, siz, name1, name2, bgc, NULL, NULL, NULL, NULL, w2, h2, ctl);
}
