#include <bits/stdc++.h>
using namespace std;
#define MOD7 1000000007
#define MOD9 1e9 + 9
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

const long long BIGINF = 2e18 + 7;
const int INF = 2e9 + 7;
const int N = 2e4 + 5;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int h, n;
	SCD(h);
	SCD(n);
	int dp[N], capacity[N], val[N];
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		SCD(capacity[i]);
		SCD(val[i]);
		//maxi = max(capacity[i], maxi);
	}
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= h; j++) {
			int num = min(j + capacity[i], h);
			dp[num] = min(dp[j] + val[i], dp[num]);
		}
	}
	printf("%d", dp[h]);
	return 0;
}

