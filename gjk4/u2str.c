/*
 * u2str.c
 *
 *  Created on: 2016年8月22日
 *      Author: zzzzzzzzzzz
 */
#include <stdio.h>
#include "for_arg_.h"
#include "../gjke4/rust.h"

void u2str__(int *err, unsigned char *buf, int argc, ...) {
	unsigned long unic;
	_for_args( argc )
		if(sscanf(s, "&#%ld;", &unic) != 1)
		if(sscanf(s, "%lx", &unic) != 1) {
			*err = 1;
			return;
		}
		if ( unic <= 0x0000007F )
		{
			// * U-00000000 - U-0000007F:  0xxxxxxx
			*buf++ = (unic & 0x7F);
			continue;
		}
		if ( unic >= 0x00000080 && unic <= 0x000007FF )
		{
			// * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
			*buf++ = ((unic >> 6) & 0x1F) | 0xC0;
			*buf++ = (unic & 0x3F) | 0x80;
			continue;
		}
		if ( unic >= 0x00000800 && unic <= 0x0000FFFF )
		{
			// * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
			*buf++ = ((unic >> 12) & 0x0F) | 0xE0;
			*buf++ = ((unic >>  6) & 0x3F) | 0x80;
			*buf++ = (unic & 0x3F) | 0x80;
			continue;
		}
		if ( unic >= 0x00010000 && unic <= 0x001FFFFF )
		{
			// * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			*buf++ = ((unic >> 18) & 0x07) | 0xF0;
			*buf++ = ((unic >> 12) & 0x3F) | 0x80;
			*buf++ = ((unic >>  6) & 0x3F) | 0x80;
			*buf++ = (unic & 0x3F) | 0x80;
			continue;
		}
		if ( unic >= 0x00200000 && unic <= 0x03FFFFFF )
		{
			// * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			*buf++ = ((unic >> 24) & 0x03) | 0xF8;
			*buf++ = ((unic >> 18) & 0x3F) | 0x80;
			*buf++ = ((unic >> 12) & 0x3F) | 0x80;
			*buf++ = ((unic >>  6) & 0x3F) | 0x80;
			*buf++ = (unic & 0x3F) | 0x80;
			continue;
		}
		if ( unic >= 0x04000000 && unic <= 0x7FFFFFFF )
		{
			// * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			*buf++ = ((unic >> 30) & 0x01) | 0xFC;
			*buf++ = ((unic >> 24) & 0x3F) | 0x80;
			*buf++ = ((unic >> 18) & 0x3F) | 0x80;
			*buf++ = ((unic >> 12) & 0x3F) | 0x80;
			*buf++ = ((unic >>  6) & 0x3F) | 0x80;
			*buf++ = (unic & 0x3F) | 0x80;
			continue;
		}
		*err = 2;
		return;
	_next_args
	*buf = 0;
}

void rust_u2str__(int *err, rust_add___ add, void* env, int argc, ...) {
	unsigned long unic;
	char buf[8];
	_for_args( argc )
		if(sscanf(s, "&#%ld;", &unic) != 1)
		if(sscanf(s, "%lx", &unic) != 1) {
			*err = 1;
			return;
		}
		if ( unic <= 0x0000007F )
		{
			// * U-00000000 - U-0000007F:  0xxxxxxx
			buf[0] = (unic & 0x7F);
			buf[1] = 0;
			add(buf, 0, env);
			continue;
		}
		if ( unic >= 0x00000080 && unic <= 0x000007FF )
		{
			// * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
			buf[0] = ((unic >> 6) & 0x1F) | 0xC0;
			buf[1] = (unic & 0x3F) | 0x80;
			buf[2] = 0;
			add(buf, 0, env);
			continue;
		}
		if ( unic >= 0x00000800 && unic <= 0x0000FFFF )
		{
			// * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
			buf[0] = ((unic >> 12) & 0x0F) | 0xE0;
			buf[1] = ((unic >>  6) & 0x3F) | 0x80;
			buf[2] = (unic & 0x3F) | 0x80;
			buf[3] = 0;
			add(buf, 0, env);
			continue;
		}
		if ( unic >= 0x00010000 && unic <= 0x001FFFFF )
		{
			// * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			buf[0] = ((unic >> 18) & 0x07) | 0xF0;
			buf[1] = ((unic >> 12) & 0x3F) | 0x80;
			buf[2] = ((unic >>  6) & 0x3F) | 0x80;
			buf[3] = (unic & 0x3F) | 0x80;
			buf[4] = 0;
			add(buf, 0, env);
			continue;
		}
		if ( unic >= 0x00200000 && unic <= 0x03FFFFFF )
		{
			// * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			buf[0] = ((unic >> 24) & 0x03) | 0xF8;
			buf[1] = ((unic >> 18) & 0x3F) | 0x80;
			buf[2] = ((unic >> 12) & 0x3F) | 0x80;
			buf[3] = ((unic >>  6) & 0x3F) | 0x80;
			buf[4] = (unic & 0x3F) | 0x80;
			buf[5] = 0;
			add(buf, 0, env);
			continue;
		}
		if ( unic >= 0x04000000 && unic <= 0x7FFFFFFF )
		{
			// * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			buf[0] = ((unic >> 30) & 0x01) | 0xFC;
			buf[1] = ((unic >> 24) & 0x3F) | 0x80;
			buf[2] = ((unic >> 18) & 0x3F) | 0x80;
			buf[3] = ((unic >> 12) & 0x3F) | 0x80;
			buf[4] = ((unic >>  6) & 0x3F) | 0x80;
			buf[5] = (unic & 0x3F) | 0x80;
			buf[6] = 0;
			add(buf, 0, env);
			continue;
		}
		*err = 2;
		return;
	_next_args
}

