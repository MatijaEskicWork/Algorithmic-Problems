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
const int N = 1 << 17 + 5;
struct SegTree {long long sumor, sumxor;};
int arr[N];
SegTree tree[N];


SegTree merge(SegTree a, SegTree b) {
	SegTree ans;
	ans.sumor = (long long) a.sumxor | b.sumxor;
	ans.sumxor = (long long) a.sumor ^ b.sumor;
	return ans;
}


void buildTree(int node, int low , int high) {
	if (low == high) {
		tree[node].sumor = arr[low];
		tree[node].sumxor = arr[high];
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
	if (low == left && high == right) return tree[node];
	int l = node << 1;
	int r = l | 1;
	int mid = low + ((high - low) >> 1);
	if (right <= mid) return query(l, low, mid, left, right);
	else if (left > mid) return query(r, mid + 1, high, left, right);
	else {
		return(merge(query(l, low, mid, left, mid), query(r, mid + 1, high, mid + 1, right)));
	}
}

void update(int node, int pos, int val, int low, int high) {
	if (pos == low && low == high) {
		arr[pos] = val;
		tree[node].sumxor = val;
		tree[node].sumor = val;
		return;
	}
	int left = node << 1;
	int right = left | 1;
	int mid = low + ((high - low) >> 1);
	if (pos <= mid) update(left, pos, val, low , mid);
	else update(right, pos, val, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
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
	cin >> n >> q;
	int cpy = n;
	n = 1 << n;
	cerr << n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ind, val;
	buildTree(1, 0, n - 1);
	for (int i = 0; i < q; i++) {
		cin >> ind >> val;
		ind--;
		update(1, ind, val, 0, n - 1);
		SegTree ans = query(1, 0, n - 1, 0, n - 1);
		if (cpy & 1) {
			cout << ans.sumor << "\n";
		}
		else cout << ans.sumxor << "\n";
	}
    return 0;
}

