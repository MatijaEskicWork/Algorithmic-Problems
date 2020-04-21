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

int n,m;
int num[100005], a[100005];


int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    SCD(n);
    SCD(m);
    long long sum = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
    	SCD(a[i]);
    	num[i] = n - a[i] + 1;
    	sum += a[i];
    	v.push_back(make_pair(a[i], i));
    }
    if (sum < n || m > n) { printf("-1\n");}
    else {
    	sort(v.begin(), v.end());
    	for (int i = 0; i < m; i++) {
    		printf("%d %d\n", v[i].first, v[i].second);
    	}
    }	

    return 0;
}

