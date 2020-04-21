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
	int a[100005];
	for (int i = 0; i < n; i++) {
		SCD(a[i]);
	}

	int height = a[0];
	long long res = a[0] + 1;	 

	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			height = a[i];
			res += a[i - 1] - a[i];
		}
		res += a[i] - height + 1;
		height = a[i];	
		res++;
	}
	printf("%lld", res);
    return 0;
}

