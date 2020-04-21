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
const int MOD = 998244353;
const int N = 200005;

bool cmp(int a, int b) {
	return (a < b) ;
}

vector<unsigned long long> a;
vector<int> b;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, y;
	long long x;
	SCD(n);
	for (int i = 0; i < n; i++) {
		SCLLD(x);
		a.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		SCD(y);
		b.push_back(y);
	}
	ull tmp;
	for (int i = 0; i < n; i++) {
		tmp = 1ULL * (i + 1) * (n - i) * a[i];
		a[i] = tmp;  
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		tmp = ((a[i] % MOD) * 1ULL * b[i] ) % MOD;
		sum = (sum + tmp) % MOD;
	}
	printf("%d\n", sum);
    return 0;
}

