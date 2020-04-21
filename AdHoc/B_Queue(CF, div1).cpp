#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;



int main()
{
	vector<pair<int, int>> v;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(make_pair(x, i));
	}
	sort(v.begin(), v.end());
	int ans[100005] = { 0 };
	int ind = -1; 
	for (int i = 0; i < n; i++) {
		if (v[i].second > ind) {
			ans[v[i].second] = -1; // he's normal index is between ind and 0, and on a index ind is number that is the smallest until this number
			// so he is smaller than all elements of array ahead of him
			ind = v[i].second;
			// so index become this index as the biggest index of number smaller then him

		}
		else {
			ans[v[i].second] = ind - (v[i].second + 1);
		}


	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
