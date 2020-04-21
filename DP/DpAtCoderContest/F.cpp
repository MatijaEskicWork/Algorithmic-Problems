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

int N = 305;

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
   	int dp[N][N];
   	string s1, s2;
    cin >> s1;
    cin >> s2;
    int n1 = s1.length(), n2 = s2.length();
    vector<char> v;

    for (int i = 0; i <= n1; i++) {
    	dp[i][0] = 0;
    }
    for (int i = 0; i <= n2; i++) {
    	dp[i][0] = 0;
    }

    for (int i = 1; i <= n1; i++) {
    	for (int j = 1; j <= n2; j++) {
    		if (s1[i - 1] == s2[j - 1]) {
    			dp[i][j] = dp[i - 1][j - 1] + 1;
    		}
    		else {
    			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    		}
    	}
    }
    if (dp[n1][n2] == 0) cout << "";
    else {
    	int i = n1, j = n2;
    	while (dp[i][j] > 0) {
    		if (dp[i-1][j-1] == dp[i - 1][j] && dp[i-1][j - 1] == dp[i][j - 1] && dp[i][j] > dp[i - 1][j - 1]) {
    			i--;
    			j--;
    			v.push_back(s1[i]);
    		}
    		else {
    			if (dp[i - 1][j] > dp[i][j - 1])
    				i--;
    			else
    				j--;
    		}
    	}
    	int size = v.size();
    	for (int i = size - 1; i >= 0; i--) {
    		cout << v[i];
    	}
	}


    return 0;
}

