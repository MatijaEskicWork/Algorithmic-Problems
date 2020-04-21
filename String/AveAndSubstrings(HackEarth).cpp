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
// to je to resenje samo treba ucitavati stringove efektnije
// preko getchar-a i ne koristiti substr, nego rucno praviti 
// substringove


int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int t;
    string s;
    cin >> t;
    while (t--) {
    	cin >> s;
    	int n = s.length();
    	//CompLPS(s, n);
    	int ans;
    	bool OK;
    	for (int i = 1; i < n / 2; i++) {
    		string sub = s.substr(0, i);
    		OK = true;
    		for (int j = i; j < n; j += i) {
    			if (sub != s.substr(j, i)) {
    				OK = false;
    				break;
    			}
    		}
    		if (OK) {
    			ans = i;
    			break;
    		}
    		
    	}
    	if (!OK) ans = n;
 		cout << ans << "\n";
    }
    return 0;
}