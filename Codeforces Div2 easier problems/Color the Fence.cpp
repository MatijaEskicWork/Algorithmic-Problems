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
	cin >> n;
	int d[10], div[10];
	for (int i = 1; i <= 9; i++) {
		cin >> d[i];
		div[i] = n / d[i];
	}
	bool zero = true;
	for (int i = 1; i <= 9; i++) {
		if (div[i] != 0) {
			zero = false;
			break;
		}
	}
	if (zero) printf("-1\n");
	else {
		int max1 = 0;
		int digit = 0;
		for (int i = 1; i <= 9; i++) { 
			if (div[i] > max1) {
				digit = i;
				max1 = div[i];
			}
		}
		string s = "";
		char ch[] = {'0', '1', '2', '3', '4', '5',
				   '6', '7', '8', '9'};
		for (int i = 0; i < max1; i++) {
			s += ch[digit];
		}
		int k = s.length();
		int rest = n % d[digit];
		rest = rest + d[digit];
		for (int i = 0; i < k; i++) {
			for (int j = 9; j > digit; j--) {
				if (d[j] <= rest) {
					rest -= d[j];
					rest += d[digit];
					s[i] = ch[j];
					break;
				}
			}
		}
		cout << s << endl;
	}
    return 0;
}

