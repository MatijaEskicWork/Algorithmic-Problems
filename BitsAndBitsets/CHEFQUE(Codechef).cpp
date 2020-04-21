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

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    bitset<10000005> bs;
    unsigned long long mod = (1LL << 32);
    int q;
    SCD(q);
    int a, b, s1;
    SCD(s1);
    SCD(a);
    SCD(b);
    long long sum = 0;
    long long s = s1;
    if (s & 1) {
    	bs.set(s/2);
    	sum += s/2;
    }
    else {
    	if (bs[s/2]) sum -= (s/2);
    	bs.reset(s / 2);
    }
    for (int i = 1; i < q; i++) {
    	//printf("%lld", s);
    	s = (a * s + b) % mod;
    	if (s & 1) {
    		bs.set(s/2);
    		sum += s/2;
    	}
    	else {
    		if (bs[s/2]) sum -= s/2;
    		bs.reset(s/2);
    	}

    }
    printf("%lld\n", sum);

    return 0;
}

