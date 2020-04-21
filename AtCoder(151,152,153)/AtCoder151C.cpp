#include <bits/stdc++.h>
using namespace std;
#define MOD7 1000000007
#define MOD9 1e9 + 9
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

const long long BIGINF = 2e18 + 7;
const int INF = 2e9 + 7;


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	int m;
	cin >> n >> m;
	int ac = 0, wa = 0;
	bool visit[100005];
	int was[100005];
	memset(was, 0, sizeof(was));
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		int x;
		string s;
		cin >> x >> s;
		if (s == "AC") {
			if (!visit[x]) {
				ac++;
				visit[x] = true;
				wa += was[x];
			}
		}
		else if (s == "WA"){
			was[x]++;
		}
	}
	cout << ac << " " << wa;
    return 0;
}

