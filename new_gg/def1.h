#ifndef def1_h_
#define def1_h_

#ifdef WIN32
#define dlle___ extern "C" __declspec(dllexport)
#define dlln___(n) n
#else
#define dlle___ extern "C"
#define dlln___(n) _##n
#endif

typedef const char* (*callback2___)(void* jsq,void* shangji,int* err,
		const char* src,bool src_is_file,int argc,...);
typedef const char* (*callback3___)(void* jsq,void* shangji,int* err,
		const char* src,bool src_is_file,int argc,const char**argv,int from);
typedef const char* (*callback2_1___)(void* jsq,void* shangji,int* err,
		const char* src,bool src_is_file,const char* src2,int argc,...);
typedef const char* (*callback3_1___)(void* jsq,void* shangji,int* err,
		const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from);
typedef const char* (*callback2_2___)(void* jsq,void* shangji,int* err,void*ce,
		const char* src,bool src_is_file,const char* src2,int argc,...);
typedef const char* (*callback3_2___)(void* jsq,void* shangji,int* err,void*ce,
		const char* src,bool src_is_file,const char* src2,int argc,const char**argv,int from);
typedef int (*callback___)(int argc,...);
typedef int (*var_new___)(void* jsq,void* qu,const char* name,const char* val,
		bool readonly,int type,bool is_noparam);
typedef const char* (*var_get___)(void* jsq,void* qu,const char* name);
typedef int (*var_del___)(void* jsq,void* qu,const char* name);
typedef void (*var_for___)(void* qu,callback___ cb);
typedef void (*var_for_1___)(void* qu,callback___ cb,int max);
typedef void (*var_for_name___)(void* jsq,void* qu2,int* err,void*ce,const char* src,callback3_2___ cb,void* qu1,int max);
typedef void* (*l4_new_qu___)(void* shangji);
typedef void (*l4_delete_qu___)(void* qu);
typedef const char* (*l4_err___)(void* l4);
typedef void (*l4_err_clear___)(void* l4);
typedef const char* (*l4_errinfo___)(void* jsq,int err);
typedef void (*l4_err_out___)(void* l4, const char* ret, int err, int by);
typedef void (*l4_go___)(void* l4, int kw);

#define jieshiqi_err_	10000
#define jieshiqi_go_	 1000
#define jieshiqi_err_go_	jieshiqi_err_+jieshiqi_go_

#endif
