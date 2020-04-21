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

int a[105], n;
//long long sol = 0;
long long dp[100005];


void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD7;
    }
}


int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    int k;
    SCD(n);
    SCD(k);
    for (int i = 0; i < n; i++) {
    	SCD(a[i]);
    }
    MEM(dp, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> add(100005);
        for (int j = k; j >= 0; j--) {
            int L = j + 1;
            int R = j + min(a[i], k - j);
            if (L <= R) {
                add[L] = (add[L] + dp[j]) % MOD7;
                if (R + 1 <= k)
                    sub(add[R + 1], dp[j]);
            }   //L..R -> dp[L] = dp[L] + dp[j] 
        }
        int prefix = 0;
        for (int j = 0; j <= k; j++) {
            prefix = (prefix + add[j]) % MOD7;
            dp[j] = (dp[j] + prefix) % MOD7;
        }
    }

    printf("%d", dp[k]);

    return 0;
}
