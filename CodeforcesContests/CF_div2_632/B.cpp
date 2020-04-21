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
    int t, x;
    SCD(t);
    while (t--) {
    	int n;
    	SCD(n);
    	int mapa[100005][3];
    	vector<int> a;
    	vector<int> b;
    	for (int i = 0; i < n; i++) {
    		SCD(x);
    		a.push_back(x);
    	}
    	for (int i = 0; i < n; i++) {
    		SCD(x);
    		b.push_back(x);
    	}
    	mapa[0][0] = 0;
    	mapa[1][0] = 0;
    	mapa[2][0] = 0;
    	for (int i = 1; i <= n; i++) {
    		mapa[i][0] = mapa[i-1][0] + ((a[i-1] == 0)? 1 : 0);
    		mapa[i][1] = mapa[i-1][1] + ((a[i-1] == 1)? 1 : 0);
    		mapa[i][2] = mapa[i-1][2] + ((a[i-1] == -1)? 1 : 0);  
    	}
    	/*for (int i = 0; i <= n; i++) {
    		printf("%d %d %d\n", mapa[i][0], mapa[i][1], mapa[i][2]);
    	}*/
    	bool OK = true;
    	int minus = 0;
    	int plus = 0;
    	for (int i = n - 1; i >= 0; i--) {
    		if (b[i] < a[i]) {
    			if (mapa[i][2] + minus <= 0) {
    				OK = false;
    				break;
    			}
    		}
    	 	else if (b[i] > a[i]) {
    	 		if (mapa[i][1] + plus <= 0) {
    	 			OK = false;
    	 			break;
    	 		}
    	 	}
    	}
    	puts(OK? "YES": "NO");
    }
    return 0;
}