#include <string.h>

#include "gjk2.h"

#ifdef _WINDOWS
__declspec(dllexport)
#else
#ifdef __cplusplus
extern "C"
#endif
#endif
char* hs7huan4ma3xu4lie4( char * z4f2ch4, char * ying3dao3fu2, unsigned * z4f2d4l2_ )
{
  char huan3cong1[9];
  int d4l2, z4f2, jin4zhi4, c4w4;
  unsigned pian1yi2, chang2;
  unsigned ying3dao3fu2chang2 = strlen( ying3dao3fu2 );
  unsigned z4f2d4l2 = 0;

  while ( * ( z4f2ch4 + z4f2d4l2 ) )
  {
    if ( /* _f */ strncmp( z4f2ch4 + z4f2d4l2, ying3dao3fu2, ying3dao3fu2chang2 ) == 0 )
    {
      jin4zhi4 = 0;
      d4l2 = ying3dao3fu2chang2 + 1;
      switch ( z4f2 = * ( z4f2ch4 + z4f2d4l2 + ying3dao3fu2chang2 ) )
      {
        case 'a':
          z4f2 = '\a';
        break;
        case 'b':
          z4f2 = '\b';
        break;
        case 'f':
          z4f2 = '\f';
        break;
        case 'n':
          z4f2 = '\n';
        break;
        case 'r':
          z4f2 = '\r';
        break;
        case 't':
          z4f2 = '\t';
        break;
        case 'v':
          z4f2 = '\v';
        break;
        case 0:
          if ( z4f2d4l2_ )
            * z4f2d4l2_ = ++z4f2d4l2;
          return z4f2ch4;
        case 'x':
        case 'X':
          jin4zhi4 = 'F';
        break;
        case '/':
          jin4zhi4 = * ( z4f2ch4 + z4f2d4l2 + d4l2++ );
        break;
        default:
          if ( z4f2 >= '0' && z4f2 <= '7' )
          {
            jin4zhi4 = '8';
            d4l2--;
          }
        break;
      }
      if ( jin4zhi4 )
      {
        if ( jin4zhi4 >= '1' && jin4zhi4 <= '2' )
          chang2 = 8;
        else if ( jin4zhi4 == '3' )
          chang2 = 6;
        else if ( jin4zhi4 >= '4' && jin4zhi4 <= '6' )
          chang2 = 4;
        else if ( (jin4zhi4 >= '7' && jin4zhi4 <= '9') || jin4zhi4 == '0' || (jin4zhi4 >= 'A' && jin4zhi4 <= 'E') )
          chang2 = 3;
        else if ( (jin4zhi4 >= 'F' && jin4zhi4 <= 'Z') || (jin4zhi4 >= 'a' && jin4zhi4 <= 'z') )
          chang2 = 2;
        else
        {
          if ( z4f2d4l2_ )
            * z4f2d4l2_ = 0xffff;
          return z4f2ch4;
        }
        for ( pian1yi2 = 0;
             pian1yi2 < chang2 &&
             ( (( z4f2 = * ( z4f2ch4 + z4f2d4l2 + d4l2 ) ) >= '0'
             && z4f2 < ( jin4zhi4 >= '1' && jin4zhi4 <= '9' ? jin4zhi4 : '9' + 1 )) || (jin4zhi4 >= 'A'
             && ( (z4f2 >= 'A' && z4f2 <= 'Z') || (z4f2 >= 'a' && z4f2 <= 'z') )) ); ++d4l2 )
             {
               huan3cong1[pian1yi2++] = z4f2;
        }
        if ( !pian1yi2 )
        {
          if ( z4f2d4l2_ )
            * z4f2d4l2_ = 0xfffe;
          return z4f2ch4;
        }
        huan3cong1[pian1yi2] = 0;
        if ( jin4zhi4 >= '1' && jin4zhi4 <= '9' )
          jin4zhi4 -= '0';
        else if ( jin4zhi4 == '0' )
          jin4zhi4 = 10;
        else if ( jin4zhi4 >= 'A' && jin4zhi4 <= 'Z' )
        {
        	int i;
          jin4zhi4 = jin4zhi4 - 'A' + 11;
#ifdef _WINDOWS
          strupr( huan3cong1 );
#else
          for(i=0;huan3cong1[i];i++){
            if(huan3cong1[i]>='a' && huan3cong1[i]<='z'){
              huan3cong1[i]=huan3cong1[i]-'a'+'A';
            }
          }
#endif
        }
        else
          jin4zhi4 = jin4zhi4 - 'a' + 37;
        z4f2 = ( int )hs7chuan4_zheng3shu4( huan3cong1, jin4zhi4, & c4w4 );
        if ( c4w4 )
        {
          if ( z4f2d4l2_ )
            * z4f2d4l2_ = 0xfffe - c4w4;
          return z4f2ch4;
        }
      }
      * ( z4f2ch4 + z4f2d4l2 ) = z4f2;
      for ( pian1yi2 = 0; (* ( z4f2ch4 + z4f2d4l2 + 1 + pian1yi2 ) = * ( z4f2ch4 + z4f2d4l2 + d4l2 + pian1yi2 )); pian1yi2++ );
    }
    z4f2d4l2++;
  }
  if ( z4f2d4l2_ )
    * z4f2d4l2_ = z4f2d4l2;
  return z4f2ch4;
}
