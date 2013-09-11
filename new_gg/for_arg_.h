#include <stdarg.h>
#define _for_args1( argc )  \
    va_list argv; \
	int i;	\
    va_start(argv, argc); \
    for (i = 0; i < argc; ++i){
#define _for_args( argc )  \
    _for_args1( argc ) \
        char*s = va_arg(argv, char*);
#define _for_args2( argc )  \
    _for_args1( argc ) \
        const char*s = va_arg(argv, const char*);
#define _next_args   \
    }   \
    va_end(argv);
