#include "client_.h"
#include "server_.h"
#include "api.h"

dlle___ void* dlln___(client_start__)(int argv2,char* argv1){
	client_* c=new client_;
	if(!c)
		return 0;
	if(c->start___(argv2,argv1)!=0){
		delete c;
		return 0;
	}
	return(void*)c;
}

dlle___ void dlln___(client_stop__)(client_* c){
	if(!c)
		return;
	c->stop___();
	delete c;
}

dlle___ char* dlln___(client_get__)(client_* c){
	if(!c)
		return NULL;
	return c->rw__->get___(c->sockfd___());
}

dlle___ void dlln___(client_get_all__)(char**addr_ret,client_* c,char*ctrl){
	if(!c)
		return;
	string s;
	for(;;){
		char*s1=c->rw__->get___(c->sockfd___());
		if(!s1)
			break;
		s+=s1;
	}
	bool onlyb=false,onlyh=false;
	if(ctrl){
		for(;*ctrl;){
			switch(*ctrl++){
			case'b':
				onlyb=true;
				break;
			case'h':
				onlyh=true;
				break;
			}
		}
	}
	if(onlyb||onlyh){
		size_t i=s.find("\r\n\r\n");
		if(i!=string::npos){
			if(onlyb)
				s=s.substr(i+4,s.size());
			else
				s=s.substr(0,i);
		}
	}
	*addr_ret=new char[s.size()+1];
	strcpy(*addr_ret,s.c_str());
}

dlle___ int dlln___(client_put__)(client_* c,char* s){
	if(!c)
		return -1;
	return c->rw__->put___(s,c->sockfd___());
}

dlle___ int dlln___(client_while__)(client_* s,int i){
	if(!s)
		return -1;
	return s->while___(i);
}

dlle___ void dlln___(client_script__)(client_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname__=scriptname;
}

dlle___ void dlln___(client_script_r__)(client_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_r__=scriptname;
}

dlle___ void dlln___(client_script_w__)(client_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_w__=scriptname;
}

dlle___ void dlln___(client_script_0__)(client_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_0__=scriptname;
}

dlle___ void* dlln___(server_start__)(unsigned int myport,unsigned int lisnum){
	server_* s;
	if(!(s=new server_))
		return 0;
	if((s->start___(myport,lisnum))!=0){
		delete s;
		return 0;
	}
	return (void*)s;
}

dlle___ void dlln___(server_script__)(server_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname__=scriptname;
}

dlle___ void dlln___(server_script_r__)(server_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_r__=scriptname;
}

dlle___ void dlln___(server_script_w__)(server_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_w__=scriptname;
}

dlle___ void dlln___(server_script_i__)(server_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_i__=scriptname;
}

dlle___ void dlln___(server_script_0__)(server_* s,char* scriptname){
	if(!s)
		return;
	s->scriptname_0__=scriptname;
}

dlle___ void dlln___(server_stop__)(server_* s){
	if(!s)
		return;
	s->stop___();
	delete s;
}

dlle___ int dlln___(server_while__)(server_* s){
	if(!s)
		return -1;
	return s->while___();
}

/*dlle__ int server_while2___(server_* s,int i){
	return s->while2___(i);
}*/

dlle___ int dlln___(server_while3__)(server_* s,int i){
	if(!s)
		return -1;
	return s->while3___(i);
}

dlle___ SOCKET dlln___(server_accept__)(server_* c){
	if(!c)
		return 0;
	return c->accept___();
}

dlle___ char* dlln___(server_accept_addr__)(server_* c){
	if(!c)
		return NULL;
	return c->accept_addr___();
}

dlle___ int dlln___(server_accept_port__)(server_* c){
	if(!c)
		return 0;
	return c->accept_port___();
}

dlle___ char* dlln___(server_get__)(server_* c,int i){
	if(!c)
		return 0;
	return c->rw__->get___(i);
}

dlle___ int dlln___(server_put__)(server_* c,char* s,int i){
	if(!c)
		return -1;
	return c->rw__->put___(s,i);
}

dlle___ void dlln___(server_put_all__)(server_* c,char* s){
	if(!c)
		return ;
	c->put___(s);
}

callback2___ callback__=0;
void* jsq_=0;
void* shangji_=0;

dlle___ void dlln___(init__)(callback2___ callback,void* jsq,void* shangji){
	callback__=callback;
	jsq_=jsq;
	shangji_=shangji;
}
