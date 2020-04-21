#include <bits/stdc++.h>
using namespace std;
#define MOD7 1000000007
#define MOD9 1e9 + 9
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

const long long BIGINF = 2e18 + 7;
const int INF = 2e9 + 7;

char mat[30][30];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int h, w;

bool OK(int row, int col) {
	return (row >= 0 && row < h && col >= 0 && col < w
			&& mat[row][col] == '.');
}


int main () {
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
		freopen("errorf.txt", "w", stderr);
	#endif
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> mat[i];
		//cerr << mat[i] << endl;	
	}
	int ans = 0;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (OK(row, col)) {
				vector<pair<int, int>> queue;
				queue.emplace_back(row, col);
				vector<vector<int>> distance(h + 1, vector<int>(w + 1));
				vector<vector<bool>> visited(h + 1, vector<bool>(w + 1));
				visited[row][col] = true;
				for (int i = 0; i < (int)queue.size(); i++) {
					pair<int, int> curr = queue[i];
					for (int direction = 0; direction < 4; direction++) {
						int new_row = curr.first + dx[direction];
						int new_col = curr.second + dy[direction];
						if (OK(new_row, new_col) && !visited[new_row][new_col]) {
							distance[new_row][new_col] = distance[curr.first][curr.second] + 1;
							queue.emplace_back(new_row, new_col);
							visited[new_row][new_col] = true;
							ans = max(ans, distance[new_row][new_col]);
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

