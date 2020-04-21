#include <iostream>
#include <cmath>
 
using namespace std;
 
bool isPrime(int x) {
    int root = (int)sqrt(x);
    for (int i = 2; i <= root; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
 
 
int main()
{
    int n;
    scanf("%d", &n);
    printf("2 ");
    int ans = n - 1;
    int cnt = 3;
    while (ans) {
        if (isPrime(cnt) && cnt % 5 == 1) {
            printf("%d ", cnt);
            ans--;
        }
        cnt++;
    }
    return 0;
}

