#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int max(int a, int b){
	if (a > b) return a;
	return b;
}


int main(void){
	int N, K, arr[1000], i, dp[1000], ukupno;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	ukupno = 0;
	for (i = 1; i < N; i++){
		ukupno += max(0, K - (arr[i] + arr[i - 1]));
		arr[i] += max(0, K - (arr[i] + arr[i - 1]));
	}
	printf("%d\n", ukupno);
	for (i = 0; i < N; i++) printf("%d ", arr[i]);
	return 0; 
	
}
