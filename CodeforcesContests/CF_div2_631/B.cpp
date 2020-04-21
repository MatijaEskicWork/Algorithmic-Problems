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

int max1[200005], max2[200005];
int m[200005], can, m1[200005], can1;

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int t, n, a;
    SCD(t);
    while (t--) {
    	int sum = 0;
    	long long prefix[200005];
    	int a[200005];
    	memset(m, 0, sizeof(m));
    	memset(m1, 0, sizeof(m));
    	SCD(n);
    	int count = 1;
    	prefix[0] = 0;
    	max1[0] = 0;
    	max2[n + 1] = 0;
    	can = -1;
    	can1 = -1;
    	for (int i = 0; i < n; i++) {
    		SCD(a[i]);
    		prefix[i + 1] = prefix[i] + a[i];
    		max1[i + 1] = max(a[i], max1[i]);
    		if (m[a[i]] == 1 && can == -1) {
    			can = i + 1;
    		}
    		m[a[i]]++;
    	}
    	for (int i = n - 1; i >= 0; i--) {
    		if (m1[a[i]] == 1 && can1 == -1) {
    			can1 = i + 1;
    		}
    		m1[a[i]]++;
    		max2[i + 1] = max(a[i], max2[i + 2]);
    	}

    	bool OK = false;
    	vector <pair<int,int>> ans;
    	for (int i = 1; i <= n - 1; i++) {
    		if (prefix[i] - prefix[0] == 1LL * i * (i + 1) / 2 &&
    			prefix[n] - prefix[i] == 1LL * (n - i) * (n - i + 1) / 2
    			&& max1[i] == i && max2[i + 1] == n - i &&
    			i < can && i + 1 > can1){
    			ans.push_back(make_pair(i, n - i));
    			OK = true;
    		}
    	}
    	if (!OK) printf("0\n");
    	else {
    		int sz = ans.size();
    		printf("%d\n", sz);
    		for (int i = 0; i < sz; i++) {
    			printf("%d %d\n", ans[i].first, ans[i].second);
    		} 
    	}
    }
    return 0;
}