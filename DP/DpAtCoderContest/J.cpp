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

const int N = 35;

double ev[N][N][N], p[N][N][N];

int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    int n, num;
    int cnt[4] = {0};
    SCD(n);
    for (int i = 0; i < n; i++) {
    	SCD(num);
   		cnt[num]++;
    }
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for (int c = n; c >= 0; c--) {
    	for (int b = n; b >= 0; b--) {
    		for (int a = n; a >= 0; a--) {
    			if (a == 0 && b == 0 && c == 0) continue;
    			if (a + b + c > n) continue;
    			double p_waste = (double) (n - (a + b + c)) / n;
    			double ev_waste = (double) p_waste / (1 - p_waste) + 1;
    			ev[a][b][c] += (double) ev_waste * p[a][b][c];


    			if (a != 0) { 
    				double p_go = (double) a / (a + b + c);
    				p[a - 1][b][c] += p[a][b][c] * p_go;
    				ev[a - 1][b][c] += ev[a][b][c] * p_go;
    			}
    			if (b != 0) {
    				double p_go = (double) b / (a + b + c);
    				p[a + 1][b - 1][c] += p[a][b][c] * p_go;
    				ev[a + 1][b - 1][c] += ev[a][b][c] * p_go;
    			}
    			if (c != 0) {
    				double p_go = (double) c / (a + b + c);
    				p[a][b + 1][c - 1] += p[a][b][c] * p_go;
    				ev[a][b + 1][c - 1] += ev[a][b][c] * p_go;
    			}
    		}
    	}
    }
    printf("%.10lf\n", ev[0][0][0]);

    return 0;
}

