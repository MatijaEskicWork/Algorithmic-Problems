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
struct SegTree {bitset<28> mask; int cnt;};

SegTree tree[N << 2];
string arr;

SegTree merge(SegTree a, SegTree b) {
	SegTree ans;
	ans.mask = a.mask | b.mask;
	ans.cnt = ans.mask.count();
	return ans;
}


void buildTree(int node, int low, int high) {
	if (low == high) {
		tree[node].cnt = 1;
		int num = (int) arr[low] - 'a';
		tree[node].mask[num] = 1;
		//cerr << tree[node].mask << endl;
		return;
	}
	int left = node << 1;
	int right = left | 1;
	int mid = low + ((high - low) >> 1);
	buildTree(left, low, mid);
	buildTree(right, mid + 1, high);
	tree[node] = merge(tree[left], tree[right]);
	//cerr << tree[node].mask << endl;
	//cerr << tree[left].mask << endl << tree[right].mask << endl;
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



void update(int node, int pos, char val, int low, int high) {
	if (pos == low && low == high) {
		arr[pos] = val;
		int num = (int) val - 'a';
		tree[node].mask &= 0;
		tree[node].mask[num] = 1;
		tree[node].cnt = 1;
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
	int q;
	cin >> arr;
	//cout << arr;
	//printf("%s", arr);
	int n = arr.length();
	cin >> q;
	//printf("%d", q);
	int code;
	char ch;
	int l, r, pos;
	buildTree(1, 0, n - 1);
	for (int i = 0; i < q; i++) {
		cin >> code;
		if (code == 1) {
			cin >> pos >> ch;
			//cerr<< pos << " " << ch << endl;
			pos--;
			update(1, pos, ch, 0, n - 1);
		}
		else {
			cin >> l >> r;
			//cerr << l << " " << r << endl;
			l--;
			r--;
			SegTree x = query(1, 0, n - 1, l, r);
			cout << (int)x.cnt << endl;
		}
	}
	
    return 0;
}

