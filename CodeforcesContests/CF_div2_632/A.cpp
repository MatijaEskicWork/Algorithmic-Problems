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
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
    #endif
    int t;
    SCD(t);
    while (t--) {
    	int n, k;
    	bool visit[105][105], mat[105][105];
    	memset(visit, false, sizeof(visit));
    	memset(mat, false, sizeof(visit));
    	SCD(n);
    	SCD(k);
    	mat[0][0] = false;
    	visit[0][0] = true;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < k; j++) {
    			if (!visit[i][j]) {
    				visit[i][j] = true;
    				mat[i][j] = true;
    			}
    		}
    	}

    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < k; j++) {
    			if (mat[i][j]) printf("B");
    			else printf("W");
    		}
    		puts("");
    	}
    }
    return 0;
}