#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int min(int x, int y){
	if (x < y) return x;
	return y;
}


int main(void){
	int num_city, capacity, i;
	scanf("%d %d", &num_city, &capacity);
	int sum = 0, need = num_city - 1;
	sum = min(capacity, need);
	int fuel = sum;
	need -= sum;
	for (i = 1; i < num_city; i++){
		fuel--;
		sum += min(capacity - fuel, need) * (i + 1);
		need -= min(capacity - fuel, need);
		fuel += min(capacity - fuel, need);
	}
	printf("%d", sum);
	
	return 0;
}

