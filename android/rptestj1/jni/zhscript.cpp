/*
 * zhscript.cpp
 *
 *  Created on: 2013-10-9
 *      Author: zzzzzzzzzzz
 */

#ifdef ver_android_
//#define cout_is_redir_

#include "new_l4/l432_so/jieshiqi___.h"
#include "new_l4/l432_so/defi.h"
#include "new_l4/l432_so/jieshiqi_callback.h"
#include "new_gg/for_arg_.h"
#include "new_gg/call_util.cpp"
dlle___ int l4_parse_args__(jieshiqi___* l4);
dlle___ void l4_err_out2__(string& s, jieshiqi___* l4, const char* ret, int err, int by);
dlle___ const char* l4_keyword__(jieshiqi___* l4,int kw);
dlle___ int l4_var_new__(jieshiqi___* jsq,qu___* qu,
		const char* name,const char* val,
		bool readonly,
		int type,bool is_noparam);

#include "org_zhscript_Jni.h"
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

static AAssetManager* aam_ = NULL;

int aam_get_file__(const char* filename, string& ret) {
	if(aam_ == NULL)
		return errinfo_open_;
	AAsset* aa = AAssetManager_open(aam_, filename, AASSET_MODE_UNKNOWN);
	if(aa == NULL)
		return errinfo_open_;
	off_t siz = AAsset_getLength(aa);
	char *buf = new char[siz + 1];
	buf[siz] = 0;
	AAsset_read(aa, buf, siz);
	AAsset_close(aa);
	ret = buf;
	delete buf;
	return 0;
}

jstring new__(const char* s, JNIEnv *env) {
	return env->NewStringUTF(s);
}

static string log_tag_;
static void log__(const char* s, android_LogPriority lp = ANDROID_LOG_INFO) {
	__android_log_print(lp, log_tag_.c_str(), "%s", s);
}
void android_log__(const string& s) {
#ifdef cout_is_redir_
	cout << s;
#else
	log__(s.c_str());
#endif
}

class s___ {
private:
	jstring js_;
	JNIEnv *env_;
	void init__(jstring js, JNIEnv *env) {
		js_ = js;
		env_ = env;
		if(js_)
			s_ = env_->GetStringUTFChars(js_, NULL);
		else
			s_ = "";
	}
public:
	const char* s_;
	s___(jstring js, JNIEnv *env) {
		init__(js, env);
	}
	s___(jobjectArray a, jsize i, JNIEnv *env) {
		init__((jstring)env->GetObjectArrayElement(a, i), env);
	}
	~s___() {
		if(js_)
			env_->ReleaseStringUTFChars(js_, s_);
	}
};

#ifdef cout_is_redir_
class androidbuf: public std::streambuf {
public:
	enum { bufsize = 128 }; // ... or some other suitable buffer size
	androidbuf() { this->setp(buffer, buffer + bufsize - 1); }
private:
	int overflow(int c) {
		if (c == traits_type::eof()) {
			*this->pptr() = traits_type::to_char_type(c);
			this->sbumpc();
		}
		return this->sync()? traits_type::eof(): traits_type::not_eof(c);
	}
	int sync() {
		int rc = 0;
		if (this->pbase() != this->pptr()) {
			log__(std::string(this->pbase(), this->pptr() - this->pbase()).c_str());
			rc = 0;
			this->setp(buffer, buffer + bufsize - 1);
		}
		return rc;
	}
	char buffer[bufsize];
};
#endif

static jieshiqi___ l4_;
static qu___* main_qu_ = NULL;

static jstring suidao2__(deque<string>* p, JNIEnv *env, jobject thiz2) {
	jclass jc = env->FindClass("org/zhscript/Jni");
	jmethodID suidao = env->GetMethodID(jc, "suidao__",
			"([Ljava/lang/String;)Ljava/lang/String;");
	jclass jc_string = env->FindClass("java/lang/String");

	jobjectArray a = env->NewObjectArray(p->size(), jc_string, NULL);
	for(size_t i = 0; i < p->size(); i++) {
		env->SetObjectArrayElement(a, i, env->NewStringUTF((*p)[i].c_str()));
	}
	return (jstring)env->CallObjectMethod(thiz2, suidao, a);
}

class shell___ {
private:
	JNIEnv *env_;
	jobject thiz2_;
public:
	int with__(s___* cmdline1, s___* suidao1);
	bool api__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret) {
		s___ s(suidao2__(p, env_, thiz2_), env_);
		//cpy__(buf, s.s_, siz);
		*addr_ret = dup__(s.s_);
		return true;
	}
	void set__(JNIEnv *env, jobject thiz2) {
		env_ = env;
		thiz2_ = thiz2;
	}
};
static shell___ shell_;

static void suidao__(char**addr_ret,char*buf,long siz,shell___* sh,void*ce,void* shangji,int argc,...) {
	deque<string> p;
	_for_args( argc )
		p.push_back(s ? s : l4_.syn_[keyword_null_].c_str());
	_next_args
	sh->api__(shangji,ce,&p,buf,siz,addr_ret);
}

