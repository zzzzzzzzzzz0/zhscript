#include "1.h"
#include <time.h>
#include "for_arg_.h"

#include "p421.h"
#include "gjk2.h"

_dle void JSBDS2(int*c4w4,char* h3ch1,long siz, char * exp,int argc,... )
{
  double answer;
  int xiaoshu=-1;
  _for_args( argc )
		switch (i) {
		case 0:
			sscanf(s,"%d",&xiaoshu);
			break;
		}
  _next_args

  *c4w4 = eval_exp( & answer, exp );

  if ( *c4w4 )
    return;
  if ( gcvt( answer, siz, h3ch1 ) == h3ch1 )
  {
    int i = strlen( h3ch1 ) - 1;
    int dian=i;
    for(;dian>=0;dian--){
    	if(h3ch1[dian]=='.')
    		break;
    }
    if(xiaoshu>=0){
		if(dian>=0){
			if(i-dian>xiaoshu){
				int i1;
				i1=dian+xiaoshu;
				if(i>i1){
					i=i1;
					h3ch1[i+1]=0;
				}
				char c=h3ch1[i1];
				for(;--i1>dian;){
					if(h3ch1[i1]!=c||i1==dian+1){
						if(c>='5'){
							h3ch1[i1+1]=0;
							i=i1;
							for(;;){
								if(++h3ch1[i1]>'9'){
									if(i1<dian){
										h3ch1[i1]='0';
									}else{
										h3ch1[i1]=0;
										i=i1-1;
									}
									if(--i1==dian){
										h3ch1[i1]=0;
										i=i1-1;
										--i1;
									}
									if(i1<0){
										h3ch1[i+2]=0;
										for(i1=i;i1>=0;i1--)
											h3ch1[i1+1]=h3ch1[i1];
										h3ch1[0]='1';
										break;
									}
								}else
									break;
							}
						}
						break;
					}
				}
			}
		}
		if(dian>=0){
			for(;i>dian;i--){
				if(h3ch1[i]=='0')
					h3ch1[i]=0;
				else
					break;
			}
		}
    }
    if ( i >= 0 && i == dian )
    {
      h3ch1[i--] = 0;
    }
  }
}

_dle size_t strftime___( char * s, size_t maxsize, const char * fmt,time_t secs_now )
{
  struct tm * time_now;

  time_now = localtime( & secs_now );
  return strftime( s, maxsize, fmt, time_now );
}

_dle size_t wstrftime( char * s, size_t maxsize, const char * fmt )
{
  time_t secs_now;

  tzset();
  time( & secs_now );
  return strftime___(s,maxsize,fmt, secs_now );
}

_dle time_t mktime__(int y, int m, int d, int h, int m2, int s) {
	struct tm t;
	t.tm_year = y - 1900;
	t.tm_mon = m - 1;
	t.tm_mday = d;
	t.tm_hour = h;
	t.tm_min = m2;
	t.tm_sec = s;
	t.tm_isdst = -1;
	return mktime(&t);
}

_dle long hs7zheng3shu4( char * chuan4, int jin4zhi4 )
{
  int c4w4;
  long shu4 = hs7chuan4_zheng3shu4( chuan4, jin4zhi4, & c4w4 );

  if ( c4w4 )
    return -c4w4;
  return shu4;
}

_dle char* getenv__(char* s){
	return getenv(s);
}


_dle void mem2hex_(char* buf,long siz,unsigned char* mem,long count){
	char s[32];
	long i=0,i1=0;
	//wsprintf(s,"%d %d",siz,count);MessageBox(0,s,"",0);
	buf[0]=0;
	for(;i<count && i1+2<siz;i++,i1+=2){
		sprintf__(s,"%02X",mem[i]);
		__strcpyn(buf+i1,s,3);
	}
}

#ifdef _WINDOWS
#define random rand
#endif
_dle void random___(char* buf,long siz,int argc,...) {
    long int max1=100,min1=0;
	long int i1;

    _for_args( argc )
		switch (i) {
		case 0:
			//max=atoi(s);
			sscanf(s,"%ld",&max1);
			break;
		case 1:
			//min=atoi(s);
			sscanf(s,"%ld",&min1);
			break;
		}
    _next_args

    i1=max1-min1;
    if (i1<=0) {
        //randomize();
        unsigned seed=-i1;
        if(!seed){
            //time_t t;
            seed=time(/*&t*/0);
    	}
        srand(seed);
		ltoa_(seed,buf,10);
		return;
    }
 	ltoa_((random()%(i1+1)+min1),buf,10);
}
