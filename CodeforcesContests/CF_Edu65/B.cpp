#include <bits/stdc++.h>
using namespace std;
#define BIGINF (int) 4e18 + 7
#define MOD7 1000000007
#define MOD9 1e9 + 9
#define INF  (int)2e9 + 7
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long ll;
typedef long double ld;
typedef string str;
typedef double d;
typedef unsigned u;
typedef unsigned long long ull;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int answer[7];
	for (int i = 1; i <= 4; i++) {
		printf("? 1 %d\n", i + 1);
		fflush(stdout);
		SCD(answer[i]);
	}
	int arr[] = {4, 8, 15, 16, 23, 42};
	for (int i = 0; i < 6; i++) {
		bool OK = true;
		int num = arr[i];
		for (int j = 1; j <= 4; j++) {
			if (answer[j] % num != 0) {
				OK = false;
			}
		}
		if (OK) answer[0] = num;
	}
	int sum = 108;
	for (int i = 1; i <= 4; i++) {
		answer[i] /= answer[0];
	}
	for (int i = 0; i <= 4; i++) {
		sum-= answer[i];
	}
	answer[5] = sum;
	printf("! ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", answer[i]);
	}

    return 0;
}

