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
    cin >> t;
    string s;
    while (t--) {
    	int n; 
    	cin >> n;
    	cin >> s;
    	int count = 0;
    	bool OK = false;
    	for (int i = n - 1; i >= 0; i--) {
    		count++;
    		if (s[i] == '8' && count == 11) {
    			OK = true;
    			break;
    		} 
    		if (count == 11) count--; 
    	}
    	puts(OK? "YES": "NO");
    }
    return 0;
}