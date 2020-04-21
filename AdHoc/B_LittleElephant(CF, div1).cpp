#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
 
 
int ans[100005] = {0}, a[100005], l[100005], r[100005], shows[100005] = { 0 };
 
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 100005)
		    shows[a[i]]++;
	}
	for (int i = 1; i < 100005; i++) {
 
		if (shows[i] >= i) {
			int prefix[100005] = { 0 };
			for (int j = 1; j <= n; j++) {
				if (a[j - 1] == i) prefix[j] = prefix[j - 1] + 1;
				else prefix[j] = prefix[j - 1];
			}
 
			for (int j = 0; j < m; j++) {
				if (prefix[r[j]] - prefix[l[j] - 1] == i) {
					ans[j]++;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}
 
	return 0;
}
