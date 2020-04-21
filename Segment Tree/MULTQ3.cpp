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
struct SegTree {int cnt1, cnt2, cnt3; int prop;};
SegTree tree[N << 2];



void push(int node, int l, int r) {
	int prop = tree[node].prop;
	tree[l].prop += prop;
	tree[r].prop += prop;
	tree[node].prop = 0;
	prop = prop % 3;
	int tmp1, tmp2, tmp3;
	if (prop == 2) {
		tmp3 = tree[l].cnt3;
		tmp2 = tree[l].cnt2;
		tmp1 = tree[l].cnt1;
		tree[l].cnt3 = tmp1;
		tree[l].cnt1 = tmp2;
		tree[l].cnt2 = tmp3;
		tmp3 = tree[r].cnt3;
		tmp2 = tree[r].cnt2;
		tmp1 = tree[r].cnt1;
		tree[r].cnt3 = tmp1;
		tree[r].cnt1 = tmp2;
		tree[r].cnt2 = tmp3; 
	}
	else if (prop == 1) {
		tmp3 = tree[l].cnt3;
		tmp2 = tree[l].cnt2;
		tmp1 = tree[l].cnt1;
		tree[l].cnt3 = tmp2;
		tree[l].cnt1 = tmp3;
		tree[l].cnt2 = tmp1;
		tmp3 = tree[r].cnt3;
		tmp2 = tree[r].cnt2;
		tmp1 = tree[r].cnt1;
		tree[r].cnt3 = tmp2;
		tree[r].cnt1 = tmp3;
		tree[r].cnt2 = tmp1;
	}
}

SegTree merge(SegTree a, SegTree b) {
	SegTree res;
	res.cnt3 = a.cnt3 + b.cnt3;
	res.cnt2 = a.cnt2 + b.cnt2;
	res.cnt1 = a.cnt1 + b.cnt1;
	res.prop = 0;
	return res;
}


void buildTree(int node, int low, int high) {
	if (low == high) {
		tree[node].cnt3 = 1;
		tree[node].cnt2 = 0;
		tree[node].cnt1 = 0;
		tree[node].prop = 0;
		return;
	}
	int left = node << 1;
	int right = left | 1;
	int mid = low + ((high - low) >> 1);
	buildTree(left, low, mid);
	buildTree(right, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
}

SegTree query(int node, int low, int high, int left, int right) {
	if (low == left && right == high) return tree[node];

	int l = node << 1;
	int r = l | 1;	
	int mid = low + ((high - low) >> 1);
	if (tree[node].prop != 0)
		push(node, l, r);

	if (right <= mid) return query(l, low, mid, left, right);
	else if (left > mid) return query(r, mid + 1, high, left, right);
	else {
		return merge(query(l, low, mid, left, mid), query(r, mid + 1, high, mid + 1, right));
	}
}

void update(int node, int low, int high, int left, int right) {
	//if (left > right) return;
	if (low == left && right == high) {
		tree[node].prop++;
		int tmp;
		tree[node].prop %= 3;
		tmp = tree[node].cnt3;
		tree[node].cnt3 = tree[node].cnt2;
		tree[node].cnt2 = tree[node].cnt1;
		tree[node].cnt1 = tmp;
		//}
		return;
	}
		int l = node << 1;
		int r = l | 1;
		int mid = low + ((high - low) >> 1);
		if (tree[node].prop != 0)
			push(node, l, r);
		if (right <= mid) update(l, low, mid, left, right);
		else if (left > mid) update(r, mid + 1, high, left, right);
		else {
			update(l, low, mid, left, mid); 
			update(r, mid + 1, high, mid + 1, right);
		}
        tree[node] = merge(tree[l], tree[r]);
       
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
		freopen("errorf.txt", "w", stderr);
	#endif
	int n, q, left, right, code;
	cin >> n >> q;
	buildTree(1, 0, n - 1);
	for (int i = 0; i < q; i++) {
		cin >> code >> left >> right;
		if (code == 0) {
			update(1, 0, n - 1, left, right);
		}
		else {
			cout << query(1, 0, n - 1, left, right).cnt3 << "\n";
		}
	}
    return 0;
}

