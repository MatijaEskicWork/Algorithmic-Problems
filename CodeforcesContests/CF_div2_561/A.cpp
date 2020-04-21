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
	int n;
	cin >> n;
	string s[105];
	int m[27] = {0};
	memset(m, 0, sizeof(m));
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		m[(int) s[i][0] - 'a']++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		int first = m[i] / 2;
		first = (first) * (first - 1) / 2;
		int second = m[i] / 2 + m[i] % 2;
		second = (second) * (second - 1) / 2;
		ans += (first + second);
	}
	printf("%d\n", ans);

    return 0;
}

