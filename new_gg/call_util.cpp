char* dup__(const char*s){
	if(!s)
		return 0;
	const char*s1=s;
	for(;*s1++;);
	char* s2=new char[s1-s];
	if(!s2)
		return 0;
	char* s3=s2;
	for(;(*s3++=*s++););
	return s2;
}

long cpy__(char*buf,const char*src,long siz){
	long i=-1;
	if(buf&&src){
		for(;(buf[++i]=*src++);){
			if(i>=siz-1){
				buf[i]=0;
				break;
			}
		}
	}
	return i;
}
