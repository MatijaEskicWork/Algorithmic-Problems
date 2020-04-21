#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
class point{
public:
    int x, y;
};
 
typedef pair<point, point> square;
 
 
square intersection(square k1, square k2) {
    point p1 = {max(k1.first.x, k2.first.x), max(k1.first.y, k2.first.y)};
    point p2 = {min(k1.second.x, k2.second.x), min(k1.second.y, k2.second.y)};
    square good_ret = make_pair(p1, p2);
    
    
    point bad1 = {-2000000000, -2000000000}, bad2 = {-2000000000, -2000000000};
    square bad_ret = make_pair(bad1, bad2);
    
    if (k1.first.x > k2.second.x || k2.first.x > k1.second.x ||
        k1.first.y > k2.second.y || k2.first.y > k1.second.y) 
        return bad_ret;
    return good_ret;
    
}
 
bool cmp(pair<point, point> p1, pair<point, point> p2) {
    return (p1.first.x < p2.first.x);
}
 
 
int main()
{
    int n, x1, y1, x2, y2;
    cin >> n;
    vector <square> points, prefix, sufix(n + 5);
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        point p1 = {x1, y1}, p2 = {x2, y2};
        points.push_back(make_pair(p1, p2));
        //cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
    }
    //sort(points.begin(), points.end(), cmp);
    //for (int i = 0; i < n; i++) {
     //   cout << points[i].first.x << " " << points[i].first.y << " " << points[i].second.x << " " << points[i].second.y << endl;
   // }
    
    square tmp = points[0];
    prefix.push_back(tmp);
    for(int i = 1; i < n; i++) {
        tmp = intersection(points[i], prefix[i - 1]);
        prefix.push_back(tmp);
    }
    tmp = points[n - 1];
    sufix[n - 1] = tmp;
    for(int i = n - 2; i >= 0; i--) {
        tmp = intersection(points[i], sufix[i + 1]);
        sufix[i] = tmp;
    }
    
    int i;
    square ans;
    for (i = 0; i < n; i++) {
        int k = (i - 1 >= 0)? i - 1: 0;
        int j = (i + 1 < n)? i + 1: n - 1;
        //cout << prefix[i].first.x << " " << prefix[i].first.y << " " << prefix[i].second.x << " " << prefix[i].second.y << endl;
        //cout << sufix[i].first.x << " " << sufix[i].first.y << " " << sufix[i].second.x << " " << sufix[i].second.y << endl;
        if (k == 0 && sufix[1].first.x != -2000000000) {
            ans = sufix[1];
            break;
        }
        else if (j == n - 1 && prefix[n - 2].first.x != -2000000000) {
            ans = prefix[n - 2];
            break;
        }
        else if (sufix[j].first.x != -2000000000 && prefix[k].first.x != -2000000000) {
            ans = intersection(prefix[k], sufix[j]);
            if (ans.first.x != -2000000000)
                break;
        }
    }
    cout << ans.first.x << " " << ans.first.y << endl;
    
    return 0;
}
