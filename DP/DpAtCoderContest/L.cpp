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

const int N = 305;

long long dp[N][N];
int a[3005];


long long rec(int low, int high) {
	if (dp[low][high] != 0) return dp[low][high];
	if (low == high) {
		return dp[low][high] = a[low];
	}	
	return dp[low][high]= max(-rec(low, high - 1) + a[high],
										-rec(low + 1, high) + a[low] );
}
int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    memset(dp, 0, sizeof(dp));
    int n;
    SCD(n);
    for (int i = 0; i < n; i++) {
    	SCD(a[i]);
    }
    long long ans = rec(0, n - 1);
    printf("%lld", dp[0][n - 1]);
    return 0;
}

