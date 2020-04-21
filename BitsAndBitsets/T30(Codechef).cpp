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

bitset<100005> bs[1005];
vector<int> a[100005];

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int n, q, L, R, x, k, val;

    SCD(n);
    SCD(q);
    for (int i = 0; i < n; i++) {
    	SCD(k);
    	for (int j = 0; j < k; j++) {
    		SCD(x);
    		a[i].push_back(x);
    		bs[x][i] = 1;

    	}
    }
    for (int i = 0; i < q; i++) {
    	int t;
    	SCD(t);
    	if (t == 1) {
    		SCD(x);
    		SCD(k);
    		x--;
    		int sz = a[x].size();
    		for (int j = 0; j < sz; j++) {
    			bs[a[x][j]][x] = 0;
    		}
    		a[x].clear();
    		for (int j = 0; j < k; j++) {
    			SCD(val);
    			bs[val][x] = 1;
    			a[x].push_back(val);
    		}
    	}
    	else {
    		SCD(L);
    		SCD(R);
    		L--;
    		R--;
    		bitset<100005> mask = 0;
    		SCD(k);
    		for (int j = 0; j < k; j++) {
    			SCD(val);
    			mask = mask | bs[val];
    		}
    		int ans;
    		mask <<= (100005 - (R + 1));
    		mask >>= (100005 - (R + 1) + L);
    		ans = (R - L + 1 - mask.count());
    		printf("%d\n", ans);
    	}
    }
    return 0;
}

