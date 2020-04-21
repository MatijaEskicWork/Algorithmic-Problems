#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    if (n == 2) {
        cout << "-1";
        return 0;
    }
    n = n - 3;
    cout << "15" << endl << "10" << endl  << "6" << endl;
    int cnt = 2;
    while (n) {
        cout << 6 * cnt << endl;
        n--;
        cnt++;
    }
    return 0;
}
