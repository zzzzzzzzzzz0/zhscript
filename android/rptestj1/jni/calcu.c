int calcu__(unsigned char* s) {
	int score = 0;
	for(; *s;)
		score += *s++;
	return (score % 100) + 1;
}

int calcu2__(int i1, int i2) {
	return ((i1 + i2) % 100) + 1;
}
