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
	//#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    //#endif
    int t;
    SCD(t);
    while (t--) {
    	int n, k;
        SCD(n);
        SCD(k);
        int sum = 0;
        int i;
        for (i = 1; i <= n; i++) {
            sum += i;
            if (sum >= k) {
                break;
            }
        }
        if (sum != k) {
            for (int j = n; j > i + 1; j--) {
                printf("a");
            }
            n = i + 1;
            printf("b");
            n--;
            int diff = sum - k;
            for (int j = diff; j > 0; j--) {
                printf("a");
            }
            n -= diff;
            n--;
            printf("b");
            for (int j = n; j > 0; j--) {
                printf("a");
            } 
            printf("\n");

        }
        else {
            for(int j = n; j > i + 1; j--) {
                printf("a");
            }
            n = i + 1;
            printf("bb");
            for (int j = n - 2; j > 0; j--) {
                printf("a");
            }
            printf("\n");
        }	
    }    

    return 0;
}

