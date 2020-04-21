#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8 + 7;
int mapa[50000];



void pour(int A, int B) {
  int move = 1, a = A, b = 0, tfr;
  int cnt = 0;
  mapa[a] = min(mapa[a], move);
  mapa[a+b] = min(mapa[a+b], move);
  mapa[b] = min(mapa[b], move);
  while (cnt != 10000) {
    mapa[a] = min(mapa[a], move);
    mapa[a+b] = min(mapa[a+b], move);
    mapa[b] = min(mapa[b], move);
    tfr = min(a, B - b);
    b += tfr;
    a -= tfr;
    move++;
    mapa[a] = min(mapa[a], move);
    mapa[a+b] = min(mapa[a+b], move);
    mapa[b] = min(mapa[b], move);
    if (a == 0) {
      a = A;
      move++;
    }
    if (b == B) {
      b = 0;
      move++;
    }
    cnt++;
  }
}
/** Reason for calculating GCD of a,b is to check whether an integral solution of 
 *  equation of form ax + by = c exist or not, to dig deeper read Diophantine Equations
 */
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main() {
  int t, a, b, c;
  #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorf.txt", "w", stderr);
  #endif
  scanf("%d%d", &a, &b);
  scanf("%d", &t);
  memset(mapa, INF, sizeof(mapa));
  pour(a,b);
  pour(b,a);
  int j = 1;
  while (t--) {
    scanf("%d", &c);
    printf("Case %d: ", j);
    if (c == 0) printf("0\n"); 
    else if (a == 0 || b == 0) {
    	if (c != a && c != b && c != a + b) {
    		printf("Damn!!\n");
    	}
    	else {
    		int maxi, mini;
    		if (a > b) {
    			maxi = a;
    			mini = b;
    		}
    		else {
    			maxi = b;
    			mini = a;
    		}
    		if (maxi + mini == 0 && c == 0) printf("0\n");
    		else if (maxi + mini != 0 && c == maxi) printf("1\n");
    	}
    }
    else if (c == 0) printf("0\n");
    else if (c > a + b) printf("Damn!!\n");
    /*if (c > a && c > b)
      printf("Damn!!\n");*/
    /*else if (c % gcd(a, b) != 0)
      printf("Damn!!\n");
    else if (c == a || c == b)
      printf("Damn!!\n");*/
    else if (c == a + b) {
          printf("2\n");
      }
      else {
        if (mapa[c] == INF || mapa[c] == 117901063) printf("Damn!!\n");
        else printf("%d\n", mapa[c]);
      }
      j++;
    }

  
  return 0;
}