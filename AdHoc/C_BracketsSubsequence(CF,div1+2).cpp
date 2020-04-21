#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int start = 0, end = 0;
    int open = 0;
    int closed = 0;
    vector <char> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (closed * 2 + (open + 1) * 2 <= k) {
                open++;
                v.push_back('(');
            }
        }
        else if (s[i] == ')' && open > 0) {
            closed++;
            open--;
            v.push_back(')');
        }
    }
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}
