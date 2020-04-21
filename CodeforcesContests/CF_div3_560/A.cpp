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
    int n;
    int x,y;
    string str;
    cin >> n >> x >> y;
    cin >> str;
    int ans = 0;
    for (int i = n - 1; i >= n - x; i--) {
    	if (i == n - y - 1 && str[i] == '0') ans++;
    	else if (i != n - y - 1){
    		if (str[i] == '1') ans++;
    	} 
    }
    //if (str[n - x - 1] == '0') ans++;
    cout << ans;

    return 0;

}

