#include "l4/args_util.cc"
#include "l4/l4___.cc"

static bool file__(const char* path,const char* ext,const char* sp,string& cmdline){
	if(lstat__(path, ext)){
		cmdline+=sp;
		cmdline+=path;
		cmdline+=ext;
		return true;
	}
	return false;
}
static bool file__(const char* path,string& cmdline){
	int i=0;
	if(file__(path,".ini"," -I ",cmdline))
		i++;
	if(file__(path,".zs"," ",cmdline))
		i++;
	return i>0;
}

static bool get_lnk_ok__(const char* path) {
	if(lstat__(path, ".zs"))
		return true;
	return false;
}

static l4___ l4_;

int main(int argc,char** argv,char** env) {
	int err;
	{
		const char* path=argv[0];
		string buf;
		if(which__(path,buf))
			path=buf.c_str();
		string cmdline="-S syn-zh -E err-zh";
		if(!file__(path,cmdline)&&get_lnk__(path,buf,true, get_lnk_ok__)){
			path=buf.c_str();
			file__(path,cmdline);
		}
		err=l4_.init__(path,cmdline.c_str(),argc,argv,1);
	}
	if(!err){
		err=l4_.jieshi__();
		if(err==errinfo_src_file_){
			err=0;
			for(;;){
				string s;
				cin>>s;
				if(cin.eof())
					break;
				cout<<l4_.jieshi2__(&err,s.c_str())<<endl;
				l4_.err_out__(l4_.err_, err, 0);
			}
		}
	}
	l4_.err_out__(l4_.err_, err, 0);
	if(err)
		return 255;
	return l4_.exit_code__();
}
