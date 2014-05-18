/*
 * main.cpp
 *
 *  Created on: 2011-12-19
 *      Author: zzzzzzzzzzz
 */

#include "mongoose.h"
#include "mongoose-xg.h"

#include "def1.h"
#include "l4/vartype.h"
#include "l4/keyword.h"
#include "l4/errinfo.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//osx 10.9 need
//#include <linux/limits.h>
#include <limits.h>
#include <unistd.h>

static int exit_flag=0;
static void signal_handler(int sig_num) {
  exit_flag = sig_num;
}
dlle___ void main__() {
  signal(SIGTERM, signal_handler);
  signal(SIGINT, signal_handler);
  while (exit_flag == 0) {
	sleep(1);
  }
  fflush(stdout);
}
dlle___ void break__() {
	exit_flag = -1;
}

static void* jsq_;
static l4_err___ l4_err_;
static l4_err_clear___ l4_err_clear_;
static l4_errinfo___ l4_errinfo_;
static callback2___ cb_;
static l4_new_qu___ qu_new_;
static l4_delete_qu___ qu_delete_;
static var_new___ var_new_;
static void* shangji_;
static std::string kw_echo_,echo_def_fmt_,
	name_get_header_,code_get_header_,
	name_get_option_,code_get_option_;

dlle___ void init__(callback2___ cb,void* jsq,
		l4_err___ l4_err,
		l4_err_clear___ l4_err_clear,
		l4_errinfo___ l4_errinfo,
		l4_new_qu___ qu_new,l4_delete_qu___ qu_delete,
		var_new___ var_new,
		void* shangji,
		char* kw_echo,char*echo_def_fmt,
		char* name_get_header,char*code_get_header,
		char* name_get_option,char*code_get_option){
	jsq_=jsq;
	cb_=cb;
	l4_err_=l4_err;
	l4_err_clear_=l4_err_clear;
	l4_errinfo_=l4_errinfo;
	qu_new_=qu_new;
	qu_delete_=qu_delete;
	var_new_=var_new;
	shangji_=shangji;

	kw_echo_=kw_echo;
	echo_def_fmt_=echo_def_fmt;
	name_get_header_=name_get_header;
	code_get_header_=code_get_header;
	name_get_option_=name_get_option;
	code_get_option_=code_get_option;
}

static void qu_var_new_form_url__(void* shangji,const char* url, int is_form_url_encoded,int* err){
	std::string value,name;
	bool is2=false;
	int a, b;
#define HEXTOI(x) (isdigit(x) ? x - '0' : x - 'W')
	for(int i=0;;i++){
		char c=url[i];
		if(c=='&'||!c){
			if(is2){
				std::string value2;
				for(size_t i1=0;i1<value.length();i1++){
					char c=value[i1];
					if(c == '%' && i1+2<value.length() && isxdigit(value[i1+1]) && isxdigit(value[i1+2])){
						a = tolower(value[i1+1]);
						b = tolower(value[i1+2]);
						value2+= (char) ((HEXTOI(a) << 4) | HEXTOI(b));
						i1 += 2;
					} else if (is_form_url_encoded && c == '+') {
						value2+= ' ';
					} else {
						value2+=c;
					}
				}
				*err=var_new_(jsq_,shangji,name.c_str(),value2.c_str(),false,vartype_var_,false);
				if(*err)
					return;
				if(!c)
					break;
				is2=false;
			}
			name.clear();
			continue;
		}
		if(c=='='){
			is2=true;
			value.clear();
			continue;
		}
		if(is2)
			value+=c;
		else
			name+=c;
	}
}

static struct mg_context *ctx_=NULL;

static std::string uploadir_="/tmp/";
dlle___ void uploadir__(char*uploadir){
	uploadir_=uploadir;
}

static std::string filenaming_code_;
dlle___ void filenaming_code__(char*s){
	filenaming_code_=s;
}

static std::string _wzs_ = ".wzs";

