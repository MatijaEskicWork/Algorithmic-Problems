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
    int t, v, n, x, a;
    SCD(t);
    while (t--) {
    	int m[1005] = {0};
    	SCD(n);
    	SCD(x);
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		SCD(a);
    		m[a] = 1;
    	}
	    for (int i = 1; i <= 205; i++) {
	    		if (x == 0 && m[i] == 0) {
	    			ans = i-1;
	    			break;
	    		}
	    		else {
	    			if (m[i] == 0) x--;
	    		}
	    	}
	    printf("%d\n", ans);
    }
    return 0;
}