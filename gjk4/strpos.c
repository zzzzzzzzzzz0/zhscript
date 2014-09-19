#include "1.h"
#include"strpos.h"

/*_dle int strpos__(char* s,char* ss,int i,int ctrl){
        int s_len,ss_len;
        char* s1;
        int i1;
        s_len=strlen(s);
        if(i>=s_len || i<0)
                return -1;
        ss_len=strlen(ss);
        i1=i;
        if(ctrl & 2){
                i1+=ss_len;
                                }
        s1=strstr(s+i1,ss);
        if(s1==NULL){
                if(ctrl & 1)
                        return s_len;
                return -1;
        }
        i1=(int)(s1-s);
        return i1;
}*/

static int strpos_2_ret_no__(int ctrl){
	if(ctrl & _strpos_with)
		return 0;
	return _strpos_result_no;
}

_dle int strpos_2__(char* s,char* ss,int i,int ctrl){
	int s_len,ss_len;
	int i1,i2,i3;

	if(s==0 || ss==0)
		return strpos_2_ret_no__(ctrl);

	s_len=strlen(s);

	if(i>=s_len)
		return strpos_2_ret_no__(ctrl);

	if(i==0 && (ctrl & _strpos_right))
		i=s_len-1;
	if(i<0){
		i+=s_len;
		if(i<0)
			return strpos_2_ret_no__(ctrl);
	}

	ss_len=strlen(ss);
	i1=i;
	if(ctrl & _strpos_jump_over_ss_len){
		if(ctrl & _strpos_right)
               		i1-=ss_len;
		else
                	i1+=ss_len;
	}
	for(;i1>=0 && i1<s_len;){
		for(i2=0;;i2++){
			i3=i1+i2;
			if(s[i3]==0 || ss[i2]==0)
				break;
			if(s[i3]!=ss[i2])
				break;
		}
		if(i2==ss_len){
			if(ctrl & _strpos_with){
				if(ctrl & _strpos_right)
					return s_len-i1==ss_len;
				else
					return i1==0;
			}
			if(ctrl & _strpos_right_result)
				return s_len-i1;
			else
				return i1;
		}
		if(ctrl & _strpos_right)
			i1--;
		else
			i1++;
	}
	if(ctrl & _strpos_return_len){
		if(ctrl & _strpos_right)
			return 0;
		else
			return s_len;
	}
	return strpos_2_ret_no__(ctrl);
}

_dle int strpos_2a3__(char* s,char* ss,int i){
	return strpos_2__(s,ss,i,0);
}

_dle int strpos_2a2__(char* s,char* ss){
	return strpos_2a3__(s,ss,0);
}

_dle int strpos_2a2r__(char* s,char* ss){
	return strpos_2__(s,ss,0,_strpos_right);
}

_dle int strpos_2a2s__(char* s,char* ss){
	return strpos_2__(s,ss,0,_strpos_with);
}

_dle int strpos_2a2e__(char* s,char* ss){
	return strpos_2__(s,ss,0,_strpos_right|_strpos_with);
}

#include "for_arg_.h"
_dle int strpos_3__(int ctrl, char* s1, int argc, ...){
	char* ss = "\r\n\t ";
	_for_args( argc )
		ss = s;
	_next_args
	if(!s1 || !ss)
		return _strpos_result_no;
	int s_len=strlen(s1);
	switch(ctrl) {
	case 0:
		i = 0;
		break;
	default:
		i = s_len - 1;
		break;
	}
	for(; i >= 0 && i < s_len;) {
		if(!strchr(ss, s1[i]))
			return i;
		switch(ctrl) {
		case 0:
			i++;
			break;
		default:
			i--;
			break;
		}
	}
	return i;
}
