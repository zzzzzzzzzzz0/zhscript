#define JMP_VER

#include "stdlib.h"
#include "ctype.h"
#include "stdio.h"
#include "string.h"
#ifdef JMP_VER
	#include <setjmp.h>
#endif

#include "p421.h"

/*#define DEBUG*/
/*#define DEBUG_TOK*/
/*#define DEBUG_ANSWER*/

#ifdef DEBUG
	#define PRINTF(s) if(count % 12 == 0) getchar();    \
		printf("\n%04d[" #s "]", count++);
	int count;
#endif
#ifdef DEBUG_TOK
	#define PRINTF1 printf("\ttok_type<%s>\ttoken<%s>",         \
		tok_type==NUMBER ? "NUMBER" :                           \
			(tok_type==VARIABLE ? "VARIABLE" : "DELIMITER"),    \
		token);
#endif
#ifdef DEBUG_ANSWER
	#define PRINTF2 printf("\tanswer(%.2f)", *answer);
#endif

#ifdef JMP_VER
	jmp_buf mark;
#endif
#ifndef JMP_VER
	extern
#endif
	char *prog;
char token[80];
char tok_type;

double vars[26] = {
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};


#ifndef JMP_VER
	void
#else
	int
#endif
 eval_exp(double *answer
	#ifdef JMP_VER
		, char *exp
	#endif
)
{
	#ifdef JMP_VER
		int jmpret;
	#endif

	#ifdef DEBUG
		count = 1;
		PRINTF(eval_exp)
	#endif

	#ifdef JMP_VER
		prog = exp;
		jmpret = setjmp(mark);
		if(jmpret)
			return jmpret;
	#endif

	get_token();
	if(!token) {
		serror(
			2
			#ifdef JMP_VER
				+ 1
			#endif
		);
		#ifndef JMP_VER
			return;
		#endif
	}
	eval_exp1(answer);
	return
		#ifdef JMP_VER
			0
		#endif
	;
}

void eval_exp1(double *answer)
{
	int slot;
	char ttok_type;
	char temp_token[80];

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp1)
	#endif

	if(tok_type==VARIABLE) {
		strcpy(temp_token, token);
		ttok_type = tok_type;

		slot = toupper(*token)-'A';

		get_token();
		if(*token != '=') {
			putback();
			strcpy(token,temp_token);
			tok_type = ttok_type;
		}
		else {
			get_token();
			eval_exp2(answer);
			vars[slot] = *answer;
			return;
		}
	}
	eval_exp2(answer);
}

void eval_exp2(double *answer)
{
	register char op;
	double temp;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp2)
	#endif

	eval_exp3(answer);
	while((op = *token) == '+' || op == '-') {
		get_token();
		eval_exp3(&temp);
		switch(op) {
			case '-':
				*answer = *answer - temp;
				break;
			case '+':
				*answer = *answer + temp;
				break;
		}
	}
}

void eval_exp3(double *answer)
{
	register char op;
	double temp;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp3)
	#endif

	eval_exp4(answer);
	while((op = *token) == '*' || op == '/' || op == '%') {
		get_token();
		eval_exp4(&temp);
		switch(op) {
			case '*':
				*answer = *answer * temp;
				break;
			case '/':
				*answer = temp ? *answer / temp : temp;
				break;
			case '%':
				if( temp ) *answer = (long int) *answer % (long int) temp;
				break;
		}
	}
}

void eval_exp4(double *answer)
{
	double temp, ex;
	register int t;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp4)
	#endif

	eval_exp5(answer);
	while(*token== '^') {
		get_token();
		eval_exp4(&temp);
		ex = *answer;
		if(temp==0.0) {
			*answer = 1.0;
			return;
		}
		for(t=(int)temp-1; t>0; --t) *answer = (*answer) * (double)ex;
	}
}

void eval_exp5(double *answer)
{
	register int op;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp5)
	#endif

	op = 0;
	if((tok_type == DELIMITER) && *token=='+' || *token == '-') {
		op = *token;
		get_token();
	}
	eval_exp6(answer);
	if(op=='-') *answer = -(*answer);
}

void eval_exp6(double *answer)
{
	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(eval_exp6)
	#endif

	if((*token == '(')) {
		get_token();
		eval_exp2(answer);
		if(*token != ')')
			serror(
				1
				#ifdef JMP_VER
					+ 1
				#endif
			);
		get_token();
	}
	else
		atom(answer);
}

void atom(double *answer)
{
	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG_ANSWER
		PRINTF2
	#endif
	#ifdef DEBUG
		PRINTF(atom)
	#endif

	switch(tok_type) {
		case VARIABLE:
			*answer = find_var(token);
			get_token();
			return;
		case NUMBER:
			*answer = atof(token);
			get_token();
			return;
		default:
			serror(
				0
				#ifdef JMP_VER
					+ 1
				#endif
			);
	}
}

void putback(void)
{
	char *t;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG
		PRINTF(putback)
	#endif

	t = token;
	for(; *t; t++) prog--;
}


void serror(int error)
{
	#ifndef JMP_VER
		static char *e[]= {
			ERRMSG1,
			ERRMSG2,
			ERRMSG3
		};
	#endif

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG
		PRINTF(serror)
	#endif

	#ifndef JMP_VER
		printf("%s\n", e[error]);
	#else
		longjmp(mark, error);
	#endif
}

void get_token(void)
{
	register char *temp;

	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG
		PRINTF(get_token)
	#endif

	tok_type = 0;
	temp = token;
	*temp = '\0';

	if(!*prog) return;

	while(isspace(*prog)) ++prog;

	if(strchr("+-*/%^=()", *prog)){
		tok_type = DELIMITER;
		*temp++ = *prog++;
	}
	else if(isalpha(*prog)) {
		while(!isdelim(*prog)) *temp++ = *prog++;
		tok_type = VARIABLE;
	}
	else if(isdigit(*prog)) {
		while(!isdelim(*prog)) *temp++ = *prog++;
		tok_type = NUMBER;
	}

	*temp = '\0';
}

int isdelim(char c)
{
	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG
		PRINTF(isdelim)
	#endif

	if(
		strchr(/*" "*/ "+-*/%^=()", c) || c==9 || c=='\r' || c==0
	)
		return 1;
	return 0;
}

double find_var(char *s)
{
	#ifdef DEBUG_TOK
		PRINTF1
	#endif
	#ifdef DEBUG
		PRINTF(find_var)
	#endif

	if(!isalpha(*s)){
		serror(
			1
			#ifdef JMP_VER
				+ 1
			#endif
		);
		return 0.0;
	}
	return vars[toupper(*token)-'A'];
}
