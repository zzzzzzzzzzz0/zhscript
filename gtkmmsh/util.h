/*
 * util.h
 *
 *  Created on: 2010-6-5
 *      Author: zzzzzzzzzzz
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <gtkmm.h>
#include"call_util.h"

void cpy__(char*buf,long num,long siz);
bool file_get__(const char*name,Glib::ustring& buf);

char* l2s__(long num,char* num2);
char* l2x__(long num,char* buf);
guint32 s2u__(const Glib::ustring&s,guint32 defa=0);
gint32 s2i__(const Glib::ustring&s,gint32 defa=0);
char* d2s__(gdouble d,char*s);
long s2l__(const Glib::ustring&s,long defa=0);
unsigned long x2lu__(const Glib::ustring&s,unsigned long defa=0);

#endif /* UTIL_H_ */
