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
	map<string, int> hash;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		int l = s.length();
		char ch1, ch2;
		ch1 = s[0];
		ch2 = s.back();
		s.clear();
		s += ch1;
		s += ch2;
		hash[s]++;
	}
	assert((int) hash.size() <= 100);
	long long ans = 0;
	for (pair<string, int> x: hash) {
		string s = x.first;
		swap(s[0], s[1]);
		if (s[0] == s[1]) {
			ans += 1LL * x.second * x.second;
		}
		else {
			ans += 1LL * hash[s] * x.second;
		}
	}
	printf("%lld" ,ans);
    return 0;
}

