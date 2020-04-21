
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
    int t;
    cin >> t;
    string s;
    while (t--) {
    	cin >> s;
    	int n = s.length();
    	int root = (int) sqrt(n);
    	int k;
    	if (root * root == n) {
    		k = root;
    	}
    	else {
    		k = root + 1;
    	}
    	int cnt = 0;
    	char mat[105][105];
    	for (int i = 0; i < k; i++) {
    		for (int j = 0; j < k; j++) {
    			if (cnt == n) mat[i][j] = '*';
    			else {
    				mat[i][j] = s[cnt];
    				cnt++;
    			}
    		}
    	}
    	int i;
    	int j;
    	string sol = "";
    	for (j = 0; j < k; j++) {
    		for (i = k - 1; i >= 0; i--) {
    			if (mat[i][j] != '*') sol += mat[i][j];
    		}
    	}
    	cout << sol << endl;
    }
    return 0;
}