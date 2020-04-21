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


using namespace std;
const int MAX_SIZE = 1000005;

long long table[MAX_SIZE];

//update position pos by mod in BIT of size -> size
void update(int size, int pos, int mod) {
	while (pos < size) {
		table[pos] += mod;
		pos += (pos & (-pos));
	}
}

int walkBIT(int max1, int kth) {
	int high = 1;
	while (high < max1) {
		high *= 2;
	}
	int diff = high;
	int ans;
	while (diff > 1) {
		if (table[high] >= kth) {
			diff /= 2;
			high -= diff;
		}
		else {
			kth -= table[high];
			diff /= 2;
			high += diff;
		}
	}
	if (table[high] == kth) ans = high;
	else if (table[high] > kth) ans = high - 1;
	else ans = high + 1;
	return ans;


}



int main() {

	int t, n;
	long long ans;


	scanf("%d", &t);
	int height, kth;
	long long numberOfPeople;
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		ans = 0;
		int max1 = 0;
		memset(table, 0, sizeof(table));
		for (int j = 0; j < n; j++) {
			scanf("%d%lld", &height, &numberOfPeople);
			max1 = max(height, max1);
			update(MAX_SIZE, height, numberOfPeople);
		}
		for (int j = 0; j < max1 + 1; j++) {
			printf("%lld\n", table[j]);
		}
		scanf("%d", &kth);
		ans = walkBIT(max1, kth);
		printf("%lld\n", ans);
	}

	return 0;
}
