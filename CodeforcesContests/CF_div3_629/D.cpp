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
int p[200005];
int a[200005];

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int t;
    SCD(t);
    while (t--) {
    	int n;	
  		SCD(n);
      int same = 1;
      unordered_map <int, int> m;
  		for (int i = 0; i < n; i++) {
  			SCD(a[i]);
        m[a[i]]++;
  		}
      if (m[a[0]] != n) same = 0;
  		int cnt = 1;
  		p[0] = 1;
      if (same) {
        cnt = 1;
        for (int i = 1; i < n; i++) {
          p[i] = p[i - 1];
        }
      }
      else if (n % 2 == 0) {
        cnt = 2;
        for (int i = 1; i < n; i++) {
            p[i] = i % 2 + 1;
        }
      }
      else {
        int first = 0;
        cnt = 2;
        for (int i = 1; i < n; i++) {
          if (a[i] != a[i - 1]) {
            p[i] = (p[i - 1] == 2)? 1 : 2; 
          }
          else {
            if (first) {
              p[i] = (p[i - 1] == 2)? 1 : 2;
            }
            else {first = 1;
              p[i] = p[i - 1];
            }
          }
        }
        if (!first && a[n - 1] != a[0]) {
          p[n - 1] = 3;
          cnt = 3;
        }
      }
      printf("%d\n", cnt);
  		for (int i = 0; i < n; i++) {
  			printf("%d ", p[i]);
  		}
  		printf("\n");
    }
    return 0;
}