int shell___::with__(s___* cmdline1, s___* suidao1) {
	l4_.args_.add_arg__(cmdline1->s_);
	int err;
	if((err = l4_parse_args__(&l4_))) {
		string s;
		l4_err_out2__(s, &l4_, NULL, err, 0);
		log__(s.c_str(), ANDROID_LOG_ERROR);
		return err;
	}

	main_qu_ = l4_.new_main_qu__();
	char buf[32];
	const char
		*dy=l4_keyword__(&l4_, keyword_call_)
		,*ky=l4_keyword__(&l4_, keyword_kaiyinhao_)
		,*by=l4_keyword__(&l4_, keyword_biyinhao_)
		,*d=l4_keyword__(&l4_, keyword_dunhao_)
		,*bs=l4_keyword__(&l4_, keyword_bianliangshi_)
		,*bz=l4_keyword__(&l4_, keyword_bianliangzhong_)
		,*c=l4_keyword__(&l4_, keyword_params_)
		,*j=l4_keyword__(&l4_, keyword_juhao_)
		,*cb=l4_keyword__(&l4_, keyword_callback_)
		,*zs=l4_keyword__(&l4_, keyword_zhujieshi_)
		,*zz=l4_keyword__(&l4_, keyword_zhujiezhong_)
		,*sj=l4_keyword__(&l4_, keyword_shangji_)
		;
	string s;
	s+=dy;s+=ky;s+="ASZ/";
	sprintf(buf, "%lx", (long)suidao__);s+=buf;
	s+="/&-$11-&";s+=by;s+=d;
	s+=ky;
	sprintf(buf, "%lx", (long)this);s+=buf;
	s+=by;s+=d;
	s+=bs;s+=cb;s+='1';s+=zs;s+=sj;s+=zz;s+=bz;s+=d;
	s+=bs;s+=c;s+=bz;s+=j;
	err=l4_var_new__(&l4_,main_qu_,suidao1->s_,s.c_str(),
			true,vartype_def_,false);

	//suidao__(NULL,buf,32,this,NULL,main_qu_,4,"a","bb","ccc","dddd");
	return err;
}

JNIEXPORT jint JNICALL Java_org_zhscript_Jni_init
(JNIEnv *env, jobject thiz,
		jstring cmdline, jstring suidao, jobject thiz2,
		jobject am, jstring log_tag)
{
	{
		s___* s = new s___(log_tag, env);
		log_tag_ = s->s_;
		delete s;
	}
	aam_ = AAssetManager_fromJava(env, am);

	shell_.set__(env, thiz2);
	s___ cmdline1(cmdline, env), suidao1(suidao, env);
	int err = shell_.with__(&cmdline1, &suidao1);
	return err;
}

JNIEXPORT jint JNICALL Java_org_zhscript_Jni_jieshi
  (JNIEnv *env, jobject thiz, jobjectArray a, jobject result, jobject thiz2)
{
	s___ code(a, 0, env);
	int argc = env->GetArrayLength(a) - 1;
	const char** argv = new const char*[argc];
	s___** argv2 = new s___*[argc];
	for(jsize i = 0; i < argc; i++) {
		argv2[i] = new s___(a, i + 1, env);
		argv[i] = argv2[i]->s_;
	}

#ifdef cout_is_redir_
	std::cout.rdbuf(new androidbuf);
#endif

	shell_.set__(env, thiz2);
	int err = 0;
	const char* ret = callback3__(&l4_,
			main_qu_, &err, false, NULL,
			code.s_, false, NULL,
			argc, argv, 0);
	delete argv;
	for(jsize i = 0; i < argc; i++) {
		delete argv2[i];
	}

	jclass jc = env->FindClass("org/zhscript/Result");
    jfieldID ret1 = env->GetFieldID(jc,"ret_","Ljava/lang/String;");
    jfieldID err1 = env->GetFieldID(jc,"err_","I");
    jfieldID err2 = env->GetFieldID(jc,"err2_","Ljava/lang/String;");
    //Ljava/lang/Boolean;
    //Z
    jfieldID end1 = env->GetFieldID(jc,"end_","I");
    env->SetObjectField(result, ret1, new__(ret, env));
    //env->SetBooleanField(result, end1, false);
    env->SetIntField(result, end1, 0);
	if(err) {
		switch(err) {
		case jieshiqi_go_+keyword_exit_:
			err = 0;
			break;
		case jieshiqi_go_+keyword_end_:
	    	//env->SetBooleanField(result, end1, true);
	    	env->SetIntField(result, end1, 1);
			break;
		default:
			string s;
			l4_err_out2__(s, &l4_, ret, err, 0);
		    env->SetObjectField(result, err2, new__(s.c_str(), env));
			break;
		}
	}
    env->SetIntField(result, err1, err);

#ifdef cout_is_redir_
    delete std::cout.rdbuf(0);
#endif

	return err;
}
#endif
