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
const int N = 1e5 + 5;
int arr[N];
struct SegTree {int mini;};
SegTree tree[N << 2];

SegTree merge(SegTree a, SegTree b) {
	SegTree ans;
	ans.mini = min(a.mini, b.mini);
	return ans;
}


void buildTree(int node, int low, int high) {
	if (low == high) {
		tree[node].mini = arr[low];
		return;
	}
	int left = node << 1;
	int right = left | 1;
	int mid = low + ((high - low) >> 1);
	buildTree(left, low , mid);
	buildTree(right, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
}

SegTree query(int node, int low, int high, int left, int right) {
	/*if (right < low || left > high || left > right) {
		SegTree ret;
		ret.mini = -1;
		return ret;
	}*/
	if (low == left && high == right) return tree[node];
	int l = node << 1;
	int r = l | 1;
	int mid = low + ((high - low) >> 1);

	if (right <= mid) return query(l, low, mid, left, right);
	else if (left > mid) return query(r, mid + 1, high, left, right);
	else {
		return merge(query(l, low, mid, left, mid), query(r, mid + 1, high, mid + 1, right));
	}

}


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
		freopen("errorf.txt", "w", stderr);
	#endif
	int n, q;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	buildTree(1, 0, n - 1);
	cin >> q;
	int l,r;
	for(int i = 0; i < q; i++) {
		cin >> l >> r;
		if (l > r) swap(l, r);
		cout << query(1, 0, n - 1, l, r).mini << "\n";
	}
    return 0;
}

