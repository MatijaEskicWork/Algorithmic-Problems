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


int mul(int x, int y) {
	return (1LL * x * y) % MOD7;
}

int power(int x, int exp) {
	int res = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		exp /= 2;
	}
	return res;
}


int inv(int x) {
	return power(x, MOD7 - 2);
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n;
	SCD(n);
	int a[10005];
	map<int, int> lcm;
	int count;
	for (int i = 0; i < n; i++) {
		SCD(a[i]);
		int x = a[i];
		for (int j = 2; j * j <= x; j++) {
			count = 0;
			while(x % j == 0) {
				count++;
				x /= j;
			}
		}
		if (x != 1) facts[x]++;
		for(pair<int, int> p: facts) {
			lcm[p.first] = max(lcm[p.first], p.second);
		} 
	}
	int num = 1;
	for (pair<int, int> p: lcm) {
		for (int i = 0; i < p.second; i++) {
			num = mul(num, p.first);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		//printf("%d ", mul(num, inv(a[i])));
		ans = (ans + mul(num, inv(a[i]))) % MOD7;
	}
	printf("%d" ,ans);
    return 0;
}

