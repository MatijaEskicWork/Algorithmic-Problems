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

long long dp[200005];
vector<pair<int, int>> v;


int binSearch(int target,int low, int high) {
	int ans = -1;
	while (low <= high) {
		int mid = low + (high - low)/2;
		if (v[mid].first == target)
			return mid;
		else if (v[mid].first < target) {
			ans = max(mid, ans);
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return ans;
}



int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, range, damage;
	SCD(n);
	SCD(range);
	SCD(damage);
	int x, h;
	for (int i = 0; i < n; i++) {
		SCD(x);
		SCD(h);
		v.emplace_back(x, h);
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		//printf("%d %d\n", v[i].first, v[i].second);
		dp[i] = dp[i] + (i > 0? dp[i - 1] : 0);
		printf("dp[%d] = %lld, ", i, dp[i]);
		if (v[i].second - dp[i] <= 0) {
			puts("");
			continue;
		}
		v[i].second -= dp[i];
		long long dam = v[i].second / damage;
		if (v[i].second % damage != 0) dam++;
		ans += dam;
		dam = 1LL * dam * damage;
		int end = binSearch(v[i].first + range*2, i, n-1);
		printf("end = %d ", end);
		end = (end != -1? end + 1: n); 
		dp[i] += dam;
		dp[end] -= dam;
		printf("ans = %lld, dam = %lld, end = %d\n", ans, dam, end);
	}
	printf("%lld\n", ans);
    return 0;
}

