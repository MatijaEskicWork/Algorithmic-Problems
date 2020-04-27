#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int BinarySearch(int array[], int key, int low, int high){
	if (high < low) 
        return -1;
	if (key >= array[high])
	 	return -2;
    if (key < array[low])
        return low; 
    if (low == high)
        return high;
        
	while (low != high) {
    	int mid = (low + high) / 2; 
    	if (array[mid] <= key) {
        	low = mid + 1;
    	}
    	else {
        	high = mid;
    	}
	}
	return high;
	
}


int main(void){	
	int i, j, N, M, arr[100000], money[100000];
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++){
		scanf("%d", &money[i]);
	}
	qsort(arr, N, sizeof(int), cmpfunc);
	for (i = 0; i < M; i++){
		int solution = BinarySearch(arr, money[i], 0, N - 1);
		if (solution == -1) printf("0\n");
		else if (solution == -2) printf("%d\n", N);
		else {
			printf("%d\n", solution );
		}
	}
	
	return 0;
}

