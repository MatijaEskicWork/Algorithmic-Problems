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

const int N = 105;



int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int h, w;
    char mat[N][N];
    SCD(h);
    SCD(w);
    getchar();
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		SCC(mat[i][j]);
    	}
    	getchar();
    }
    long long dp[N][N];
 	memset(dp, 1, sizeof(dp));
 	bool show = false; 
 	for (int i = 0; i < h; i++) {
 		if (mat[i][0] == '#' || show) {
 			dp[i][0] = 0;
 			show = true;
 		}
 		else  dp[i][0] = 1;
 	}
 	show = false;
 	for (int i = 0; i < w; i++) {
 		if (mat[0][i] == '#' || show) {
 			dp[0][i] = 0;
 			show = true;
 		}
 		else  dp[0][i] = 1;
 	}

 	for (int i = 1; i < h; i++) {
 		for (int j = 1; j < w; j++) {
 			dp[i][j] = 0;
 			if (mat[i][j] == '.') {
 				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD7;
 			}
 			else {
 				dp[i][j] = 0;
 			}
 		}
 	}
 	printf("%lld", dp[h - 1][w - 1]);


    return 0;
}

