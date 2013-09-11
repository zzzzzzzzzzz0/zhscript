/*
 * keyword.h
 *
 *  Created on: 2010-5-3
 *      Author: zzzzzzzzzzz
 */

#ifndef KEYWORD_H_
#define KEYWORD_H_

enum{
	keyword_is_out_=-2,
	keyword_no_,//-1
	keyword_kaiyinhao_,keyword_biyinhao_,
	keyword_bianliangshi_,keyword_bianliangzhong_,
	keyword_asc_,
	keyword_kaikuohao_,keyword_bikuohao_,
	keyword_zhujieshi_,keyword_zhujiezhong_,
	keyword_juhao_,keyword_tanhao_,
	keyword_maohao_,
	keyword_douhao_,keyword_fenhao_,
	keyword_dunhao_,keyword_dunhao2_,
	keyword_jieheshi_,keyword_jiehezhong_,

	keyword_dengyu_,keyword_budengyu_,
	keyword_xiaoyudengyu_,keyword_xiaoyu_,
	keyword_dayudengyu_,keyword_dayu_,
	keyword_fei_,
	keyword_and_,keyword_or_,
	keyword_if_,keyword_then_,keyword_else_,
	keyword_switch_,

	keyword_for_,keyword_break_,keyword_continue_,
	keyword_loop_,keyword_break2_,keyword_continue2_,

	keyword_set_,keyword_top_,keyword_shangji_,keyword_lock_,keyword_lib_,keyword_main_,
	keyword_equ_,

	keyword_delete_,
	keyword_define_,keyword_noparam_,
	keyword_alias_,
	keyword_has_,

	keyword_yuanyangshi_,keyword_yuanyangzhong_,
	keyword_yuanyang_,
	keyword_codeshi_,keyword_codezhong_,
	keyword_code_,

	keyword_echo_,
	keyword_exec_,keyword_call_,
	keyword_load_,keyword_eval_,keyword_with_,
	keyword_end_,keyword_exit_,

	keyword_param_,keyword_params_,
	keyword_length_,keyword_dian_,
	keyword_,
	keyword_null_,
	keyword_callback_,
	keyword_win_,

	keywords_length_
};

#define keyword_is_t_			1000
#define keyword_is_text_		-(keyword_is_t_+keyword_kaiyinhao_)
#define keyword_is_yuanyang_	-(keyword_is_t_+keyword_yuanyangshi_)
#define keyword_is_code_		-(keyword_is_t_+keyword_codeshi_)

#endif /* KEYWORD_H_ */
