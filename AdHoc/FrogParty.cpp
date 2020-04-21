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

string s;


int orientation(int pos, int n) {
	int from_left = pos - 1;
	int from_right = n - pos;
	if ((from_left == from_right) || (abs(from_left - from_right) <= 1 && n % 2 == 0)) {
		return 0; // michal is center of whole set
	}
	else if (from_left < from_right) {
		return 1; // michal is center of left set	
	}
	return 2; // michal is center of right set
}

void jump(int &i, int diff, bool &right) {
	if (right) {
		printf("%d %d\n" ,i , i + diff);
		i += diff;
	}
	else {
		printf("%d %d\n" ,i , i - diff);
		i -= diff;
	}
	right = !right;
}



int main () {
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
    #endif
    int t;
    SCD(t);
    int n, m, curr_pos, count ;
    bool right;
    while (t--) {
    	SCD(n);
    	SCD(m);
    	if (n == 1) {
    		printf("YES\n");
    		continue;
    	}
    	printf("YES\n");
    	//the hardest case: when i have to split it into two parts
    	if (m > 1 && m < n) {
    		int orient = orientation(m, n);
    		if (!orient) {
    			count = 1;
    			if (m <= (n+1) / 2) right = true;
    			else right = false;
    			curr_pos = m;
    			while (count != n) {
    				jump(curr_pos, count, right);
    				count++;
    			}

    		}
    		else if (orient == 1) {
    			count = 1;
    			int high = 2 * m - 1;
    			right = true;
    			curr_pos = m;
    			while (count != high) {
    				jump(curr_pos, count, right);
    				count++;
    			}
    			count = 1;
    			curr_pos = m * 2 + (n - (2 * m - 1))/ 2;
    			int rest = n - (m * 2 - 1);
    			right = rest & 1;
    			while (count != rest) {
    				jump(curr_pos, count, right);
    				count++;
    			}
    			curr_pos = 1;
    			right = true;
    			jump(curr_pos, m * 2 - 1, right);
    		}
    		else {
    			count = 1;
    			int low = n - ((n - m) * 2);
    			int rest = n - low + 1;
    			right = (rest & 1)? 0 : 1;
    			curr_pos = m;
    			count = 1;
    			while (count != rest){
    				jump(curr_pos, count, right);
    				count++;
    			}
    			rest = low - 1;
    			curr_pos = (rest + 1) / 2;
    			count = 1;
    			right = (rest & 1)? 0 : 1; 
    			while (count != rest) {
    				jump(curr_pos, count, right);
    				count++;
    			}
    			right = false;
    			jump(n, n - low + 1, right);
    		}	
    	}
    	//everyone will jump and they will be on the position next to michal on the left
    	else if (m == 1) {
    		int all = n - 1;
    		curr_pos = 2 + (n - 1) / 2;
    		right = (n - 1) & 1;
    		count = 1;
    		while (count != all) {
    			jump(curr_pos, count, right);
    			count++;
    		}
    		if (n != 1) {
    			curr_pos = 1;
    			right = true;
    			jump(curr_pos, 1, right);
    		}
    	}
    	//everyone will jump and they will be on the position next to michal on the right
    	else {

    		int all = n - 1;
    		curr_pos = n / 2;
    		right = ((n - 1) & 1)? 0 : 1;
    		count = 1;
    		while (count != all) {
    			jump(curr_pos, count, right);
    			count++;
    		}
    		if (n != 1) {
    			curr_pos = n;
    			right = false;
    			jump(curr_pos, 1, right);
    		}
    	}
    	//printf("%s", s);
    }
    return 0;
}