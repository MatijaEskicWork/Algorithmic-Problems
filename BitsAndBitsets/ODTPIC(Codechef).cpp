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

bitset<4005> prefix_a[1005], prefix_b[1005], mask;

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);	
    int x,n,m,q,l1,l2,r1,r2;
    SCD(n);
    SCD(m);
    SCD(q);
    prefix_a[0] = 0;
    prefix_b[0] = 0;
    for (int i = 1; i <= n; i++) {
    	SCD(x);
    	prefix_a[i] = prefix_a[i - 1];
    	prefix_a[i][x] = !prefix_a[i - 1][x];
    }
    for (int j = 1; j <= m; j++) {
    	SCD(x);
    	prefix_b[j] = prefix_b[j - 1];
    	prefix_b[j][x] = !prefix_b[j - 1][x];
    }
    for (int i = 0; i < q; i++) {
    	SCD(l1);
    	SCD(r1);
    	SCD(l2);
    	SCD(r2);
    	mask = prefix_a[r1] ^ prefix_a[l1-1] ^ prefix_b[r2] ^ prefix_b[l2-1]; 
   		printf("%u\n", mask.count()); 
    }

    return 0;
}


