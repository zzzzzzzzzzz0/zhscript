#include "1.h"
#include <stdarg.h>

//#define hm7t1sh4xie3

_dle int HS7DU2JIE2GOU4( char * chuan4, char * ge2shi4,... )
{
  va_list zhan4biao3;
  int d4l2 = 0;
  int shi3 = 0, chang2 = 2;
  long zheng3shu4, quan3;
  int chang2d4l2;
  char * zh3zh1;

  for ( va_start( zhan4biao3, ge2shi4 ); * ge2shi4; )
  {
    switch ( * ge2shi4++ )
    {
      case 's':
        zh3zh1 = ge2shi4;
        while ( * ge2shi4 >= '0' && * ge2shi4 <= '9' )
          ge2shi4++;
        shi3 = atoi( zh3zh1 );
      break;
      case 'c':
        zh3zh1 = ge2shi4;
        while ( * ge2shi4 >= '0' && * ge2shi4 <= '9' )
          ge2shi4++;
        chang2 = atoi( zh3zh1 );
      break;
      case '.':
        zh3zh1 = va_arg( zhan4biao3, char * );
        zheng3shu4 = 0L;
        quan3 = 1L;
        for ( chang2d4l2 = chang2; chang2d4l2--; )
        {
          zheng3shu4 += ( unsigned char ) * ( chuan4 + shi3++ ) * quan3;
          quan3 *= 256L;
        }
        ltoa_( zheng3shu4, zh3zh1, 10 );
        d4l2++;
      break;
      case '*':
				__strcpyn( va_arg( zhan4biao3, char * ), chuan4 + shi3, chang2 + 1 );
        shi3 += chang2;
        d4l2++;
      break;
      default:
        goto bh7mo4wei3;
    }
  }
bh7mo4wei3:
  va_end( zhan4biao3 );
  return d4l2;
}

_dle int HS7XIE3JIE2GOU4( char * chuan4, char * ge2shi4,... )
{
  va_list zhan4biao3;
  int d4l2 = 0;
  int shi3 = 0, chang2 = 2;
  long zheng3shu4;
  int chang2d4l2;
  char * zh3zh1;

#ifdef hm7t1sh4xie3
  MessageBox( 0, "hi", "xie3", 64 );
#endif
  for ( va_start( zhan4biao3, ge2shi4 ); * ge2shi4; )
  {
    switch ( * ge2shi4++ )
    {
      case 's':
        zh3zh1 = ge2shi4;
        while ( * ge2shi4 >= '0' && * ge2shi4 <= '9' )
          ge2shi4++;
        shi3 = atoi( zh3zh1 );
      break;
      case 'c':
        zh3zh1 = ge2shi4;
        while ( * ge2shi4 >= '0' && * ge2shi4 <= '9' )
          ge2shi4++;
        chang2 = atoi( zh3zh1 );
      break;
      case '.':
        zheng3shu4 = va_arg( zhan4biao3, long );
#ifdef hm7t1sh4xie3
        {
          char h3ch1[64];

          wsprintf( h3ch1, "d4l2=%d\n""zheng3shu4=%ld(%#lX)", d4l2, zheng3shu4, zheng3shu4 );
          MessageBox( 0, h3ch1, "", 0 );
        }
#endif
        for ( chang2d4l2 = chang2; chang2d4l2--; )
        {
          * ( chuan4 + shi3++ ) = ( char )( zheng3shu4 % 256L );
          zheng3shu4 >>= 8;
#ifdef hm7t1sh4xie3
          {
            char h3ch1[64];

            wsprintf( h3ch1, "chang2d4l2=%d/%d\n""[%d]=%d(%#X)\n""zheng3shu4=%ld(%#lX)", chang2d4l2, chang2, shi3 - 1, * ( chuan4 + shi3 - 1 ),
                 * ( chuan4 + shi3 - 1 ), zheng3shu4, zheng3shu4 );
            MessageBox( 0, h3ch1, "", 0 );
          }
#endif
        }
        d4l2++;
      break;
      case '*':
				__strcpyn( chuan4 + shi3, va_arg( zhan4biao3, char * ), chang2 + 1 );
        shi3 += chang2;
        d4l2++;
      break;
      default:
        goto bh7mo4wei3;
    }
  }
bh7mo4wei3:
  va_end( zhan4biao3 );
#ifdef hm7t1sh4xie3
  MessageBox( 0, "bye", "xie3", 64 );
#endif
  return d4l2;
}
