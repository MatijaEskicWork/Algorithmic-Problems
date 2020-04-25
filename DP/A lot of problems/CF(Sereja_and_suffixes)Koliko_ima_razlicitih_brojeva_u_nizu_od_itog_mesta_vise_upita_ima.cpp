#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){	
	int num, i, N, M, arr[100000], count[100001] = {0}, sol[100002] = {0};
	scanf("%d" , &N);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	int sum = 0;
	for (i = N - 1 ; i > -1; i--){
		if (count[arr[i]] == 0) sol[i + 1] = sol[i + 2] + 1;			
		else sol[i + 1] = sol[i + 2];
		count[arr[i]]++;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++){
		scanf("%d" , &num);
		printf("%d\n", &sol[num]);
	}
	
	
	return 0;
}

