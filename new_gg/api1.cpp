/*
 * api1.cpp
 *
 *  Created on: 2014年7月13日
 *      Author: zzzzzzzzzzz
 */
/*
调用先调用“G”、‘‘库名’’、“_api__”、“$0”、“$9”、“$19”、“$2”、“$3”、“$4”、“$13”、“$23”、“$17”了。
*/

#include "api1.h"

callback2_2___ callback_;
callback3_2___ callback3_;
var_new___ var_new_;
var_get___ var_get_;
var_del___ var_del_;
var_for_name___ var_for_name_;
l4_err_out___ l4_err_out_;
void* jsq_;
void* main_qu_;

dlle___ void dlln___(api__)(void* jsq,
		callback2_2___ cb,
		callback3_2___ cb3,
		var_new___ var_new,var_get___ var_get,var_del___ var_del,
		var_for_name___ var_for_name,
		l4_err_out___ l4_err_out,
		void* main_qu)
{
	jsq_=jsq;
	callback_=cb;
	callback3_=cb3;
	var_new_=var_new;
	var_get_=var_get;
	var_del_=var_del;
	var_for_name_ = var_for_name;
	l4_err_out_=l4_err_out;
	main_qu_ = main_qu;
}
