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



const int N = (int) 1e6 + 5;

int high[4*N + 1] = {0}, low[4*N + 1] = {0}; // 2*N because it can be unbalanced
int _min[4*N + 1], delta[4*N + 1];

void init(int i, int a, int b) {
	low[i] = a;
	high[i] = b;

	if (a == b) return;

	int mid = (a + b)/2;
	init(2 * i, a, mid);
	init(2 * i + 1, mid + 1, b);
}

void propagate(int i) {
	delta[2 * i] += delta[i];
	delta[2 * i + 1] += delta[i];
	delta[i] = 0;
}

void update(int i) {
	_min[i] = min(_min[2*i] + delta[2*i],
				_min[2*i+1] + delta[2*i+1]);
}


void increment(int i, int a, int b, int val) {
	if (b < low[i] || high[i] < a) return;

	// Whole cover, it is whole in a range
	if (a <= low[i] && high[i] <= b) {
		delta[i] += val;
		return;
	}

	propagate(i);

	increment(2*i, a, b, val);
	increment(2*i+1, a, b, val);

	update(i);

} 

int minimum(int i, int a, int b) {
	if (b < low[i] || high[i] < a) 
			return INF;
	if (a <= low[i] && high[i] <= b)
		return _min[i] + delta[i];

	propagate(i);

	int minLeft = minimum(2*i, a, b);
	int minRight = minimum(2*i+1, a, b);

	update(i);

	return min(minLeft, minRight);

}





int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int n; 
    cin >> n;
    init(1, 0, n - 1);
    int q, l, r, val;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		cin >> l >> r >> val;
    		increment(1, l, r, val);
    	}
    	else {
    		cin >> l >> r;
    		printf("minimum[%d, %d] je %d\n", l, r, minimum(1, l, r));
    	}
    }  
    return 0;
}

