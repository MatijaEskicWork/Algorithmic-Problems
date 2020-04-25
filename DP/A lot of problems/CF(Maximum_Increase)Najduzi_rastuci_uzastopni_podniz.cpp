#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	int N, i, arr[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	int max = 0, curr = 1;
	
	for (i = 1; i < N; i++){
		if (arr[i] > arr[i - 1]){
			curr++;
		}
		else {
			if (curr > max) max = curr;
			curr = 1;
		}
	}
	if (curr > max) max = curr;
	printf("%d", max);
	return 0;
}
