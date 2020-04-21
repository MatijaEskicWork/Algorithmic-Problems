#include <bits/stdc++.h>
using namespace std;
#define BIGINF (int) 4e18 + 7
#define MOD7 1000000007
#define MOD9 1e9 + 9
#define INF  (int)2e9 + 7
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

int previous(vector<int> arr, int target,int start, int end)  {    
    int ans = -1;  
    while (start <= end) {  
        int mid = (start + end) / 2;  
        if (arr[mid] == target) {  
            return mid;  
        }  
        else if (arr[mid] > target) {
        	end = mid - 1;
        }
        else {  
            ans = mid;  
            start = mid + 1;  
        }  
    }  
    return ans;  
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n;
	SCD(n);
	int a;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		SCD(a);
		v.push_back(abs(a));
	}
	long long ans = 0;;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) continue;
		if (i > 0 && v[i] == v[i - 1]) {
			ans++;
		}
		int num = v[i] * 2;
		int diff =  upper_bound(v.begin(), v.end(), num) - 
					upper_bound(v.begin(), v.end(), v[i]);
		ans += diff;
		//printf("%d %d ", v[i], diff);
	}
	printf("%lld", ans);
    return 0;
}

