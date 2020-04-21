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
	string s;
	cin >> n;
	cin >> s;
	string s1 = "";
	if (n % 2 == 0) {
		int i = 0;
		while (i < n) {
			for (int j = i; j <= i + 1; j++) {
				s1 += s[j];
			}
			i += 2;
			if (i < n) 
				s1 += '-';
		}
	}
	else {
		int i = 0; 
		for (int j = 0; j < 3; j++) {
			s1 += s[j];
		}
		i = 3;
		if (i < n) s1 += '-';
		while (i < n){
			for (int j = i; j <= i + 1; j++) {
				s1 += s[j];
			}
			i += 2;
			if (i < n) 
				s1 += '-';
		}
	}
	cout << s1 << endl;
    return 0;
}

