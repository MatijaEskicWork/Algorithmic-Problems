#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void){
	int numQ = 0, numA = 0;
	
	int sum = 0;
	char word[100];
	int i;
	scanf("%s", word);
	int length = strlen(word);
	for (i = 0; i < length; i++){
		if (word[i] == 'Q'){
			sum += numA;
			numQ++;
		}
		else if (word[i] == 'A'){
			numA += numQ;
		}
	}
	printf("%d", sum);
	return 0;
}
