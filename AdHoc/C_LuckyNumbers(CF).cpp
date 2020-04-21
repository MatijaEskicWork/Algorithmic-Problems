#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
 
 
 
int main()
{
	int n; 
	scanf("%d", &n);
	long long ans = 0;
	long long power = 2;
	for (int i = 1; i <= n; i++) {
		ans += power;
		power *= 2;
	}
	printf("%lld\n", ans);
 
	return 0;
}
