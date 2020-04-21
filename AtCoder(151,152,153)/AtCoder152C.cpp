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


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	SCD(n);
	int x;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) {
		SCD(x);
		v.emplace_back(x, i);
	}
	sort(v.begin(), v.end());
	int ans = 1;`
	int ind = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].second < ind) ans++;
		ind = min(ind, v[i].second);
	}
	printf("%d", ans);
    return 0;
}

