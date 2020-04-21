#include <iostream>
 
using namespace std;
 
int main() {
    int N, ans = 0, x;
    scanf("%d", &N);
    for (int i  = 0; i < N; i++) {
        scanf("%d", &x);
        ans = ans + x - 1;
    }
    printf("%d\n", ans);
    return 0;
}
