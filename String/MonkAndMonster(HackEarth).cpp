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


void CompLPS(string, int);
int lps[100005];

int SearchKMP(string txt, string pat, bool hash[]) {
	int n = txt.length();
	int m = pat.length();

	int ans = 0;
	CompLPS(pat, m);
	int i = 0, j = 0;
	while (i < n) {
		if (txt[i] == pat[j]) {
			i++;
			j++;
		}
		if (j == m) {
			hash[i - j] = true;
			j = lps[j - 1];
		}
		else if (i < n && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				i++;
			}
		}
	}
	return ans;
}

void CompLPS(string pat, int m) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			} 
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}




int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int t, cost[100005];
    string s, pat;
    cin >> t;
    while (t--) {
    	int n;
    	bool m[100005] = {false};
    	cin >> s >> pat;
    	cin >> n;
    	vector<int> pos;
    	for (int i = 0; i < n; i++) {
    		cin >> cost[i];
    	}
    	SearchKMP(s, pat, m);
    	int q = pat.length();
    	int dp[100005];
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		//cout << m[i] << " ";
    		if (m[i] == false) {
    			dp[i] = (i != 0)? dp[i - 1] : 0;
    		}
    		else {
    			dp[i] = dp[i - 1];
    			dp[i] = max((i - q >= 0)? dp[i - q] + cost[i] : cost[i], dp[i]);
    		}
    		ans = max(dp[i], ans);
    	}
    	cout << ans << "\n";
    }
    return 0;
}