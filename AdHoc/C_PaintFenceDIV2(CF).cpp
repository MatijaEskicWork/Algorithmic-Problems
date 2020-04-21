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


const int N = 5005;

vector<int> cnt(N, 0);
vector<int> preffOnes(N, 0);


int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int n, q, x, y;
    vector <pair<int, int>> v;
    SCD(n);
    SCD(q);
    for (int i = 0; i < q; i++) {
    	SCD(x);
    	SCD(y);
    	x--;
    	y--;
    	v.push_back(make_pair(x,y));
    	for (int j = x; j <= y; j++) {
    		cnt[j]++;
    	}
    }

    int ans = 0;
    for (int prim = 0; prim < q; prim++) {

    	for (int j = v[prim].first; j <= v[prim].second; j++) {
 			cnt[j]--;
    	}
    	int sum = 0;
    	for (int j  = 0; j < n; j++) {
    		if (cnt[j] > 0)	
    			sum++;
    		//printf("%d ", cnt[j]);
    	}
    	//printf("%d", sum);
    	///printf("\n");
    	preffOnes[0] = 0;
    	for (int j = 0; j < n; j++) {
    		preffOnes[j + 1] = preffOnes[j] + ((cnt[j] == 1)? 1 : 0);
    		//printf("%d ", preffOnes[j + 1]);
    	}
    	//printf("\n");
    	int temp = 0;
    	for (int sec = prim + 1; sec < q; sec++) {
    		int L = v[sec].first;
    		int R = v[sec].second + 1;
    		temp = sum - (preffOnes[R] - preffOnes[L]);
    		ans = max(ans, temp);
    		//printf("%d\n", ans);
    	}
    	for (int j = v[prim].first; j <= v[prim].second; j++) {
 			cnt[j]++;
    	}
    }
    printf("%d", ans);

    return 0;
}

