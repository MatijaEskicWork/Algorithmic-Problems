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
	int q;
	long long a, b, m;
	SCD(q);
	for (int i = 0; i < q; i++) {
		scanf("%lld%lld%lld", &a, &b, &m);
		if (a == b) {
			printf("1 %lld\n", a);
			continue;
		}
		bool OK = false;
		for (int n = 2; n <= 50; n++) {
			long long over = (a + 1) << (n - 2);
			if (over > b) 
				break;
			vector<long long> ans = {a};
			long long r = a;
			long long prefix = a;
			long long rem = b - over; 
			long long val; 
			//printf("n = %d\n", n);
			//printf("rem = %lld, prefix = %lld\n", rem, prefix);
			for (int j = 2; j <= n; j++) {
				long long pow_2 = (1LL << max(0, n - (j + 1)));
				long long num = min(rem / pow_2, m - 1); // num is from 0 - (m - 1)
				rem -= 	num * pow_2;
				val = ans[j - 2] * 2 - r + num + 1; 
				ans.push_back(val);
				//printf("val = %lld, pow_2 = %lld, rem = %lld, prefix = %lld\n", val, pow_2, rem, prefix);
				r = num + 1;
				prefix += val;
			}
			if (rem == 0) {
				printf("%d", n);
				for (int k = 0; k < n; k++) {
					printf(" %lld", ans[k]);
				}
				puts("");
				OK = true;
				break;
			}
		}
		if (!OK) puts("-1");
	}
    return 0;
}

