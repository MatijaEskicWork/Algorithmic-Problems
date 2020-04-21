#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAX_SIZE = 10000005;

long long table[MAX_SIZE];

//update position pos by mod in BIT of size -> size
void update(int size, int pos, int mod) {
	while (pos < size) {
		table[pos] += mod;
		pos += (pos & (-pos));
	}
}

long long prefixSum(int pos) {
	long long sum = 0;
	while (pos > 0) {
		sum += table[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

//sum of elements between i and j index, where i < j
long long rangeSum(int i, int j) {
	return prefixSum(j) - prefixSum(i);
}



int main() {

	int t, n;
	long long ans;


	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int x;
		ans = 0;
		int max1 = 0;
		memset(table, 0, sizeof(table));
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			max1 = max(x, max1);
			//table[x] = 1;
			update(MAX_SIZE, x, 1);
			ans += rangeSum(x, max1);
		}

		//ans = prefixSum(max1);
		printf("%lld\n", ans);
	}

	return 0;
}
