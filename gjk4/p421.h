#define DELIMITER 1
#define VARIABLE  2
#define NUMBER    3
#define ERRMSG1 "syntax error"
#define ERRMSG2 "unbalanced parentheses"
#define ERRMSG3 "no expression present"

int eval_exp(double *answer, char *exp);
void eval_exp2(double *answer);
void eval_exp1(double *result);
void eval_exp3(double *answer), eval_exp4(double *answer);
void eval_exp5(double *answer);
void eval_exp6(double *answer), atom(double *answer);
void get_token(void), putback(void);
void unary(char o, double *r);
void serror(int error);
double find_var(char *s);
int isdelim(char c);
