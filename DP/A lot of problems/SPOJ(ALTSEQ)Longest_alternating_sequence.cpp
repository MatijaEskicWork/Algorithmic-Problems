#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){
	int N, T, k, i, j, arr[5000], inc[5000], dec[5000], sol[5000] ;
	scanf("%d", &T);
	for (k = 0; k < T; k++){
	
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		inc[i] = 1;
		dec[i] = 1;
	}
	for (i = 1; i < N; i++){
		for (j = 0; j < i; j++){
			if (arr[i] > arr[j] && inc[i] < inc[j] + 1){
				inc[i] = inc[j] + 1;
			}
		}
	}
	for (i = N - 2; i > -1; i--){
		for (j = N - 1; j > i; j--){
			if (arr[i] > arr[j] && dec[i] < dec[j] + 1){
				dec[i] = dec[j] + 1;
			}
		}
	}
	int max = 0;
	for (i = 0; i < N; i++){
		sol[i] = inc[i] + dec[i] - 1;
		if (sol[i] > max) max = sol[i];
	}
	printf("%d\n", max);
	
	}
	
}
