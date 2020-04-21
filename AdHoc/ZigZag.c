#include <stdio.h>
#include <math.h>

int main(void) {

	int T, i;
	long long  x, y, resenje, razlika;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%lld%lld", &x, &y);
		if (x == y) printf("-1\n");
		else if (x > y) printf("1\n");
		else {
			resenje = 1;
			razlika = y - x;
			resenje += 1 + 2 * (x / razlika);
			if (y / x <= 2 && x % razlika == 0)
				resenje -= 1;
			printf("%lld\n", resenje);
		}
	}
	return 0;
}