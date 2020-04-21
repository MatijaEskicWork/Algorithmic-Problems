#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
 
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
 
int main()
{
	int t;
	int n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(make_pair(x, i));
		}
		int ans = 0;
		sort(v.begin(), v.end(), cmp);
		int ind = -1;
		for (int i = 0; i < n; i++) {
			//cout << v[i].first << " " << v[i].second << endl;
			if (v[i].second < ind) ans++;
			if (v[i].second > ind) ind = v[i].second;
		}
		cout << ans << endl;
	}
	return 0;
}
 
