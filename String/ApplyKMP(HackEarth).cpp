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
int SearchKMP(string txt, string pat) {
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
			ans++;
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
    string s, pat;
    cin >> pat;
    cin >> s;
    int ans = SearchKMP(s, pat);

    cout << ans;
    return 0;
}

