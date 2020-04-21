#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> s;
    n = s.length();
    int curr = 1, max1 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            curr++;
        }
        else if (s[i] == s[i + 1]) {
            if (curr > max1) {
                max1 = curr;
            }
            curr = 1;
        }
    }
    if (curr > max1) max1 = curr;
    
    int left = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            left = i + 1;
            break;
        }
    }
    
    int right = 0;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == s[i - 1]) {
            right = n - i;
            break;
        }
    }
    int sec_ans = 0;
    if (s[0] != s[n - 1]) sec_ans = right + left;
    int ans = max(max1, sec_ans);
    cout << ans;
    return 0;
}
