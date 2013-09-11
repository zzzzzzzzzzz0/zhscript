/*
 * jieshiqi_call.h
 *
 *  Created on: 2010-3-28
 *      Author: zzzzzzzzzzz
 */

#ifndef JIESHIQI_CALL_H_
#define JIESHIQI_CALL_H_

#define calltype_void_	     	0L
#define calltype_char_	     	0x00000001L
#define calltype_int_	      	0x00000002L
#define calltype_unsigned_		0x00000010L
#define calltype_long_	     	0x00000020L
#define calltype_zhizhen_		0x00000100L
#define calltype_addr_			0x00000400L
#define calltype_loadlibrary_	0x00001000L
#define calltype_getprocaddr_	0x00002000L
#define calltype_freelibrary_	0x00004000L

#define calltype_niyazhan_		0x00010000L	//逆压栈
#define calltype_jia_qian_		0x00020000L	//前面加下划线
#define calltype_add_sp_		0x00040000L
#define calltype_cdecl_       	calltype_add_sp_

#define calltype_args_			0x00100000L	//标准
#define calltype_buf_siz_		0x00200000L
#define calltype_ret_err_		0x00400000L
#define calltype_buf_			0x01000000L
#define calltype_ret_addr_		0x02000000L

#define calltype_memory_		0x10000000L
#define calltype_var_			0x20000000L

#define calltype_err_type_		0x80000000L

#define funcfmt_func_fengefu_	'/'
#define funcfmt_param_fengefu_	'-'

#endif /* JIESHIQI_CALL_H_ */
