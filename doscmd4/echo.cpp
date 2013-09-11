#include<string>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

#include "for_arg_.h"
#include "def1.h"
dlle___ int dlln___(mkdir__)(char* filename);

int putfile2___(char* filename,const char*modes,const char* s,long len){
	FILE* f;

	f=fopen(filename,modes);
	if(f==NULL)
		return 1;
	if(fwrite(s,1,len,f)!=len)
		return 2;

	fclose(f);
	return 0;
}

dlle___ int dlln___(echo__)(int argNum,...) {
    bool cmd_end=false;
    bool hex_out=false;
    string modes="wb";
    string buf1;
    _for_args(argNum)
	    if (i>=argNum-1) {
	    	if(!dlln___(mkdir__)(s))
	    		return 1;
	    	if(hex_out){
				FILE*	tfs=fopen(s,modes.c_str());
				if(!tfs)
					return 1;
                char buf[1];
                for(unsigned int i1=0;i1<buf1.length();i1+=2){
                	if(sscanf(buf1.c_str()+i1,"%2x",&buf[0])!=1)
                		return 3;
                    fwrite(buf,sizeof(buf),1,tfs);
                }
                fclose(tfs);
	    	}else{
	    		int err=putfile2___(s,modes.c_str(),buf1.c_str(),buf1.length());
		        if (err)
		            return 20+err;
	    	}
	        break;
	    }
        if(!cmd_end){
        	string s1=s;
            if(s1=="-hex"){
            	hex_out=true;
                continue;
            }
            if(s1.substr(0,2)=="-m"){
            	modes=s1.substr(2);
            	continue;
            }
            if(s1=="--"){
            	cmd_end=true;
                continue;
            }
        }
        buf1+=s;
    _next_args
    return 0;
}
