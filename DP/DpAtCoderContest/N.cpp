#include <bits/stdc++.h>
using namespace std;
#define BIGINF (int) 1e18 + 7
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
    int a[505];
    long long dp[405][405];
    memset(dp, BIGINF, sizeof(dp));
    for (int i = 0; i < n; i++) {
    	SCD(a[i]);
    }
    long long prefix[405];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
    	prefix[i] += prefix[i - 1] + a[i - 1];
    }
    for (int L = n - 1; L >= 0; L--) {
    	for (int R = L; R < n; R++) {
    		if (L == R) {
    			dp[L][R] = 0;
    		}
    		else {
    			for (int k = L; k <= R - 1; k++) {
    				dp[L][R] = min(dp[L][R], dp[L][k] + 
    							   dp[k + 1][R] + (prefix[R + 1] - prefix[L]));
    			}
    		}
    	}
    }
   	// dp[i][j] min cost to convert into one
    printf("%lld" , dp[0][n - 1]);

    return 0;
}

