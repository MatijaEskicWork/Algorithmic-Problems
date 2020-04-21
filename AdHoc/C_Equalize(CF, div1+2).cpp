#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    char bit1[1000000], bit2[1000000];
    for (int i = 0; i < N; i++){
        cin >> bit1[i];
    }
    for (int i = 0; i < N; i++){
        cin >> bit2[i];
    }
    
    int i = 0;
    int cnt = 0;
    while (i < N){
        if (bit1[i] != bit2[i] && bit1[i + 1] != bit2[i + 1] && abs(bit1[i] - bit1[i + 1]) == 1) {
            i += 2;
            cnt++;
        }
        else if (bit1[i] != bit2[i]) {
            i++;
            cnt++;
        }
        else 
            i++;
    }
    cout << cnt;
    
    
    return 0;
}
