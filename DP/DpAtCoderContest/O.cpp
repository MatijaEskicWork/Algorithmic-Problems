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
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int n;
    SCD(n);
    int bs[22][22];
    vector<int> dp((1 << n) + 5);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		SCD(bs[i][j]);
    	}
    }

    for (int bmask = 0; bmask < (1 << n) - 1; i++) {
    	int i = __builtin_popcount(bmask);
    	for (int j = 0; j < n; j++) {
    		if (bs[i][j] && )
    	}
    }

    printf("%d", dp[(1 << n) - 1])
    return 0;
}

