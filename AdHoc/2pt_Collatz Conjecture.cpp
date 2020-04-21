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
    while (1) {
    	unordered_map <long long, int> m, m2;
    	long long a,b, meet;
    	SCLLD(a);
    	SCLLD(b);
    	long long cpya = a, cpyb = b;
    	//printf("%lld %lld\n", cpya, cpyb);
    	if (a == b && a == 0) break;
    	int sa;
    	int sb;
    	m[a] = -1;
    	int sum = 10000000;
    	for (int i = 0; i < 1000; i++) {
    		if (a == 1) break;
    		if (a & 1LL) {
    			a = 1LL * a * 3 + 1;
    		}
    		else a = a / 2;
    		if (m[a]) continue;
    		m[a] = i + 1;
    		if (a == 1) {
    			break;
    		}
    	}
    	if (m[b]) {
    		sa = ((m[b] == -1)? 0 : m[b]);
    		sb = 0; 
    		meet = b;
    		sum = max(sa, sb);
    	}
    	for (int i = 0; i < 1000; i++) {
    		if (b == 1) break;
    		if (b & 1LL) {
				b = 1LL * b * 3 + 1;
			}
			else b = b / 2;
			if (m2[b] && b != 1) continue;
			else if (m2[b] && b == 1) break;
			if (m[b]) {
				int l = (m[b] == -1)? 0: m[b]; 
				int max1 = max(l, i + 1);
				if (max1 < sum) {  
					sum = max1;
					sa = ((m[b] == -1)? 0 : m[b]);
					sb = i + 1;
					meet = b;
				}
			}
			m2[b] = i + 1;
			if (b == 1) {
				break;
			}	
		}
    	printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n", cpya, sa, cpyb, sb, meet);

    }
    return 0;
}