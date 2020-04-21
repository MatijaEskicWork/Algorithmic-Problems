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

vector<int> a;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	SCD(n);
	vector<char> s(200005);
	char ch;
	getchar();
	for (int i = 0; i < n; i++) {
		s[i] = getchar();
		//printf("%c", s[i]);
	}
	vector<char> ans;
	int cnt = 0;
	int pos = 0;
	while (cnt < n) {
		if (pos % 2 == 0) {
			int start = cnt;
			while (cnt < n && s[start] == s[cnt + 1]) {
				cnt++;
			}
			ans.push_back(s[start]);
		}
		else {
			ans.push_back(s[cnt]);
		}
		cnt++;
		pos++;
	}	
	int length = ans.size();
	if (length & 1) length--;
	int diff = n - length;
	printf("%d\n", diff);
	for (int i = 0; i < length; i++) {
		printf("%c", ans[i]);
	}
	printf("\n");
    return 0;
}
