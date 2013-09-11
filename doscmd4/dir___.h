/*
 * dir___.h
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#ifndef DIR____H_
#define DIR____H_
#include <regex.h>
#include "def1.h"
#include<string>
#include <vector>
using namespace std;

class dir_opt___{
public:
	bool subdir_;
	bool a_hidden_,a_dir_,a_file_,a_lnk_;
	char tongpei_;
	bool icase_;
	int sort_;
	bool dir_not_tongpei_;
	bool out_dir_enter_,out_dir_exit_;
	bool test_lnk_is_dir_;
	bool not_;
	dir_opt___(){
		subdir_=false;
		a_hidden_=a_dir_=a_file_=a_lnk_=false;
		tongpei_=0;
		icase_=false;
		sort_=-1;
		dir_not_tongpei_=true;
		out_dir_enter_=out_dir_exit_=false;
		test_lnk_is_dir_=true;
		not_=false;
	}
};

class dir___ {
private:
	int dir2__(const char*dir,int depth,string dir2,regex_t* reg,const char*tongpei,
			dir_opt___*opt,const char* src,void*ce,void*qu,callback2_2___ cb);
	int exec__(regex_t* reg,const char*tongpei,dir_opt___*opt,
			string dir2,const char* name,bool is_dir,
			const char* src,void*ce,void*qu,callback2_2___ cb);
public:
	dir___();
	virtual ~dir___();
	void dir__(int*err1,char*buf,long siz,
			const char*dir,const char*tongpei,const char*opt1,
			const char* src,void*ce,void*qu,callback2_2___ cb);
	void sort__(int sort1);
	void first__(int sort1);

	vector<string> list_;
	int i_,ii_;
};

#endif /* DIR____H_ */
