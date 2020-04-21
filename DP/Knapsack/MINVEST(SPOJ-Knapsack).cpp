#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define MOD1 1e9 + 7
#define MOD2 1e9 + 9
#define inf  (int)2e9 + 7
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef long long ll;
typedef string str;
typedef double d;
typedef unsigned u;
typedef unsigned long long ull;




int main()
{
    int t, years, n;
    ll start;
    int v[1000][2] = { 0 };
    SCD(t);
    int cost, ann_interest;
    int dp[100000] = { 0 };
    for (int k = 0; k < t; k++) {
        SCLLD(start);
        SCD(years);
        SCD(n);
        MEM(dp, 0);
        MEM(v, 0);
        int start_div1000 = start / 1000;
        for (int i = 0; i < n; i++) {
            SCD(cost);
            SCD(ann_interest);
            v[i][0] = cost;
            v[i][1] = ann_interest;
        }
        for (int i = 0; i < years; i++) {
            int j = 0;
            while (j <= start_div1000) {
                for (int l = 0; l < n; l++) {
                    if (j >= (v[l][0] / 1000) && dp[j - v[l][0] / 1000] + v[l][1] > dp[j]) {
                        dp[j] = dp[j - v[l][0] / 1000] + v[l][1];
                    }
                }
                j++;
            }
            start = start + dp[start_div1000];
            start_div1000 = start / 1000;
        }
        printf("%lld\n", start);
    }

    return 0;
}
