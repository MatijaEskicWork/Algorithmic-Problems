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
    int n, a[10005], b[10005], c[10005];
    int dp[10005][3];
    SCD(n);
    MEM(dp, 0);
    for (int i = 0; i < n; i++) {
    	SCD(a[i]);
    	SCD(b[i]);
    	SCD(c[i]);
    }
    for (int i = 1; i <= n; i++) {
    	dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i - 1];
    	dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i - 1];
    	dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c[i - 1];
    }
    int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    printf("%d", ans);

    return 0;
}

