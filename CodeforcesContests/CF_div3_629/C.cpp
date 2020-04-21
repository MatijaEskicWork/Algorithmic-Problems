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
	//#ifndef ONLINE_JUDGE
    	freopen("inputf.txt", "r", stdin);
    	freopen("outputf.txt", "w", stdout);
    //#endif
    int t;
    SCD(t);
    getchar();
    while (t--) {
    	int n;
    	SCD(n);
    	getchar();
    	vector<int> a,b;
    	char c;
    	int end = 0;
    	for (int i = 0; i < n; i++) {
    		c = getchar();
    		if (c == '2' && !end) {
    			a.push_back(1);
    			b.push_back(1);

    		}
    		else if (c == '2' && end) {
    			a.push_back(0);
    			b.push_back(2);
    		}
    		else if (c == '1' && !end) {
    			a.push_back(1);
    			b.push_back(0);
    			end = 1;
    		}
    		else if (c == '1' && end) {
    			a.push_back(0);
    			b.push_back(1);
    		}
    		else {
    			a.push_back(0);
    			b.push_back(0);
    		}
    	}
    	getchar();
    	for (int i = 0; i < n; i++) {
    		printf("%d", a[i]);
    	}
    	printf("\n");
    	for (int i = 0; i < n; i++) {
    		printf("%d", b[i]);
    	}
    	printf("\n");
    }
    return 0;
}