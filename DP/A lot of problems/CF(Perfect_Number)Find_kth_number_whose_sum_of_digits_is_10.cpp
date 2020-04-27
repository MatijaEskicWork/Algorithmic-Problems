#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int rastavi(int N){
	int ukupno = 0;
	while (N > 0){
		ukupno += N % 10;
		N /= 10;
	}
	if (ukupno == 10) return 1;
	return 0;
}




int main(void){
	int i, brojac = -1, niz[100000], K;
	for (i = 0; i < 11000000; i++){
		if (rastavi(i)) {
			brojac++;
			niz[brojac] = i;
		}
	}
	scanf("%d", &K);
	printf("%d", niz[K - 1]);
	return 0;
}
