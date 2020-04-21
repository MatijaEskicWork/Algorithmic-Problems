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

vector<pair<int, int>> pairs;
unordered_map<int, int> m;
vector<pair<int, int>> mapa(1000005);

int next(int target, int start, int end) { 
    int ans = -1; 
    while (start <= end) { 
        int mid = (start + end) / 2;  
        if (pairs[mid].second == target)
            return mid;
        else if (pairs[mid].second < target) 
            start = mid + 1;  
        else { 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
    return ans; 
}



int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
    int n, q;
    SCD(n);
    SCD(q);
    int x, l, r, p, k;
    for (int i = 0; i < n; i++) {
    	SCD(x);
    	pairs.push_back(make_pair(x,i));
    }
    sort(pairs.begin(), pairs.end());
    for (int i = 0; i < n; i++) {
    	if (i != 0) {
    		if (pairs[i - 1].first == pairs[i].first) {
    			m[pairs[i].first]++;
                mapa[pairs[i].first].second = i;
    		}
    		else {
                mapa[pairs[i - 1].first].second = i - 1;
                m[pairs[i].first]++;
                mapa[pairs[i].first].first = i;
            }
    	}
    	else {
    		m[pairs[i].first]++;
            mapa[pairs[i].first].first = i;
    	}
    }
    mapa[pairs[n - 1].first].second = n - 1;
    /*for (int i = 0; i < n; i++) {
        printf("%d %d %d %d\n",pairs[i].first, pairs[i].second, mapa[pairs[i].first].first, mapa[pairs[i].first].second);
    }*/

    for (int i = 0; i < q; i++) {
    	SCD(l);
    	SCD(r);
    	SCD(p);
    	SCD(k);
        l--;
        r--;
        int L = mapa[p].first;
        int R = mapa[p].second;
    	int first = next(l, L, R);
        if (first == -1 || first + k - 1 > n - 1) printf("-1\n");
        else {
            if (pairs[first + k - 1].first == p && 
                pairs[first + k - 1].second <= r)
                printf("%d\n", pairs[first + k - 1].second + 1);
            else printf("-1\n");
        }
    }
    return 0;
}

