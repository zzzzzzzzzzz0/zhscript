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
#include "listitem.h"
#include <vector>

class dir_opt___{
public:
	bool subdir_;
	bool a_hidden_,a_dir_,a_file_,a_lnk_;
	char tongpei_;
	bool icase_;
	int sort_;
	bool dir_not_tongpei_;
	bool out_dir_enter_,out_dir_exit_,out_dir_exit2_;
	bool dirlnk_is_dir_;
	bool not_;
	bool flag_;
	dir_opt___(){
		subdir_=false;
		a_hidden_=a_dir_=a_file_=a_lnk_=false;
		tongpei_=0;
		icase_=false;
		sort_=-1;
		dir_not_tongpei_=true;
		out_dir_enter_=out_dir_exit_=out_dir_exit2_=false;
		dirlnk_is_dir_=true;
		not_=false;
		flag_ = true;
	}
};

class gi_item___ {
public:
	regex_t* re_;
	bool tanhao_;
	string s_;
	gi_item___(regex_t* re, bool tanhao, const string& s) : re_(re),tanhao_(tanhao), s_(s) {}
};

class dir___ {
private:
	const char *tongpei_, *src_;
	dir_opt___*opt_;
	regex_t* reg_;
	void *ce_, *qu_;
	callback2_2___ func_;
	vector<gi_item___*> gi_items_;
	int dir2__(const char*dir,int depth,string dir2);
	int exec__(string dir2,const char* name,bool is_dir, bool is_lnk, char typ2, size_t begin);

	vector<list_item___*> list2_;
	bool use2_;
public:
	dir___() {use2_ = false;}
	dir___(int) {use2_ = true;}
	virtual ~dir___();
	void dir__(int*err1,char*buf,long siz,
			const char*dir,const char*tongpei,const char*opt1,
			const char* src,void*ce,void*qu,callback2_2___ cb);
	void sort__(int sort1);
	void first__(int sort1);
	bool split__(char c, char*buf,long siz);
	int count__();
	void clear__();

	vector<string> list_;
	long i_, i2_;
	int ii_;
	vector<string>* list__();
};

#endif /* DIR____H_ */
