#include <bits/stdc++.h>
using namespace std;
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
const long long BIGINF = 2e18 + 20;
const int N = 5005;



bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first + a.second < b.first + b.second;
}


int main () {
	/*#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif*/	

	int n, w, s;
	vector<pair<int, int>> v;
	SCD(n);
	for (int i = 0; i < n; i++) {
		SCD(s);
		SCD(w);
		v.push_back(make_pair(w, s));
	}
	sort(v.begin(), v.end(), cmp);
	/*for (int i = 0; i < n; i++) {
		printf("%d %d, ", v[i].first, v[i].second);
	} */
	long long dp[N];
	for (int i = 1; i <= n; i++) {
		dp[i] = BIGINF;
	}
	int ans = 1;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int used = i + 1; used >= 1; used--) {
			if (dp[used - 1] <= v[i].second) {
				dp[used] = min(dp[used], dp[used - 1] + v[i].first);
			}
			//printf("dp[%d] = %lld\n",used, dp[used]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] != BIGINF) {
			ans = max(ans, i);
		}
	}
	printf("%d\n", ans);
    return 0;
}

