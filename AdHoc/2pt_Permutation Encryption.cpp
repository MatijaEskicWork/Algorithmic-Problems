#include <bits/stdc++.h>
using namespace std;
#define MOD7 1000000007
#define MOD9 1e9 + 9
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

const long long BIGINF = 2e18 + 7;
const int INF = 2e9 + 7;


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	int p[100];
	while (1) {
		char m[300][200];
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 200; j++){
				m[i][j] = ' ';
			}
		}
		char s[1000];
		SCD(n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			SCD(p[i]);
		}
		char ch;
		getchar();
		int len = 0;
		while ((ch = getchar()) != '\n') {
			s[len++] = ch;
		}
		int count = 0;
		for (int i = 0; i < len; i++) {
			if ( (i + 1) % n == 0) {
				m[n][count] = s[i];
				count++;
				continue;
			}
			m[(i+1) % n][count] = s[i];
			//if ((i+1) % n == 0) count++;
		}
		//printf("%s", s);
		int cnt = 0;
		count = 0;
		printf("'");
		if (len % n != 0) len = (len / n) * n + n;
		//printf("%d", len);
		while (cnt < len) {
			int ind = p[cnt % n];
			printf("%c", m[ind][count]);
			if (cnt % n == n - 1) count++;
			cnt++;
		}	
		puts("'");
	}
    return 0;
}

