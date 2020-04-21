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
struct SegTree{long long sum; int cnt = 0;};
long long arr[N];
SegTree tree[N << 2];


SegTree merge(SegTree a, SegTree b) {
	SegTree res;
	res.sum = a.sum + b.sum;
	return res;
}

void buildTree(int node, int low, int high) {
	if (low == high) {
		tree[node].sum = arr[low];
		return;
	}
	int left = node << 1;
	int right = (node << 1) | 1;
	int mid = low + ((high - low) >> 1);

	buildTree(left, low, mid);
	buildTree(right, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
}


SegTree query(int node, int low, int high, int left, int right) {
	if (low == left && right == high) return tree[node];
	int l = node << 1;
	int r = (node << 1) | 1;
	int mid = low + ((high - low) >> 1);
	if (right <= mid) return query(l, low, mid, left, right);
	else if (left > mid) return query(r, mid + 1, high, left ,right);
	else {
		return merge(query(l, low, mid, left, mid), 
				query(r, mid + 1, high, mid + 1, right));
	}
}

void update(int node, int low, int high, int left, int right) {
	if (tree[node].sum == high - low + 1) return;
	if (low == high) {
		tree[node].sum = floor(sqrt(tree[node].sum));
		return;
	}
	int l = node << 1;
	int r = (node << 1) | 1;
	int mid = low + ((high - low) >> 1);
	if (right <= mid) update(l, low, mid, left, right);
	else if (left > mid) update(r, mid + 1, high, left, right);
	else {
		update(l , low, mid, left, mid);
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
	int n, q, code, x, y;
	int j = 1;
	while(cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cin >> q;
		buildTree(1, 0, n - 1);
		cout << "Case #" << j << ":" << "\n";
 		for (int i = 0; i < q; i++) {
			cin >> code >> x >> y;
			x--;
			y--;
			if (x > y) swap(x, y);
			if (code) {
				cout << query(1, 0, n - 1, x, y).sum << "\n";
				//printf("%lld\n", query(1, 0, n - 1, x, y).sum);
			}
			else {
				update(1, 0, n - 1, x, y);
			}
		}
		j++;
	}
    return 0;
}

