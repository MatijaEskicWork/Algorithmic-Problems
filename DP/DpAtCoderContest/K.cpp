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
    int n, k;
    cin >> n >> k;
    int a[105];
    bool dp[100005];
    memset(dp, false, sizeof(dp));
    dp[0] = false;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
    	for(int j = 0; j < n; j++) {
    		if (i - a[j] >= 0) {
    			if (dp[i - a[j]] == false) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    }
    if (dp[k]) printf("First");
    else printf("Second");

    return 0;
}

