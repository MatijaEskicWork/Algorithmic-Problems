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

vector<pair<int, int>> v(1000005);
vector<int> arr;
int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, x, a;
	SCD(n);
	SCD(x);
	for (int i = 0; i < x; i++) {
		v[i].first = INF;
	}
	for (int i = 0; i < n; i++) {
		SCD(a);
		a--;
		arr.push_back(a);
		v[a].first = min(v[a].first, i);
		v[a].second = max(v[a].second, i);

	}
	bool increase = true;
	for (int i = 0; i < n - 1; i++) {
		if (!(arr[i] <= arr[i + 1])) {
			increase = false;
			break;
		}
	}
	if (increase) {
		printf("%lld\n", 1LL * x * (x + 1) / 2);
		return 0;
	}
	int ans = 0;
	int L = 0;
	vector<int> l;
	vector<int> r;
	l.push_back(-1);
	r.push_back(INF);
	int big_so_far = v[L].second;
	l.push_back(big_so_far);
	while (big_so_far < v[L + 1].first) {
		big_so_far = max(big_so_far, v[L + 1].second);
		l.push_back(big_so_far);
		L++;
	}
	int R = x - 1;
	int small_so_far = v[R].first;
	r.push_back(small_so_far);
	while (small_so_far > v[R -	 1].second) {
		small_so_far = min(small_so_far, v[R - 1].first);
		r.push_back(small_so_far);
		R--;
	}
	//printf("%d %d\n", L, R);
	int j = r.size() - 1;
	for (int num: l) {
		while (j >= 0 && r[j] < num) {
			j--;
		}
		ans += j + 1;
	}
	printf("%d", ans);
    return 0;
}

