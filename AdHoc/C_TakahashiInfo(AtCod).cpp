#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int mat[4][4];
    int a[3], b[3];
    bool OK = true;
    int pos1 = -1, pos2 = -1;
    for (int i  = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    a[0] = 0;
    b[0] = mat[0][0] - a[0];
    b[1] = mat[0][1] - a[0];
    b[2] = mat[0][2] - a[0];
    a[1] = mat[1][0] - b[0];
    a[2] = mat[2][0] - b[0];
    //if (OK) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i] + b[j] != mat[i][j]) {
                    OK = false;
                    break;
                }
            }
            if (!OK) break;
        }
    //}
    if (OK) printf("Yes\n");
    else printf("No\n");
    return 0;
}
