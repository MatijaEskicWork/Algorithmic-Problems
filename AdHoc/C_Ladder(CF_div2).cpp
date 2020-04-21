#include <iostream>
 
using namespace std;
 
int main()
{
    int n, m;
    int a[100005];
    int up[100005] = {0}, down[100005] = {0};
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] <= a[i - 1]) 
            down[i] = down[i - 1];
        else down[i] = i;
    }
    
    for (int i = n - 1; i > -1; i--) {
        if (i < n - 1 && a[i] <= a[i + 1])
            up[i] = up[i + 1];
        else up[i] = i;
    }
    
    
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l ,&r);
        if (up[l - 1] >= down[r - 1]) printf("Yes\n");
        else printf("No\n");
    }
 
    return 0;
}
