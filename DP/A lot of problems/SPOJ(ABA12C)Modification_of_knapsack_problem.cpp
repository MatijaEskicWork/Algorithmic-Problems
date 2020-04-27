#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void){
	int i, j, l, T, N, K, price[1000], dp[1001];
	scanf("%d", &T);
	for (l = 0; l < T; l++){
	
	scanf("%d %d", &N, &K);
	for (i = 1; i < K + 1; i++){
		scanf("%d", &price[i]);
	}
	for (i = 1; i < K + 1; i++){
		if (price[i] != -1) dp[i] = price[i];
		else dp[i] = 0;
	}
	
	for (i = 1; i < K + 1; i++){
		for (j = 1; j < i; j++){
			if (price[j] == -1) continue;
			else if ((dp[i - j] + price[j] < dp[i] && dp[i] != 0) || (dp[i - j] + price[j] > dp[i] && dp[i] == 0) && dp[i - j] != 0) dp[i] = dp[i - j] + price[j];
		}
	}
	if (dp[K] == 0) printf("-1\n");
	else printf("%d\n", dp[K]);
	}
	
	return 0;
}
