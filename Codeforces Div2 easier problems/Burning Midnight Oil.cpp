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


bool can(int num, int k, int target) {
	int ans = 0;
	ans += num;
	int cpy = k;
	while (num / k > 0) {
		ans += num / k;
		k *= cpy;
	}
	return ans >= target;
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	int k;
	cin >> n >> k;
	int high = n;
	int low = 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		//printf("%d %d\n", mid,(int) can(mid, k, n));
		if (can(mid, k, n)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%d", low);
    return 0;
}

