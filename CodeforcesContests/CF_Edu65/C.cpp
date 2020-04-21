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


const int N = 500005;

vector<int> group[N], vert_groups[N];
bool visited[N];
bool visitedG[N];
vector<int> component;
int sol[N];


void dfs(int a) {
	visited[a] = true;
	component.push_back(a);
	for (int x: vert_groups[a]) {
		if (!visitedG[x]) { 
			visitedG[x] = true;
			for (int v: group[x]) {
				if (!visited[v]) {
					dfs(v);
				}
			}
		}
	}
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif
	int n, m, sz, vertex;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &sz);
		for (int j = 0; j < sz; j++) {
			scanf("%d", &vertex);
			group[i].push_back(vertex);
			vert_groups[vertex].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			for (int member: component) {
				sol[member] = component.size();
			}
			component.clear();
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", sol[i]);
	}
	printf("\n");
    return 0;
}

