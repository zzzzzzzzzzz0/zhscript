#include "1.h"
#include "gjk2.h"
#include "for_arg_.h"

_dle void int2fmtstr__(int* c4w4,char* buf,long siz,unsigned long src,int argc,...){
	char ret[128];
	int jinzhi[32]={60};
	char* fenge[32]={(char*)":"};
	int jinzhi_len=-1,jinzh_i;
	unsigned long quan,shu;
	int i1=(argc + 1)/2 - 1,i2,i3,ret_i;
	_for_args( argc )
		if((i % 2)==0){
                  jinzhi_len++;
                  i3=atoi(s);
                  if(i3<1){
                	  *c4w4=1;
                	  strcpy(buf,s);
                	  strcat(buf," lt 1");
                	  return;
                  }
                  jinzhi[i1 - jinzhi_len]=i3;
		}else{
                  fenge	[i1 - jinzhi_len]=s;
		}
	_next_args
	if(++jinzhi_len<1)
		jinzhi_len=1;
    i1=jinzhi_len-1;
    for(jinzh_i=jinzhi_len;jinzh_i<32;jinzh_i++){
          jinzhi[jinzh_i]=jinzhi[i1];
          fenge[jinzh_i]=fenge[i1];
    }
	/*for(i1=0;i1<32;i1++)
		printf("%d%s",jinzhi[i1],fenge[i1]);*/
    ret_i=127;
    ret[ret_i]=0;
	for(jinzh_i=0;jinzh_i<32;jinzh_i++){
		quan=jinzhi[jinzh_i];
		shu=src%quan;
		//printf("%lu %lu %lu %d %d\n",src,quan,shu,jinzh_i,jinzhi_len);
        i1=sprintf__(buf,"%lu",shu);
        ret_i-=i1;
        for(i2=0;i2<i1;i2++)
                  ret[ret_i+i2]=buf[i2];
        src/=quan;

        if(src==0&&jinzh_i>=jinzhi_len-1)
                  break;

        i3=jinzh_i+1;
        if(i3>=32){
                  strcpy(buf,"over");
                  return;
		}
		i1=strlen(fenge[i3]);
        ret_i-=i1;
        for(i2=0;i2<i1;i2++)
                  ret[ret_i+i2]=fenge[i3][i2];
	}
	strcpy(buf,ret+ret_i);
}

_dle long fmtstr2int__(int* c4w4,char* buf,long siz,char* src,int argc,...){
	unsigned long ret=0;
	if(src){
		int src_i=strlen(src)-1,buf_i;
		int jinzhi[32]={60};
		int jinzhi_len=0,jinzh_i,jinzhi_i;
		int suan;
		int wei=0;
		_for_args( argc )
			jinzhi[jinzhi_len++]=atoi(s);
		_next_args
		if(!jinzhi_len)
			jinzhi_len=1;
		buf_i=siz;
		buf[--buf_i]=0;
		//printf("%d %d '%s'\n",jinzhi_len,buf_i,src);
		for(;;){
			char c;
			if(src_i<0)
				break;
			c=src[src_i];
			suan=1;
			if((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z')){
				buf[--buf_i]=c;
				suan=0;
			}
			if(src_i==0)
				suan=1;
			if(suan && buf_i<siz-1){
				unsigned long shu4 = hs7chuan4_zheng3shu4( buf+buf_i, 10, c4w4 );
				//printf("buf='%s' %d %d %d\n",buf+buf_i,*c4w4,buf_i,src_i);
				if ( *c4w4 ){
					strcpy(buf,buf+buf_i);
					return 0;
				}
				//printf("shu=%ld\n",shu4);
				for(jinzhi_i=wei-1;jinzhi_i>=0;jinzhi_i--){
                                        jinzh_i=jinzhi_len-1-jinzhi_i;
                                        if(jinzh_i<0)
                                          jinzh_i=0;
					shu4*=jinzhi[jinzh_i];
					//printf("\t[%d]%d shu=%ld\n",jinzh_i,jinzhi[jinzh_i],shu4);
				}
				//printf("shu=%ld\n",shu4);
				ret+=shu4;
				//printf("ret=%ld\n",ret);
				buf_i=siz-1;
				wei++;
			}
			src_i--;
		}
	}
	return ret;
}
