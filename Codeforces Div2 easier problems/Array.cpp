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

bitset<100005> bs;
int a[100005];
unordered_map <int, int> m;
int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, k;
	SCD(n);
	SCD(k);
	for (int i = 0; i < n; i++) {
		SCD(a[i]);
	}
	int ans = 0;
	if (k > n) {
		printf("-1 -1\n");
		return 0;
	}

	for (int i = 0; i < k; i++) {
		m[a[i]]++;
		bs[a[i]] = 1;
	}
	ans = bs.count();
	if (ans == k) {
		printf("%d %d\n", 1, k);
		return 0;
	}
	int l = -1, r = -1;
	for (int i = k; i < n; i++) {
		printf("%d %d %d %d, ", m[a[i]], a[i], m[a[i - k]], a[i - k]);
		m[a[i - k]]--;
		if (m[a[i - k]] == 0) ans--;
		m[a[i]]++;
		if (m[a[i]] == 1) ans++;
		if (ans == k) {
			l = i - k + 1;
			r = i + 1;
			break;
		}
	}
	printf("%d %d\n", l,r );
    return 0;
}

/* Treba odraditi ovo, nije tezak problem*/