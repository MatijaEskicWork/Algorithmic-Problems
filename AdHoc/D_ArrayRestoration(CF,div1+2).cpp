#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector <int> v;
    int max1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        max1 = max(x, max1);
    }
    set<int> s;
    int hash[200005] = {0};
    vector <pair<int, int>> range(200005);
    bool OK = true;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            int j = i;
            while(v[j] == 0 && j < n) {
                j++;
            }
            
            if (j != n) {
                int num = v[j];
                if(max1 != q)  {
                    num = q;
                    max1 = q;
                }
                for (int k = i; k < j; k++) v[k] = num;
            }
            else if (i != 0) {
                int num = v[i - 1];
                if(max1 != q)  {
                    num = q;
                    max1 = q;
                }
                for (int k = i; k < j; k++) v[k] = num;
            }
            else 
                for (int k = 0; k < n; k++) v[k] = q;
        }
    }
    int hash1[200005] = {0};
    for (int i = 0; i < n; i++) {
        hash[v[i]]++;
        hash1[v[i]]++;
        max1 = max(v[i], max1);
    }
    for (int i = 0; i < n; i++) {
        if (hash[v[i]] == hash1[v[i]]) {
            range[v[i]].first = i;
            hash[v[i]]--;
            if (hash[v[i]] == 0) range[v[i]].second = i;
        }
        else {
            hash[v[i]]--;
            if (hash[v[i]] == 0) range[v[i]].second = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (range[v[i]].first == i) {
            if (s.empty()) {
                if (range[v[i]].first != range[v[i]].second) {
                    s.insert(v[i]);
                }
            }
            else if (v[i] < *s.rbegin()) {
                OK = false;
                break;
            }
            else {
                if (range[v[i]].first != range[v[i]].second) {
                    s.insert(v[i]);
                }
            }
        }
        else if (range[v[i]].second == i) {
            if (v[i] < *s.rbegin()) {
                OK = false;
                break;
            }
            else {
                s.erase(v[i]);
            }
        }
        else {
            if (v[i] < *s.rbegin()){
                OK = false;
                break;
            }
        }
    }
    if (OK && max1 == q) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) 
            cout << v[i] << " " ;
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
