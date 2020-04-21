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
    vector<double> dp(n + 1);//probability that there was i heads so far
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
    	double head;
    	SCLF(head);
    	for (int j = i + 1; j >= 0; j--) { 
    		dp[j] = ((j == 0)? 0 : 1.0 *dp[j - 1] * head) + 1.0 * dp[j] * (1 - head); 
    	}
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        int tail = n - i;
        if (i > tail) {
            ans += dp[i];        
        }
    } 
    printf("%.10lf\n", ans);
    return 0;
}

