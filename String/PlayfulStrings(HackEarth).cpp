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
    int t;
   	string s;
    cin >> t;
    while (t--) {
    	cin >> s;
    	int n = s.length();
    	bool OK = true;
    	for (int i = 0; i < n - 1; i++) { 
    		int j = i + 1;
    		int diff = abs(s[i] - 'a' - (s[j] - 'a'));
    		if (diff != 1 && !((s[i] == 'a' && s[j] == 'z') ||
    			(s[i] == 'z' && s[j] =='a'))) {
    			OK = false;
    			break;
    		}
    	}
    	puts(OK? "YES" : "NO");
    }
    return 0;
}