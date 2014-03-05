/*
 * args_util.hh
 *
 *  Created on: 2014年2月18日
 *      Author: zzzzzzzzzzz
 */

#ifndef ARGS_UTIL_HH_
#define ARGS_UTIL_HH_

#include <string>

#define jieshiqi_args_del_ "-\xff"

extern void jieshiqi_args_del__(std::string& s);
extern void jieshiqi_args_del_line__(std::string& s, size_t from);
extern void jieshiqi_args_del__(char* s);
extern void jieshiqi_args_del_line__(char* s, size_t from);

#endif /* ARGS_UTIL_HH_ */
