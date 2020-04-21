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
const int N = 1e4 + 5;
int arr[N];
struct SegTree{int pref, suff, sum, maxsum;};
SegTree tree[N << 2];

SegTree merge(SegTree a, SegTree b) {
	SegTree ans;
	ans.sum = a.sum + b.sum;
	ans.maxsum = max(max(a.maxsum, b.maxsum), (a.suff + b.pref));
	ans.pref = max(a.sum + b.pref, a.pref);
	ans.suff = max(a.suff + b.sum, b.suff);	
	return ans;
}



void buildTree(int node, int low, int high) {
	if (low == high) {
		tree[node].pref = tree[node].suff = 
		tree[node].maxsum = tree[node].sum = arr[low];
		return;
	}
	int left = node << 1;
	int right = (node << 1) | 1;
	int mid = low + ((high - low) >> 1);

	buildTree(left, low, mid);
	buildTree(right, mid + 1, high);
	tree[node] = merge(tree[left],tree[right]);

}

SegTree query(int node, int low, int high, int left, int right) {
	if (left > high || right < low || left > right) {
		SegTree seg;
		seg.sum = 0;
		seg.maxsum = -INF;
		seg.pref = -INF;
		seg.suff = -INF;
		return seg;
	}
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
		freopen("errorf.txt", "w", stderr);
	#endif
	int t, n, x1, x2, y1, y2, q, ans;
	cin >> t;
	SegTree q1, q2, q3, q4;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cin >> q;
		buildTree(1, 0, n - 1);
		for (int i = 0; i < q; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;
			y1--;
			x2--;
			y2--;
			if (x2 > y1) {
				q1 = query(1, 0, n - 1, x1, y1);
				q2 = query(1, 0, n - 1, y1+1, x2-1);
				q3 = query(1, 0, n - 1, x2, y2);
				ans = q1.suff + q2.sum + q3.pref;
				/*cout << q1.suff << " " << q2.sum << " " << q3.pref << "\n";*/
			}
			else {
				q1 = query(1, 0, n - 1, x1, x2-1);
				q2 = query(1, 0, n - 1, x2, y1);
				q3 = query(1, 0, n - 1, y1+1, y2);
				q4 = query(1, 0, n - 1, x2, y2);
				int maxi = max(q2.maxsum, (q1.suff + q4.pref));
				ans = max((q2.suff + q3.pref), maxi);
				/*cout << q2.maxsum << " " << q1.suff << " " << q2.pref << " " <<
				  q2.suff << " " << q3.pref << " " << q2.sum << "\n";*/
			}	 
			//cerr << ans << "\n";
			cout << ans << "\n";
		}
	}

    return 0;
}

