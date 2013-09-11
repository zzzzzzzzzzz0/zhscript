//gcc -O3 -o rptestj_score.so -shared -fPIC rptestj_score.c
int get_score(unsigned char*s){
	int score=0;
	for(;*s;)
		score+=*s++;
	score%=100;
	return score;
}

