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

const int N = 2e5 + 5;

int a[N];
long long pref[N];
set<long long> m;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	SCD(n);
	pref[0] = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		SCD(a[i]);
		pref[i + 1] = pref[i] + a[i];
		//printf("%lld ", pref[i + 1] );
	}

	int end = 1;
	int start = 0;
	m.insert(pref[start]);
	while (end <= n) {
		int pos = *m.find(pref[end]) - 0;
		//printf("%d %d %d ", pos, start, end);
		if (pos == end - start) {
			//printf("%d %d ", end, pref[end]);
			m.insert(pref[end]);	
			end++;
		}
		else {
			int i = start;
			while (pref[i] != pref[end]) {
				ans += (end - i - 1);
				//printf("%lld %d ", ans, i);
				i++;
			}
			ans += (end - i - 1);
			//printf("%lld %d ", ans, i);
			m.clear();
			start = i + 1;
			end = start + 1;
			if (start > n) break;
			m.insert(pref[start]);
		}
	}
	if (!m.empty()) {
		int i = start;
		while (i <= n) {
			ans += (n - i);
			i++;
		}
	}

	printf("%lld\n", ans);
    return 0;
}

