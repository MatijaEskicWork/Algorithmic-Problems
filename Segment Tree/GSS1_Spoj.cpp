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
const int N = 5e4 + 5;

int arr[N]; 
struct SegTree {int suff, pref, maxsum, sum;};
SegTree tree[N << 2];


// a is left, b is right
SegTree merge(SegTree a, SegTree b) {
	SegTree ans;
	ans.sum = a.sum + b.sum;
	ans.maxsum = max(max(a.maxsum, b.maxsum), (b.pref + a.suff));
	ans.pref = max(a.sum + b.pref, a.pref);
	ans.suff = max(a.suff + b.sum, b.suff);
	return ans;	
}


void buildSeg(int node, int low, int high) {
	if (low == high) {
		tree[node].suff = tree[node].pref = 
		tree[node].maxsum = tree[node].sum = arr[low];
		return;
	}
	int left = node << 1;
	int right = (node << 1) | 1;
	int mid = low + ((high - low) >> 1);
	buildSeg(left, low, mid);
	buildSeg(right, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
}

SegTree query(int node, int low, int high, int left, int right) {
	if (low == left && high == right) return tree[node];

	int l = node << 1;
	int r = (node << 1) | 1;

	int mid = low + ((high - low) >> 1);
	if (right <= mid) return query(l, low, mid, left, right);
	else if (left > mid) return query(r, mid + 1, high, left, right);
	else {

		return (merge(query(l, low, mid, left, mid), 
				query(r, mid + 1, high, mid + 1, right)));
	}
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n,q;
	SCD(n);
	for (int i = 0; i < n; i++) {
		SCD(arr[i]);
	}
	buildSeg(1, 0, n - 1);
	SCD(q);
	int l, r;
	for (int i = 0; i < q; i++) {
		SCD(l);
		SCD(r);
		l--;
		r--;
		printf("%d\n", query(1, 0, n -1, l, r).maxsum);	
	}
    return 0;
}

