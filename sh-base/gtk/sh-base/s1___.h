/*
 * s1___.h
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#ifndef S1____H_
#define S1____H_
#include <gtk/gtk.h>

class s1___ {
private:
	const char* src2_;
	const char* signal_;
	char type_;
	int i_;
public:
	GCallback cb_;

	s1___(const char* src2, const char* signal, char type);
	s1___(const char* src2, const char* signal, char type, GCallback cb);
	char type__() {return type_;}
	const char* signal__() {return signal_;}
	const char* src2__() {return src2_;}
	int i__() {return i_;}
};

extern size_t s1s_length__();
extern s1___* s1s__(int i);

#endif /* S1____H_ */
