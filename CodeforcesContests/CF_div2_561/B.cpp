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

vector<int> facts;
unordered_map<int, int> factMap; 

void factors(int n) {
	int root = (int) floor(sqrt(n));
	int i = 2;
	while (n > 1 && i <= root) {
		if (n % i == 0) {
			facts.push_back(i);
			while (n % i == 0) {
				n /= i;
				factMap[i]++;
			}
		}
		i++;
	}
	if (n > 1) facts.push_back(n);
}



int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	factors(n);
	int size = facts.size();
	int m, k;
	string s = "aeoiu";
	bool OK = false;
	for (int i = 5; i < n; i++) {
		if (n % i == 0 && n / i >= 5) {
			OK = true;
			m = i;
			k = n / i;
			break;
		}
	}
	if (!OK) {
		cout << "-1" << endl;
		return 0;
	}

	for (int i = 6; i <= m; i++) {
		s += s[(int)s.length() - 5];
	}
	for (int j = 0; j < k; j++ ) {
		//shifting
		cout << s;
		s = s.substr(1) + s[0];
	}
    return 0;
}

