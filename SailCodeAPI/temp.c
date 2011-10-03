#include <stdio.h>

char nm[] = {"$GPGLL,5330.12,N,00215.31,W,134531,A*2"};

int main(int argc, const char *argv[])
{
	int i;
	for (i = 0; i < sizeof(nm); i++) {
		printf("%c", nm[i]);
	}
	return 0;
}
