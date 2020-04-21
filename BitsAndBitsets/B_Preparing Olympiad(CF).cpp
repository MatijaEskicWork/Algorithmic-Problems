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
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, L, R, x;
   	cin >> n >> L >> R >> x;
   	bitset<1<<16> mask;
   	int prefix[100];
   	int a[100];
   	prefix[0] = 0;
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   	}
   	int ans = 0;

   	for (int bs = 1; bs <= 1 << n; bs++) {
   		mask = bs;
   		int sum = 0;
   		int min1 = INF;
   		int max1 = 0;
   		for (int i = 0; i < 15; i++) {
   			if (mask[i]) {
   				sum += a[i];
   				min1 = min(min1, a[i]);
   				max1 = max(max1, a[i]);
   			}
   		}
   		if (sum >= L && sum <= R && max1 - min1 >= x) {
   			ans++;
   		}
   	} 	
   	printf("%d\n", ans);
    return 0;
}

