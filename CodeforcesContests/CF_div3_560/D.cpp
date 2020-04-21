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
    int t;
    SCD(t);
    while (t--) {
    	int n, a;
    	vector<int> v;
    	SCD(n);
    	for (int i = 0; i < n; i++) {
    		SCD(a);
    		v.push_back(a);	
		}
		sort(v.begin(), v.end());
		int end = n / 2;
		long long guessed;
		guessed = 1LL * v[0] * v[n - 1];
		bool OK = true;
		//printf("%lld ", guessed);
		for (int i = 0; i < end; i++) {
			long long tmp = 1LL * v[i] * v[n - (i + 1)];
			if (v[i] == 1) {
				OK = false;
				break;
			}
			if (guessed != tmp) {
				OK = false;
				break;
			}
		}
		//printf("%d ", (int)OK);
		if (n & 1) {
			int num = v[end];
			//printf("%d ", num);
			if (1LL * num * num != guessed){
				OK = false;
			}
		}
		int cnt = 0;
		int root = (int)sqrt(guessed);
		for (int i = 1; i <= root; i++) {
			if (guessed % i == 0) {
				cnt += 2;
			}
		}
		if (1LL * root * root == guessed) cnt--;
		if (cnt - 2 != n) OK = false;

		if (OK) {
			printf("%lld\n", guessed);
		}
		else printf("-1\n");
    }
    return 0;
}