static void *callback__(enum mg_event event, struct mg_connection *conn) {
	if (event == MG_NEW_REQUEST) {
		bool is_zs;
		std::string script;
		{
			char path[PATH_MAX];
			struct mgstat st;
			convert_uri_to_file_name(conn, path, sizeof(path), &st);
			if(st.is_directory)
				substitute_index_file(conn, path, sizeof(path), &st);
			script=path;
			is_zs=(script.rfind(_wzs_)==script.length()-_wzs_.length());
		}
		if(is_zs){
			if(script.find(uploadir_) == 0) {
				return NULL;
			}
			void* qu=qu_new_(shangji_);
			char out[8]="";
			int err;
			const char* ret="";
			for(;;){
				{
					size_t size=echo_def_fmt_.size();
					if(code_get_header_.size()>size)
						size=code_get_header_.size();
					char* code_buf=new char[size+32];
					sprintf(code_buf,echo_def_fmt_.c_str(),sprintf,mg_printf,conn,out);
					err=var_new_(jsq_,qu,kw_echo_.c_str(),code_buf,true,vartype_def_,false);
					if(err){
						delete code_buf;
						break;
					}
					sprintf(code_buf,code_get_header_.c_str(),mg_get_header,conn);
					err=var_new_(jsq_,qu,name_get_header_.c_str(),code_buf,true,vartype_def_,false);
					if(err){
						delete code_buf;
						break;
					}
					delete code_buf;
				}
				if((err=var_new_(jsq_,qu,"ip",inet_ntoa(conn->client.rsa.sin.sin_addr),true,vartype_var_,false)))
					break;
				{
					const char *cl=mg_get_header(conn, "Content-Length");
					if(cl){
						size_t cl1=atoi(cl);
						const char* ct=mg_get_header(conn, "Content-Type");
						std::string boundary;
						if(ct){
							const char* ct1="multipart/form-data; boundary=";
							for(;;ct++,ct1++){
								if(!*ct1){
									boundary=ct;
									break;
								}
								if(*ct!=*ct1)
									break;
							}
						}
						if(boundary.empty()){
							char* postdata=new char[cl1+1];
							postdata[mg_read(conn, postdata, cl1)]=0;
							qu_var_new_form_url__(qu,postdata,1,&err);
							delete postdata;
							if(err)
								break;
						}else{
							std::string buf2;
							{
								char*buf=new char[128];
								for(;;){
									int siz=mg_read(conn, buf, 128);
									if(siz<=0)
										break;
									for(int i=0;i<siz;i++)
										buf2.append(1,buf[i]);
								}
								delete buf;
							}
							size_t pos1=0;
							std::string sp="\r\n\r\n";
							for(;;){
								size_t pos2=buf2.find(boundary,pos1);
								if(pos2==std::string::npos)
									break;
								if(pos1>0){
									std::string value,name,filename,s,s2;
									size_t posp=buf2.find(sp,pos1);
									bool is2=false;
									for(size_t i=pos1;i<posp+2/*\r\n*/;i++){
										char c=buf2[i];
										//printf("%c",c);
										if(c=='\n'||c==';'){
											//printf("<%s=%s>",s.c_str(),s2.c_str());
											if(is2){
												if(s=="name")
													name=s2;
												else if(s=="filename")
													filename=s2;
												is2=false;
											}
											s.clear();
											continue;
										}
										if(c=='='||c==':'){
											is2=true;
											s2.clear();
											continue;
										}
										if((c>=0&&c<=' ')||c=='"')
											continue;
										if(is2)
											s2+=c;
										else
											s+=c;
									}
									//printf("|\n");
									size_t 	i_b=posp+sp.length(),
											i_e=pos2-4/*\r\n--*/;
									if(i_b<i_e){
										/*for(size_t i=i_b;i<i_e;i++){
											char c=buf2[i];
											if(c>=' '&&c<='~')
												printf("%c",c);
											else if(c=='\n')
												printf("</\n");
											else
												printf(" %i ",c);
										}*/
										if(filename.empty()){
											value=buf2.substr(i_b,i_e-i_b);
										}else{
											if(!filenaming_code_.empty()){
												ret=cb_(jsq_,qu,&err,filenaming_code_.c_str(),false,
														2,uploadir_.c_str(),filename.c_str());
												if(err)
													break;
												if(ret[0])
													filename=ret;
												else
													filename=uploadir_+filename;
											}else
												filename=uploadir_+filename;
											value=filename;
											FILE *fp;
											if ((fp = fopen(filename.c_str(), "wb+")) == NULL){
												ret=filename.c_str();
												err=jieshiqi_err_+errinfo_open_;
												break;
											}else{
												fwrite(buf2.c_str()+i_b, 1, i_e-i_b, fp);
												if (ferror(fp)){
													ret=filename.c_str();
													err=jieshiqi_err_+errinfo_get_;
												}
												(void) fclose(fp);
											}
										}
									}
									//printf("|%u-%u-%u/%s=%s;\n|\n|\n",pos1,posp,pos2,name.c_str(),value.c_str());
									if((err=var_new_(jsq_,qu,name.c_str(),value.c_str(),false,vartype_var_,false)))
										break;
								}
								pos1=pos2+boundary.size()+2/*\r\n*/;
							}
							if(err)
								break;
						}
					}
				}

				/*for(int i=0;i<request_info->num_headers;i++){
					printf("%s\t%s\n",request_info->http_headers[i].name,request_info->http_headers[i].value);
				}*/

				char* qs=conn->request_info.query_string;
				if(qs){
					qu_var_new_form_url__(qu,qs,1,&err);
					if(err)
						break;
				}
				ret=cb_(jsq_,qu,&err,script.c_str(),true,0);
				qu_delete_(qu);
				break;
			}
			//printf("out%s\n",out);
			switch(err){
			case jieshiqi_err_go_+keyword_end_:
			case jieshiqi_err_go_+keyword_exit_:
				break;
			default:
				if(err){
					if(!out[0])
						mg_printf(conn, "HTTP/1.1 200 OK\r\n"
				              "Content-Type: text/plain\r\n\r\n");
					if(err>=jieshiqi_err_){
						err-=jieshiqi_err_;
						mg_printf(conn, "%s%s%s",ret,l4_err_(jsq_),l4_errinfo_(jsq_,err));
						l4_err_clear_(jsq_);
					}else
						mg_printf(conn, "%s err%d",ret,err);
				}
				break;
			}
			return (void*)"";
		}
	}
	return NULL;
}

dlle___ void stop__(){
	if(ctx_)
		mg_stop(ctx_);
}

#include "for_arg_.h"
dlle___ int start__(int argc,...) {
	const char *options[64] = {
			"listening_ports", "8083",
			NULL};
	int i1=1;
	char c=0;
	_for_args( argc )
		if(i>=62)
			break;
		if(i<1){
			if(s)
				options[i1]=s;
			i1++;
		}else{
			switch(c){
			default:
				options[i1++]=s;
				break;
			}
			c=0;
		}
	_next_args
	if(i1>1)
		options[i1]=NULL;

	ctx_ = mg_start(&callback__, NULL, options);
	if(ctx_){
		size_t size=code_get_option_.size();
		char* code_buf=new char[size+32];
		sprintf(code_buf,code_get_option_.c_str(),mg_get_option,ctx_);
		/*err=*/var_new_(jsq_,shangji_,name_get_option_.c_str(),code_buf,true,vartype_def_,false);
		delete code_buf;
	}
	return ctx_?1:0;
}
