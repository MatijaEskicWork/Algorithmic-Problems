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

vector<int> trans[200005];
vector<int> v;
int n, m, x, y;
bool possible(int days) {
	vector<int> last_chance_day[20005];
	vector<int> off_market(20005);
	for (int type = 0; type < n; type++) {
		int sz = trans[type].size();
		int last = -1;
		for (int day = 0; day < sz; day++) {
			if (trans[type][day] <= days)
				last = max(last, trans[type][day]);
		}
		if (last != -1) 
			last_chance_day[last].push_back(type);
	}

	int money = 0;
	vector<int> copy = v;
	for (int day = 0; day <= days; day++) {
		money++;
		for (auto type: last_chance_day[day]) {
			if (money >= copy[type]) {
				money -= copy[type];
				copy[type] = 0;
			}
			else {
				copy[type] -= money;
				money  = 0;
				break;
			}
		}	
	}
	return accumulate(copy.begin(), copy.end(), 0) * 2 <= money;
}




int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	SCD(n);
	SCD(m);
	int num_type;
	long long all = 0;
	for (int i = 0; i < n; i++) {
		SCD(num_type);
		v.push_back(num_type);
		all += num_type;
	}

	for (int i = 0; i < m; i++){ 
		SCD(x);
		SCD(y);
		y--;
		x--;
		trans[y].push_back(x);
	}
	int low = 0, high = 2 * all;
	//printf("%d %d ", low, high);
	while (high > low) {
		int mid = (high + low) / 2;
		if (possible(mid)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%d\n", low + 1);





    return 0;
}

