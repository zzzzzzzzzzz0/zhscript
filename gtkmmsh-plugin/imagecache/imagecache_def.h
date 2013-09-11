/*
 * imagecache_def.h
 *
 *  Created on: 2010-12-26
 *      Author: zzzzzzzzzzz
 */

#ifndef IMAGECACHE_DEF_H_
#define IMAGECACHE_DEF_H_

typedef Glib::RefPtr<Gdk::Pixbuf> (*imagecache___)(void* ic,const Glib::ustring& filename,int pix_limit_width,int pix_limit_height,bool pix_limit_aspect);

extern void get_imagecache__(const char*buf,imagecache___& ic,void*& ic_arg1);
#endif /* IMAGECACHE_DEF_H_ */
