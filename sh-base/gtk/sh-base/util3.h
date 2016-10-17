/*
 * util3.h
 *
 *  Created on: 2016年2月29日
 *      Author: zzzzzzzzzzz
 */

#ifndef SH_BASE_UTIL3_H_
#define SH_BASE_UTIL3_H_

#include <gtk/gtk.h>

extern GtkWidget* get__(GtkWidget* w, int i);
extern void foreach__(GtkWidget* w, const char* code, void* ce, void* shangji);

#ifdef ver_thread_
extern void thread_begin__();
extern void thread_end__();
#endif

#endif /* SH_BASE_UTIL3_H_ */
