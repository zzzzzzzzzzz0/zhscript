/*
 * main.cpp
 *
 *  Created on: 2011-6-8
 *      Author: zzzzzzzzzzz
 */
#include "def1.h"

#include "Engine.h"
Engine engine_;
bool is_rev_board_=false;

dlle___ void init__(const char*fen){
	if(!fen||!fen[0])
		fen=start_fen;
	engine_.init_snapshot(fen);
}

dlle___ int get_piece__(int selected_x,int selected_y){
	return engine_.get_piece(selected_x, selected_y,is_rev_board_);
}

dlle___ int try_move__(int selected_chessman,int dst_x,int dst_y)
{
	int dst = engine_.get_dst_xy(dst_x,dst_y,is_rev_board_);
	int src = engine_.get_chessman_xy(selected_chessman);
	int mv =  engine_.get_move(src,dst);
	return engine_.make_move(mv);
}

dlle___ int try_move2__(char*t_mv){
	int mv=engine_.iccs_str_to_move(t_mv);
	return engine_.make_move(mv);
}

dlle___ const char*get_chinese_last_move__(){
	return engine_.get_chinese_last_move().c_str();
}

dlle___ void to_fens__(char *szFen){
	engine_.to_fens(szFen);
}

dlle___ bool red_player__(){
	return engine_.red_player();
}

dlle___ bool mate__(){
	return engine_.mate();
}

dlle___ bool get_checkby__(){
	return engine_.get_checkby();
}


#include "robot.h"
Robot robot_;
callback2___ cb_;
void* jsq_;
void* shangji_;
std::string script_;

bool robot_out_slot__(const Glib::IOCondition& condition){
	char buf[1024];
	int buf_len = 1024;
	char* p = buf;
	for (; buf_len > 0; ) {
		int len = robot_.get_robot_log(p, buf_len);
		if (len <= 0)
			break;
		p += len;
		buf_len -= len;
	}
	if (buf_len > 0) {
		*p = 0;
		int err;
		cb_(jsq_,shangji_,&err,script_.c_str(),false,1,buf);
	}
	return true;
}

dlle___ void robot_init__(callback2___ cb,void* jsq,void* shangji,const char* script){
	cb_=cb;
	jsq_=jsq;
	shangji_=shangji;
	script_=script;
	robot_.set_out_slot(sigc::ptr_fun(robot_out_slot__));
}

dlle___ bool robot_start__(){
	robot_.start();
	if(!robot_.running())
		return false;
	robot_.send_ctrl_command("ucci\n");
	return true;
}

dlle___ void robot_stop__(){
	robot_.send_ctrl_command("quit\n");
	robot_.stop();
}

dlle___ void robot_send_ctrl_command__(const char*s){
	robot_.send_ctrl_command(s);
	robot_.send_ctrl_command("\n");
}
