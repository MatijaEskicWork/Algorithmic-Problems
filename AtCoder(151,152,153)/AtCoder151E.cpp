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


const int N = 2e5 + 5;
int factorial[N];

int mul(int x, int y) {
	return 1LL * x * y % MOD7;
}

int power(int x, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		exp >>= 1;
	}
	return res;
}


int inv(int x) {
	return power(x, MOD7 - 2);	
}

int binomial(int x, int y){
	if (x < y) return 0;
	return mul(factorial[x], inv(mul(factorial[y], factorial[x - y])));
}

int sub(int x, int y) {
	int k = x - y;
	if (k < 0) k += MOD7;
	return k;
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, k;
	SCD(n);
	SCD(k);
	int x;
	factorial[0] = 1;
	for (int i = 1; i <= N; i++) {
		factorial[i] = mul(factorial[i - 1], i);
	}
	vector<int> v;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		SCD(x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		/*int diff = sub(v[i + 1], v[i]);
		int num_ways = binomial(n, k);
		num_ways = sub(num_ways, binomial(i + 1, k));
		num_ways = sub(num_ways, binomial(n - i - 1, k));*/
		int num_max = binomial(i, k - 1);
		int num_min = binomial(n - (i + 1), k - 1);
		num_max = mul(num_max, v[i]);
		num_min = mul(num_min, v[i]);
		int l = sub(num_max, num_min);	
		ans = (ans + l) % MOD7;
	}
	printf("%d", ans);
    return 0;
}

