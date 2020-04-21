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
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, q;
	SCD(n);
	SCD(q);
	int x, y;
	int bad = 0;
	int mat[5][n + 5];
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < q; i++) {
		SCD(x);
		SCD(y);
		bool forbidden = mat[x][y];
		mat[x][y] = (mat[x][y] > 0)? 0 : 1;
		int cnt = 0;
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i == x) continue;
				if (mat[i][j]) {
					if (forbidden) {
						bad++;
					}
					else {
						bad--;
					}
				} 
			}
		}
		puts((bad)? "No" : "Yes");
	}
    return 0;
}

