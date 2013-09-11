#include "l4/l4___.cc"

bool file__(const char* path,const char* ext,const char* sp,string& cmdline){
	string file;
	file=path;
	file+=ext;
	//if((access(file.c_str(),F_OK))==0){
	struct stat info;
	if(lstat(file.c_str(), &info) == 0){
		cmdline+=sp;
		cmdline+=file;
		return true;
	}
	return false;
}
bool file__(const char* path,string& cmdline){
	int i=0;
	if(file__(path,".ini"," -I ",cmdline))
		i++;
	if(file__(path,".zs"," ",cmdline))
		i++;
	return i>0;
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
		if(!file__(path,cmdline)&&get_lnk__(path,buf,true)){
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
