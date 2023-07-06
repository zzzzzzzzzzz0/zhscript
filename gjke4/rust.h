/*
 * rust.h
 *
 *  Created on: 2020年12月19日
 *      Author: zzzzzzzzzzz
 */

#ifndef RUST_H_
#define RUST_H_

/*
rust_cb___ cb, rust_cb_free___ f, void* env, void* ret
const char* argv[] {""};
char *s = cb(env, ret, err, '0', code, argc, argv);
f(s);
*/
typedef char*(*rust_cb___)(void*, void*, int*, char, const char*, size_t, const char**);
typedef char*(*rust_cb2___)(int*, char, const char*, size_t, const char**);
typedef void*(*rust_cb_free___)(char*);

/*
rust_add___ add, void* env
add(buf.c_str(), 0, env);
*/
typedef void*rust_add___(const char*,/*bool*/int,void*);


#endif /* RUST_H_ */
