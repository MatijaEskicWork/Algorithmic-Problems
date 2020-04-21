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

const int N = 10005;

bitset<N> bs[53];

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int m, n, k, a;
	SCD(m);
	SCD(n);
	for (int i = 0; i < m; i++) {
		int k;
		SCD(k);
		for (int j = 0; j < k; j++) {
			SCD(a);
			bs[i].set(a);
		}
	}
	bool OK = true;
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if ((bs[i] & bs[j]) == 0) {
				puts("impossible");
				OK = false;
				break;
			}
		}
		if (!OK) break;
	}
	if (OK)
		puts("possible");
    return 0;
}

