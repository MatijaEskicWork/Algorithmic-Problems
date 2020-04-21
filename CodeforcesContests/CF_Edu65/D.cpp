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
	SCD(n);
	vector<char> v;
	char ch;
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		v.push_back(ch);
	}
	int r = 0, b = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (v[i] == '(') {
				if (r <= b) {
					r++;
					ans.push_back(0);
				}
				else {
					b++;
					ans.push_back(1);
				}
			}
			else {
				if (r >= b) {
					r--;
					ans.push_back(0);
				}
				else {
					b--;
					ans.push_back(1);
				}
			}
		}
		else {
			ans.push_back(0);
			r++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", ans[i]);
	}
	puts("");
    return 0;
}

