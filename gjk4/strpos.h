/*
 * strpos.h
 *
 *  Created on: 2009-2-1
 *      Author: zzzzzzzzzzz
 */

#ifndef STRPOS_H_
#define STRPOS_H_

#define _strpos_return_len				1
#define _strpos_jump_over_ss_len	2
#define _strpos_right_result						4
#define _strpos_right							0x10
#define _strpos_with  0x20
#define _strpos_result_no					-1

_dle int strpos_2__(char* s,char* ss,int i,int ctrl);

#endif /* STRPOS_H_ */
