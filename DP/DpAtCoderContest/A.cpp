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
    int n, x;
    SCD(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
    	SCD(x);
    	v.push_back(x);
    }
    int dp[100005];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
    	if (i <= 1) {
    		dp[i] = dp[i - 1] + abs(v[i] - v[i - 1]);
    	}
    	else {
    		dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]),
    					dp[i - 2] + abs(v[i] - v[i - 2]));
    	}
    }
    printf("%d", dp[n - 1]);


    return 0;
}

