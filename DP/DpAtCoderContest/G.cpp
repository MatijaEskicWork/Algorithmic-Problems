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

int N = 10005;
bool visited[10005];
int dp[10005];
int inDegree[10005];
vector<int> graph[10005];

void dfs(int vertex) {
	visited[vertex] = true;
	int size = graph[vertex].size();
	for (int i = 0; i < size; i++) {
		int a = graph[vertex][i];
		dp[a] = max(dp[a], dp[vertex] + 1);
		inDegree[a]--;
		if (inDegree[a] == 0) dfs(a);
	} 
}


int main () {
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    int n,m;
    SCD(n);
    SCD(m);
    int x, y;
    memset(dp, 0, sizeof(dp));
    memset(visited, false, sizeof(dp));
    for (int i = 0; i < m; i++) {
    	SCD(x);
    	SCD(y);
    	graph[x].push_back(y);
    	inDegree[y]++;
    }

    for (int i = 1; i <= n; i++) {
    	if (!visited[i] && inDegree[i] == 0) dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}

