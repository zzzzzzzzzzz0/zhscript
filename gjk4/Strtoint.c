#include "gjk2.h"

#define NULL 0
//#define HM7T2SH4B3B3

long hs7chuan4_zheng3shu4( char *chuan4, int jin4zhi4, int *c4w4 ) {
	long f3h2 = 0L, mi1;
	int	wei4 = 0, fu2hao4 = 1, z4f2, ci4shu4;
	char *zhi3;

	switch( *chuan4 ) {
	case '-':
		fu2hao4 = -1;
	case '+':
		chuan4++;
		break;
	}
	for( zhi3 = chuan4; *zhi3 && *zhi3 != '.'; zhi3++ )
		wei4++;
	for( zhi3 = chuan4; wei4; zhi3++ ) {
		z4f2 = *zhi3;
		if( z4f2 >= '0' && z4f2 <= '9' )
			z4f2 -= '0';
		else if( z4f2 >= 'A' && z4f2 <= 'Z' )
			z4f2 = z4f2 - 'A' + 10;
		else if( z4f2 >= 'a' && z4f2 <= 'z' )
			z4f2 = z4f2 - 'a' + 36;
		else {
			if( c4w4 != NULL )
				*c4w4 = HM7C4W4CH4ZH3SH4Z4F2;
			return fu2hao4 * f3h2;
		}
		if( z4f2 >= jin4zhi4 ) {
			if( c4w4 != NULL )
				*c4w4 = HM7C4W4CH4ZH3SH4JIN4ZHI4;
			return fu2hao4 * f3h2;
		}
		wei4--;
		mi1 = 1L;
		for( ci4shu4 = wei4; ci4shu4 > 0; ci4shu4-- )
			mi1 *= jin4zhi4;
		f3h2 += z4f2 * mi1;
	}
	if( c4w4 != NULL )
		*c4w4 = 0;
	return fu2hao4 * f3h2;
}
