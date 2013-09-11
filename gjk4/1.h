#ifdef _WINDOWS
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#ifdef _WINDOWS
#define _dle __declspec(dllexport)
#else
#ifdef __cplusplus
#define _dle extern "C"
#else
#define _dle extern
#endif
#endif

extern char* __strcpyn(char* s,const char* chuan4,int chang2);
extern int __cat(char* s,int len);
extern void cat4__(char* s);
extern void cpy4__(char* s);
extern void head4__(char* s);
extern void free___();
extern char* s___();
extern const char* ret___(long l);
extern const char* ret_s___(char* s);
extern char* ltoa_(long l,char* buf,int radix);

#ifdef _WINDOWS
#define sprintf__ wsprintf
#else
#define sprintf__ sprintf
#endif
