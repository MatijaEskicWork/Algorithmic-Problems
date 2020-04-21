#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.length();
    bool OK = false;
    int pos1 = -1, pos2 = -1;
    for (int i  = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            OK = true;
            pos1 = i + 1;
            pos2 = i + 2;
            break;
        }
    }
    
    if (n > 2 && !OK) {
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 2]) {
                pos1 = i + 1;
                pos2 = i + 3;
                break;
            }
        }
    }
    printf("%d %d\n", pos1, pos2);
    return 0;
}
