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
	int x,y, n;
	SCD(x);
	SCD(y);
	SCD(n);
	int sol;
	if (n == 1) {sol = x;}
	else if (n == 2) { sol = y; }
	else {
		if (x < 0) x += MOD7;
		if (y < 0) y += MOD7;
		if (n % 6 == 3) {
			sol = y - x;
		}
		else if (n % 6 == 4) {
			sol = -x;
		}
		else if (n % 6 == 5) {
			sol = -y;
		} 
		else if (n % 6 == 0) {
			sol = x - y;
		}
		else if (n % 6 == 1) {
			sol = x;
		}
		else sol = y;
	}
	if (sol < 0) sol += MOD7;
	if (sol >= MOD7) sol -= MOD7;
		printf("%d\n", sol);

    return 0;
}

